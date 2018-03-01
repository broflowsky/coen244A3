/*
 * Customer.h
 *
 *  Created on: Feb 14, 2018
 *      Author: vpuyf
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

class Car;	//forward declaration
#include <string>
using namespace std;

class Customer {
friend ostream& operator<<(ostream& ,const Customer&);
protected:
	int customerId;
	string name;
	string address;
	string tel;
	Car* carRented;

public:
	Customer(int =0,string="_name",string="_address",string="_tel"); //default and parameter constructors
	Customer(const Customer&); 					//copy constructor
	virtual ~Customer();						//destructor
	virtual void print(ostream&)const = 0;		// pure virtual

//////////////   SETTERS    ///////////////////////
	virtual void setCustomerId(int);
	virtual void setName(string);
	virtual void setAddress(string);
	virtual void setTel(string);
	virtual void setCar(Car*);

//////////////   GETTERS    ///////////////////////
	virtual int getCustomerID()const;
	virtual string getName()const;
	virtual string getAddress()const;
	virtual string getTel()const;
	virtual Car& getCar()const;			//return by reference

};
#endif /* CUSTOMER_H_ */
