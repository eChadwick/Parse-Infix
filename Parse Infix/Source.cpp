#include <iostream>
#include "InfixEvaluator.h"
using namespace std;

void main() {
	InfixEvaluator test;
	try {
		//The string to evaluate.  Insert your string between the quotes.
		string INPUT_STRING = "";
		int output_value = test.evaluate(INPUT_STRING);
	}
	catch(ExpressionException ee) {
		cout << ee.what();
	}
}