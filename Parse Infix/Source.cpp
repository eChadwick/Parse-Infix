#include <cstdlib>
#include <iostream>
#include "infix_evaluator.h"
using namespace std;

void main() {
	infix_evaluator test;
	string test_string = "+!!----";
	test.eval_unaries(0, 7, 5, test_string);
	getchar();
}