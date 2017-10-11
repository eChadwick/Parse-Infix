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

int infix_evaluator::evaluate(string input)
{
	string::iterator iter = input.begin();
	unsigned int index = 0;
	while (iter != input.end())
	{
		// Unary Search
		unsigned int start = index;
		while (!isdigit(*iter))
		{
			++iter;
			++index;
			if (iter == input.end())
				throw expression_exception(index, "Unexpected end of expression");
		}

		unsigned int length = index - start;
		string s_operand;
		while (iter != input.end() && isdigit(*iter))
		{
			s_operand += *iter;
			++iter;
			++index;
		}

		operands.push(eval_unaries(start, length, stoul(s_operand), input));

		while (iter != input.end() && *iter == ' ')
		{
			++iter;
			++index;
		}

		// The only valid place to end evaluation -- after an operand.
		if (iter == input.end())
		{
			if (!operators.empty())
				eval_stack(0);

			return operands.top();
		}
		else if (isdigit(*iter))
			throw expression_exception(index, "Unexpected operand");
			

		string binary;
		string double_op = input.substr(index, 2);
		string single_op = input.substr(index, 1);
		int precedence = -1;

		for (map<string, int>::const_iterator miter = precedences.begin(); miter != precedences.end(); ++miter)
			if (miter->first.length() == 2 && miter->first == double_op)
			{
				binary = double_op;
				precedence = miter->second;
				break;
			}
			else if (miter->first.length() == 1 && miter->first == single_op)
			{
				binary = single_op;
				precedence = miter->second;
			}

		if (precedence < 0)
			throw new expression_exception(index, "Expected a valid binary operator");

		if (!operators.empty() && precedence <= precedences.at(operators.top()))
			eval_stack(precedence);

		operators.push(binary);
		++iter;
		++index;

		if (iter == input.end())
			throw expression_exception(index, "Unexpected end of expression");
	}
}
