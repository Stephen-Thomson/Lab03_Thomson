#pragma once
/***************************************************************************************************************************
* Class: PotionCase
*
* Purpose: This object is a dynamic array of Potions.
*
* Manager Functions:
*	Default Constructor
*	Deconstructor
*	Copy Constructor
*	Move Copy
*	Operator Constructor
*	Move Operator
*
* Methods:
*	GetElements
*	Insert
*	Drop
*	Find
*	Inventory
*	FillEmpty
*	Use
*
*
****************************************************************************************************************************/
#include "Potion.h"

class PotionCase
{
	public:
		PotionCase();
		PotionCase(const PotionCase& copy);
		PotionCase(PotionCase&& copy);
		PotionCase& operator=(PotionCase& rhs);
		PotionCase& operator=(PotionCase&& rhs);
		~PotionCase();
		int GetElements() const;
		void Insert(const Potion& toadd);
		void Drop(const Potion& todelete);
		int Find(const Potion& target);
		void Inventory() const;
		void FillEmpty(Potion Newpotion);
		void Use(Potion todrink);
	private:
		Potion ** m_array;
		int m_elements;
};