#include "expression_exception.h"

expression_exception::expression_exception(unsigned int index, std::string message)
	: runtime_error("Error in expression at " + std::to_string(index) + ": " + message) {}
