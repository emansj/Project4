//CSE 335 Spring 2014, Project 3
//
//Evaluate_Operation.cc - Implementation of Evaluate_Operation functionality.

#include "Evaluate_Operation.h"


//Constructor.  The STL stack sets up itself.  Hooray.
Evaluate_Operation::Evaluate_Operation()
{
}

//Since the result stack is only meaningful in the context of an ongoing
//Evaluate() operation, there's no point in copying it around.  The copy
//constructor and assignment operator don't need to do anything.
Evaluate_Operation::Evaluate_Operation(const Evaluate_Operation& src)
{
}

const Evaluate_Operation& Evaluate_Operation::operator=(
	const Evaluate_Operation& src)
{
	return *this;
}

//Destructor.  The STL stack cleans itself up, too.
Evaluate_Operation::~Evaluate_Operation()
{
}


bool Evaluate_Operation::Evaluate(Expression& expr, bool& out_result)
{
	//Visit the given expression to have the evaluation process started.
	expr.Accept(*this);

	//Grab the results, then clean off the stack so it won't be crudded
	//up in future operations.
	RESULT final_eval = results.top();
	results.pop();

	//See what happened and respond appropriately.
	switch (final_eval)
	{
	case TRUE:
		out_result = true;
		return true;
		break;
	case FALSE:
		out_result = false;
		return true;
		break;
	default:
		return false;
		break;
	}
}


void Evaluate_Operation::Visit_literal(Literal& literal)
{
	//Literals always evaluate to whatever their set value is.  Send back
	//that.
	if (literal.Get_value())
		results.push(TRUE);
	else
		results.push(FALSE);
}


void Evaluate_Operation::Visit_variable(Variable& variable)
{
	//Make sure the variable has a defined value.
	if (variable.Is_defined())
	{
		//Send back this value.
		if (variable.Get_value())
			results.push(TRUE);
		else
			results.push(FALSE);
	}
	else
	{
		//Indicate that the variable is undefined.
		results.push(UNDEFINED);
	}
}


void Evaluate_Operation::Visit_logical_not(Logical_Not& not_op)
{
	//Try to get the value of the operator's subexpression.
	not_op.Get_child()->Accept(*this);

	RESULT child_result = results.top();
	results.pop();

	//See if we got a valid result back.  Evaluate it if we did.  If we
	//didn't... we're still undefined.
	switch (child_result)
	{
	case TRUE:
		results.push(FALSE);
		break;
	case FALSE:
		results.push(TRUE);
		break;
	default:
		results.push(UNDEFINED);
		break;
	}
}


void Evaluate_Operation::Visit_logical_and(Logical_And& and_op)
{
	//Evaluate the operator's two subexpressions to see what we're
	//dealing with.
	and_op.Get_left_child()->Accept(*this);
	RESULT left_result = results.top();
	results.pop();

	and_op.Get_right_child()->Accept(*this);
	RESULT right_result = results.top();
	results.pop();

	//See if we can short-circuit this expression.  Do so if possible.
	if ((left_result == FALSE) || (right_result == FALSE))
	{
		results.push(FALSE);
	}
	//See if this whole thing is actually true.
	else if ((left_result == TRUE) && (right_result == TRUE))
	{
		results.push(TRUE);
	}
	//The only alternative is that at least one side is undefined and at
	//most one side is true.  That means... we don't know the answer.
	else
	{
		results.push(UNDEFINED);
	}
}


void Evaluate_Operation::Visit_logical_or(Logical_Or& or_op)
{
	//Check the children.
	or_op.Get_left_child()->Accept(*this);
	RESULT left_result = results.top();
	results.pop();

	or_op.Get_right_child()->Accept(*this);
	RESULT right_result = results.top();
	results.pop();

	//Try to short-circuit the expression, so we can handle having one
	//side be undefined if absolutely necessary.
	if ((left_result == TRUE) || (right_result == TRUE))
	{
		results.push(TRUE);
	}
	//Check for the other case we can actually evaluate.
	else if ((left_result == FALSE) && (right_result == FALSE))
	{
		results.push(FALSE);
	}
	//Looks like we're stuck.
	else
	{
		results.push(UNDEFINED);
	}
}


void Evaluate_Operation::Visit_implication(Implication& imp_op)
{
	//Check the children.
	imp_op.Get_left_child()->Accept(*this);
	RESULT left_result = results.top();
	results.pop();

	imp_op.Get_right_child()->Accept(*this);
	RESULT right_result = results.top();
	results.pop();

	//If the left side is false or the right side is true, the implication
	//guaranteed to be true, even if the other side is undefined.
	if ((left_result == FALSE) || (right_result == TRUE))
	{
		results.push(TRUE);
	}
	//Check for the one other case where the expression can be evaluated.
	else if ((left_result == TRUE) && (right_result == FALSE))
	{
		results.push(FALSE);
	}
	//Nope, can't evaluate this.
	else
	{
		results.push(UNDEFINED);
	}
}


void Evaluate_Operation::Visit_equivalence(Equivalence& equiv_op)
{
	//Check the children.
	equiv_op.Get_left_child()->Accept(*this);
	RESULT left_result = results.top();
	results.pop();

	equiv_op.Get_right_child()->Accept(*this);
	RESULT right_result = results.top();
	results.pop();

	//See if we can evaluate the equivalence.  No short-circuiting here.
	if ((left_result != UNDEFINED) && (right_result != UNDEFINED))
	{
		//Are they equivalent?
		if (left_result == right_result)
			results.push(TRUE);
		else
			results.push(FALSE);
	}
	//Nope!
	else
	{
		results.push(UNDEFINED);
	}
}
