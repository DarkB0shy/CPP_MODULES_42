#include <iostream>
#include "headers/Serializer.hpp"

int main() {
    Data data;
    data.id = 42;
    data.val = "RTFM!";
    uintptr_t first = Serializer::serialize(&data);
    std::cout << "Serialized data: " << first << std::endl;
    Data* second = Serializer::deserialize(first);
    std::cout << "Data Id: " << second->id << " Val: " << second->val << std::endl;
    return (0);
}
