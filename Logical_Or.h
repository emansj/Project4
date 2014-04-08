//CSE 335 Spring 2014, Project 3
//
//Logical_Or.h - Class representing a Boolean OR operator.

#ifndef _LOGICAL_OR_H_
#define _LOGICAL_OR_H_

#include "Binary_Operator.h"


class Logical_Or : public Binary_Operator
{
public:
	Logical_Or();
	Logical_Or(const Logical_Or& src);
	const Logical_Or& operator=(const Logical_Or& src);
	virtual ~Logical_Or();

	//Implementations of pure virtual binary operator functions.
	virtual void Accept(Expression_Operation& visitor);
	virtual bool Operate(bool left_operand, bool right_operand) const;
	virtual const string& Get_symbol() const;
};

#endif //ndef _LOGICAL_OR_H_
