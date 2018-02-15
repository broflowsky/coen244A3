/*
 * Car.h
 *
 *  Created on: Feb 14, 2018
 *      Author: vpuyf
 *
 *
 * Customer can only rent Car type regular
 * Corporate and VIP rent Car type regular AND luxe
 *
 *
 * Functions to implement
 ********** addCar() add car to inventory
 *
 *
 * */
#ifndef CAR_H_
#define CAR_H_
#include<string>
#include<iostream>
using namespace std;


class Car {
	string type;
	int id;
	bool isAvailable;
	friend ostream& operator<<(ostream&, const Car&);
public:

	Car(string = "regular", int = 0);
	~Car();

	///////////////Setters Getters//////////////
	void setID(int);
	void setType(string);
	void setAvailability(bool);

	int getID()const;
	bool getAvailability()const;
	string getType()const;
	///////////////////////////////////////////

};

#endif /* CAR_H_ */
