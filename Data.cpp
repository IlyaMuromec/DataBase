
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "myString.h"
#include "Data.h"

MyData::MyData(const MyData& other): sex(other.sex), m_age(other.m_age), m_salary(other.m_salary)
{
	m_job = other.m_job;
}

MyData::MyData(MyData&& other) : sex(other.sex), m_age(other.m_age), m_salary(other.m_salary)
{
	m_job = std::move(other.m_job);
}

MyData& MyData::operator=(const MyData& other)
{
	sex=other.sex;
	m_age=other.m_age;
	m_salary=other.m_salary;
	m_job = other.m_job;
	return *this;
}


MyData& MyData::operator=(MyData&& other)
{
	sex = other.sex;
	m_age = other.m_age;
	m_salary = other.m_salary;
	m_job = std::move(other.m_job);
	return *this;
}

std::ostream& operator<<(std::ostream& os, MyData& d)
{
	os  << "\nSex: " << (d.sex==MyData::MALE? "male": (d.sex == MyData::FMALE ? "female" : "undef") )
		<< "\nAge: "
		<< d.m_age
		<< "\njob: " 
		<< d.m_job 
		<< "\nSalary: " 
		<< d.m_salary 
		<< '\n';
	return os;
}


