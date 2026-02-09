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

	std::string getIdeaAtIndex(size_t index) const;
	void setIdeaAtIndex(const std::string& idea, size_t index);

private:
	std::string _ideas[ARRAY_SIZE];
};
