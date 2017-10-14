#include "ExpressionException.h"

ExpressionException::ExpressionException(unsigned int index, std::string message)
	: runtime_error("Error in expression at " + std::to_string(index) + ": " + message) {}
