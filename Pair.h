#pragma once

class Pair
{
	MyString key; // unique key is lastname of employee
	MyData data; // data of employee

	Pair& operator=(const Pair&);
	Pair& operator=(Pair&&);

	bool operator==(const char* k) const { return key==k; };


	friend std::ostream& operator<<(std::ostream& os, Pair& p);
	friend class Base;
};

std::ostream& operator<<(std::ostream& os, Pair& p);

