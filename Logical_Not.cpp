//CSE 335 Spring 2014, Project 3
//
//Logical_Not.cc - Implementation of Logical_Not class member functions.

#include "Logical_Not.h"
#include "Expression_Operation.h"


//Constructor... doesn't do anything!
Logical_Not::Logical_Not()
{
}


//Copy constructor... invokes the parent class's copy constructor so the
//expression pointer will get copied.
Logical_Not::Logical_Not(const Logical_Not& src)
	: Unary_Operator(src)
{
}


//Assignment operator... same business as in the copy constructor.
const Logical_Not& Logical_Not::operator=(const Logical_Not& src)
{
	Unary_Operator::operator=(src);
	return *this;
}


//Destructor.  Nothing speical to do here.
Logical_Not::~Logical_Not()
{
}


void Logical_Not::Accept(Expression_Operation& visitor)
{
	visitor.Visit_logical_not(*this);
}


//Return the negation of the given operand.
bool Logical_Not::Operate(bool operand) const
{
	return !operand;
}


const string& Logical_Not::Get_symbol() const
{
	//Make sure we've got a representation of the NOT symbol that won't
	//go anywhere, then return it.
	static const string symbol = "~";
	return symbol;
}
