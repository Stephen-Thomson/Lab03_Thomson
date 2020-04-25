#pragma once
/***************************************************************************************************************************
* Class: Potion
*
* Purpose: This object is a magical potion, containg the name, description, potency, and cost of the potion.
*
* Manager Functions:
*	Default Constructor
*	Overloaded Constructor
*	Deconstructor
*	Copy Constructor
*	Operator Constructor
*
* Methods:
*	setname
*	setdescription
*	setpotency
*	setcost
*	getname
*	getdescription
*	getpotency
*	getcost
*	display
*	convert
*	drink
*
*
****************************************************************************************************************************/
#include "String.h"

class Potion
{
public:
	Potion();
	Potion(String name, String description, String potency, String cost);
	Potion(const Potion& copy);
	Potion(Potion&& copy);
	Potion& operator=(const Potion& rhs);
	Potion& operator=(Potion&& rhs);
	~Potion();
	operator char* () const;
	void setname(String name);
	void setdescription(String description);
	void setpotency(String potency);
	void setcost(String cost);
	const String getname() const;
	const String getdescription() const;
	const String getpotency() const;
	const String getcost() const;
	void display();
	int convert();
	void drink();
private:
	String m_name;
	String m_description;
	String m_potency;
	String m_cost;

};

