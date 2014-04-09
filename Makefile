#CSE 335 Spring 2014, Project 3
#
#Sample project makefile.


#Set some useful compilation flags up here where it's readable, instead of
#later on in the makefile where it's not.
CXX=g++
CXXFLAGS=-Wall -g
LD=g++


#Define the executable that we're building and all of the objects that we're
#linking into it.
project3: \
	Binary_Operator.o \
	Equivalence.o \
	Evaluate_Operation.o \
	Expression_Operation_Lite.o \
	Free_Operation.o \
	Implication.o \
	Literal.o \
	Logical_And.o \
	Logical_Not.o \
	Logical_Or.o \
	main.o \
	Print_Operation.o \
	Simplify_Operation.o \
	Unary_Operator.o \
	Variable.o 
	${LD} $^ -o $@


#Have .o files automatically built from their corresponding .cc files.
%.o : %.cc
	${CXX} -c $< ${CXXFLAGS} -o $@




#Make it possible to clean up the results of compilation quickly.
clean:
	rm -f project3 *.o


#Set things up so that an object will be rebuilt whenever a header that it
#depends on changes.  We do this by entering all of the dependencies.
#
#These were automatically generated and appended to the Makefile with this
#bash script (note that the CSE systems favor csh, so you may have to invoke
#bash manually to run it):
#
#for SOURCE in *.cpp; do g++ -MM ${SOURCE} >> Makefile; echo >> Makefile; done
Binary_Operator.o: Binary_Operator.cpp Binary_Operator.h Expression.h

Equivalence.o: Equivalence.cpp Equivalence.h Binary_Operator.h \
  Expression.h Expression_Operation.h Literal.h Variable.h Logical_Not.h \
  Unary_Operator.h Logical_And.h Logical_Or.h Implication.h

Evaluate_Operation.o: Evaluate_Operation.cpp Evaluate_Operation.h \
  Expression_Operation.h Literal.h Expression.h Variable.h Logical_Not.h \
  Unary_Operator.h Logical_And.h Binary_Operator.h Logical_Or.h \
  Implication.h Equivalence.h

Expression_Operation_Lite.o: Expression_Operation_Lite.cpp \
  Expression_Operation_Lite.h Expression_Operation.h Literal.h \
  Expression.h Variable.h Logical_Not.h Unary_Operator.h Logical_And.h \
  Binary_Operator.h Logical_Or.h Implication.h Equivalence.h

Free_Operation.o: Free_Operation.cpp Free_Operation.h \
  Expression_Operation_Lite.h Expression_Operation.h Literal.h \
  Expression.h Variable.h Logical_Not.h Unary_Operator.h Logical_And.h \
  Binary_Operator.h Logical_Or.h Implication.h Equivalence.h

Implication.o: Implication.cpp Implication.h Binary_Operator.h \
  Expression.h Expression_Operation.h Literal.h Variable.h Logical_Not.h \
  Unary_Operator.h Logical_And.h Logical_Or.h Equivalence.h

Literal.o: Literal.cpp Literal.h Expression.h Expression_Operation.h \
  Variable.h Logical_Not.h Unary_Operator.h Logical_And.h \
  Binary_Operator.h Logical_Or.h Implication.h Equivalence.h

Logical_And.o: Logical_And.cpp Logical_And.h Binary_Operator.h \
  Expression.h Expression_Operation.h Literal.h Variable.h Logical_Not.h \
  Unary_Operator.h Logical_Or.h Implication.h Equivalence.h

Logical_Not.o: Logical_Not.cpp Logical_Not.h Unary_Operator.h Expression.h \
  Expression_Operation.h Literal.h Variable.h Logical_And.h \
  Binary_Operator.h Logical_Or.h Implication.h Equivalence.h

Logical_Or.o: Logical_Or.cpp Logical_Or.h Binary_Operator.h Expression.h \
  Expression_Operation.h Literal.h Variable.h Logical_Not.h \
  Unary_Operator.h Logical_And.h Implication.h Equivalence.h

Print_Operation.o: Print_Operation.cpp Print_Operation.h \
  Expression_Operation_Lite.h Expression_Operation.h Literal.h \
  Expression.h Variable.h Logical_Not.h Unary_Operator.h Logical_And.h \
  Binary_Operator.h Logical_Or.h Implication.h Equivalence.h

Simplify_Operation.o: Simplify_Operation.cpp Simplify_Operation.h \
  Expression_Operation.h Literal.h Expression.h Variable.h Logical_Not.h \
  Unary_Operator.h Logical_And.h Binary_Operator.h Logical_Or.h \
  Implication.h Equivalence.h Free_Operation.h \
  Expression_Operation_Lite.h

Unary_Operator.o: Unary_Operator.cpp Unary_Operator.h Expression.h

Variable.o: Variable.cpp Variable.h Expression.h Expression_Operation.h \
  Literal.h Logical_Not.h Unary_Operator.h Logical_And.h \
  Binary_Operator.h Logical_Or.h Implication.h Equivalence.h
  
Parser.o: Parser.h AbstractBuilder.h Expression.h Logical_And.h Binary_Operator.h Logical_Not.h Unary_Operator.h Literal.h Variable.h
 
AbstractBuilder.o: AbstractBuilder.h Expression.h Logical_And.h Binary_Operator.h Logical_Not.h Unary_Operator.h Logical_Or.h Equivalence.h Literal.h Variable.h

  
main.o: main.cpp AbstractBuilder.h Expression.h Logical_And.h \
 Binary_Operator.h Logical_Not.h Unary_Operator.h Literal.h Variable.h \
 Equivalence.h Implication.h Logical_Or.h Parser.h Print_Operation.h \
 Expression_Operation_Lite.h Expression_Operation.h Evaluate_Operation.h \
 Simplify_Operation.h Free_Operation.h


