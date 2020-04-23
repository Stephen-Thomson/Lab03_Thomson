#include <cString>
#include <cctype>
#include <iostream>
using std::cout;
using std::endl;
#include "String.h"

/************************************************************************************************************
* Purpose: Default Constructor
*
* Precondition:
*	None
*
* Postcondition:
*	Creates the String
**************************************************************************************************************/
String::String() : m_string(nullptr)
{

}

/************************************************************************************************************
* Purpose: Single Argument Constructor
*
* Precondition:
*	None
*
* Postcondition:
*	Creates the String
**************************************************************************************************************/
String::String(char ch)
{
	m_string = new char[2];
	m_string[0] = ch;
	m_string[1] = '\0';
}

/************************************************************************************************************
* Purpose: Const Char Constructor
*
* Precondition:
*	None
*
* Postcondition:
*	Creates the String
**************************************************************************************************************/
String::String(const char* String) : m_string(nullptr)
{
	if (String != nullptr)
	{
		m_string = new char[strlen(String) + 1];
		strcpy_s(m_string, strlen(String) + 1, String);
	}
}

/************************************************************************************************************
* Purpose: Copy Constructor
*
* Precondition:
*	None
*
* Postcondition:
*	Creates the String
**************************************************************************************************************/

String::String(const String& copy) : m_string(nullptr)
{
	if (copy.m_string != nullptr)
	{
		m_string = new char[strlen(copy.m_string) + 1];
		strcpy_s(m_string, strlen(copy.m_string) + 1, copy.m_string);
	}
}


/************************************************************************************************************
* Purpose: Move Copy Constructor
*
* Precondition:
*	A string (copy)
*
* Postcondition:
*	Redirects the resources.
**************************************************************************************************************/
String::String(String&& copy)
{
	m_string = copy.m_string;
	copy.m_string = nullptr;
}

/************************************************************************************************************
* Purpose: Destructor
*
* Precondition:
*	m_string
*
* Postcondition:
*	Deallocates/Deletes the String
**************************************************************************************************************/
String::~String()
{
	delete[] m_string;
}

/************************************************************************************************************
* Purpose: Operator = Constructor
*
* Precondition:
*	None
*
* Postcondition:
*	Creates the String
**************************************************************************************************************/
String& String::operator=(String& rhs)
{
	if (this != &rhs)
	{
		delete[] m_string;
		if (rhs.m_string != nullptr)
		{
			m_string = new char[strlen(rhs.m_string) + 1];
			strcpy_s(m_string, strlen(rhs.m_string) + 1, rhs.m_string);
		}
		else
		{
			m_string = nullptr;
		}
	}
	return *this;
}


/************************************************************************************************************
* Purpose: Move Operator
*
* Precondition:
*	A string (rhs).
*
* Postcondition:
*	Redirects the resources.
**************************************************************************************************************/
String& String::operator=(String&& rhs)
{
	if (this != &rhs)
	{
		delete[] m_string;
		m_string = rhs.m_string;
		rhs.m_string = nullptr;
	}
	return *this;
}


/************************************************************************************************************
* Purpose: Operator Converter.
*
* Precondition:
*	None
*
* Postcondition:
*	Returns m_string.
**************************************************************************************************************/
String::operator char* () const
{
	return m_string;
}

/************************************************************************************************************
* Purpose: Displays the String.
*
* Precondition:
*	None
*
* Postcondition:
*	Displays String
**************************************************************************************************************/
void String::Display() const
{
	cout << m_string;
}

/************************************************************************************************************
* Purpose: Getter, returns the data in the String
*
* Precondition:
*	m_string
*
* Postcondition:
*	Returns data in String
**************************************************************************************************************/
const char* String::getString() const
{
	return m_string;
}

/************************************************************************************************************
* Purpose: Changes all letters in the String to uppercase characters.
*
* Precondition:
*	m_string
*
* Postcondition:
*	Modifies m_string
**************************************************************************************************************/
void String::Upper()
{
	if (m_string != NULL)
	{
		for (int i = 0; i < strlen(m_string); i++)
		{
			m_string[i] = toupper(m_string[i]);
		}
	}
}


/************************************************************************************************************
* Purpose: Changes all letters in the String to lowercase characters.
*
* Precondition:
*	m_string
*
* Postcondition:
*	Modifies m_string
**************************************************************************************************************/
void String::Lower()
{
	if (m_string != NULL)
	{
		for (int i = 0; i < strlen(m_string); i++)
		{
			m_string[i] = tolower(m_string[i]);
		}
	}
}

/************************************************************************************************************
* Purpose: Finds the lenght of the string.
*
* Precondition:
*	None
*
* Postcondition:
*	Returns integer length of string.
**************************************************************************************************************/
int String::Length()
{
	int x = strlen(m_string);
	return x;
}








