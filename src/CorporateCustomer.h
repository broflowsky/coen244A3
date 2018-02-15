/*
 * CorporateCustomer.h
 *
 *  Created on: Feb 14, 2018
 *      Author: vpuyf
 */

#ifndef CORPORATECUSTOMER_H_
#define CORPORATECUSTOMER_H_

#include "Customer.h"

class CorporateCustomer: public Customer {
	string companyName;
	string companyAddress;
	static int maxRentalPeriod;
public:
	CorporateCustomer(int=0,string="_name",string="_address",string="_tel",
					string="_companyName",string="_companyAddress");
	virtual ~CorporateCustomer();
	virtual void print(ostream&)const;

	void setCompanyName(string);
	void setCompanyAddress(string);
	string getCompanyName()const;
	string getCompanyAddress()const;
	virtual int getMaxRental()const;
};
#endif /* CORPORATECUSTOMER_H_ */
