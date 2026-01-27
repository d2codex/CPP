#include <iostream>

class Example
{
public:
	// default constructor cause it has no arguments
	// automatically invoked when we create an object w/o params
	Example()
	{
		std::cout << "Created Entity\n";
	}
	Example(int x)
	{
		std::cout << "Created Entity with " << x << '\n';
	}
};

// initializing inside the constructor body = inefficient!!
// initializes twice!
class Entity1
{
private:
	Example _example;
public:
	Entity1()
	{
		_example = Example(8); // default construct + assignment
	}
};

// using constructor initializer list
// always do it this way, more efficient!
class Entity2
{
private:
	Example _example;
public:
	Entity2() : _example(8)
	{
	}
};

int	main(void)
{
	std::cout << "e1:\n";
	Entity1 e1;
	std::cout << "\ne2:\n";
	Entity2 e2;
	
	return (0);
}
