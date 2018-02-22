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
 ********** addCar() 		adds car to list<car>
 ********** removeCar()
 ********** addCustomer() 	to list<Customer>
 ********** removeCustomer()
 ********** rentCar() 		assigns car to customer
 ********** returnCar() 	takse car back from customer
 ********** getCustomerPrivilege()  returns maxRentalPeriod
 ********** changePrivilege() just changes the maxRentalPeriod
 ********** isRented() 	applies to a car
 ********** isRenting()	applies to a customer
 ********** getCustomerRank() 	returns either regular OR corporate OR VIP
 ********** getTypeRentedCar() 	calls on a CORPORATE customer returns the types of car he rented
 *
 *
 * */
#ifndef CAR_H_
#define CAR_H_

class Customer; //forward declaration, get errors if i use //#include "Customer.h"
#include<string>
#include<iostream>

using namespace std;


class Car {
	string type;
	int id;
	bool isAvailable;
	friend ostream& operator<<(ostream&, const Car&);
	Customer* whoIsRenting;
public:

	Car(string = "regular", int = 0);	//default and parameter constructor
	Car(const Car&);					//copy constructor
	~Car();								//destructor

	///////////////Setters Getters//////////////
	void setID(int);
	void setType(string);
	void setAvailability(bool);

	int getID()const;
	bool getAvailability()const;
	string getType()const;
	Customer& getCustomer()const; //return by reference

	///////////		operator overloads    //////////////
	bool operator==(const Car&) const;
	bool operator!=(const Car& c)const{return !(Car::operator==(c));};

};

#endif /* CAR_H_ */
