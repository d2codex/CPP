#include "Serializer.hpp"
#include "Logger.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer&) {}
Serializer& Serializer::operator=(const Serializer&)
{ return (*this); }
Serializer::~Serializer() {}

uintptr_t	Serializer::serialize(Data* ptr)
{
	LOG_DEBUG() << "original ptr: " << ptr;
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	LOG_DEBUG() << "raw value: " << raw;
	LOG_DEBUG() << "raw value hex: 0x" << std::hex << raw;
	return(reinterpret_cast<Data*>(raw));
}
