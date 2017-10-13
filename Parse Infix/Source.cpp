#include <cstdlib>
#include <iostream>
#include "infix_evaluator.h"
using namespace std;

void main() {
	infix_evaluator test;
	string test_string = "10! !!++ ++- --- 5";
	//test.evaluate(test_string);
	//cout << endl << "Evaluating unary: " << test.eval_unaries(3, 5, 5, test_string);

	test.eval_unaries(2, 15, test_string);
	getchar();
}