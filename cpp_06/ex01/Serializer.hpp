#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>

#include "Data.hpp"

/*
https://stackoverflow.com/questions/573294/when-to-use-reinterpret-cast

reinterpret_cast only guarantees that 
if you cast a pointer to a different type,
and then reinterpret_cast it back to the original type,
you get the original value.*/

 
class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &c);
		Serializer & operator=(const Serializer &a);
		~Serializer();
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data*		deserialize(uintptr_t	raw);
};

#endif