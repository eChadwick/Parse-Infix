#include "expression_exception.h"

expression_exception::expression_exception()
{
	runtime_error::runtime_error("Unknown error in expression.");
}

expression_exception::expression_exception(unsigned int index, std::string message)
{
	runtime_error::runtime_error(error);
}

const char * expression_exception::what()
{
	char* error;
	sprintf(error, "Error in expression at %u: %s", index, message);
}

