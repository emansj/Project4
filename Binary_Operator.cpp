//CSE 335 Spring 2014, Project 3
//
//Binary_Operator.cc - Implementation of Binary_Operator class members.

#include "Binary_Operator.h"


//Constructor.  Nullifies the child pointers so we know they haven't been set
//up yet.
Binary_Operator::Binary_Operator()
	: left_child(NULL),
	right_child(NULL)
{
}


//Copy constructor.  Moves over the child pointers directly (shallow copy)..
//which we can get away with since we're not freeing them in the destructor.
Binary_Operator::Binary_Operator(const Binary_Operator& src)
	: left_child(src.left_child),
	right_child(src.right_child)
{
}


//Assignment operator, just like the copy constructor.
const Binary_Operator& Binary_Operator::operator=(const Binary_Operator& src)
{
	left_child = src.left_child;
	right_child = src.right_child;
	return *this;
}


//Destructor.  Does nothing because you haven't learned about reference
//counting yet. :)
Binary_Operator::~Binary_Operator()
{
}


//Methods for accessing the child expressions, in both const and non-const
//forms.
Expression* Binary_Operator::Get_left_child()
{
	return left_child;
}

Expression* Binary_Operator::Get_right_child()
{
	return right_child;
}

const Expression* Binary_Operator::Get_left_child() const
{
	return left_child;
}

const Expression* Binary_Operator::Get_right_child() const
{
	return right_child;
}


//Methods for actually setting the child pointers.
void Binary_Operator::Set_left_child(Expression* new_child)
{
	left_child = new_child;
}

void Binary_Operator::Set_right_child(Expression* new_child)
{	right_child = new_child;
}
