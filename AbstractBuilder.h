#ifndef _ABSBUILDER_H_
#define _ABSBUILDER_H_

using namespace std;

#include <string>
#include <stack>
#include "Expression.h"
#include "Logical_And.h"
#include "Logical_Not.h"
#include "Literal.h"
#include "Variable.h"

class AbstractBuilder{
public:
  virtual void addParent( Expression* left, Expression* right) = 0;
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
  virtual void addParent(){  //MISSING LOGIC for addParent
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
  virtual void addUnaryOperand(string s){
    // s should always be ~
    Expression * e = new Logical_Not();
    _exprTree.push(e);
  }
  virtual void addBinaryOperand(string s){
    //switch (s){
     // case '&':
	Expression * e = new Logical_And();
    //}
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