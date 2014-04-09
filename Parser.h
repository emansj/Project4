#ifndef _PARSER_H_
#define _PARSER_H_

#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include "AbstractBuilder.h"

using namespace std;

class Parser{
private:
  string _str;
  ConcreteBuilder * b;
  bool isValid;
public:
  Parser(string str):_str(str){};
  virtual void parse(){
  //  char c [] = {'~', '>', '=', '&', '|'};
//    char a = NULL;
/*    for ( int i = 0; i <= _str.length(); i++) {
      c = _str.at(i);
      if ( c == '~' )
      {
	if ( _str.at(i+1) != c[0]
      }
      cout << c[i] << endl;
    
    }
    
*/
      
     /* c = _str.at(i);
      switch(c){
	case '~': 
	  b.addOperand("~");
	  break;
	case '=':
	  b.addOperand("=");
	  break;	
	case '>':
	  b.addOperand(">");
	  break;	  
	case '&':
	  b.addOperand("&");
	  break;	  
	case '|':
	  b.addOperand("|");
	  break;	
	default:
	  b.addLiteralObj(&c);  */

   }
};

#endif
