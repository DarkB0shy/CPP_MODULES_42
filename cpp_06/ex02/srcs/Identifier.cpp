//                                              <static_cast> vs <dynamic_cast>
//
//  When using <static_cast> in c++98 the compiler does not perform any runtime checks on the types involved. These are used for upcasting (from derived class to base class) and downcasting.
//  Static casts are faster but can result in undefined behaviour.
//  <dynamic_cast> is mostly used for "safe downcasting" and it also performs a type check to ensure the cast is valid, returning nullptr for pointers or bad_cast for references. This only
//  works with classes that have at least one virtual function (polymorphic classes). They are safer but also slower.


#include "../headers/Identifier.hpp"

Base* generate(void) {
    std::srand(static_cast<unsigned int>(std::time(0)));
    int random = std::rand() % 4;
    switch (random) {
        case 0:
            std::cout << "Generated instance of A\n";
            return new A();
        case 1:
            std::cout << "Generated instance of B\n";
            return new B();
        case 2:
            std::cout << "Generated instance of C\n";
            return new C();
        default: return nullptr;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) std::cout << "Pointer identifies: A\n";
    else if (dynamic_cast<B*>(p)) std::cout << "Pointer identifies: B\n";
    else if (dynamic_cast<C*>(p)) std::cout << "Pointer identifies: C\n";
    else std::cout << "Pointer identifies: Unknown type\n";
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Reference identifies: A\n";
    } catch (const std::bad_cast&) {
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << "Reference identifies: B\n";
        } catch (const std::bad_cast&) {
            try {
                (void)dynamic_cast<C&>(p);
                std::cout << "Reference identifies: C\n";
            } catch (const std::bad_cast&) {std::cout << "Reference identifies: Unknown type\n";}
        }
    }
}