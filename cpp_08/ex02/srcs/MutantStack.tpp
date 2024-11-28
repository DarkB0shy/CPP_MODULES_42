template <typename T, typename Container>
mutantStack<T, Container>::mutantStack() : std::stack<T, Container>() {}

// The "actual" copying takes place here: std::stack<T,Container>(other). This invokes the copy constructor of the base class with the elements held in &other.
template <typename T, typename Container>
mutantStack<T, Container>::mutantStack(const mutantStack<T, Container>& other) : std::stack<T, Container>(other) {}

template <typename T, typename Container>
mutantStack<T, Container>& mutantStack<T, Container>::operator=(const mutantStack<T, Container>& other) {
    if (this != &other) std::stack<T, Container>::operator=(other);
    return *this;
}

template <typename T, typename Container>
mutantStack<T, Container>::~mutantStack() {}

template <typename T, typename Container>
typename mutantStack<T, Container>::iterator mutantStack<T, Container>::begin() {return this->c.begin();}

template <typename T, typename Container>
typename mutantStack<T, Container>::iterator mutantStack<T, Container>::end() {return this->c.end();}

template <typename T, typename Container>
typename mutantStack<T, Container>::const_iterator mutantStack<T, Container>::begin() const {return this->c.begin();}

template <typename T, typename Container>
typename mutantStack<T, Container>::const_iterator mutantStack<T, Container>::end() const {return this->c.end();}

template <typename T, typename Container>
typename mutantStack<T, Container>::reverse_iterator mutantStack<T, Container>::rbegin() {return this->c.rbegin();}

template <typename T, typename Container>
typename mutantStack<T, Container>::reverse_iterator mutantStack<T, Container>::rend() {return this->c.rend();}

template <typename T, typename Container>
typename mutantStack<T, Container>::const_reverse_iterator mutantStack<T, Container>::rbegin() const {return this->c.rbegin();}

template <typename T, typename Container>
typename mutantStack<T, Container>::const_reverse_iterator mutantStack<T, Container>::rend() const {return this->c.rend();}
