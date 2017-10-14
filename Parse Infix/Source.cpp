#include <cstdlib>
#include <iostream>
#include "InfixEvaluator.h"
using namespace std;

void main() {
	InfixEvaluator test;
	try
	{
		cout << endl << test.evaluate("10-! !! ++ ++ ---- 5");
		cout << endl << test.evaluate("5*7+5-2/2+10+++7");
		cout << endl << test.evaluate("(4==5==0==1)*80==80");
		cout << endl << test.evaluate("(--(7^(2+1))+(!!!(!!0))*4)");
		cout << endl << test.evaluate("(3>2)||(2==1)&&1");
		cout << endl << test.evaluate("(!(3^2)&&!0)>=1");
		cout << endl << test.evaluate("1+!!!!!((((((((0))))))))*7^10");
		cout << endl << test.evaluate("-(72-(-5))<5||0&&!1");
	}
	catch(ExpressionException ee)
	{
		cout << ee.what();
	}
	getchar();
}