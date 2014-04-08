//CSE 335 Spring 2014, Project 3
//
//Implication.h - Class representing a Boolean implication operator.

#ifndef _IMPLICATION_H_
#define _IMPLICATION_H_

#include "Binary_Operator.h"


class Implication : public Binary_Operator
{
public:
	Implication();
	Implication(const Implication& src);
	const Implication& operator=(const Implication& src);
	virtual ~Implication();

	//Implementations of pure virtual binary operator functions.
	virtual void Accept(Expression_Operation& visitor);
	virtual bool Operate(bool left_operand, bool right_operand) const;
	virtual const string& Get_symbol() const;
};

#endif //ndef _IMPLICATION_H_
