/*
 * VipCustomer.h
 *
 *  Created on: Feb 15, 2018
 *      Author: vpuyf
 */

#ifndef VIPCUSTOMER_H_
#define VIPCUSTOMER_H_

#include "Customer.h"

class VipCustomer: public Customer {
	static int maxRentalPeriod;
public:
	VipCustomer(int=0,string="_name",string="_address",string="_tel"); //default and parameter constructor
	VipCustomer(const VipCustomer&);		//copy constructor
	virtual ~VipCustomer();					//destructor


	virtual void print(ostream& out)const;
	virtual int getMaxRental()const;
};

#endif /* VIPCUSTOMER_H_ */
