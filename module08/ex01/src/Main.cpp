#include "Span.hpp"
#include <iostream>
#include <vector>

void printTestHeader(const std::string& title) {
    std::cout << "\n===== " << title << " =====" << std::endl;
}

int main() {

    printTestHeader("Basic Functionality Test");
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    printTestHeader("Test: many numbers");
    try {
        Span sp(10000);

        std::vector<int> data;
        for (int i = 0; i < 10000; ++i)
            data.push_back(i * 2);

        sp.addNumbers(data.begin(), data.end());

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    printTestHeader("Test: shortestSpan with 1 element");
    try {
        Span sp(2);
        sp.addNumber(42);
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    printTestHeader("Test: longestSpan with no elements");
    try {
        Span sp(2);
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    printTestHeader("Test: Adding too many numbers individually");
    try {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4);
    } catch (const std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    printTestHeader("Test: Adding range that exceeds capacity");
    try {
        Span sp(5);
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        vec.push_back(6);

        sp.addNumbers(vec.begin(), vec.end());
    } catch (const std::exception& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    }

    printTestHeader("Test: Partial range add that fits");
    try {
        Span sp(5);
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);

        sp.addNumbers(vec.begin(), vec.end());
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
