#include "Span.hpp"
#include "Logger.hpp"
#include <algorithm>
#include <climits>

Span::Span(unsigned int N) : _maxNumbers(N), _vector(0)
{
	_vector.reserve(N);
	LOG_DEBUG() << "Span Parameterized constructor called";
	LOG_DEBUG() << "max numbers:     " << _maxNumbers;
	LOG_DEBUG() << "vector size:     " << _vector.size();
	LOG_DEBUG() << "vector capacity: " << _vector.capacity();
}

Span::Span(const Span& other) :
	_maxNumbers(other._maxNumbers),
	_vector(other._vector)
{
	LOG_DEBUG() << "Span copy constructor called"; 
	LOG_DEBUG() << "(copy) max numbers:     " << _maxNumbers;
	LOG_DEBUG() << "(copy) vector size:     " << _vector.size();
	LOG_DEBUG() << "(copy) vector capacity: " << _vector.capacity();
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
	LOG_DEBUG() << "(assign) vector capacity: " << _vector.capacity();

	return (*this);
}

Span::~Span()
{
	LOG_DEBUG() << "Span deconstructor called";
}

void	Span::addNumber(int n)
{
	if (_vector.size() >= _maxNumbers)
		throw SpanFullException();

	_vector.push_back(n);

	LOG_DEBUG() << "(add) vector size:     " << _vector.size();
	LOG_DEBUG() << "(add) vector capacity: " << _vector.capacity();
}

std::vector<int>	Span::getSortedVector() const
{
	if (_vector.size() < 2)
		throw NoSpanException();

	std::vector<int> tmp(_vector);
	std::sort(tmp.begin(), tmp.end());

	return (tmp);
}

unsigned int	Span::shortestSpan() const
{
	std::vector<int> tmp = getSortedVector();

	long long shortest = LLONG_MAX;
	for (size_t i = 0; i < tmp.size() - 1; i++)
	{
		long long	diff = static_cast<long long>(tmp[i + 1]) -
						   static_cast<long long>(tmp[i]);
		if (diff < shortest)
			shortest = diff;
	}
	LOG_INFO() << "Shortest span: " << static_cast<unsigned int>(shortest);
	return (static_cast<unsigned int>(shortest));
}

unsigned int	Span::longestSpan() const
{
	std::vector<int> tmp = getSortedVector();
	
	long long longest = (static_cast<long long>(tmp.back()) -
						 static_cast<long long>(tmp.front()));
	LOG_INFO() << "Longest Span: " << static_cast<unsigned int>(longest);

	return (static_cast<unsigned int>(longest));
}

void	Span::printVector() const
{
	for (unsigned int i = 0; i < _vector.size(); i++)
		std::cout << "index[" << i << "]: " << _vector.at(i) << '\n';
}
