//CSE 335 Spring 2014, Project 3
//
//Print_Operation.h - Visitor class for printing out expression trees.

#ifndef _PRINT_OPERATION_H_
#define _PRINT_OPERATION_H_

//The way the Unary_Operator and Binary_Operator classes are set up, we don't
//need to know the specific type of each operator.  We can get away with
//implementing the lite version.
#include "Expression_Operation_Lite.h"
#include <iostream>
using std::ostream;


class Print_Operation : public Expression_Operation_Lite
{
public:
	Print_Operation();
	Print_Operation(const Print_Operation& src);
	const Print_Operation& operator=(const Print_Operation& src);
	virtual ~Print_Operation();

	//Begins the printing process on a given expression.  If the top-level
	//node in the expression tree is an operator, this will traverse down
	//into its subexpressions and give you a nice, parenthesized, infix
	//printout.
	void Print(Expression& expr, ostream& output_stream);

	//Implementations of class-specific visitor functions.
	virtual void Visit_literal(Literal& literal);
	virtual void Visit_variable(Variable& variable);
	virtual void Visit_unary_operator(Unary_Operator& operate);
	virtual void Visit_binary_operator(Binary_Operator& operate);

protected:
	//The output stream currently being used for printing.  Updated
	//every time someone requests a new print, then kept internally so the
	//the Visit_...() functions have an output stream to print to.
	ostream* out;
};


#endif //ndef _PRINT_OPERATION_H_
