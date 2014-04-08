//CSE 335 Spring 2014, Project 3
//
//Unary_Operator.cc - Implementation of Unary_Operator class member functions.

#include "Unary_Operator.h"


//Constructor.  Makes sure that we know the child pointer isn't initialized yet.
Unary_Operator::Unary_Operator()
	: child(NULL)
{
}


//Destructor.  Does NOT free the child!
Unary_Operator::~Unary_Operator()
{
}


//Copy constructor.  If we did free the child in the destructor, this would
//be suicidal (we'd end up freeing the child at least twice).  Fortunately,
//we don't free the child, so this is fine.
Unary_Operator::Unary_Operator(const Unary_Operator& src)
	: child(src.child)
{
}


//Assignment operator.
const Unary_Operator& Unary_Operator::operator=(const Unary_Operator& src)
{
	child = src.child;

	return *this;
}


//Sends back a pointer to our child.
Expression* Unary_Operator::Get_child()
{
	return child;
}


//Sends back a constant pointer to the child, in case some very well-behaved
//function would like to work on it.
const Expression* Unary_Operator::Get_child() const
{
	return child;
}


//Sets a new child pointer.
void Unary_Operator::Set_child(Expression* new_child)
{
	child = new_child;
}
