#include "Serializer.hpp"


int main(void) {
    Data originalData = {"Hello", 42, "World"};
    Data copyData;

    Serializer serializer;
    uintptr_t bytes = serializer.serialize(&originalData);
    copyData = *serializer.deserialize(bytes);
    std::cout << "Original data info: " << originalData.s1 << " " << originalData.n << " " << originalData.s2 << std::endl;
    std::cout << "Copy data info: " << copyData.s1 << " " << copyData.n << " " << copyData.s2 << std::endl;

    copyData.s1 = "Goodbye";
    copyData.n = 21;
    copyData.s2 = "Earth";

    std::cout << "Original data info: " << originalData.s1 << " " << originalData.n << " " << originalData.s2 << std::endl;
    std::cout << "Copy data info: " << copyData.s1 << " " << copyData.n << " " << copyData.s2 << std::endl;

    std::cout << "Original data address: " << &originalData << std::endl;
    std::cout << "Copy data address: " << &copyData << std::endl;
    return 0;
}