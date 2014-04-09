#ifndef _ABSBUILDER_H_
#define _ABSBUILDER_H_

using namespace std;
#include <iostream> 
#include <string>
#include <stack>
#include "Expression.h"
#include "Logical_And.h"
#include "Logical_Not.h"
#include "Logical_Or.h"
#include "Equivalence.h"
#include "Implication.h"
#include "Literal.h"
#include "Variable.h"

class AbstractBuilder{
public:
  virtual void addParent(/* Expression* left, Expression* right */) = 0;
  virtual void addLiteralObj( string s ) = 0;
  virtual void addVariableObj( string s ) = 0;
  virtual void addUnaryOperand( string s ) = 0;
  virtual void addBinaryOperand( string s ) = 0;
};
class ConcreteBuilder : public AbstractBuilder{
private:
  stack <Expression*> _exprTree;
public:
  ConcreteBuilder() {};
  virtual void addParent(/*Expression * left, Expression * right*/){  //MISSING LOGIC for addParent
    _exprTree.pop();
    Expression * right = _exprTree.top();
    _exprTree.pop();
    Expression * parent = _exprTree.top();
    _exprTree.pop();
    Expression * left = _exprTree.top();
    _exprTree.pop();  
    _exprTree.pop();  // twice?
    
    parent->Set_left_child( left );
    parent->Set_right_child( right );
    //parent->SetParent();
    _exprTree.push( parent );
  }
  virtual void addUnaryOperand( string s ){
    char c = s.at(0);
	Expression * e;
	switch(c){
	  case '~':
		e = new Logical_Not();
		break;
	  default:
	  break;
	}
    _exprTree.push(e);
  }
  virtual void addBinaryOperand( string s  ){
	char c = s.at(0);
	Expression * e;
	switch (c){
      case '&':
		e = new Logical_And();
		break;
	   case '|':
	   	e = new Logical_Or();
		break;
	   case '>':
	    e = new Implication();
		break;
	   case '=':
	    e = new Equivalence();
		break;
	   default:
	    break;
    }
    _exprTree.push(e);
  }
  virtual void addLiteralObj(string s){
    Expression * a;
    if (s == "true")
      a = new Literal(true);
    else 
      a = new Literal(false);
    _exprTree.push(a);
  } 
  virtual void addVariableObj(string s){
    Variable v;
    v.Set_name(s);
    Expression * e = &v;
    _exprTree.push(e);
  }    
};
    
#endif
