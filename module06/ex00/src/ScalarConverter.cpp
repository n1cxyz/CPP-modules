#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <iomanip>
#include <limits>
#include <cmath>
#include <sstream>
#include <cerrno>

static bool isDisplayableChar(int value) {
    return (value >= 32 && value <= 126);
}

void ScalarConverter::convert(const std::string& literal) {
    char c;
    int i;
    float f;
    double d;

    bool special = false;

    if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
        special = true;
        f = std::strtof(literal.c_str(), NULL);
        d = static_cast<double>(f);
    } else if (literal == "-inf" || literal == "+inf" || literal == "nan") {
        special = true;
        d = std::strtod(literal.c_str(), NULL);
        f = static_cast<float>(d);
    } else if (literal.length() == 1 && !std::isdigit(literal[0])) {
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    } else if (literal.find('.') != std::string::npos && literal[literal.length() - 1] == 'f') {
        errno = 0;
        f = std::strtof(literal.c_str(), NULL);
        if (errno != ERANGE) {
            d = static_cast<double>(f);
            i = static_cast<int>(f);
            c = static_cast<char>(f);
        }
    } else if (literal.find('.') != std::string::npos) {
        errno = 0;
        d = std::strtod(literal.c_str(), NULL);
        if (errno != ERANGE) {
            f = static_cast<float>(d);
            i = static_cast<int>(d);
            c = static_cast<char>(d);
        }
    } else {
        errno = 0;
        long val = std::strtol(literal.c_str(), NULL, 10);
        if (errno != ERANGE && val >= INT_MIN && val <= INT_MAX) {
            i = static_cast<int>(val);
            c = static_cast<char>(i);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
        } else {
            std::cout << "int: impossible" << std::endl;
            std::cout << "char: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
    }

    std::cout << "char: ";
    if (special || f < 0 || f > 127)
        std::cout << "impossible" << std::endl;
    else if (isDisplayableChar(c))
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;

    std::cout << "int: ";
    if (special || d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
        std::cout << "impossible" << std::endl;
    else
        std::cout << i << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: ";
    if (special)
        std::cout << f << "f" << std::endl;
    else
        std::cout << f << "f" << std::endl;

    std::cout << "double: ";
    if (special)
        std::cout << d << std::endl;
    else
        std::cout << d << std::endl;
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

