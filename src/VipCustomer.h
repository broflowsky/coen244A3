/*
 * VipCustomer.h
 *
 *  Created on: Feb 15, 2018
 *      Author: vpuyf
 */

#ifndef VIPCUSTOMER_H_
#define VIPCUSTOMER_H_

#include "Customer.h"

class VipCustomer: public Customer{

	static int maxRentalPeriod;

public:
	//default and parameter constructor
	VipCustomer(int=0,string="_name",string="_address",string="_tel");

	//copy constructor
	VipCustomer(const VipCustomer&);

	//destructor
	virtual ~VipCustomer();

	// Setter and Getter
	static void setMaxRental(int);
	static int getMaxRental();

	//Print function
	virtual void print(ostream& out)const;
};

#endif /* VIPCUSTOMER_H_ */
