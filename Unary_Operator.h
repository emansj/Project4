//CSE 335 Spring 2014, Project 3
//
//Unary_Operator.h - Interface for unary Boolean operators in an expression
//tree.

#ifndef _UNARY_OPERATOR_H_
#define _UNARY_OPERATOR_H_

#include <string>
#include "Expression.h"
using std::string;


class Unary_Operator : public Expression
{
public:
	virtual ~Unary_Operator();

	//Lets you manage the expression that this operator will affect.
	//Note that deleting unary operators will NOT free their child
	//expression; you'll need to free those yourself.  Later on in the
	//course, you'll learn about a better way to handle this...
	Expression* Get_child();
	const Expression* Get_child() const;
	void Set_child(Expression* new_child);

	//Interface for having operators actually operate on a Boolean value.
	virtual bool Operate(bool operand) const = 0;

	//Gets a printable representation of the operator itself.
	virtual const string& Get_symbol() const = 0;

protected:
	//Pointer to the expression that this operator is working on.
	Expression* child;

	//Keep the constructors hidden...  no sense instantiating an abstract
	//type.
	Unary_Operator();
	Unary_Operator(const Unary_Operator& src);
	const Unary_Operator& operator=(const Unary_Operator& src);
};

#endif //ndef _UNARY_OPERATOR_H_
