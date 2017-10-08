#pragma once
#include <iostream>
#include <stack>
using namespace std;

class PostfixEvaluator {
public:
	int eval(string);
//private:
	void compute(string);
	stack<int> number_stack;

	// For testing only.  
	void push(int in) { number_stack.push(in); }
	int top() { return number_stack.top(); }
};
