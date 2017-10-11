#pragma once
#include <string>
#include <sstream>
#include <stdexcept>

class expression_exception :
	public std::exception
{
public:
	expression_exception(unsigned int index, std::string message);
	const char* what();
private:
	const std::string message;
	const unsigned int index;
};

