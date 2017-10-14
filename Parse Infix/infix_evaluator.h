#pragma once

#include "expression_exception.h"
#include <string>
#include <stack>
#include <map>
#include <iostream>
using namespace std;

// A class for evaluating an infix expression and returning its value as an integer.
class infix_evaluator {
public:
	// @param input is the infix expression to evaluate.
	// @return is the value of the string as a single integer
	int evaluate(string input);
private:
	stack<int> operands;
	stack<string> operators;
	const map<string, int> precedences = {
		{ "!", 8 },{ "!!", 8 },{ "++", 8 },{ "--", 8 },
        { "^", 7 },
       	{ "*", 6 },{ "/", 6 },{ "%", 6 },
       	{ "+", 5 },{ "-", 5 },
       	{ ">", 4 },{ ">=", 4 },{ "<", 4 },{ "<=", 4 },
       	{ "==", 3 },{ "!=", 3 },
       	{ "&&", 2 },
       	{ "||", 1 },
   	};

	// Evaluate the stacks as far as necessary to prepare them for the next operator to be pushed.
	// @param precedence is the precedence of the next operator to be added to the operator stack.
	// Passing 0 will evaluate until either '(' is found or the stack is empty.
	void eval_stack(int precedence);

	// Evaluate one or many repeated +, -, or ! in a substring of infix_string.  Whitespace between
	// consecutive operators is ignored.
	// @param start is an interator to the first index of the substring in the infix_string
	// @param length is the length of the substring
	// @param operand is the operand which the unary operators will be applied to
	// @param operator_string is the string of one or many repeated + and/or -  and/or !
	// @return is the value of operand after unary operations have been applied.
	void parse_unaries(int start, int length, string& infix_string);

	// Evaluate an operator.  Pop correct number of operands, apply operator and push result to operand
	// stack.
	// @param op is the operator to be evaluated.
	void eval_operator(string op);
};
