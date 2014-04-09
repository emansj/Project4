//CSE 335 Spring 2014, Project 3
//
//main.cc - Driver for testing Boolean expression classes.

#include "AbstractBuilder.h"
#include "Equivalence.h"
#include "Implication.h"
#include "Literal.h"
#include "Logical_And.h"
#include "Logical_Not.h"
#include "Logical_Or.h"
#include "Variable.h"
#include "Parser.h"
#include "Print_Operation.h"
#include "Evaluate_Operation.h"
#include "Simplify_Operation.h"
#include "Free_Operation.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;


//void Print_and_eval(Expression& expr, ostream& out);
//void Run_all_ops(Expression& expr, ostream& out);
//void Run_test_set_one(ostream& out);
//void Run_test_set_two(ostream& out);
//void Run_exhaustive_simplify_test(ostream& out);
 
 
int main(int argc, char** argv)
{
  Parser p("x & y");
  p.parse();
  ConcreteBuilder  b;
  b.addBinaryOperand("&");
  b.addVariableObj("x");
  
// 	cout << "TEST SET ONE" << endl;
// 	cout << "------------" << endl;
// 	Run_test_set_one(cout);
// 	cout << endl;
// 
// 	cout << "TEST SET TWO" << endl;
// 	cout << "------------" << endl;
// 	Run_test_set_two(cout);
// 	cout << endl;

/*	cout << "REALLY BIG TEST" << endl;
	cout << "---------------" << endl;
	Run_exhaustive_simplify_test(cout);
	cout << endl;
*/
	return 0;
}


//Prints a given expression, then says what it evaluates to.
void Print_and_eval(Expression& expr, ostream& out)
{
	Print_Operation print;
	Evaluate_Operation eval;
	bool result, defined;

	print.Print(expr, out);
	defined = eval.Evaluate(expr, result);
	if (defined)
	{
		out << " evaluates to " << result << "." << endl;
	}
	else
	{
		out << " is undefined." << endl;
	}
}


//Runs the whole gamut of print/evaluate/simplify operations, sending all of
//the collected information to the given output stream.
void Run_all_ops(Expression& expr, ostream& out)
{
	Print_Operation print;
	Simplify_Operation simpler;
	Free_Operation freer;
	print.Print(expr, out);
	out << endl;
	//Print_and_eval(expr, out);

	Expression* simple_version = simpler.Simplify(expr);
	out << "Simplified version:  ";
	print.Print(*simple_version, out);
	out << endl;
	freer.Free(simple_version);
}


//Prints and evaluates the first set of test cases from the project 1 addendum.
void Run_test_set_one(ostream& out)
{
	Literal iamtrue(true), iamfalse(false);

	//(true & false)
	Logical_And andop;
	andop.Set_left_child(&iamtrue);
	andop.Set_right_child(&iamfalse);
	Print_and_eval(andop, out);

	//(true | false)
	Logical_Or orop;
	orop.Set_left_child(&iamtrue);
	orop.Set_right_child(&iamfalse);
	Print_and_eval(orop, out);

	//((true & false) > (true | false))
	Implication imp;
	imp.Set_left_child(&andop);
	imp.Set_right_child(&orop);
	Print_and_eval(imp, out);

	//(~(true | false) = true)
	Logical_Not notop;
	notop.Set_child(&orop);

	Equivalence equiv;
	equiv.Set_left_child(&notop);
	equiv.Set_right_child(&iamtrue);
	Print_and_eval(equiv, out);
}


//Prints, evaluates, and simplifies the second set of test cases from the
//project 3 addendum.
void Run_test_set_two(ostream& out)
{
	Literal iamtrue(true), iamfalse(false);
	Variable x, y, z;
	x.Set_name("x");
	y.Set_name("y");
	z.Set_name("z");

	out << "Second set" << endl;

	//Assemble (((x & true) > (false | y)) = z).
	Logical_And andop;
	andop.Set_left_child(&x);
	andop.Set_right_child(&iamtrue);

	Logical_Or orop;
	orop.Set_left_child(&iamfalse);
	orop.Set_right_child(&y);

	Implication imp;
	imp.Set_left_child(&andop);
	imp.Set_right_child(&orop);

	Equivalence equiv;
	equiv.Set_left_child(&imp);
	equiv.Set_right_child(&z);

	//See what we can do with that expression with everything undefined.
	Run_all_ops(equiv, out);
	out << endl;
	bool val;
	for (int i = 0; i < 3; i++){
		out << "Enter the value of x, y, and z" << endl;
		cin >> val;
		x.Set_value(val);
		cin >> val;
		y.Set_value(val); 
		cin >> val;
		z.Set_value(val);
		out << "Evaluation Result " << endl;
		Print_and_eval(equiv, out);
		out << endl;
	} 


	// ((((x | y) & z) > (~w | false)) = true)
	Variable x1, y1, z1, w;
	x1.Set_name("x");
	y1.Set_name("y");
	z1.Set_name("z");

	w.Set_name("w");
	Logical_Or orop2;
	orop2.Set_left_child(&x1);
	orop2.Set_right_child(&y1);

	Logical_And andop2;
	andop2.Set_left_child(&orop2);
	andop2.Set_right_child(&z1);

	Logical_Not notop;
	notop.Set_child(&w);
	
	Logical_Or orop1;
	orop1. Set_left_child(&notop);
	orop1.Set_right_child(&iamfalse);

	Implication imp2;
	imp2.Set_left_child(&andop2);
	imp2.Set_right_child(&orop1);
	
	Equivalence eq2;
	eq2.Set_left_child(&imp2);
	eq2.Set_right_child(&iamtrue);	 		

	//See what we can do with that expression with everything undefined.
	Run_all_ops(eq2, out);
	out << endl;

	for (int i = 0; i < 3; i++){
		out << "Enter the value of x, y, z, and w" << endl;
		cin >> val;
		x1.Set_value(val);
		cin >> val;
		y1.Set_value(val); 
		cin >> val;
		z1.Set_value(val);
		cin >> val;
		w.Set_value(val);
		out << "Evaluation Result " << endl;
		Print_and_eval(eq2, out);
		out << endl;
	} 
}


//Test every simplification axiom from the project 1 addendum.
void Run_exhaustive_simplify_test(ostream& out)
{
	Literal iamtrue(true), iamfalse(false);
	Variable x;
	x.Set_name("x");

	//1.  (A & false) == false
	Logical_And andop;
	andop.Set_left_child(&x);
	andop.Set_right_child(&iamfalse);
	Run_all_ops(andop, out);

	//2.  (false & A) == false
	andop.Set_left_child(&iamfalse);
	andop.Set_right_child(&x);
	Run_all_ops(andop, out);

	//3.  (A & true) == A
	andop.Set_left_child(&x);
	andop.Set_right_child(&iamtrue);
	Run_all_ops(andop, out);

	//4.  (true & A) == A
	andop.Set_left_child(&iamtrue);
	andop.Set_right_child(&x);
	Run_all_ops(andop, out);

	//5.  (A | false) == A
	Logical_Or orop;
	orop.Set_left_child(&x);
	orop.Set_right_child(&iamfalse);
	Run_all_ops(orop, out);

	//6.  (false | A) == A
	orop.Set_left_child(&iamfalse);
	orop.Set_right_child(&x);
	Run_all_ops(orop, out);

	//7.  (A | true) == true
	orop.Set_left_child(&x);
	orop.Set_right_child(&iamtrue);
	Run_all_ops(orop, out);

	//8.  (true | A) == true
	orop.Set_left_child(&iamtrue);
	orop.Set_right_child(&x);
	Run_all_ops(orop, out);

	//9.  (A > false) == ~A
	Implication imp;
	imp.Set_left_child(&x);
	imp.Set_right_child(&iamfalse);
	Run_all_ops(imp, out);

	//10.  (false > A) == true
	imp.Set_left_child(&iamfalse);
	imp.Set_right_child(&x);
	Run_all_ops(imp, out);

	//11.  (A > true) == true
	imp.Set_left_child(&x);
	imp.Set_right_child(&iamtrue);
	Run_all_ops(imp, out);

	//12.  (true > A) == A
	imp.Set_left_child(&iamtrue);
	imp.Set_right_child(&x);
	Run_all_ops(imp, out);

	//13.  (A = false) == ~A
	Equivalence equiv;
	equiv.Set_left_child(&x);
	equiv.Set_right_child(&iamfalse);
	Run_all_ops(equiv, out);

	//14.  (false = A) == ~A
	equiv.Set_left_child(&iamfalse);
	equiv.Set_right_child(&x);
	Run_all_ops(equiv, out);

	//15.  (A = true) == A
	equiv.Set_left_child(&x);
	equiv.Set_right_child(&iamtrue);
	Run_all_ops(equiv, out);

	//16.  (true = A) == A
	equiv.Set_left_child(&iamtrue);
	equiv.Set_right_child(&x);
	Run_all_ops(equiv, out);
}
