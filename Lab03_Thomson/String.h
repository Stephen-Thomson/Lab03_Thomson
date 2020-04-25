#pragma once

/***************************************************************************************************************************
* Class: String
*
* Purpose: This contains a String and allows manipulation of it.
*
* Manager Functions:
*	Default Constructor
*	Overloaded Constructor
*	Copy Constructor
*	Destructor
*	Operator Constructor
*	Move Copy
*	Move Operator
*	Operator Conversion
*
* Methods:
*	Display
*	getString
*	Upper
*	Lower
*
*
****************************************************************************************************************************/

class String
{
public:
	String();
	String(char ch);
	String(const char* String);
	String(const String& copy);
	String(String&& copy);
	~String();
	String& operator=(const String& rhs);
	String& operator=(String&& rhs);
	operator char* () const;
	void Display() const;
	const char* getString() const;
	void Upper();
	void Lower();
	int Length();

private:
	char* m_string;
};

