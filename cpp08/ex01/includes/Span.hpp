#pragma once

#include <vector>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <climits>

class Span
{
public:
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

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

	// methods
	void			addNumber(int n);
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;

	template<typename Iterator>
	void			addNumber(Iterator begin, Iterator end)
	{
		for(; begin != end; ++begin)
			addNumber(*begin);
	}

	//utility functions
	void	printVector() const;

private:
	unsigned int		_maxNumbers;
	std::vector<int>	_vector;
};

template<typename Container>
Container generateRandomNumbers(size_t n)
{
	Container c;
	
	const size_t MAX_SIZE = 2000000;
	if (n > MAX_SIZE)
		n = MAX_SIZE;

	for (size_t i = 0; i < n; i++)
	{
		int num = rand() % n;
		if (rand() % 2)
			num = -num;
		c.push_back(num);
	}
	return (c);
}
