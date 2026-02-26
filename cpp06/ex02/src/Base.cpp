#include "Base.hpp"
#include "Logger.hpp"

Base::~Base()
{
	LOG_DEBUG() << "Base destructor called";
}
