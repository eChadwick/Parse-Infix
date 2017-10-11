#include "infix_evaluator.h"

void infix_evaluator::eval_stack(int precedence)
{
}

//infix_string&, int start, length, operand.  Can strip spaces
int infix_evaluator::eval_unaries(int start, int length, int operand, string& infix_string)
{	
	if (length == 0)
		return operand;
	else {
		int index = start + length - 1;
		char token = infix_string[index];
		int count = 1;
		while (count < length && infix_string[index] == infix_string[index -1]) {
			count++;
			index--;
		}
		if (token == '!') {
			if (count % 2 == 0)
				eval_unaries(start, length - count, !!operand, infix_string);
			else
				eval_unaries(start, length - count, !operand, infix_string);
		}else if (token == '+') {
			if (count % 2 == 0) {
				for (int i = 0; i < count / 2; i++) {
					operand++;
				}
				eval_unaries(start, length - count, operand, infix_string);
			}
			else {
				cout << "Binary operator with single operand at index " << index;
			}
		}else if (token == '-') {
			if (count % 2 == 0) {
				for (int i = 0; i < count / 2; i++) {
					operand--;
				}
				eval_unaries(start, length - count, operand, infix_string);
			}
			else {
				cout << "Binary operator with single operand at index " << index;
			}
		}
	}
}

infix_evaluator::evaluate(string input)
{
	string::iterator iter = input.begin();
	while (iter != input.end())
	{

	}
}
