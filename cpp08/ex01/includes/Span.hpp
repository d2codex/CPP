#pragma once

#include <vector>

class Span
{
public:
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void			addNumber(int n);
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;

	//addRangeIterator

	//exceptions
	class SpanFullException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("Span is full");
			}
	};
	class NoSpanException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("No span possible. Must have at least 2 numbers.");
			}
	};

	//utility functions
	void	printVector() const;

private:
	unsigned int		_maxNumbers;
	std::vector<int>	_vector;
};
