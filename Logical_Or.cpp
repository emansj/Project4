//CSE 335 Spring 2014, Project 3
//
//Logical_Or.cc - Implementation of Logical_Or class member functions.

#include "Logical_Or.h"
#include "Expression_Operation.h"


//Constructor... no special work to do here.
Logical_Or::Logical_Or()
{
}


//Copy constructor:  invoke the parent class so the subexpressions get moved.
Logical_Or::Logical_Or(const Logical_Or& src)
	: Binary_Operator(src)
{
}

//Assignment operator:  same deal as the copy constructor.
const Logical_Or& Logical_Or::operator=(const Logical_Or& src)
{
	Binary_Operator::operator=(src);
	return *this;
}


//Destructor.  No extra work here, either.
Logical_Or::~Logical_Or()
{
}


void Logical_Or::Accept(Expression_Operation& visitor)
{
	visitor.Visit_logical_or(*this);
}


//Apply a logical OR operation to the two operands.
bool Logical_Or::Operate(bool left_operand, bool right_operand) const
{
	return (left_operand || right_operand);
}


//Send back an easily-recognized symbol for the logical OR.
static const string symbol = "|";
const string& Logical_Or::Get_symbol() const
{
	return symbol;
}
