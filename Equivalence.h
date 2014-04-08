//CSE 335 Spring 2014, Project 3
//
//Equivalence.h - Class representing a Boolean equivalence (biconditional)
//operator.

#ifndef _EQUIVALENCE_H_
#define _EQUIVALENCE_H_

#include "Binary_Operator.h"


class Equivalence : public Binary_Operator
{
public:
	Equivalence();
	Equivalence(const Equivalence& src);
	const Equivalence& operator=(const Equivalence& src);
	virtual ~Equivalence();

	//Implementations of pure virtual binary operator functions.
	virtual void Accept(Expression_Operation& visitor);
	virtual bool Operate(bool left_operand, bool right_operand) const;
	virtual const string& Get_symbol() const;
};

#endif //ndef _EQUIVALENCE_H_
