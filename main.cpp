// Темы:
// Перегрузка операторов.
// Встроенные объекты 

#include "iostream"
#include <tchar.h>
#define	  stop __asm nop

#include "myString.h"
#include "Data.h"
#include "Pair.h"
#include "Base.h"

int _tmain(int argc, _TCHAR* argv[])
{
//////////////////////////////////////////////////////////////////////

/*
	Develop a "database" of employees through an associative array.
	The key is the last name(the key in the task is unique, so there cannot be several 
	Ivanovs in the database), and the data : gender, age, position, salary...
	Implement:
	adding employees to the database
	exception
	displaying information about a specific employee
	display of all(or interesting) information about all employees
*/
		Base bd; // Default сonstructor

		bd["Ivanov"] = MyData(MyData::MALE, 30, "engenier", 80);
		/*
		 1 - create auto nameless instance of type MyData
		 2 - call operator []
		 2.1 - add memory
		 2.2 - return address new data for key: Ivanov
		 3 - call operator =
		*/
		bd["Lavrova"] = MyData(MyData::FMALE, 35, "programmer", 100);	
		bd["Petrov"] = MyData(MyData::MALE, 45, "cook", 60);	

		std::cout << bd << std::endl; // print base

		// test different constructors and operators
		// ----------------------------------------		
		Base bd3=bd; // Copy constructor

		std::cout << bd3 << std::endl; // print base

		bd.deletePair("Ivanov");

		std::cout << bd << std::endl; // print base

		const Base bd1 = bd; // Copy constructor
		
		Base bd2; // Default constructor 
		bd2 = bd; // operator =

		std::cout << bd2 << std::endl; // print base
		{
			Base bd4=bd; // Copy constructor
			std::cout << bd4 << std::endl; // print base
			bd3 = std::move(bd4); // 
			std::cout << bd4 << std::endl; // print base
			std::cout << bd3 << std::endl; // print base
		}
		std::cout << bd3 << std::endl; // print base
		stop
	return 0;
}//endmain


