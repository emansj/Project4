//CSE 335 Spring 2014, Project 3
//
//Equivalence.cc - Implementation of Equivalence class member functions.

#include "Equivalence.h"
#include "Expression_Operation.h"


//Constructor... no special work to do here.
Equivalence::Equivalence()
{
}


//Copy constructor:  invoke the parent class so the subexpressions get moved.
Equivalence::Equivalence(const Equivalence& src)
	: Binary_Operator(src)
{
}

//Assignment operator:  same deal as the copy constructor.
const Equivalence& Equivalence::operator=(const Equivalence& src)
{
	Binary_Operator::operator=(src);
	return *this;
}


//Destructor.  No extra work here, either.
Equivalence::~Equivalence()
{
}


void Equivalence::Accept(Expression_Operation& visitor)
{
	visitor.Visit_equivalence(*this);
}


//Apply an equivalence operation to the two operands.
bool Equivalence::Operate(bool left_operand, bool right_operand) const
{
	//For equivalence to hold, the two operands must be the same.
	return (left_operand && right_operand) ||
		(!left_operand && !right_operand);
}


//Send back the best one-character symbol for the implication operator
//that we can find (and people can type easily).
static const string symbol = "=";
const string& Equivalence::Get_symbol() const
{
	return symbol;
}
