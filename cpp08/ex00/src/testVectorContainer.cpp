#include "easyfind.hpp"
#include "tests.hpp"
#include "Logger.hpp"
#include <vector>
#include <climits>

int	testVectorContainer()
{
	int	failed = 0;
	int	total = 0;

	printHeader("container demo");
	// Demo
	{
		// create the container(dynamically allocated array)
		std::vector<int> container;
		// optional set the array to a desired size
		std::vector<int>::size_type size;
		container.reserve(5);
		// verify the size of the container
		size = container.capacity();
		LOG_DEBUG() << "Capicity manually set to: " << size;
		// populate the container
		container.push_back(1);
		container.push_back(3);
		container.push_back(3);
		container.push_back(7);
		container.push_back(-7);
		container.push_back(0);
		container.push_back(INT_MIN);
		container.push_back(INT_MAX);

		//print the array
		printContainer(container);

		LOG_DEBUG() << "Capicity dynamically resized to: " << container.capacity();
		LOG_DEBUG() << "Potential Max size is: " << container.max_size();

		std::cout << yel("======================================\n");
		printHeader("easyfind");
		// first occurance of 3 findable
		{
			easyfind(container, 3);
			if (!assertEqual("duplicate returns first occurrance", 3, container[1]))
				failed++;
			total++;
		}
		// find 0
		{
			easyfind(container, 0);
			if (!assertEqual("0 is findable", 0, container[5]))
				failed++;
			total++;
		}
		// find INT_MIN
		{
			easyfind(container, INT_MIN);
			if (!assertEqual("INT_MIN is findable", INT_MIN, container[6]))
				failed++;
			total++;
		}
		// find last element
		{
			easyfind(container, INT_MAX);
			if (!assertEqual("find last element", INT_MAX, container[7]))
				failed++;
			total++;
		}
		// find first element
		{
			easyfind(container, 1);
			if (!assertEqual("find first element", 1, container[0]))
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
			std::vector<int> empty;

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
