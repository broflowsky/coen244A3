/*
 * regular.h
 *
 *  Created on: Mar 1, 2018
 *      Author: vpuyf
 */

#ifndef REGULAR_H_
#define REGULAR_H_

#include "Customer.h"
#include <string>
using namespace std;

class Regular: public Customer {
	static int maxRentalPeriod; // children classes get different values
public:
	Regular(int =0,string="_name",string="_address",string="_tel");
	Regular(const Regular&);
	virtual ~Regular();
	virtual void print(ostream&)const;

	void setCustomerId(int);
	void setName(string);
	void setAddress(string);
	void setTel(string);
	static void setMaxRental(int);
	void setCar(Car*);

//////////////   GETTERS    ///////////////////////
	int getCustomerID()const;
	string getName()const;
	string getAddress()const;
	string getTel()const;
	static int getMaxRental();	//cannot have const qualifier
	Car& getCar()const;			//return by reference
};

#endif /* REGULAR_H_ */
