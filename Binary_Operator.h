//CSE 335 Spring 2014, Project 3
//
//Binary_Operator.h - Interface for binary operators in a Boolean expression
//tree.
#ifndef _BINARY_OPERATOR_H_
#define _BINARY_OPERATOR_H_

#include <string>
#include "Expression.h"
using std::string;


class Binary_Operator : public Expression
{
public:
	virtual ~Binary_Operator();

	//Functions for managing the expressions on either side of this
	//operator.  Note that freeing a Binary_Operator object will not
	//free it's child expressions... you must do that yourself.
	Expression* Get_left_child();
	Expression* Get_right_child();
	const Expression* Get_left_child() const;
	const Expression* Get_right_child() const;
	void Set_left_child(Expression* new_child);
	void Set_right_child(Expression* new_child);

	//Interface for having operators actually operate on something.
	//virtual bool Operate(bool left_operand, bool right_operand) const = 0;

	//Gets a printable representation of the operator itself.
	virtual const string& Get_symbol() const = 0;

protected:
	//Pointers to the two expressions referenced by this operator.
	Expression* left_child, * right_child;

	//Keep the constructors hidden...
	Binary_Operator();
	Binary_Operator(const Binary_Operator& src);
	const Binary_Operator& operator=(const Binary_Operator& src);
};

#endif //ndef _BINARY_OPERATOR_H_
