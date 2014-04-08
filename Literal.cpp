//CSE 335 Spring 2014, Project 3
//
//Literal.cc - Implementation of Literal class member functions.

#include "Literal.h"
#include "Expression_Operation.h"


//Constructor.  Assigns the literal an arbitrary default value.
Literal::Literal()
	: value(false)
{
}


//Move convenient constructor that assigns a proper initial value.
Literal::Literal(bool init_value)
	: value(init_value)
{
}


//Copy constructor.
Literal::Literal(const Literal& src)
	: value(src.value)
{
}


//Assignment operator.
const Literal& Literal::operator=(const Literal& src)
{
	value = src.value;
	return *this;
}


//Destructor.  Doesn't need to do anything.
Literal::~Literal()
{
}


//Returns the current value of the literal.
bool Literal::Get_value() const
{
	return value;
}


//Updates the literal to have the given value.
void Literal::Set_value(bool new_value)
{
	value = new_value;
}


//Calls the literal-specific function in the given visitor.
void Literal::Accept(Expression_Operation& visitor)
{
	visitor.Visit_literal(*this);
}
