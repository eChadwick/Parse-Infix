#pragma once

#include <string>
#include <stack>
#include <map>
#include <iostream>
using namespace std;

class infix_evaluator {
public:
	// @param infix_string is the infix expression to evaluate.
	// @return is the value of the string as a single integer
	int eval(string infix_string);
//private:
	stack<int> operands;
	stack<string> operators;
	const map<string, int> precedence = {
        	{ "!", 8 },{ "!!", 8 },{ "++", 8 },{ "--", 8 },
        	{ "^", 7 },
        	{ "*", 6 },{ "/", 6 },{ "%", 6 },
        	{ "+", 5 },{ "-", 5 },
        	{ ">", 4 },{ ">=", 4 },{ "<", 4 },
        	{ "==", 3 },{ "!=", 3 },
        	{ "&&", 2 },
        	{ "||", 1 },
    	};

	// evaluates the stacks as far as possible and pushes the result to operand stack.
	// @param precedence is the precedence of the next operator to be added to the operator stack.
	void eval_stack(int next_precedence);

	// evaluates one or many repeated +, -, or ! in a substring of infix_string.  Whitespace between
	// consecutive operators is ignored.
	// @param start is an interator to the first index of the substring in the infix_string
	// @param length is the length of the substring
	// @param operand is the operand which the unary operators will be applied to
	// @param operator_string is the string of one or many repeated + and/or -  and/or !
	// @return is the value of operand after unary operations have been applied.
	int eval_unaries(int start, int length, int operand, string& infix_string);
	
	int evaluate(string input);
};
