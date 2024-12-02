#include "headers/ScalarConverter.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./converter <literal>" << std::endl;
        return (1);
    }
    // if (strlen(argv[1]) >= 19) {
    //     std::cerr << "Nice try. That number is way too big old pal." << std::endl;
    //     return (2);
    // }
    ScalarConverter::convert(argv[1]);
    return (0);
}