#pragma once
#include <string>
#include <sstream>
#include <stdexcept>

// A wrapper class around standard exception.  Adds the index of the error to the error message.
class ExpressionException : public std::runtime_error
{
public:
	// Constructor for expression_exception
	// @param index is the index in the string where the error was detected.
	// @param message is the error message thrown.
	ExpressionException(unsigned int index, std::string message);
};

