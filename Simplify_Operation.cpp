//CSE 335 Spring 2014, Project 3
//
//Simplify_Operation.cc - Implementation of Simplify visitor functionality.

#include "Simplify_Operation.h"
#include "Free_Operation.h"


//Constructors and such.  We're not supposed to free the Expressions that we
//pass back and the stack contents have no meaning outside of a Simplify
//operation.  Therefore, these shouldn't do anything.
Simplify_Operation::Simplify_Operation()
{
}

Simplify_Operation::Simplify_Operation(const Simplify_Operation& src)
{
}

const Simplify_Operation& Simplify_Operation::operator=(const Simplify_Operation& src)
{
	return *this;
}

Simplify_Operation::~Simplify_Operation()
{
}


Expression* Simplify_Operation::Simplify(Expression& expr)
{
	//Visit the given expression.  This will go through the entire
	//expression tree and put the simplified result on the stack.
	expr.Accept(*this);

	//Grab the simplified version and give it back.  Also clean off that
	//other stack.
	Expression* result = Pop(simplified);
	value.pop();
	return result;
}


void Simplify_Operation::Visit_literal(Literal& literal)
{
	//Literals cannot be simplified.  The best we can do is to copy it
	//(since we're supposed to be sending back a *new* expression tree).
	Literal* copy = new Literal(literal);
	simplified.push(copy);

	//Also store the value of the literal (so our parent node doesn't have
	//to do something complicated to conclude that it is a literal).
	if (literal.Get_value())
		value.push(TRUE);
	else
		value.push(FALSE);
}


void Simplify_Operation::Visit_variable(Variable& variable)
{
	//See if the variable has an assigned value or not.  If it does, we
	//can replace it with an equivalent literal.  If not, the best we can
	//do is to copy the variable.
	if (variable.Is_defined())
	{
		simplified.push(new Literal(variable.Get_value()));
		if (variable.Get_value())
			value.push(TRUE);
		else
			value.push(FALSE);
	}
	else
	{
		simplified.push(new Variable(variable));
		value.push(UNDEFINED);
	}
}


void Simplify_Operation::Visit_logical_not(Logical_Not& not_op)
{
	//Simplfy the operator's child expression as much as possible.
	not_op.Get_child()->Accept(*this);
	Expression* simple_child = Pop(simplified);
	RESULT child_value = Pop(value);

	//See what kind of results we got from that simplification.
	if (child_value != UNDEFINED)
	{
		//Hooray, we can replace NOT(child) with a simple literal.
		//Kill of the child since we don't need it anymore, then make
		//a new literal to represent the inverse of its value.
		Free_Operation freer;
		freer.Free(simple_child);

		if (child_value == TRUE)
		{
			simplified.push(new Literal(false));
			value.push(FALSE);
		}
		else
		{
			simplified.push(new Literal(true));
			value.push(TRUE);
		}
	}
	else
	{
		//Hrm, we don't know what this is.  Make a new NOT operator
		//to connect the child to, so it mimics the structure of the
		//original expression.
		Logical_Not* copy = new Logical_Not;
		copy->Set_child(simple_child);
		simplified.push(copy);
		value.push(UNDEFINED);
	}
}


void Simplify_Operation::Visit_logical_and(Logical_And& and_op)
{
	//Simplify the two children as much as we can.
	and_op.Get_left_child()->Accept(*this);
	Expression* left_simple = Pop(simplified);
	RESULT left_value = Pop(value);

	and_op.Get_right_child()->Accept(*this);
	Expression* right_simple = Pop(simplified);
	RESULT right_value = Pop(value);

	//See if we can represent this operator by a single literal.  There are
	//actually a couple ways in which this could happen.
	Free_Operation freer;
	if ((left_value == FALSE) || (right_value == FALSE))
	{
		//A & False = False.  Free the children and make a new literal.
		freer.Free(left_simple);
		freer.Free(right_simple);
		simplified.push(new Literal(false));
		value.push(FALSE);
	}
	else if ((left_value == TRUE) && (right_value == TRUE))
	{
		//True & True = True.  Same business.
		freer.Free(left_simple);
		freer.Free(right_simple);
		simplified.push(new Literal(true));
		value.push(TRUE);
	}
	//Okay, we can't get a defined value, but maybe we can still simplify
	//things a little.
	else if (left_value == TRUE)
	{
		//True & A = A.  Kill the literal on the left and give back A.
		freer.Free(left_simple);
		simplified.push(right_simple);
		value.push(UNDEFINED);
	}
	else if (right_value == TRUE)
	{
		freer.Free(right_simple);
		simplified.push(left_simple);
		value.push(UNDEFINED);
	}
	//Looks like there's nothing we can do but copy the original setup.
	else
	{
		Logical_And* copy = new Logical_And();
		copy->Set_left_child(left_simple);
		copy->Set_right_child(right_simple);
		simplified.push(copy);
		value.push(UNDEFINED);
	}
}


void Simplify_Operation::Visit_logical_or(Logical_Or& or_op)
{
	//Simplify the two children as much as we can.
	or_op.Get_left_child()->Accept(*this);
	Expression* left_simple = Pop(simplified);
	RESULT left_value = Pop(value);

	or_op.Get_right_child()->Accept(*this);
	Expression* right_simple = Pop(simplified);
	RESULT right_value = Pop(value);

	//Check for cases where we can assign the whole expression a
	//definite value.  Replace the whole thing with a literal if we can.
	Free_Operation freer;
	if ((left_value == TRUE) || (right_value == TRUE))
	{
		//A | True = True.
		freer.Free(left_simple);
		freer.Free(right_simple);
		simplified.push(new Literal(true));
		value.push(TRUE);
	}
	else if ((left_value == FALSE) && (right_value == FALSE))
	{
		//False | False = False.
		freer.Free(left_simple);
		freer.Free(right_simple);
		simplified.push(new Literal(false));
		value.push(FALSE);
	}
	//See if we can at least cut out one of the children.  That's still
	//simplified by a little.
	else if (left_value == FALSE)
	{
		//False | A = A.
		freer.Free(left_simple);
		simplified.push(right_simple);
		value.push(UNDEFINED);
	}
	else if (right_value == FALSE)
	{
		freer.Free(right_simple);
		simplified.push(left_simple);
		value.push(UNDEFINED);
	}
	//Nothing we can do.  Put the two simplified children between an OR.
	else
	{
		Logical_Or* copy = new Logical_Or;
		copy->Set_left_child(left_simple);
		copy->Set_right_child(right_simple);
		simplified.push(copy);
		value.push(UNDEFINED);
	}
}


void Simplify_Operation::Visit_implication(Implication& imp_op)
{
	//Simplify the two children as much as we can.
	imp_op.Get_left_child()->Accept(*this);
	Expression* left_simple = Pop(simplified);
	RESULT left_value = Pop(value);

	imp_op.Get_right_child()->Accept(*this);
	Expression* right_simple = Pop(simplified);
	RESULT right_value = Pop(value);

	//See if we can assign this expression a simple Boolean value.
	//If we can, throw out the children and replace them with a literal.
	Free_Operation freer;
	if ((left_value == FALSE) || (right_value == TRUE))
	{
		//False > A = True.  A > True = True.
		freer.Free(left_simple);
		freer.Free(right_simple);
		simplified.push(new Literal(true));
		value.push(TRUE);
	}
	else if ((left_value == TRUE) && (right_value == FALSE))
	{
		//True > False = False.
		freer.Free(left_simple);
		freer.Free(right_simple);
		simplified.push(new Literal(false));
		value.push(FALSE);
	}
	//See if we can cut out one side of the expression, at least.
	else if (left_value == TRUE)
	{
		//True > A = A.
		freer.Free(left_simple);
		simplified.push(right_simple);
		value.push(UNDEFINED);
	}
	else if (right_value == FALSE)
	{
		//A > False = ~A.
		freer.Free(right_simple);
		Logical_Not* notter = new Logical_Not;
		notter->Set_child(left_simple);
		simplified.push(notter);
		value.push(UNDEFINED);
	}
	//Nope, we're stuck.  Duplicate the original expression setup.
	else
	{
		Implication* copy = new Implication;
		copy->Set_left_child(left_simple);
		copy->Set_right_child(right_simple);
		simplified.push(copy);
		value.push(UNDEFINED);
	}
}


void Simplify_Operation::Visit_equivalence(Equivalence& equiv_op)
{
	//Simplify the two children as much as we can.
	equiv_op.Get_left_child()->Accept(*this);
	Expression* left_simple = Pop(simplified);
	RESULT left_value = Pop(value);

	equiv_op.Get_right_child()->Accept(*this);
	Expression* right_simple = Pop(simplified);
	RESULT right_value = Pop(value);

	//See if we can replace both children and the equivalence operator with	
	//a single literal.  That's as simple as it gets.
	Free_Operation freer;
	if ((left_value != UNDEFINED) && (right_value != UNDEFINED))
	{
		//Clean up the no-longer-needed children.
		freer.Free(left_simple);
		freer.Free(right_simple);

		//Evaluate the equivalence.
		if (left_value == right_value)
		{
			simplified.push(new Literal(true));
			value.push(TRUE);
		}
		else
		{
			simplified.push(new Literal(false));
			value.push(FALSE);
		}
	}
	//Well, see if we can remove one half of the expression, then.
	else if (left_value != UNDEFINED)
	{
		//True == A = A.  False == A = ~A.  See which it is.
		freer.Free(left_simple);
		if (left_value == TRUE)
		{
			simplified.push(right_simple);
		}
		else
		{
			Logical_Not* notter = new Logical_Not;
			notter->Set_child(right_simple);
			simplified.push(notter);
		}
		value.push(UNDEFINED);
	}
	else if (right_value != UNDEFINED)
	{
		freer.Free(right_simple);
		if (right_value == TRUE)
		{
			simplified.push(left_simple);
		}
		else
		{
			Logical_Not* notter = new Logical_Not;
			notter->Set_child(left_simple);
			simplified.push(notter);
		}
		value.push(UNDEFINED);
	}
	//Looks like we have to duplicate the original setup.
	else
	{
		Equivalence* copy = new Equivalence;
		copy->Set_left_child(left_simple);
		copy->Set_right_child(right_simple);
		simplified.push(copy);
		value.push(UNDEFINED);
	}
}
