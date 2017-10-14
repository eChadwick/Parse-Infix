#pragma once
#include <string>
#include <sstream>
#include <stdexcept>

class ExpressionException : public std::runtime_error
{
public:
	ExpressionException(unsigned int index, std::string message);
};

