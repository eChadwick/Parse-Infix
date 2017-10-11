#include "expression_exception.h"

expression_exception::expression_exception(unsigned int index, std::string message) : index(index), message(message) {}

const char * expression_exception::what()
{
	std::ostringstream msg_stream("Error in expression at ");
	msg_stream << index << ": " << message;
	return msg_stream.str().c_str();
}

