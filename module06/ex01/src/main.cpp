#include "Serializer.hpp"

int main() {
    Data original;
    original.id = 42;
    original.letter = 'A';
    original.value = 3.14;

    uintptr_t raw = Serializer::serialize(&original);

    Data* recovered = Serializer::deserialize(raw);

    if (recovered == &original) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
        std::cout << "Recovered Data: id = " << recovered->id
                  << ", letter = " << recovered->letter
                  << ", value = " << recovered->value << std::endl;
    } else {
        std::cout << "Failed: Pointers do not match." << std::endl;
    }

    return 0;
}