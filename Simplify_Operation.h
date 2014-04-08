//CSE 335 Spring 2014, Project 3
//
//Simplify_Operation.h - Visitor class for simplifying expressions.

#ifndef _SIMPLIFY_OPERATION_H_
#define _SIMPLIFY_OPERATION_H_

#include "Expression_Operation.h"
#include <stack>
using std::stack;


class Simplify_Operation : public Expression_Operation
{
public:
	Simplify_Operation();
	Simplify_Operation(const Simplify_Operation& src);
	const Simplify_Operation& operator=(const Simplify_Operation& src);
	virtual ~Simplify_Operation();

	//Takes the given expression tree and creates a new, logically
	//equivalent tree, in as simple a form as possible.  It's your
	//responsibility to free it.
	Expression* Simplify(Expression& expr);

	//Visitor functions for the various Expression classes.
	virtual void Visit_literal(Literal& literal);
	virtual void Visit_variable(Variable& variable);
	virtual void Visit_logical_not(Logical_Not& not_op);
	virtual void Visit_logical_and(Logical_And& and_op);
	virtual void Visit_logical_or(Logical_Or& or_op);
	virtual void Visit_implication(Implication& imp_op);
	virtual void Visit_equivalence(Equivalence& equiv_op);

protected:
	//Stacks up the results from simplifying subexpressions.  All of these
	//should be newly-allocated objects, so you can/should free them if you
	//find you can replace them with an even simpler version.
	stack<Expression*> simplified;

	//Stacks up the value of each of the subexpressions.  This makes it
	//easier to simplify each node in the expression, since it saves you
	//the trouble of evaluating the simplified children.  As a rule,
	//defined values should appear here if and only if the corresponding
	//Expression object is a Literal (since otherwise, the Expression could
	//be made simpler).
	enum RESULT {TRUE, FALSE, UNDEFINED};
	stack<RESULT> value;

	//Convenience function for getting around the fact that the STL pop
	//operation returns void.  Seems trivial, but cleans things up a lot.
	template<typename T>
	T Pop(stack<T>& source)
	{
		T temp = source.top();
		source.pop();
		return temp;
	}
};


#endif //ndef _SIMPLIFY_OPERATION_H_
