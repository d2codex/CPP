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

	//print function
	void printVector() const;

private:
	unsigned int		_maxNumbers;
	std::vector<int>	_vector;
};
