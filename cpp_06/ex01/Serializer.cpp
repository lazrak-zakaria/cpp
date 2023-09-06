#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &copy)
{
	(void) copy;

}

Serializer::~Serializer()
{
}

Serializer & Serializer::operator=(const Serializer &assign)
{
	(void) assign;
	return *this;
}

uintptr_t	Serializer::serialize(Data *a)
{
	uintptr_t answer = reinterpret_cast<uintptr_t> (a);
	return answer;
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	Data*	answer = reinterpret_cast<Data*> (raw);
	return answer;
}
