// std::stack provides a LIFO data structure, meaning elements are added and removed exclusively from the top through member functions like push(), pop(), and front().
// It does not support iteration by default. This is because it is part of a broader variety of containers called "container adaptors" that restrict the access patterns of data
// through an "hidden" container such as std::deque for std::stack, std::deque or std::list for std::queue and std::vector for std::priority_queue; these are never fully exposed.
//
// So the std::stack must be made iterable.
// mutantStack will have support for iterators by exposing the ones of the underlying container "c" which is protected
//
// std::vector and std::list are called sequence containers instead.

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <typename T, typename Container = std::deque<T>>                               // std::deque will be the standard underlying container unless specified otherwise.
class mutantStack : public std::stack<T, Container> {
    public:
        mutantStack();
        mutantStack(const mutantStack &other);
        mutantStack &operator=(const mutantStack &other);
        ~mutantStack();
        typedef typename Container::iterator iterator;                                  // "typename" tells the compiler that what follows is a type, not a variable or a member
        typedef typename Container::const_iterator const_iterator;
        typedef typename Container::reverse_iterator reverse_iterator;
        typedef typename Container::const_reverse_iterator const_reverse_iterator;
        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
        reverse_iterator rbegin();
        reverse_iterator rend();
        const_reverse_iterator rbegin() const;
        const_reverse_iterator rend() const;
};

#include "../srcs/MutantStack.tpp"

#endif