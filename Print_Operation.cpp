//CSE 335 Spring 2014, Project 3
//
//Print_Operation.cc - Implementation of all of the expression-printing
//visitor functions.

#include "Print_Operation.h"
#include <iostream>
using std::ostream;
using std::boolalpha;


//Nothing special for the constructors and destructors to do, other than make
//sure that the temporary out pointer is initialized.
Print_Operation::Print_Operation()
	: out(NULL)
{
}


//Copy constructor & assignment operator.  May as well copy the output
//stream pointer, though it shouldn't make a difference since it gets
//reset every time someone prints.
Print_Operation::Print_Operation(const Print_Operation& src)
	: out(src.out)
{
}


const Print_Operation& Print_Operation::operator=(const Print_Operation& src)
{
	out = src.out;
	return *this;
}


Print_Operation::~Print_Operation()
{
}


void Print_Operation::Print(Expression& expr, ostream& output_stream)
{
	//Remember where we're going to be printing.
	out = &output_stream;

	//Have the given expression object tell us what type it is so we can
	//start printing it.
	expr.Accept(*this);
}


void Print_Operation::Visit_literal(Literal& literal)
{
	//Print a nice, alphanumeric representation of the literal's value
	//rather than those crummy 1s and 0s.
	*out << boolalpha << literal.Get_value();
}


void Print_Operation::Visit_variable(Variable& variable)
{
	//Print the name of the variable.  As far as printing goes, we don't
	//care about whether it's defined or not.
	*out << variable.Get_name();
}


void Print_Operation::Visit_unary_operator(Unary_Operator& operate)
{
	//Print out the symbol for the operator itself, followed by whatever
	//expression it's applying to.
	*out << operate.Get_symbol();
	operate.Get_child()->Accept(*this);
}


void Print_Operation::Visit_binary_operator(Binary_Operator& operate)
{
	//Print the two subexpressions, with the symbol for the operator
	//sandwiched in the middle.  Wrap the whole thing in parentheses to
	//avoid ambiguity.
	*out << "(";
	operate.Get_left_child()->Accept(*this);
	*out << " " << operate.Get_symbol() << " ";
	operate.Get_right_child()->Accept(*this);
	*out << ")";
}
