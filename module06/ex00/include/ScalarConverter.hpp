#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class scalarConverter {
private:
	scalarConverter();
	~scalarConverter();
public:	
	static void convert(const std::string& input);
};

#endif