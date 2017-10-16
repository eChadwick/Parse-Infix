#pragma once

#include "ExpressionException.h"

#include <string>
#include <stack>
#include <map>
using namespace std;

// A class for evaluating an infix expression and returning its value as an integer.
class InfixEvaluator {
public:
	// @param input is the infix expression to evaluate.
	// @return is the value of the string as a single integer
	int evaluate(string input);
private:
	stack<int> operands;
	stack<string> operators;
	const map<string, int> precedences = {
		{ "!", 8 },{ "!!", 8 },{ "++", 8 },{ "--", 8 },{ "-1", 8 },
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

	// Evaluate an operator.  Pop correct number of operands, apply operator and push result to operand
	// stack.
	// @param op is the operator to be evaluated.
	void eval_operator(string op);
};
