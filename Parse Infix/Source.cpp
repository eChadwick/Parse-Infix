#include <cstdlib>
#include <iostream>
#include "infix_evaluator.h"
using namespace std;

void main() {
	infix_evaluator test;
	try
	{
		string test_string = "10! !!++ ++- --- 5";
		cout << endl << test.evaluate(test_string);

		cout << endl << endl << test.evaluate("10++5");
		cout << endl << test.evaluate("10 5");
		cout << endl << test.evaluate("10+5-");
		cout << endl << test.evaluate("++5");
		cout << endl << test.evaluate("5");

	}
	catch(expression_exception ee)
	{
		cerr << ee.what();
	}
	getchar();
}