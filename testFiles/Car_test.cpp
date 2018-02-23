/*
 * Car_test.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: vpuyf
 */

#include "Car.h"
#include <iostream>

using namespace std;


int main(){


	cout<<"\tCar Driver\n";

	//Creating Car instances
	Car*c1 = new Car();
	Car*c2 = new Car("Luxe",1000);
	Car*c3 = new Car(*c2);


	//Printing cars info
	cout<<*c1<<endl
		<<*c2<<endl
		<<*c3<<endl;

	//Using setters
	c1->setID(100);
	c1->setAvailability(false);
	c1->setType("luxe");

	//Printing info using the getters
	cout<<"\nPrinting info updated car\n";
	cout<<"\nID:\t"				<<c1->getID()
		<<"\nType:\t"			<<c1->getType()
		<<"\nAvailability:\t"	<<(c1->getAvailability()?"available":"rented");


	return 0;
}

