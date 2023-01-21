
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "myString.h"


MyString::MyString()
{
	m_pStr = new char[strlen("empty") + 1];
	strcpy(m_pStr, "empty");
}

// Определение конструктора
MyString::MyString( const char*  init )
{
	m_pStr = new char[strlen(init) + 1];
	strcpy(m_pStr, init);	
}

// Определение конструктора копирования
MyString::MyString(const MyString& other)
{
	m_pStr = new char[strlen(other.m_pStr) + 1];
	strcpy(m_pStr, other.m_pStr);
}

// Определение перемещающего конструктора 
MyString::MyString(MyString&& other)
{
	m_pStr = other.m_pStr; // 
	other.m_pStr = nullptr;
}

// Определение деструктора.
MyString::~MyString()
{
	delete[] m_pStr;
}

// Method of class
//------------------------------------

const char* MyString::GetString(void)
{
	return (m_pStr);
}

const char* MyString::GetString(void) const
{
	return (m_pStr);
}

void MyString::SetNewString(const char* init)
{
	delete[] m_pStr;
	m_pStr = new char[strlen(init) + 1];
	strcpy(m_pStr, init);
}

MyString& MyString::operator=(const char* str)
{
	delete[] m_pStr;
	m_pStr = new char[strlen(str) + 1];
	strcpy(m_pStr, str);
	return *this;
}

MyString& MyString::operator=(const MyString& r)
{
	if (this!= &r)
	{
		delete[] m_pStr;
		m_pStr = new char[strlen(r.m_pStr) + 1];
		strcpy(m_pStr, r.m_pStr);
	}
	return *this;
}

MyString& MyString::operator=(MyString&& other)
{
	m_pStr = other.m_pStr;
	other.m_pStr = nullptr;
	return *this;
}

bool MyString::operator==(const char* str)
{	
	return (strcmp(str, m_pStr) == 0);
}

bool MyString::operator==(const char* str) const
{
	return (strcmp(str, m_pStr) == 0);
}

MyString Concatenation(const char* str1, ...)
{

	// General str1 is pointer on string:
	// str1 is address of string
	// *str1 is string
	// &str1 is address, where parameters are located  

	const char** pp = reinterpret_cast<const char**>(&str1);
	// pp - addres of function parameters
	// *pp - addres of string
	// **pp - string

	int nSimbol = 0, nStr = 0;

	while (**pp != '0')
	{
		nSimbol += strlen(*pp);
		nStr++;
		pp++;
	}

	char* pStr = new char[nSimbol + 1];

	*pStr = '\0';

	const char** pp1 = reinterpret_cast<const char**>(&str1);

	while (**pp1 != '0')
	{
		strcat(pStr, *pp1);
		pp1++;
	}

	MyString ret_str(pStr);

	delete[] pStr;

	return ret_str;
}

std::ostream& operator<< (std::ostream& os, const MyString& str)
{
	os << str.m_pStr; // Why can't I use m_pStr?
	return os;
}

