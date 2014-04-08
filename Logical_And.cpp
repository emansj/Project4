//CSE 335 Spring 2014, Project 3
//
//Logical_And.cc - Implementation of Logical_And class member functions.

#include "Logical_And.h"
#include "Expression_Operation.h"


//Constructor... no special work to do here.
Logical_And::Logical_And()
{
}


//Copy constructor:  invoke the parent class so the subexpressions get moved.
Logical_And::Logical_And(const Logical_And& src)
	: Binary_Operator(src)
{
}

//Assignment operator:  same deal as the copy constructor.
const Logical_And& Logical_And::operator=(const Logical_And& src)
{
	Binary_Operator::operator=(src);
	return *this;
}


//Destructor.  No extra work here, either.
Logical_And::~Logical_And()
{
}


void Logical_And::Accept(Expression_Operation& visitor)
{
	visitor.Visit_logical_and(*this);
}

/*
//Apply a logical AND operation to the two operands.
bool Logical_And::Operate(bool left_operand, bool right_operand) const
{
	return (left_operand && right_operand);
}
*/

//Send back an easily-recognized symbol for the logical AND.
static const string symbol = "&";
const string& Logical_And::Get_symbol() const
{
	return symbol;
}
