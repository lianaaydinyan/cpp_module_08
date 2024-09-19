#ifndef _spamm_
#define _spamm_

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>
#include <cstdlib>
#include <ctime>


class Span
{
    private:
        unsigned int n;
        std::vector<int> span;
    public:
    
        Span() = delete;
        Span(unsigned int count);
        Span& operator=(const Span& copy);
        Span(const Span& copy);
        ~Span();
    public:
        int     shortestSpan() ;
        int     longestSpan() ;
        void    addNumber(int number) ;
    public:
    template <typename InputIterator>
    void bonus(InputIterator begin, InputIterator end);
    int  getSize() const;
    public:
        class span_is_full_baby_ : public std::exception
		{ 
			public:
				const char* what() const throw();
		};
        class not_found_404_ : public std::exception
        {
            public:
				const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream ow, const Span& obj);

Span::Span(unsigned int count) : n(count) {}
Span::~Span() {}
Span::Span(const Span& copy) : n(copy.n), span(copy.span) {}

Span& Span::operator=(const Span& copy)
{
    if (this != &copy)
    {
        this->n = copy.n;
        this->span = copy.span;
    }
    return *this;
}

void Span::addNumber(int number)
{
    if (span.size() >= n)
        throw span_is_full_baby_();
    span.push_back(number);
}

int Span::shortestSpan()
{
    if (span.size() < 2)
        throw not_found_404_();
    std::vector<int> sorted = span;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; ++i)
    {
        int currentSpan = sorted[i + 1] - sorted[i];
        if (currentSpan < minSpan)
            minSpan = currentSpan;
    }
    return minSpan;
}

int Span::longestSpan()
{
    if (span.size() < 2)
        throw not_found_404_();
    int minNum = *std::min_element(span.begin(), span.end());
    int maxNum = *std::max_element(span.begin(), span.end());
    return maxNum - minNum;
}

const char* Span::span_is_full_baby_::what() const throw()
{
    return "Span is already full. Cannot add more numbers.";
}

const char* Span::not_found_404_::what() const throw()
{
    return "Not enough numbers stored to find a span.";
}

template <typename InputIterator>
void Span::bonus(InputIterator begin, InputIterator end)
{
    for (InputIterator it = begin; it != end; ++it)
        addNumber(*it);
}

int Span::getSize() const
{
    return n;
}

std::ostream& operator<<(std::ostream& os, const Span& obj)
{
    os << "Span capacity: " << obj.getSize() << ", Contents: ";
    
    if (obj.getSize() == 0)
        os << "empty";
    else
    {
        os << "[";
        for (unsigned int i = 0; i < obj.getSize(); ++i)
        {
            if (i > 0)
                os << ", ";
        }
        os << "]";
    }
    
    return os;
}
#endif