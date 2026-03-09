#include "Span.hpp"
#include "Logger.hpp"

Span::Span(unsigned int N) : _maxNumbers(N), _vector(0)
{
	LOG_DEBUG() << "Span Parameterized constructor called";
	LOG_DEBUG() << "max numbers:     " << _maxNumbers;
	LOG_DEBUG() << "vector size:     " << _vector.size();
}

Span::Span(const Span& other) :
	_maxNumbers(other._maxNumbers),
	_vector(other._vector)
{
	LOG_DEBUG() << "Span copy constructor called"; 
	LOG_DEBUG() << "(copy) max numbers:     " << _maxNumbers;
	LOG_DEBUG() << "(copy) vector size:     " << _vector.size();
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxNumbers = other._maxNumbers;
		_vector = other._vector;
	}
	else
		LOG_WARNING() << "Span self-assignment ignored";

	LOG_DEBUG() << "Span assignment operator called"; 
	LOG_DEBUG() << "(assign) max numbers:     " << _maxNumbers;
	LOG_DEBUG() << "(assign) vector size:     " << _vector.size();

	return (*this);
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

	LOG_DEBUG() << "(add) vector size:     " << _vector.size();
}

void	Span::printVector() const
{
	for (unsigned int i = 0; i < _vector.size(); i++)
		std::cout << "index[" << i << "]: " << _vector.at(i) << '\n';
}
