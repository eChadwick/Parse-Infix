#include <iostream>
#include <cstdio>
#include "infix_evaluator.h"
using namespace std;

void main() {
	infix_evaluator test;
	string test_string = "10+----5";
	test.evaluate(test_string);

	test.evaluate("10++5");
	test.evaluate("10 5");
	test.evaluate("10+5-");
	test.evaluate("++5");
	test.evaluate("5");

	cout << endl << "Evaluating unary: " << test.eval_unaries(3, 6, 5, test_string);
	getchar();
}