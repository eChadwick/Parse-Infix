#pragma once
#include <string>
#include <stdexcept>

// A wrapper class around standard exception.  Adds the index of the error to the error message.
class expression_exception : public std::runtime_error
{
public:
	// Constructor for expression_exception
	// @param index is the index in the string where the error was detected.
	// @param message is the error message thrown.
	expression_exception(unsigned int index, std::string message);
};

