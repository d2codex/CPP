#pragma once

#include <stack>
#include <deque>
#include <iostream>
#include <iterator>

// MutantStack inherits from std::stack (see documentation from
// gcc/libstdc++-v3/include/bits/stl_stack.h)
// template<typename _Tp, typename _Sequence = deque<_Tp>>
// so stack takes 2 parameters the first is the element type ex: int
// and the second is the container type, if not specified it is
// defaulted to a deque(double ended queue) container
// stack has public memeber (among others):
//   typedef _Sequence	container_type;
//  and protected (allows access to derived classes):
//     _Sequence c;
//  c is the underlying container so i can use that to access
//  it's member functions, in this exercise that would be the iterators
template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	typedef typename std::stack<T, Container>::container_type	container_type;
	typedef typename container_type::iterator					iterator;
	typedef typename container_type::reverse_iterator			reverse_iterator;
	typedef typename container_type::const_iterator				const_iterator;
	typedef typename container_type::const_reverse_iterator		const_reverse_iterator;

	MutantStack() {}
	MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}
	MutantStack& operator=(const MutantStack& other)
	{
		if (this != &other)
			std::stack<T, Container>::operator=(other);
		return (*this);
	}
	~MutantStack() {}

	iterator begin() { return (this->c.begin()); }
	iterator end() { return (this->c.end()); }
	
	reverse_iterator rbegin() { return (this->c.rbegin()); }
	reverse_iterator rend() { return (this->c.rend()); }

	const_iterator begin() const { return (this->c.begin()); }
	const_iterator end() const { return (this->c.end()); }

	const_reverse_iterator rbegin() const { return (this->c.rbegin()); }
	const_reverse_iterator rend() const { return (this->c.rend()); }
};

template<typename T>
void printElements(const T& container)
{
	typedef typename T::const_iterator const_iterator;
	for(const_iterator it = container.begin(); it != container.end(); ++it)
	{
		std::cout << "[" << std::distance(container.begin(), it) << "]: " <<
			*it << '\n';
	}
}
