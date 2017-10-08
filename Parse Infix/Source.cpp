#include <cstdlib>
#include "infix_evaluator.h"

//Below included for class testing.  remove before submission.
#include "postfix_evaluator.h"
using namespace std;

void main() {
	PostfixEvaluator test;
	test.eval("5 -1 -");
	getchar();
}
