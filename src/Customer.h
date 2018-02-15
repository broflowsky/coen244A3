/*
 * Customer.h
 *
 *  Created on: Feb 14, 2018
 *      Author: vpuyf
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <string>
using namespace std;

class Customer {
friend ostream& operator<<(ostream& ,const Customer&);
protected:
	int customerId;
	string name;
	string address;
	string tel;
	static int maxRentalPeriod; // children classed get different values

public:
	Customer(int =0,string="_name",string="_address",string="_tel");
	virtual ~Customer();
	virtual void print(ostream&)const;

	void setCustomerId(int);
	void setName(string);
	void setAddress(string);
	void setTel(string);

	int getCustomerID()const;
	string getName()const;
	string getAddress()const;
	string getTel()const;
	virtual int getMaxRental()const;

};

#endif /* CUSTOMER_H_ */
