#pragma once

#include "infix_to_postfix.h"
#include<string>
#include<stack>
using namespace std;

class infix_to_postfix {
public:
	// @param infix_string is the infix expression to evaluate.
	// @return is the value of the string as a single integer
	int eval(string infix_string);
private:
	stack<int>operators;
	stack<char>operands;

	// evaluates the stacks as far as possible and pushes the result to operators stack.
	// @param precedence is the precedence of the next operator to be added to the stack.
	void eval_stack(int precedence);

	// evaluates one or many repeated +, -, or ! in a substring of infix_string
	// @param start is the first index of the substring
	// @param length is the length of the substring
	// @param operand is the operand which the unary operators will be applied to
	// @return is the value of operand after unary operations have been applied.
	int eval_unaries(int start, int length, int operand);
};