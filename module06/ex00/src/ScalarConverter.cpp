#include "ScalarConverter.hpp"

scalarConverter::scalarConverter() {}
scalarConverter::~scalarConverter() {}

static bool isValidInput(const std::string& input) {
	size_t i = 0;
	while (i < input.length() && std::isspace(input[i]))
		i++;
	if (i == input.length())
		return false;

	while (i < input.length() && !std::isspace(input[i]))
		i++;
	while (i < input.length() && std::isspace(input[i]))
		i++;

	return i == input.length();
}

static char convertToChar(const std::string& input, size_t& pos) {
	pos++;
	if (!std::isprint(input[pos])) {
		std::cout << "Invalid Input.\nChar must be printable" << std::endl;
		return 0;
	}
	if (input[pos + 1] != '\'') {
		std::cout << "Invalid Input.\nChar must be single" << std::endl;
		return 0;
	}
	return input[pos + 1];
}

static void print(char c) {
	if (c == 0)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
}

// bool isInt(const std::string& input) {
	
// }

// bool isFloat(const std::string& input) {
	
// }

// bool isDouble(const std::string& input) {
	
// }

void scalarConverter::convert(const std::string& input) {
	char c = 0;
	if (!isValidInput(input)) {
		std::cout << "Invalid Input." << std::endl;
		return;
	}
	for (size_t i = 0; i < input.length(); ++i) {
		while (i < input.length() && std::isspace(input[i]))
			i++;
		// char
		std::cout << input[i] << std::endl;
		if (input[i] == '\'') {
			c = convertToChar(input, i);
		}	
	}
	print(c);
}
