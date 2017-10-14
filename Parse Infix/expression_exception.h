#pragma once
#include <string>
#include <sstream>
#include <stdexcept>

class expression_exception :
	public std::runtime_error
{
public:
	expression_exception(unsigned int index, std::string message);
};

