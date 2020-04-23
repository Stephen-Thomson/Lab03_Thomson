#include <iostream>
using std::cout;
using std::endl;
#include "PotionCase.h"



/************************************************************************************************************
* Purpose: Creates Default PotionCase
*
* Precondition:
*	None
*
* Postcondition:
*	Creates an empty case.
**************************************************************************************************************/
PotionCase::PotionCase() : m_array(nullptr), m_elements(0)
{

}


/************************************************************************************************************
* Purpose: Copy Constructor.
*
* Precondition:
*	Potion Case
*
* Postcondition:
*	Sets the value of the copy.
**************************************************************************************************************/
PotionCase::PotionCase(const PotionCase& copy)
{
	m_array = copy.m_array;
	m_elements = copy.m_elements;
}


/************************************************************************************************************
* Purpose: Move Copy
*
* Precondition:
*	Potion Case
*
* Postcondition:
*	Redirects resources.
**************************************************************************************************************/
PotionCase::PotionCase(PotionCase&& copy)
{
	m_array = copy.m_array;
	m_elements = copy.m_elements;
	copy.m_array = nullptr;
}


/************************************************************************************************************
* Purpose: Operator Constructor
*
* Precondition:
*	Potion Case
*
* Postcondition:
*	Potion Case created.
**************************************************************************************************************/
PotionCase& PotionCase::operator=(PotionCase& rhs)
{
	if (this != &rhs)
	{
		m_array = rhs.m_array;
		m_elements = rhs.m_elements;
	}
	return *this;
}


/************************************************************************************************************
* Purpose: Move Operator
*
* Precondition:
*	Potion Case
*
* Postcondition:
*	Redirects resources.
**************************************************************************************************************/
PotionCase& PotionCase::operator=(PotionCase&& rhs)
{
	if (this != &rhs)
	{
		delete[] m_array;
		m_array = rhs.m_array;
		m_elements = rhs.m_elements;
		rhs.m_array = nullptr;
	}
	return *this;
}


/************************************************************************************************************
* Purpose: Dtor
*
* Precondition:
*	None
*
* Postcondition:
*	Deletes PotionCase
**************************************************************************************************************/
PotionCase::~PotionCase()
{
	for (int i = 0; i < m_elements; i++)
	{
		delete[] m_array[i];
	}
	delete[] m_array;
}


/************************************************************************************************************
* Purpose: Getter for Elements
*
* Precondition:
*	None
*
* Postcondition:
*	Returns the value in Elements
**************************************************************************************************************/
int PotionCase::GetElements() const
{
	return m_elements;
}


/************************************************************************************************************
* Purpose: Adds a Potion to the Case.
*
* Precondition:
*	Potion
*
* Postcondition:
*	Adds a potion to the array.
**************************************************************************************************************/
void PotionCase::Insert(const Potion& toadd)
{
	Potion** Temp = nullptr;
	Temp = new Potion * [m_elements + 1];
	for (int i = 0; i < m_elements; i++)
	{
		Temp[i] = m_array[i];
	}
	Temp[m_elements] = new Potion[1];
	Temp[m_elements]->setname(toadd.getname());
	Temp[m_elements]->setdescription(toadd.getdescription());
	Temp[m_elements]->setpotency(toadd.getpotency());
	Temp[m_elements]->setcost(toadd.getcost());
	delete[] m_array;
	m_array = Temp;
	m_elements += 1;
}


/************************************************************************************************************
* Purpose: Deletes a Potion.
*
* Precondition:
*	Potion
*
* Postcondition:
*	Removes a Potion from the array.
**************************************************************************************************************/
void PotionCase::Drop(const Potion& todelete)
{
	Potion** Temp = nullptr;
	int Index = 0;
	Temp = new Potion * [m_elements - 1];
	Index = Find(todelete);
	if (Index >= 0)
	{
		for (int i = 0; i < Index; i++)
		{
			Temp[i] = m_array[i];
		}
		delete[] m_array[Index];
		for (int i = Index + 1; i < m_elements; i++)
		{
			Temp[i - 1] = m_array[i];
		}
		delete[] m_array;
		m_array = Temp;
		m_elements--;
	}
	else
	{
		cout << "That potion is not in the Case." << endl;
	}
}


/************************************************************************************************************
* Purpose: Locates a specific Potion.
*
* Precondition:
*	Potion
*
* Postcondition:
*	Returns the element number of the Potion.
**************************************************************************************************************/
int PotionCase::Find(const Potion& target)
{
	int Found = -1;
	int Index = 0;
	for (int i = 0; i < m_elements; i++)
	{
		Found = strcmp(m_array[i]->getname(), target.getname());
		if (Found == 0)
		{
			Index = i;
			i = m_elements;
		}
	}
	return Index;
}


/************************************************************************************************************
* Purpose: Displays the contents of the Case.
* Precondition:
*	None
*
* Postcondition:
*	Displays Potions.
**************************************************************************************************************/
void PotionCase::Inventory() const
{
	if (m_array != nullptr)
	{
		for (int i = 0; i < m_elements; i++)
		{
			m_array[i]->display();
		}
	}
	else
	{
		cout << "The Case is Empty." << endl;
	}
}


/************************************************************************************************************
* Purpose: Alters an Empty Potion
*
* Precondition:
*	New Potion
*
* Postcondition:
*	Alters the values of a default Potion.
**************************************************************************************************************/
void PotionCase::FillEmpty(Potion Newpotion)
{
	Potion Pot1;
	int Index = Find(Pot1);
	if (Index >= 0)
	{
		m_array[Index]->setname(Newpotion.getname());
		m_array[Index]->setdescription(Newpotion.getdescription());
		m_array[Index]->setpotency(Newpotion.getpotency());
		m_array[Index]->setcost(Newpotion.getcost());
	}
	else
	{
		cout << "You have no Empty Bottles." << endl;
	}
}


/************************************************************************************************************
* Purpose: Use a Potion from the Case.
*
* Precondition:
*	Potion
*
* Postcondition:
*	Drinks the potion.
**************************************************************************************************************/
void PotionCase::Use(Potion todrink)
{
	int Index = Find(todrink);
	if (Index >= 0)
	{
		m_array[Index]->drink();
	}
	else
	{
		cout << "You do not possess that Potion." << endl;
	}
}


