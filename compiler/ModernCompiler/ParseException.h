#ifndef _PARSE_EXCEPTION_H
#define _PARSE_EXCEPTION_H

#include <iostream>

class ParseException
{
private: 
	std::string _message;
	ParseException();

public:
	ParseException(std::string message)
		: _message(message) {}

	std::string GetMessage() { return _message;  }
};

#endif