//CSE 335 Spring 2014, Project 3
//
//Variable.cc - Implementation of Variable class member functions.

#include "Variable.h"
#include "Expression_Operation.h"


//Constructor.  Make sure that the variable is marked as undefined, then
//give it an arbitrary value and nondescript name.
Variable::Variable()
	: defined(false),
	value(false),
	name("")
{
}


//Copy constructor.
Variable::Variable(const Variable& src)
	: defined(src.defined),
	value(src.value),
	name(src.name)
{
}


//Assignment operator.
const Variable& Variable::operator=(const Variable& src)
{
	defined = src.defined;
	value = src.value;
	name = src.name;

	return *this;
}


//Destructor (which doesn't have any work to do).
Variable::~Variable()
{
}


//Returns whether the variable's value has been defined or not.
bool Variable::Is_defined() const
{
	return defined;
}

//Returns the value associated with the variable (assumes that it's defined).
bool Variable::Get_value() const
{
	return value;
}

//Resets the variable to an undefined state.
void Variable::Clear_value()
{
	defined = false;
}

//Assigns a value to the variable.
void Variable::Set_value(bool new_value)
{
	defined = true;
	value = new_value;
}

//Gives back the variable's name.
const string& Variable::Get_name() const
{
	return name;
}

//Assigns the variable a new name.
void Variable::Set_name(const string& new_name)
{
	name = new_name;
}

//Invokes the variable-specific method on the given visitor.
void Variable::Accept(Expression_Operation& visitor)
{
	visitor.Visit_variable(*this);
}
