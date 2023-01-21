
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "myString.h"
#include "Data.h"
#include "Pair.h"

Pair& Pair::operator=(const Pair& other)
{
	data = other.data;
	key = other.key;
	return *this;
}

Pair& Pair::operator=(Pair&& other)
{
	data = std::move(other.data);
	key = std::move(other.key);
	return *this;
}


std::ostream& operator<<(std::ostream& os, Pair& p)
{
	os<<'\n'<< p.key;
	os<<p.data;
	return os;
}
