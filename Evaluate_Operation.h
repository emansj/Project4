//CSE 335 Spring 2014, Project 3
//
//Evaluate_Operation.h - Visitor class for evaluating an expression tree.

#ifndef _EVALUATE_OPERATION_H_
#define _EVALUATE_OPERATION_H_

#include "Expression_Operation.h"
#include <stack>
using std::stack;


class Evaluate_Operation : public Expression_Operation
{
public:
	Evaluate_Operation();
	Evaluate_Operation(const Evaluate_Operation& src);
	const Evaluate_Operation& operator=(const Evaluate_Operation& src);
	virtual ~Evaluate_Operation();

	//Evaluates the given expression.  Returns true if the expression was
	//evaluated successfully; false if an undefined variable was found.  If
	//the evaluation was successful, the result of the evaluation will be
	//passed back in out_result.
	bool Evaluate(Expression& expr, bool& out_result);

	//Actual visitor function hooks.
	virtual void Visit_literal(Literal& literal);
	virtual void Visit_variable(Variable& variable);
	virtual void Visit_logical_not(Logical_Not& not_op);
	virtual void Visit_logical_and(Logical_And& and_op);
	virtual void Visit_logical_or(Logical_Or& or_op);
	virtual void Visit_implication(Implication& imp_op);
	virtual void Visit_equivalence(Equivalence& equiv_op);

protected:
	//When evaluating an expression, there are actually three possible
	//results:
	//1.  The expression evaluates to true.
	//2.  The expression evaluates to false.
	//3.  The expression can't be evaluated at all.
	//For simplicity, combine these three results into one type, then
	//stack them up so that the results of evaluating each node in the
	//expression tree will persist across calls to the Visit...() functions.
	enum RESULT {TRUE, FALSE, UNDEFINED};
	stack<RESULT> results;
};


#endif //ndef _EVALUATE_OPERATION_H_
