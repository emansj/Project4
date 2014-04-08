//CSE 335 Spring 2014, Project 3
//
//Free_Operation.h - Visitor class that frees an entire expression tree.  Use
//only when you know what you're doing.

#ifndef _FREE_OPERATION_H_
#define _FREE_OPERATION_H_

//We don't need to know what kind of operator something is to free its children.
//Use the lite version.
#include "Expression_Operation_Lite.h"


class Free_Operation : public Expression_Operation_Lite
{
public:
	Free_Operation();
	Free_Operation(const Free_Operation& src);
	const Free_Operation& operator=(const Free_Operation& src);
	virtual ~Free_Operation();

	//Frees the given expression.  If the expression object itself has
	//any subexpressions, they will be freed recursively.  You should only
	//call this if you're confident that none of the objects in the
	//expression tree are being used anywhere.
	void Free(Expression* expr);

	virtual void Visit_literal(Literal& literal);
	virtual void Visit_variable(Variable& variable);
	void Visit_unary_operator(Unary_Operator& operate);
	void Visit_binary_operator(Binary_Operator& operate);
};


#endif //ndef _FREE_OPERATION_H_
