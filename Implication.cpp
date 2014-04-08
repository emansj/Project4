//CSE 335 Spring 2014, Project 3
//
//Implication.cc - Implementation of Implication class member functions.

#include "Implication.h"
#include "Expression_Operation.h"


//Constructor... no special work to do here.
Implication::Implication()
{
}


//Copy constructor:  invoke the parent class so the subexpressions get moved.
Implication::Implication(const Implication& src)
	: Binary_Operator(src)
{
}

//Assignment operator:  same deal as the copy constructor.
const Implication& Implication::operator=(const Implication& src)
{
	Binary_Operator::operator=(src);
	return *this;
}


//Destructor.  No extra work here, either.
Implication::~Implication()
{
}


void Implication::Accept(Expression_Operation& visitor)
{
	visitor.Visit_implication(*this);
}


//Apply an implication operation on the two operands.
bool Implication::Operate(bool left_operand, bool right_operand) const
{
	//This combination of logical ops is equivalent to implication.
	// the previous code looks erroneous, so commented out
	//return (left_operand || !right_operand);
	return (!left_operand || right_operand);

}


//Send back something that kind of looks like an implication operator,
//or at least the best we can do with only one character that people can
//easily type.
static const string symbol = ">";
const string& Implication::Get_symbol() const
{
	return symbol;
}
