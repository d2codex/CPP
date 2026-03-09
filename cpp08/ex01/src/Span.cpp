#include "Span.hpp"
#include "Logger.hpp"

Span::Span(unsigned int N) : _maxNumbers(N), _vector(0)
{
	LOG_DEBUG() << "Span Parameterized constructor called";
	LOG_DEBUG() << "max numbers:     " << _maxNumbers;
	LOG_DEBUG() << "vector capacity: " << _vector.capacity();
	LOG_DEBUG() << "vector size:     " << _vector.size();
//	LOG_DEBUG() << *this; // may have to overload this to print out
}

Span::Span(const Span& other) :
	_maxNumbers(other._maxNumbers),
	_vector(other._vector)
{
	LOG_DEBUG() << "Span copy constructor called"; 
	LOG_DEBUG() << "(cpy) vector capacity: " << _vector.capacity();
	LOG_DEBUG() << "(cpy) vector size:     " << _vector.size();
}

Span::~Span()
{
	LOG_DEBUG() << "Span deconstructor called";
}

void	Span:: addNumber(int n)
{
	if (_vector.size() >= _maxNumbers)
		throw SpanFullException();

	_vector.push_back(n);

	LOG_DEBUG() << "(add) vector capacity: " << _vector.capacity();
	LOG_DEBUG() << "(add) vector size:     " << _vector.size();
}

