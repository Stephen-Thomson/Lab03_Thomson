#include <iostream>
using std::cout;
using std::endl;
#include <cmath>
#include "Potion.h"

/************************************************************************************************************
* Purpose: Creates Default Potion
*
* Precondition:
*	None
*
* Postcondition:
*	Creates the Strings
**************************************************************************************************************/
Potion::Potion() : m_name("Empty Bottle"), m_description("An Empty Bottle"), m_potency("NONE"), m_cost("0.0.0.0")
{

}

/************************************************************************************************************
* Purpose: 4 Argument Constructor
*
* Precondition:
*	4 String parameters.
*
* Postcondition:
*	Creates the Strings
**************************************************************************************************************/
Potion::Potion(String name, String description, String potency, String cost) : m_name(name), m_description(description),m_potency(potency), m_cost(cost)
{
	m_potency.Upper();
}

/************************************************************************************************************
* Purpose: Copy Constructor
*
* Precondition:
*	A Copy of a Potion
*
* Postcondition:
*	Creates the Strings
**************************************************************************************************************/
Potion::Potion(const Potion& copy) : m_name(copy.m_name), m_description(copy.m_description), m_potency(copy.m_potency), m_cost(copy.m_cost)
{
	m_potency.Upper();
}


/************************************************************************************************************
* Purpose: Move Copy Constructor
*
* Precondition:
*	A Potion (copy)
*
* Postcondition:
*	Redirects the resources.
**************************************************************************************************************/
Potion::Potion(Potion&& copy)
{
	m_name = copy.m_name;
	m_description = copy.m_description;
	m_potency = copy.m_potency;
	m_potency.Upper();
	m_cost = copy.m_cost;
	copy.m_name = nullptr;
	copy.m_description = nullptr;
	copy.m_potency = nullptr;
	copy.m_cost = nullptr;

}

/************************************************************************************************************
* Purpose: Operator = Constructor
*
* Precondition:
*	Values for the Right Hand Side Potion.
*
* Postcondition:
*	Modifies the Strings.
**************************************************************************************************************/
Potion& Potion::operator=(Potion& rhs)
{
	if (this != &rhs)
	{
		m_name = rhs.m_name;
		m_description = rhs.m_description;
		m_potency = rhs.m_potency;
		m_cost = rhs.m_cost;
		m_potency.Upper();
	}
	return *this;
}


/************************************************************************************************************
* Purpose: Move Operator
*
* Precondition:
*	A Potion (rhs).
*
* Postcondition:
*	Redirects the resources.
**************************************************************************************************************/
Potion& Potion::operator=(Potion&& rhs)
{
	{
		if (this != &rhs)
		{
			m_name = rhs.m_name;
			m_description = rhs.m_description;
			m_potency = rhs.m_potency;
			m_potency.Upper();
			m_cost = rhs.m_cost;
			rhs.m_name = nullptr;
			rhs.m_description = nullptr;
			rhs.m_potency = nullptr;
			rhs.m_cost = nullptr;
		}
		return *this;
	}

}

/************************************************************************************************************
* Purpose: Destructor
*
* Precondition:
*	Previously created Potion
*
* Postcondition:
*	Destroys the Potion
**************************************************************************************************************/
Potion::~Potion()
{

}

/************************************************************************************************************
* Purpose: Setter for name String.
*
* Precondition:
*	A String Paramter
*
* Postcondition:
*	Sets the Value of the String.
**************************************************************************************************************/
void Potion::setname(String name)
{
	m_name = name;
}

/************************************************************************************************************
* Purpose: Setter for description String.
*
* Precondition:
*	A String paramter.
*
* Postcondition:
*	Sets Value of String.
**************************************************************************************************************/
void Potion::setdescription(String description)
{
	m_description = description;
}

/************************************************************************************************************
* Purpose: Setter for Potency
*
* Precondition:
*	A String parameter.
*
* Postcondition:
*	Sets the String value.
**************************************************************************************************************/
void Potion::setpotency(String potency)
{
	m_potency = potency;
	m_potency.Upper();
}

/************************************************************************************************************
* Purpose: Setter for cost.
*
* Precondition:
*	A String parameter.
*
* Postcondition:
*	Sets the String value.
**************************************************************************************************************/
void Potion::setcost(String cost)
{
	m_cost = cost;
}

/************************************************************************************************************
* Purpose: Getter for name.
*
* Precondition:
*	None
*
* Postcondition:
*	Returns the name String.
**************************************************************************************************************/
const String Potion::getname() const
{
	return m_name;
}

/************************************************************************************************************
* Purpose: Getter for description.
*
* Precondition:
*	None
*
* Postcondition:
*	Returns the description String.
**************************************************************************************************************/
const String Potion::getdescription() const
{
	return m_description;
}

/************************************************************************************************************
* Purpose: Getter for potency.
*
* Precondition:
*	None
*
* Postcondition:
*	Returns potency String.
**************************************************************************************************************/
const String Potion::getpotency() const
{
	return m_potency;
}

/************************************************************************************************************
* Purpose: Getter for cost
*
* Precondition:
*	None
*
* Postcondition:
*	Returns cost String.
**************************************************************************************************************/
const String Potion::getcost() const
{
	return m_cost;
}

/************************************************************************************************************
* Purpose: Displays the Potion.
*
* Precondition:
*	None
*
* Postcondition:
*	Displays the data in the potion.
**************************************************************************************************************/
void Potion::display()
{
	int coin = 4;
	cout << "Name: " << m_name.getString() << endl;
	cout << "Description: " << m_description.getString() << endl;
	cout << "Potency: " << m_potency.getString() << endl;
	cout << "Cost: ";
	for (int i = 0; i < m_cost.Length(); i++)
	{
		if (m_cost.getString()[i] != '.')
		{
			cout << m_cost.getString()[i];
		}
		else
		{
			coin -= 1;
			switch (coin)
			{
			case 1:
			{
				cout << " Silver ";

			}
			break;
			case 2:
			{
				cout << " Gold ";
			}
			break;
			case 3:
			{
				cout << " Platinum ";
			}
			break;
			}
		}

	}
	cout << " Copper\n" << endl;
}

/************************************************************************************************************
* Purpose: Converts the cost String into an integer of the value in copper.
*
* Precondition:
*	None
*
* Postcondition:
*	Returns an integer.
**************************************************************************************************************/
int Potion::convert()
{
	int count = 7;
	int total = 0;
	int value = 0;
	int digit = 1;
	for (int i = 0; i < m_cost.Length(); i++)
	{
		if (m_cost.getString()[i] != '.')
		{
			if (digit == 1)
			{
				if (m_cost.getString()[i + 1] == '.' || m_cost.getString()[i + 1] == NULL)
				{
					digit = 2;
					count -= 1;
				}
			}
			value = (m_cost.getString()[i] - 48) * (pow(10, count));
			total += value;
			count--;
		}
		if (digit == 2)
		{
			digit = 1;
		}
		else if (m_cost.getString()[i] != '.')
		{
			digit = 2;
		}
	}
	return total;
}

/************************************************************************************************************
* Purpose: Resets Values after the potion is drunk.
*
* Precondition:
*	Potion
*
* Postcondition:
*	Sets the potion to default.
**************************************************************************************************************/
void Potion::drink()
{
	m_name = "Empty Bottle";
	m_description = "An Empty Bottle";
	m_potency = "NONE";
	m_cost = "0.0.0.0";
}

