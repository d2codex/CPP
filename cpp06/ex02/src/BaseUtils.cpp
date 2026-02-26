#include "Base.hpp"
#include "BaseUtils.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "colors.hpp"
#include <iostream>
#include <cstdlib>

Base* generate(void)
{
	int random = std::rand() % 3;

	switch(random)
	{
		case 0: return (new A);
		case 1: return (new B);
		default: return (new C);
	}
}

Type	getType(Base* p)
{
	if (!p)
		return (TYPE_UNKNOWN);
	if (dynamic_cast<A*>(p))
		return (TYPE_A);
	else if (dynamic_cast<B*>(p))
		return (TYPE_B);
	else if (dynamic_cast<C*>(p))
		return (TYPE_C);
	else
		return (TYPE_UNKNOWN);
}

Type	getType(Base& p)
{
    try
	{
        (void)dynamic_cast<A&>(p);
        return TYPE_A;
    }
	catch (...) {}
	try
	{
        (void)dynamic_cast<B&>(p);
        return TYPE_B;
    }
	catch (...) {}
    return TYPE_C;
}

void identify(Base* p)
{
	Type t = getType(p);
	if (t == TYPE_UNKNOWN)
	{
		std::cout << mag("Pointer is null.\n");
		return ;
	}
	if (t == TYPE_A)
		std::cout << "Base type: A\n";
	else if (t == TYPE_B)
		std::cout << "Base type: B\n";
	else if (t == TYPE_C)
		std::cout << "Base type: C\n";
}

void identify(Base& p)
{
	Type t = getType(p);
	if (t == TYPE_A)
		std::cout << "Base type: A\n";
	else if (t == TYPE_B)
		std::cout << "Base type: B\n";
	else
		std::cout << "Base type: C\n";
}
