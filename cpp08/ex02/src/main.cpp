/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:12:39 by diade-so          #+#    #+#             */
/*   Updated: 2026/03/11 09:12:40 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "colors.hpp"
#include <climits>
#include <list>

void printTestName(const std::string& testName)
{
	std::cout << yel("======================================================\n");
	std::cout << YEL << "Testing " << testName << RESET << '\n';
}

int	main(void)
{
	// subject test - default container deque
	{
		printTestName("subject test (deque)");
		MutantStack<int>	mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	// subject test - list continer
	{
		printTestName("subject test (list)");
		MutantStack<int, std::list<int> >	mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int, std::list<int> >::iterator it = mstack.begin();
		MutantStack<int, std::list<int> >::iterator ite = mstack.end();
		++it;--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int, std::list<int> > s(mstack);
	}
	// default container (deque)
	{
		printTestName("base class functions - deque demo");
		MutantStack<int> mdeque;

		// check size of container
		std::cout << "check size: " << mdeque.size() << '\n';
		// check if its empty
		if (mdeque.empty())
			std::cout << "container is empty\n";
		// add an element to the mdeque
		mdeque.push(42);
		mdeque.push(-42);
		mdeque.push(0);
		mdeque.push(INT_MIN);
		mdeque.push(INT_MAX); // top element here

		printElements(mdeque);
		// access top element
		printTestName("check top element");
		std::cout << "top element: " << mdeque.top() << '\n';

		printTestName("remove top element");
		//remove top element
		mdeque.pop();
		printElements(mdeque);

		// testing iterators
		printTestName("iterator");
		MutantStack<int>::iterator it;
		for(it = mdeque.begin(); it != mdeque.end(); ++it)
		{
			std::cout << "[" << std::distance(mdeque.begin(), it) << "] "
					 << *it << '\n';
		}

		// testing reverse iterator
		printTestName("reverse iterator");
		MutantStack<int>::reverse_iterator rev_it;
		for(rev_it = mdeque.rbegin(); rev_it != mdeque.rend(); ++rev_it)
		{
			std::cout << "[" << std::distance(mdeque.rbegin(), rev_it) << "] "
					 << *rev_it << '\n';
		}
	}
}
