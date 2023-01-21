
#pragma once

class MyString
{
    char* m_pStr;	//строка-член класса

public:
	MyString();
	explicit MyString(const char* init);
	MyString(const MyString&);
	MyString(MyString&&);
	~MyString();
	const char* GetString(void);
	const char* GetString(void) const;
	void SetNewString(const char*);

	MyString& operator=(MyString&&);
	MyString& operator=(const char*);
	MyString& operator=(const MyString&);
	
	bool operator==(const char*);
	bool operator==(const char*) const;

	friend std::ostream& operator<< (std::ostream& os, const MyString& str);
};

MyString Concatenation(const char*, ...);

std::ostream& operator<< (std::ostream& os, const MyString& str);

