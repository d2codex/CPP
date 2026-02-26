#pragma once

class Base
{
public:
	virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

enum Type
{
	A_TYPE,
	B_TYPE,
	C_TYPE,
};

Base*	generate(void);
void			identify(Base* p);
void			identify(Base& p);
Type	identifyType(Base* p);
Type	identifyType(Base& p);
