#include "iter.hpp"

#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(const T& elem) {
    std::cout << elem << " ";
}

template <typename T>
void increment(T& elem) {
    ++elem;
}

void toUpper(std::string& s) {
    for (size_t i = 0; i < s.length(); ++i)
        s[i] = std::toupper(static_cast<unsigned char>(s[i]));
}

int main() {
    std::cout << "Testing with int array:\n";
    int nums[] = {1, 2, 3, 4, 5};
    std::size_t numsLen = sizeof(nums) / sizeof(nums[0]);

    std::cout << "Original: ";
    iter(nums, numsLen, printElement<int>);
    std::cout << "\n";

    iter(nums, numsLen, increment<int>);

    std::cout << "After increment: ";
    iter(nums, numsLen, printElement<int>);
    std::cout << "\n\n";

    std::cout << "Testing with string array:\n";
    std::string words[] = {"hello", "world"};
    std::size_t wordsLen = sizeof(words) / sizeof(words[0]);

    std::cout << "Original: ";
    iter(words, wordsLen, printElement<std::string>);
    std::cout << "\n";

    iter(words, wordsLen, toUpper);

    std::cout << "After toUpper: ";
    iter(words, wordsLen, printElement<std::string>);
    std::cout << "\n\n";

    std::cout << "Testing with const array:\n";
    const double values[] = {1.1, 2.2, 3.3};
    std::size_t valuesLen = sizeof(values) / sizeof(values[0]);

    iter(values, valuesLen, printElement<double>);
    std::cout << "\n";

    return 0;
}
