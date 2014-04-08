//CSE 335 Spring 2014, Project 3
//
//Expression_Operator_Lite.cc - Implementation for enabling the "lite"
//Expression visitor convenience functions.

#include "Expression_Operation_Lite.h"


//Constructor/destructor.  No need to do anything; we just need to have them
//so subclasses can be instantiated.
Expression_Operation_Lite::Expression_Operation_Lite()
{
}

Expression_Operation_Lite::~Expression_Operation_Lite()
{
}


//Have any functions for unary operators go into the common Unary_Operator
//visitor function.
void Expression_Operation_Lite::Visit_logical_not(Logical_Not& not_op)
{
	this->Visit_unary_operator(not_op);
}


//Have any functions for specific binary operators use the common visitor
//function.
void Expression_Operation_Lite::Visit_logical_and(Logical_And& and_op)
{
	this->Visit_binary_operator(and_op);
}

void Expression_Operation_Lite::Visit_logical_or(Logical_Or& or_op)
{
	this->Visit_binary_operator(or_op);
}

void Expression_Operation_Lite::Visit_implication(Implication& imp_op)
{
	this->Visit_binary_operator(imp_op);
}

void Expression_Operation_Lite::Visit_equivalence(Equivalence& equiv_op)
{
	this->Visit_binary_operator(equiv_op);
}
