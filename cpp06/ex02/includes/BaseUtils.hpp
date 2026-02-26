#pragma once

enum Type
{
	TYPE_A,
	TYPE_B,
	TYPE_C,
	TYPE_UNKNOWN,
};

Base*	generate(void);
Type	getType(Base* p);
Type	getType(Base& p);
void	identify(Base* p);
void	identify(Base& p);
