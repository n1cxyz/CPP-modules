#include <iostream>
#include "Array.hpp"

int main() {
    try {
        Array<int> arr(5);
        for (size_t i = 0; i < arr.size(); ++i)
            arr[i] = i * 10;

        Array<int> copy = arr;
        copy[0] = 100;

        std::cout << "Original[0]: " << arr[0] << std::endl;
        std::cout << "Copy[0]: " << copy[0] << std::endl;

		const Array<int> constArr = arr;
        std::cout << "Const Array[1]: " << constArr[1] << std::endl;
		// constArr[1] = 42;

        std::cout << arr[10] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}