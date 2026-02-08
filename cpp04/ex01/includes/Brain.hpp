#pragma once

#include <string>

class Brain
{
public:
	enum { ARRAY_SIZE = 100 };

	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	~Brain();

private:
	std::string _ideas[ARRAY_SIZE];
};
