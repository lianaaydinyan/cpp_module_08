#ifndef _mutant_
#define _mutant_


#include <stack>
#include <iostream>
template<typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};


#endif