//CSE 335 Spring 2014, Project 3
//
//Variable.h - Class for variables that may appear in a Boolean expression.

#ifndef _VARIABLE_H_
#define _VARIABLE_H_

#include <string>
#include "Expression.h"
using std::string;


class Variable : public Expression
{
public:
	Variable();
	Variable(const Variable& src);
	const Variable& operator=(const Variable& src);
	virtual ~Variable();

	//Functions for getting/setting the value of the variable.  You should
	//always call Is_defined() before calling Get_value() to verify that
	//the variable has been assigned a value.  Otherwise, the value
	//returned by Get_value() is meaningless.  Variables become defined
	//once Set_value() is called.  If you'd like to take a variable back
	//out of the defined state, call Clear_value().
	bool Is_defined() const;
	bool Get_value() const;
	void Clear_value();
	void Set_value(bool new_value);

	//Gets/sets the name of the variable.
	const string& Get_name() const;
	void Set_name(const string& new_name);

	//Implementation of pure virtual visiting function.
	virtual void Accept(Expression_Operation& visitor);

protected:
	bool defined;
	bool value;
	string name;
};


#endif //ndef _VARIABLE_H_
