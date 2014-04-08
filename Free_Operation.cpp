//CSE 335 Spring 2014, Project 3
//
//Free_Operation.cc - Implementation of expression-freeing visitor class.

#include "Free_Operation.h"


//Constructors/destructors.  There is nothing to do here; ergo, they do nothing.
Free_Operation::Free_Operation()
{
}

Free_Operation::Free_Operation(const Free_Operation& src)
{
}

const Free_Operation& Free_Operation::operator=(const Free_Operation& src)
{
	return *this;
}

Free_Operation::~Free_Operation()
{
}


void Free_Operation::Free(Expression* expr)
{
	//Have the expression object identify itself so we can start freeing.
	expr->Accept(*this);
}


void Free_Operation::Visit_literal(Literal& literal)
{
	//Literals are nodes on the expression tree.  Just delete it.
	delete &literal;
}


void Free_Operation::Visit_variable(Variable& variable)
{
	//Variables have no subexpressions.  Delete the given object.
	delete &variable;
}


void Free_Operation::Visit_unary_operator(Unary_Operator& operate)
{
	//Have the operator's subexpression freed, then free the operator
	//itself.
	operate.Get_child()->Accept(*this);
	delete &operate;
}


void Free_Operation::Visit_binary_operator(Binary_Operator& operate)
{
	//Free both subexpressions while we know where they are, then get rid
	//of the now-childless operator.
	operate.Get_left_child()->Accept(*this);
	operate.Get_right_child()->Accept(*this);
	delete &operate;
}
