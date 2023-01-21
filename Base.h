#pragma once

class Base
{
	size_t m_n; // max number of employees in database
	size_t m_cap; // number of employees in database
	Pair* pBase ; // point on database

public:
	
	Base();
	Base(const Base&);
	Base(Base&&);
	~Base();

	Base& operator=(const Base&);
	Base& operator=(Base&&);
	
	MyData& operator[](const char* key); // operator is used to get exist data and set new data

	void deletePair(const char* key); // 

	friend std::ostream& operator<<(std::ostream& os, Base& b);
};

std::ostream& operator<<(std::ostream& os, Base& b);

