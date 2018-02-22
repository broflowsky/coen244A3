/*
 * Customer.h
 *
 *  Created on: Feb 14, 2018
 *      Author: vpuyf
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

class Car;
#include <string>
using namespace std;

class Customer {
friend ostream& operator<<(ostream& ,const Customer&);
protected:
	int customerId;
	string name;
	string address;
	string tel;
	static int maxRentalPeriod; // children classes get different values
	Car* carRented;

public:
	Customer(int =0,string="_name",string="_address",string="_tel"); //default and parameter constructors
	Customer(const Customer&); 					//copy constructor
	virtual ~Customer();						//destructor
	virtual void print(ostream&)const;

//////////////   SETTERS    ///////////////////////
	void setCustomerId(int);
	void setName(string);
	void setAddress(string);
	void setTel(string);
	static void setMaxRental(int);

//////////////   GETTERS    ///////////////////////
	int getCustomerID()const;
	string getName()const;
	string getAddress()const;
	string getTel()const;
	static int getMaxRental();	//cannot have const qualifier
	Car& getCar()const;			//return by reference

};
#endif /* CUSTOMER_H_ */
