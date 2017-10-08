#include "postfix_evaluator.h"
#include <sstream>
#include <cmath>
using namespace std;

int PostfixEvaluator::eval(string input_string) {
	while (!number_stack.empty()) {
		number_stack.pop();
	}

	istringstream in(input_string); 
	char next;
	while (in >> next) {
		if (isdigit(next)) {
			in.unget();
			int next_int;
			in >> next_int;
 			number_stack.push(next_int);
		}
		else if (next == '!') {
			if (in.get() == '=') 
				compute("!=");
			else {
				in.unget();
				compute("!");
			}
		}
		else if (next == '+') {
			if (in.get() == '+')
				compute("++");
			else {
				in.unget();
				compute("+");
			}
		}
		else if (next == '-') {
			if (in.get() == '-')
				compute("--");
			else {
				in.unget();
				compute("-");
			}
		}
		else if (next == '>') {
			if (in.get() == '=')
				compute(">=");
			else {
				in.unget();
				compute(">");
			}
		}
		else if (next == '<') {
			if (in.get() == '=')
				compute("<=");
			else {
				in.unget();
				compute("<");
			}
		}
		else if (next == '=') {
			in.get();
			compute("==");
		}
		else if (next == '&') {
			in.get();
			compute("&&");
		}
		else if (next == '|') {
			in.get();
			compute("||");
		}
		else {
			compute(string(1,next));
		}
	}
	
	if (number_stack.empty()) {
		cout << "Something went wrong.  The number stack is empty.";
		exit(1);
	}

	int solution = number_stack.top();
	number_stack.pop();

	if (!number_stack.empty()) {
		cout << "Uh-oh.  The postfix calculation has finished and there are still items in the stack.  Not good.";
		exit(1);
	}
	cout << solution;
	return solution;
}

void PostfixEvaluator::compute(string op)
{
	if (op == " ") {
		return;
	}
	else if (op == "!") {
		int temp = number_stack.top();
		number_stack.pop();
		number_stack.push(!temp);
	}
	else if (op == "++") {
		int temp = number_stack.top();
		number_stack.pop();
		number_stack.push(temp + 1);
	}
	else if (op == "--") {
		int temp = number_stack.top();
		number_stack.pop();
		number_stack.push(temp - 1);
	}
	//else if (op == "-") {
		//do negative stuff or subtraction stuff
	//}
	else if (op == "^") {
		int right = number_stack.top();
		number_stack.pop();
		int left = number_stack.top();
		number_stack.pop();
		number_stack.push(pow(left, right));
	}
	else if (op == "*") {
		int right = number_stack.top();
		number_stack.pop();
		int left = number_stack.top();
		number_stack.pop();
		number_stack.push(left * right);
	}
	else if (op == "/") {
		int right = number_stack.top();
		number_stack.pop();
		int left = number_stack.top();
		number_stack.pop();
		number_stack.push(left / right);
	}
	else if (op == "%") {
		int right = number_stack.top();
		number_stack.pop();
		int left = number_stack.top();
		number_stack.pop();
		number_stack.push(left % right);
	}
	else if (op == "+") {
		int right = number_stack.top();
		number_stack.pop();
		int left = number_stack.top();
		number_stack.pop();
		number_stack.push(left + right);
	}
	else if (op == ">") {
		int right = number_stack.top();
		number_stack.pop();
		int left = number_stack.top();
		number_stack.pop();
		number_stack.push(left > right);
	}
	else if (op == "<") {
		int right = number_stack.top();
		number_stack.pop();
		int left = number_stack.top();
		number_stack.pop();
		number_stack.push(left < right);
	}
	else if (op == ">=") {
		int right = number_stack.top();
		number_stack.pop();
		int left = number_stack.top();
		number_stack.pop();
		number_stack.push(left >= right);
	}
	else if (op == "<=") {
		int right = number_stack.top();
		number_stack.pop();
		int left = number_stack.top();
		number_stack.pop();
		number_stack.push(left <= right);
	}
	else if (op == "==") {
		int right = number_stack.top();
		number_stack.pop();
		int left = number_stack.top();
		number_stack.pop();
		number_stack.push(left == right);
	}
	else if (op == "!=") {
		int right = number_stack.top();
		number_stack.pop();
		int left = number_stack.top();
		number_stack.pop();
		number_stack.push(left != right);
	}
	else if (op == "&&") {
		int right = number_stack.top();
		number_stack.pop();
		int left = number_stack.top();
		number_stack.pop();
		number_stack.push(left && right);
	}
	else if (op == "||") {
		int right = number_stack.top();
		number_stack.pop();
		int left = number_stack.top();
		number_stack.pop();
		number_stack.push(left || right);
	}
}
