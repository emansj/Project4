//CSE 335 Spring 2014, Project 3
//
//Expression_Operation.h - Interface for visitor classes that do useful things
//with expression trees (printing, evaluating, and so forth).

#ifndef _EXPRESSION_OPERATION_H_
#define _EXPRESSION_OPERATION_H_

#include "Literal.h"
#include "Variable.h"
#include "Logical_Not.h"
#include "Logical_And.h"
#include "Logical_Or.h"
#include "Implication.h"
#include "Equivalence.h"


class Expression_Operation
{
public:
	virtual void Visit_literal(Literal& literal) = 0;
	virtual void Visit_variable(Variable& variable) = 0;
	virtual void Visit_logical_not(Logical_Not& not_op) = 0;
	virtual void Visit_logical_and(Logical_And& and_op) = 0;
	virtual void Visit_logical_or(Logical_Or& or_op) = 0;
	virtual void Visit_implication(Implication& imp_op) = 0;
	virtual void Visit_equivalence(Equivalence& equiv_op) = 0;

protected:
	Expression_Operation() {}
	virtual ~Expression_Operation() {}

private:
	//Get the copy constructor and assignment operators tucked out of the
	//way.  People shouldn't be copying these around without knowing
	//their type.
	Expression_Operation(const Expression_Operation& src);
	const Expression_Operation& operator=(const Expression_Operation& src);
};


#endif //ndef _EXPRESSION_OPERATION_H_
