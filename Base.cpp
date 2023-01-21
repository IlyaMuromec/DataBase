
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "myString.h"
#include "Data.h"
#include "Pair.h"
#include "Base.h"


// Default constructor
Base::Base() : m_n(0), m_cap(m_n), pBase(nullptr)
{
	;
}

// Copy constructor
Base::Base(const Base& other)
{
	m_cap = other.m_n;
	m_n = other.m_n;

	pBase = new Pair[m_cap];

	for (size_t i = 0; i < m_cap; i++)
	{
		pBase[i] = other.pBase[i]; 
	}
}

// Move constructor
Base::Base(Base&& other)
{
	m_cap = other.m_cap;
	m_n = other.m_n;

	pBase = other.pBase;
	other.pBase = nullptr;
	
	other.m_cap=0;
	other.m_n=0;
}

// Destructor
Base::~Base()
{
	delete[] pBase;
}

// = 
Base& Base::operator=(const Base& other)
{
	if ( this != &other)
	{
		if (m_n >= other.m_n)
		{
			m_cap = other.m_n;
			m_n = other.m_n;

			for (size_t i = 0; i < m_cap; i++)
			{
				pBase[i] = other.pBase[i];
			}
		}
		else
		{
			m_cap = other.m_n;
			m_n = other.m_n;

			delete[] pBase;

			pBase = new Pair[m_cap];

			for (size_t i = 0; i < m_cap; i++)
			{
				pBase[i] = other.pBase[i];
			}
		}

	}
	return *this;
}
 
// Move =
Base& Base::operator=(Base&& other)
{
	if (this != &other)
	{
		delete[] pBase;

		m_cap = other.m_cap;
		m_n = other.m_n;

		pBase = other.pBase;
		other.pBase = nullptr;
		other.m_cap = 0;
		other.m_n = 0;
	}
	return *this;
}

MyData& Base::operator[](const char* key)
{
	for (size_t i = 0; i < m_n; i++) // loking for employee with target key
	{
		if (pBase[i] == key)
		{
			return pBase[i].data; // return data for reading
		}
	}
	if (m_n >= m_cap) // add new employee
	{
		m_cap++;
		Pair* tmp = new Pair[m_cap];
		for (size_t i = 0; i < m_n; i++) 
		{
			tmp[i] = std::move(pBase[i]);
		}
		delete[] pBase;
		pBase = tmp;
	}
	pBase[m_n].key = key;
	m_n++;
	return pBase[m_n-1].data; // return data for writing
}

void Base::deletePair(const char* key)
{
	int num=-1;
	for (size_t i = 0; i < m_n && num<0; i++)
	{
		if (pBase[i] == key)
		{
			num = i;
		}
	}
	if (num >= 0)
	{
		for (size_t i = num; i < m_n-1; i++)
		{
			pBase[i] = pBase[i + 1];
		}
		pBase[m_n-1].data = MyData(MyData::UNDEF, 0, "enpty", 0);
		m_n--;
	}
	else
	{
		std::cout << "Incorrect input\n";
	}
}

std::ostream& operator<<(std::ostream& os, Base& b)
{
	os << "\nDatabase\n";

	for (size_t i = 0; i < b.m_n; i++)
	{
		os<< b.pBase[i];
	}

	os <<"\nEnd of Database\n";
	return os;
}

