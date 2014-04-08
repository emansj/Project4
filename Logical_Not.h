//CSE 335 Spring 2014, Project 3
//
//Logical_Not.h - Class for the logical NOT operator.

#ifndef _LOGICAL_NOT_H_
#define _LOGICAL_NOT_H_

#include "Unary_Operator.h"


class Logical_Not : public Unary_Operator
{
public:
	Logical_Not();
	Logical_Not(const Logical_Not& src);
	const Logical_Not& operator=(const Logical_Not& src);
	virtual ~Logical_Not();

	//Implementation of the pure virtual unary operator functions.
	virtual void Accept(Expression_Operation& visitor);
	virtual bool Operate(bool operand) const;
	virtual const string& Get_symbol() const;
};

#endif //ndef _LOGICAL_NOT_H_
