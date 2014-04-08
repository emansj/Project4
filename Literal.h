//CSE 335 Spring 2014, Project 3
//
//Literal.h - Class definition for Boolean literals in an expression.

#ifndef _LITERAL_H_
#define _LITERAL_H_

#include "Expression.h"


class Literal : public Expression
{
public:
	Literal();
	Literal(bool init_value);
	Literal(const Literal& src);
	const Literal& operator=(const Literal& src);
	virtual ~Literal();

	//Gets/sets the value of the literal.
	bool Get_value() const;
	void Set_value(bool new_value);

	//Implementation of pure virtual visiting function.
	virtual void Accept(Expression_Operation& visitor);

protected:
	bool value;
};

#endif //ndef _LITERAL_H_
