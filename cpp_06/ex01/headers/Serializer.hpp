#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <cstdint>
// Holds uintptr_t. It stands for unsigned integer pointer type, it is used to hold a pointer only it is treated as an integer rather than a memory address. This type is
// the safest way to cast a variable to a pointer without losing information. It is designed to hold a pointer in any system as an unsigned int.

struct Data {
    int id;
    std::string val;
};

class Serializer {
    private:
        Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif