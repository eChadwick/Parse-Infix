#include "infix_evaluator.h"

void infix_evaluator::eval_stack(int precedence)
{
	if (operators.top() == ")") {
		operators.pop();
		while (!operators.empty() && operators.top() != "("){
			eval_operator(operators.top());
			operators.pop();
		}
		if (operators.empty())
			cout << "Unbalanced parentheses";
		if (operators.top() == "(")
			operators.pop();
	}
	else {
		
		while (!operators.empty())
		{
			if (operators.top() == "(")
				if (precedence == 0)
					throw expression_exception(0, "");
				else
					break;
			else if (precedence > precedences.at(operators.top()))
				break;

			eval_operator(operators.top());
			operators.pop();
		}
	}
}

//infix_string&, int start, length, operand.  Can strip spaces
void infix_evaluator::parse_unaries(int start, int length, string& infix_string)
{	
	stack<string> temp_stack;
	int index = start + length - 1;
	while (index >= start) {
		char token = infix_string[index];
		if (token != '!' && token != '+' && token != '-' && token != ' ') {
			cout << "Invalid unary token at index " << index;
		}
		while (token == ' ') {
			index--;
			token = infix_string[index];
			if (token != '!' && token != '+' && token != '-' && token != ' ') {
				cout << "Invalid unary token at index " << index;
			}
		}
			int count = 0;
			while (index >= start && (token == infix_string[index] || infix_string[index] == ' ')) {
				if (infix_string[index] == token) {
					count++;
				}
				index--;
			}
			if (token == '!') {
				if (count % 2 == 0) {
					temp_stack.push("!");
					temp_stack.push("!");
				}
				else {
					temp_stack.push("!");
				}
			}
			else if (token == '+') {
 				if (count % 2 == 0) {
					for (int i = 0; i < count / 2; i++) {
						temp_stack.push("++");
					}
				}
				else {
					cout << "Binary operator with single operand at index " << index;
				}
			}
			else if (token == '-') {
				if (count % 2 == 0) {
					for (int i = 0; i < count / 2; i++) {
						temp_stack.push("--");
					}
				}
				else {
					cout << "Binary operator with single operand at index " << index;
				}
			}
		}
	while (!temp_stack.empty()) {
		operators.push(temp_stack.top());
		temp_stack.pop();
	}
}

void infix_evaluator::eval_operator(string op)
{
	if (op == " ") {
		return;
	}
	else if (op == "!") {
		int temp = operands.top();
		operands.pop();
		operands.push(!temp);
	}
	else if (op == "++") {
		int temp = operands.top();
		operands.pop();
		operands.push(temp + 1);
	}
	else if (op == "--") {
		int temp = operands.top();
		operands.pop();
		operands.push(temp - 1);
	}
	else if (op == "^") {
		int right = operands.top();
		operands.pop();
		int left = operands.top();
		operands.pop();
		operands.push(pow(left, right));
	}
	else if (op == "*") {
		int right = operands.top();
		operands.pop();
		int left = operands.top();
		operands.pop();
		operands.push(left * right);
	}
	else if (op == "/") {
		int right = operands.top();
		operands.pop();
		int left = operands.top();
		operands.pop();
		operands.push(left / right);
	}
	else if (op == "%") {
		int right = operands.top();
		operands.pop();
		int left = operands.top();
		operands.pop();
		operands.push(left % right);
	}
	else if (op == "+") {
		int right = operands.top();
		operands.pop();
		int left = operands.top();
		operands.pop();
		operands.push(left + right);
	}
	else if (op == "-") {
		int right = operands.top();
		operands.pop();
		int left = operands.top();
		operands.pop();
		operands.push(left - right);
	}
	else if (op == ">") {
		int right = operands.top();
		operands.pop();
		int left = operands.top();
		operands.pop();
		operands.push(left > right);
	}
	else if (op == "<") {
		int right = operands.top();
		operands.pop();
		int left = operands.top();
		operands.pop();
		operands.push(left < right);
	}
	else if (op == ">=") {
		int right = operands.top();
		operands.pop();
		int left = operands.top();
		operands.pop();
		operands.push(left >= right);
	}
	else if (op == "<=") {
		int right = operands.top();
		operands.pop();
		int left = operands.top();
		operands.pop();
		operands.push(left <= right);
	}
	else if (op == "==") {
		int right = operands.top();
		operands.pop();
		int left = operands.top();
		operands.pop();
		operands.push(left == right);
	}
	else if (op == "!=") {
		int right = operands.top();
		operands.pop();
		int left = operands.top();
		operands.pop();
		operands.push(left != right);
	}
	else if (op == "&&") {
		int right = operands.top();
		operands.pop();
		int left = operands.top();
		operands.pop();
		operands.push(left && right);
	}
	else if (op == "||") {
		int right = operands.top();
		operands.pop();
		int left = operands.top();
		operands.pop();
		operands.push(left || right);
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
		unsigned int length = 0;
		while (!isdigit(*iter))
		{
			if (*iter == ')')
				throw expression_exception(index, "Unexpected closing parenthesis");

			while (*iter == '(')
			{
				if (length > 0)
					parse_unaries(start, length, input);
				operators.push("(");
				++iter;
				++index;
				start = index;
				length = 0;
			}

			++length;
			++iter;
			++index;
			if (iter == input.end())
				throw expression_exception(index, "Unexpected end of expression");
		}

		//unsigned int length = index - start;
		string s_operand;
		while (iter != input.end() && isdigit(*iter))
		{
			s_operand += *iter;
			++iter;
			++index;
		}

		parse_unaries(start, length, input);
		operands.push(stoul(s_operand));

		while (iter != input.end())
		{
			if (*iter == ' ')
			{
				++iter;
				++index;
			}
			else if (*iter == ')')
			{
				operators.push(")");
				eval_stack(0);
				++iter;
				++index;
			}
			else if (isdigit(*iter))
				throw expression_exception(index, "Unexpected operand");
			else if (*iter == '(')
				throw expression_exception(index, "Unexpected opening parenthesis");
			else
				break;
		}

		// The only valid place to end evaluation -- after an operand.
		if (iter == input.end())
		{
			if (!operators.empty())
				eval_stack(0);

			return operands.top();
		}
			

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
