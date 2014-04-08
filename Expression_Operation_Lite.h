//CSE 335 Spring 2014, Project 3
//
//Expression_Operation_Lite.h - Simplified Expression visitor for operations
//that don't care about the specific types of unary/binary operators.

#ifndef _EXPRESSION_OPERATION_LITE_H_
#define _EXPRESSION_OPERATION_LITE_H_

#include "Expression_Operation.h"


class Expression_Operation_Lite: protected Expression_Operation
{
public:
	//The four "lite" functions for concrete visitors to implement.
	using Expression_Operation::Visit_literal;
	using Expression_Operation::Visit_variable;
	virtual void Visit_unary_operator(Unary_Operator& unary_op) = 0;
	virtual void Visit_binary_operator(Binary_Operator& binary_op) = 0;

	//Implement these, funneling them into the two simpler functions.
	virtual void Visit_logical_not(Logical_Not& not_op);
	virtual void Visit_logical_and(Logical_And& and_op);
	virtual void Visit_logical_or(Logical_Or& or_op);
	virtual void Visit_implication(Implication& imp_op);
	virtual void Visit_equivalence(Equivalence& equiv_op);

protected:
	//Keep the constructors tucked away so people don't try to instantiate
	//one of these.
	Expression_Operation_Lite();
	virtual ~Expression_Operation_Lite();

private:
	Expression_Operation_Lite(const Expression_Operation_Lite& src);
	const Expression_Operation_Lite& operator=(
		const Expression_Operation_Lite& src);
};


#endif //ndef _EXPRESSION_OPERATION_LITE_H_
