//CSE 335 Spring 2014, Project 3
//
//Logical_And.h - Class representing a Boolean AND operator.

#ifndef _LOGICAL_AND_H_
#define _LOGICAL_AND_H_

#include "Binary_Operator.h"


class Logical_And : public Binary_Operator
{
public:
	Logical_And();
	Logical_And(const Logical_And& src);
	const Logical_And& operator=(const Logical_And& src);
	virtual ~Logical_And();

	//Implementations of pure virtual binary operator functions.
	virtual void Accept(Expression_Operation& visitor);
	//virtual bool Operate(bool left_operand, bool right_operand) const;
	virtual const string& Get_symbol() const;
};

#endif //ndef _LOGICAL_AND_H_
