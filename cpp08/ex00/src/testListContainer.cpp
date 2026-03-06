#include "easyfind.hpp"
#include "tests.hpp"
#include "Logger.hpp"
#include <list>
#include <climits>

int	testListContainer()
{
	int	failed = 0;
	int	total = 0;

	printHeader("list container demo");
	// Demo
	{
		// create the container(dynamically allocated array)
		std::list<int> container;
		// verify the size of the container
		LOG_DEBUG() << "Capicity manually set to: " << container.size();
		// populate the container
		container.push_front(1);
		container.push_back(3);
		container.push_back(7);
		container.push_back(-7);
		container.push_back(0);
		container.push_back(INT_MIN);
		container.push_back(INT_MAX);

		//print the array
		printContainer(container);

		std::list<int>::iterator it = container.begin();
		std::advance(it, 1); // move to second element
		//insert in middle
		container.insert(it, 3);
		std::cout << yel("======================================\n");
		std::cout << yel("after insertion\n");
		printContainer(container);


		LOG_DEBUG() << "Capicity dynamically resized to: " << container.size();
		LOG_DEBUG() << "Potential Max size is: " << container.max_size();

		std::cout << yel("======================================\n");
		printHeader("easyfind");
		// first occurance of 3 findable
		{
			easyfind(container, 3);
		//	std::advance(it, 1); // move to second element
			if (!assertEqual("duplicate returns first occurrance", 3, *it))
				failed++;
			total++;
		}
		// find 0
		{
			easyfind(container, 0);
			std::list<int>::iterator it = container.begin();
			std::advance(it, 5);
			if (!assertEqual("0 is findable", 0, *it))
				failed++;
			total++;
		}
		// find INT_MIN
		{
			easyfind(container, INT_MIN);
			std::list<int>::iterator it = container.begin();
			std::advance(it, 6);
			if (!assertEqual("INT_MIN is findable", INT_MIN, *it))
				failed++;
			total++;
		}
		// find last element
		{
			easyfind(container, INT_MAX);
			std::list<int>::iterator it = container.begin();
			std::advance(it, 7);
			if (!assertEqual("find last element", INT_MAX, *it))
				failed++;
			total++;
		}
		// find first element
		{
			easyfind(container, 0);
			//std::list<int>::iterator it = container.begin();
			if (!assertEqual("find first element", 1, container.front()))
				failed++;
			total++;
		}
		// value not findable
		{
			bool thrown = false;
			try
			{
				easyfind(container, 10);
				
			}
			catch (std::runtime_error& e)
			{
				thrown = true;
				LOG_ERROR() << e.what();
			}
			if (!assertEqual("10 is not findable - throws exception", true, thrown))
				failed++;
			total++;
		}
		// empty array
		{
			std::list<int> empty;

			bool thrown = false;
			try
			{
				easyfind(empty, 1);
			}
			catch (std::runtime_error& e)
			{
				thrown = true;
				LOG_ERROR() << e.what();
			}
			if (!assertEqual("Empty array - throws exception", true, thrown))
				failed++;
			total++;
		}
		printSummary(failed, total);
		return (failed);
	}
}
