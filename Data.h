#pragma once

class MyData
{
public:
	enum Sex {UNDEF, MALE, FMALE};
private:
	Sex sex;
	size_t m_age;
	MyString m_job;
	float m_salary;
public:
	MyData(): sex(UNDEF), m_age(0), m_salary(0) {};
	MyData(Sex s, size_t age, const char* job, float sal) : sex(s), m_age(age), m_job(job), m_salary(sal) {};

	MyData(const MyData&);
	MyData(MyData&&);
	
	MyData& operator=(const MyData&);
	MyData& operator=(MyData&&);

	friend std::ostream& operator<<(std::ostream& os, MyData& d);
};

std::ostream& operator<<(std::ostream& os, MyData& d);


