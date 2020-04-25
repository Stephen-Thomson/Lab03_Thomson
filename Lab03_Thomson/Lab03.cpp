/******************************************************************************************************************************
*
* Author:		Stephen Thomson
* Filename:		Lab03.cpp
* Date Created:	4/22/2020
*
* Assignment: Lab 03: Create a Dynamic Array to hold potions
*
* Overview:
*	This program will test the functionality of the PotionCase class. It will create an array of 5 potions
*	and display them, followed by the total cost of the potions.
*
* Input:
*	None
*
* Output:
*	The values of the 5 potions in the array and the total cost of all potions.
*
********************************************************************************************************************************/
#define CRTBDG_MAP_ALLOC
#include <cmath>
#include <iostream>
using std::cout;
using std::endl;
#include "PotionCase.h"
#include <crtdbg.h>


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int Cost = 0;
	int Total = 0;
	PotionCase Mycase;
	Potion Pot1;
	Potion Pot2;
	Potion Pot3;
	Potion Pot4;
	Potion Pot5;
	Pot1.setname("Heal"); Pot1.setdescription("Adds 10 HP"); Pot1.setpotency("Normal");
	Pot1.setcost("0.5.6.15");
	Pot2.setname("Heal+"); Pot2.setdescription("Adds 50 HP"); Pot2.setpotency("Strong");
	Pot2.setcost("1.15.7.35");
	Pot3.setname("Add Poison"); Pot3.setdescription("Adds Posion to your weapon: -5hp/sec"); Pot3.setpotency("Normal");
	Pot3.setcost("0.11.16.5");
	Pot4.setname("Strength"); Pot4.setdescription("Adds 25 to Damage"); Pot4.setpotency("Normal");
	Pot4.setcost("1.35.9.5");
	Pot5.setname("Invincibility"); Pot5.setdescription("Invincible for 60 seconds"); Pot5.setpotency("Strong");
	Pot5.setcost("16.25.36.76");

	Mycase.Insert(Pot1);
	Mycase.Insert(Pot2);
	Mycase.Insert(Pot3);
	Mycase.Insert(Pot4);
	Mycase.Insert(Pot5);

	cout << "First 5 added to the case: " << endl;
	Mycase.Inventory();

	Potion Pot6;
	Pot6.setname("Fire Resistance"); Pot6.setdescription("25% to Fire Reistance"); Pot6.setpotency("Normal");
	Pot6.setcost("0.5.6.15");
	Mycase.Insert(Pot6);

	Mycase.Use(Pot4);
	cout << "Fire Reisistance Added, and Strength Drunk: " << endl;
	Mycase.Inventory();

	Potion Pot7;
	Pot7.setname("Cold Resistance"); Pot7.setdescription("25% to Cold Reistance"); Pot7.setpotency("Normal");
	Pot7.setcost("0.5.6.15");
	Mycase.FillEmpty(Pot7);
	cout << "Cold Resistance Filled the Empty Bottle: " << endl;
	Mycase.Inventory();

	cout << Pot1 << endl;

}




