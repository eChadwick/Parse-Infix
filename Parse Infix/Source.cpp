#include <cstdlib>
#include <iostream>
#include "infix_evaluator.h"
using namespace std;

void main() {
	infix_evaluator test;
	string test_string = "10+!!----5";
	cout << endl << "Evaluating unary: " << test.eval_unaries(3, 6, 5, test_string);
	test_string = "10+!!!----5";
	cout << endl << "Evaluating unary: " << test.eval_unaries(3, 7, 5, test_string);
	test_string = "10+!!++----5";
	cout << endl << "Evaluating unary: " << test.eval_unaries(3, 8, 5, test_string);
	test_string = "10+!!+--5";
	cout << endl << "Evaluating unary: " << test.eval_unaries(3, 5, 5, test_string);
	test_string = "10+!!+++5";
	cout << endl << "Evaluating unary: " << test.eval_unaries(3, 5, 5, test_string);
	test_string = "10+++5";
	cout << endl << "Evaluating unary: " << test.eval_unaries(3, 2, 5, test_string);
	test_string = "10+!0";
	cout << endl << "Evaluating unary: " << test.eval_unaries(3, 1, 0, test_string);
	test_string = "10+!1";
	cout << endl << "Evaluating unary: " << test.eval_unaries(3, 1, 1, test_string);
	test_string = "10+!!0";
	cout << endl << "Evaluating unary: " << test.eval_unaries(3, 2, 0, test_string);

	test_string = "10+++$5";
	cout << endl << "Evaluating unary: " << test.eval_unaries(3, 4, 5, test_string);
	test_string = "10+++500";
	cout << endl << "Evaluating unary: " << test.eval_unaries(3, 5, 5, test_string);

	test_string = "10+++5++5";
	cout << endl << "Evaluating unary: " << test.eval_unaries(3, 5, 5, test_string);
	getchar();
}