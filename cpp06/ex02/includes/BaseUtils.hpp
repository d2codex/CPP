#pragma once

enum Type
{
	A_TYPE,
	B_TYPE,
	C_TYPE,
	UNKNOWN_TYPE,
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);
Type	identifyType(Base* p);
Type	identifyType(Base& p);
