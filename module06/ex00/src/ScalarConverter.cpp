#include "ScalarConverter.hpp"
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cmath>
#include <cerrno>

scalarConverter::scalarConverter() {}
scalarConverter::~scalarConverter() {}

static bool isChar(const std::string& input) {
	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
		return true;
	return false;
}

static bool isSpecial(const std::string& input) {
	if (input == "nan" || input == "nanf" || input == "+inf" ||
		input == "-inf" || input == "+inff" || input == "-inff")
		return true;
	return false;
}

void scalarConverter::convert(const std::string& input) {
	std::cout << "DEBUG input string: '" << input << "' length: " << input.size() << "\n";
	if (isChar(input)) {
		char c = input[0];
		std::cout << "char: " << c << std::endl;
		std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(c) << "f\n";
        std::cout << "double: " << static_cast<double>(c) << "\n";
        return;
	} else if (isSpecial(input)) {
		std::string base = input;
		std::cout << "DEBUG base string: '" << base << "' length: " << base.size() << "\n";
		bool hasF = false;
		if (input[input.size() - 1] == 'f') {
			base = input.substr(0, input.length() - 1);
			hasF = true;
		}

		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";

		if (hasF)
			std::cout << "float: " << input << "\n";
		else
			std::cout << "float: " << base << "f\n";

		std::cout << "double: " << base << "\n";
			return;
	}
}
