#include "InfixEvaluator.h"

void InfixEvaluator::eval_stack(int precedence)
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
					throw ExpressionException(0, "");
				else
					break;
			else if (precedence > precedences.at(operators.top()))
				break;

			eval_operator(operators.top());
			operators.pop();
		}
	}
}

void InfixEvaluator::eval_operator(string op)
{
	int right = operands.top();
	operands.pop();

	if (op == "!") operands.push(!right);
	else if (op == "++") operands.push(right + 1);
	else if (op == "--") operands.push(right - 1);
	else if (op == "-1") operands.push(right * -1);
	else
	{
		int left = operands.top();
		operands.pop();

		if (op == "^") operands.push(pow(left, right));
		else if (op == "*") operands.push(left * right);
		else if (op == "/") operands.push(left / right);
		else if (op == "%") operands.push(left % right);
		else if (op == "+") operands.push(left + right);
		else if (op == "-") operands.push(left - right);
		else if (op == ">") operands.push(left > right);
		else if (op == "<") operands.push(left < right);
		else if (op == ">=") operands.push(left >= right);
		else if (op == "<=") operands.push(left <= right);
		else if (op == "==") operands.push(left == right);
		else if (op == "!=") operands.push(left != right);
		else if (op == "&&") operands.push(left && right);
		else if (op == "||") operands.push(left || right);
	}
}

int InfixEvaluator::evaluate(string input)
{
	string::iterator iter = input.begin();
	unsigned int index = 0;
	while (iter != input.end())
	{
		// Unary Search
		unsigned int start = index;
		unsigned int length = 0;
		char token = '?';
		while (!isdigit(*iter))
		{
			if (*iter == ')')
				throw ExpressionException(index, "Unexpected closing parenthesis");

			if (*iter == '(')
			{
				operators.push("(");
				++iter;
				++index;
				start = index;
				length = 0;
				continue;
			}

			if (length == 0)
				switch (*iter)
				{
				case '+': case '-': case '!':
					token = *iter;
					length = 1;
					start = index;
					break;
				case ' ':
					break;
				default: throw ExpressionException(index, "Expected valid unary operator");
				}
			
			if (*(iter + 1) == token)
				++length;
			else
			{
				if (length % 2)
					switch (token)
					{
					case '-':
						if (isdigit(*(iter + 1)) || *(iter + 1) == '(')
						{
							operators.push("-1");
							length--;
							break;
						}
					case '+':
						if (start > 0 && input[start - 1] == token)
							throw ExpressionException(start - 1, "Expected valid binary operator");
						else
							throw ExpressionException(start, "Unexpected binary operator");
						break;
					case '!':
						operators.push("!");
					}
				if (!(length % 2))
					if (token == '!')
					{
						operators.push("!");
						operators.push("!");
					}
					else
						for (int i = 0; i < length / 2; i++)
							operators.push(string(new char[3] { token, token, '\0' }));

				length = 0;
			}

			++iter;
			++index;
			if (iter == input.end())
				throw ExpressionException(index, "Unexpected end of expression");
		}

		string s_operand;
		while (iter != input.end() && isdigit(*iter))
		{
			s_operand += *iter;
			++iter;
			++index;
		}

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
				throw ExpressionException(index, "Unexpected operand");
			else if (*iter == '(')
				throw ExpressionException(index, "Unexpected opening parenthesis");
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

		map<string, int>::const_iterator m_iter = precedences.find(input.substr(index, 2));
		if (m_iter == precedences.end() || m_iter->first == "++" || m_iter->first == "--")
			m_iter = precedences.find(input.substr(index, 1));

		if (m_iter == precedences.end() || m_iter->first == "!")
			throw ExpressionException(index, "Expected valid binary operator");

		int precedence = m_iter->second;

		if (!operators.empty() && operators.top() != "(" && precedence <= precedences.at(operators.top()))
			eval_stack(precedence);

		operators.push(m_iter->first);
		iter += operators.top().length();
		index += operators.top().length();

		if (iter == input.end())
			throw ExpressionException(index, "Unexpected end of expression");
	}
}
