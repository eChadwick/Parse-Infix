#include <cstdlib>
#include <iostream>
#include "infix_evaluator.h"
using namespace std;

void main() {
	infix_evaluator test;
	try
	{

		/*test.operands.push(5);
		test.operands.push(2);
		test.operands.push(2);	

		test.operators.push("++");
		test.operators.push("(");
		test.operators.push("*");
		test.operators.push("(");
		test.operators.push("+");
		test.operators.push(")");

		test.eval_stack(0);
		test.eval_stack(test.precedences.at("+"));*/

		/*test.operators.push("++");
		test.operands.push(20);
		test.operators.push("(");


		test.operators.push("+");
		test.operators.push("!");
		test.operators.push("(");
		test.operands.push(3);
		test.operators.push("-");
		test.operands.push(2);
		test.operators.push(")");

		test.eval_stack(0);
		
		test.operators.push(")");

		test.eval_stack(0);

		test.eval_stack(test.precedences.at("*"));

		test.operators.push("*");
		test.operators.push("++");
		test.operators.push("(");
		test.operands.push(7);
		test.operators.push(")");

		test.eval_stack(0);
		test.eval_stack(0);*/

		//string test_string = "10! !!++ ++- --- 5";
		////test.evaluate(test_string);

		//test.evaluate("10++5");
		//test.evaluate("10 5");
		//test.evaluate("10+5-");
		//test.evaluate("++5");
		//test.evaluate("5");

		cout << test.evaluate("++(5*(2+2)+!(3-2))*++(7)");


	}
	catch(expression_exception ee)
	{
		cout << ee.what();
	}
	getchar();
}