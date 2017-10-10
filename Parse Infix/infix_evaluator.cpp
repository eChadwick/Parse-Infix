#include "infix_evaluator.h"
#include <stack>
#include <string>

class InfixEvaluator
{
	stack<string> operators;
	stack<int> operands;
	const std::map<std::string, int> precedence = {
		{ "!", 8 },{ "!!", 8 },{ "++", 8 },{ "--", 8 },
		{ "^", 7 },
		{ "*", 6 },{ "/", 6 },{ "%", 6 },
		{ "+", 5 },{ "-", 5 },
		{ ">", 4 },{ ">=", 4 },{ "<", 4 },
		{ "==", 3 },{ "!=", 3 },
		{ "&&", 2 },
		{ "||", 1 },
	};

	int evaluate(string input)
	{

	}
};