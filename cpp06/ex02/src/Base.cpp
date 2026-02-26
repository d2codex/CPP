#include "Base.hpp"
#include "Logger.hpp"
#include <cstdlib>
#include <ctime>

Base::~Base()
{
	LOG_DEBUG() << "Base destructor called";
}

Base* generate(void)
{
	int random = std::rand() % 3;

	if (random == 0)
		return (new A);
	if (random == 1)
		return (new B);
	return (new C);
}

void identify(Base* p)
{
	if (!p)
	{
		std::cout << mag("Pointer is null.\n");
		return ;
	}
	if (dynamic_cast<A*>(p))
		std::cout << "Base type: A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "Base type: B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "Base type: C\n";
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Base type: A\n";
		return ;
	}
	catch (...) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Base type: B\n";
		return ;
	}
	catch (...) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Base type: C\n";
		return ;
	}
	catch (...) {}
}

Type	identifyType(Base* p)
{
	if (!p)
	{
		std::cout << mag("Pointer is null.\n");
		return (UNKNOWN_TYPE);
	}
	if (dynamic_cast<A*>(p))
		return (A_TYPE);
	else if (dynamic_cast<B*>(p))
		return (B_TYPE);
	else
		return (C_TYPE);
}

Type	identifyType(Base& p)
{
    try
	{
        (void)dynamic_cast<A&>(p);
        return A_TYPE;
    }
	catch (...) {}
	try
	{
        (void)dynamic_cast<B&>(p);
        return B_TYPE;
    }
	catch (...) {}
    return C_TYPE;
}
