#include "Brain.hpp"
#include "Logger.hpp"
#include "colors.hpp"
#include <iostream>

Brain::Brain()
{
	// strings are automatically initialized to empty
	LOG_INFO() << "Brain default constructor called";
	LOG_DEBUG() << "Address: " << _ideas;
}

Brain::Brain(const Brain& other)
{
	for (size_t i = 0; i < ARRAY_SIZE; i++)
		_ideas[i] = other._ideas[i];
	LOG_INFO() << "Brain copy constructor called";
	LOG_DEBUG() << "Address: " << _ideas;

}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < ARRAY_SIZE; i++)
			_ideas[i] = other._ideas[i];
	}
	else
		LOG_WARNING() << "Brain self-assignment ignored";
	
	LOG_INFO() << "Brain assignment constructor called";
	LOG_DEBUG() << "Address: " << _ideas;
	return (*this);
}

Brain::~Brain()
{
	LOG_INFO() << "Brain destructor called";
}
