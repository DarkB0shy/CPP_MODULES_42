#include "headers/MutantStack.hpp"

// int main () {
//     mutantStack<int> mstack;
//     mstack.push(5);
//     mstack.push(17);
//     std::cout << mstack.top() << std::endl;
//     mstack.pop();
//     std::cout << mstack.size() << std::endl;
//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     mstack.push(0);
//     mutantStack<int>::iterator it = mstack.begin();
//     mutantStack<int>::iterator ite = mstack.end();
//     while (it != ite)
//     {
//     std::cout << *it << std::endl;
//     ++it;
//     }
//     std::stack<int> s(mstack);
//     return (0);
// }

int main () {
    mutantStack<std::string> mstack;
    mstack.push("AB");
    mstack.push("CD");
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push("EF");
    mstack.push("GH");
    mstack.push("IJ");
    mstack.push("Z");
    mutantStack<std::string>::iterator it = mstack.begin();
    mutantStack<std::string>::iterator ite = mstack.end();
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<std::string> s(mstack);
    return (0);
}

// #include <vector>

// int main() {
//     mutantStack<int, std::vector<int>> mstack;                              // Using std::vector<int> instead of std::dequeue.
//     mstack.push(5);
//     mstack.push(17);
//     std::cout << mstack.top() << std::endl;
//     mstack.pop();
//     std::cout << mstack.size() << std::endl;
//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     mstack.push(0);
//     mutantStack<int, std::vector<int>>::iterator it = mstack.begin();
//     mutantStack<int, std::vector<int>>::iterator ite = mstack.end();
//     while (it != ite) {
//         std::cout << *it << std::endl;
//         ++it;
//     }
//     std::stack<int, std::vector<int>> s(mstack);
//     return (0);
// }
