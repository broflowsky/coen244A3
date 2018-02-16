/*
 * CorporateCustomer.h
 *
 *  Created on: Feb 14, 2018
 *      Author: vpuyf
 */

#ifndef CORPORATECUSTOMER_H_
#define CORPORATECUSTOMER_H_

#include "Customer.h"
#include<string>
#include<iostream>
using namespace std;

class CorporateCustomer: public Customer {
	string companyName;
	string companyAddress;
	static int maxRentalPeriod;
public:
	CorporateCustomer(int=0,string="_name",string="_address",string="_tel",
					string="_companyName",string="_companyAddress"); //default and parameter constructor
	CorporateCustomer(const CorporateCustomer&);		//copy constructor
	virtual ~CorporateCustomer();				//destructor

	virtual void print(ostream&)const;

	//////////////   SETTERS    ///////////////////////
	void setCompanyName(string);
	void setCompanyAddress(string);

	//////////////   GETTERS    ///////////////////////
	string getCompanyName()const;
	string getCompanyAddress()const;
	virtual int getMaxRental()const;
};
#endif /* CORPORATECUSTOMER_H_ */
