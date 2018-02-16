/*
 * CorporateCustomer_test.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: vpuyf
 */

#include "CorporateCustomer.h"

#include<iostream>
using namespace std;
int main(){

	Customer* c = new Customer();
	CorporateCustomer* cc = new CorporateCustomer();

	cout<<c->getMaxRental()<<endl<<cc->getMaxRental()<<endl
			<<*c<<endl<<*cc;
	return 0;
}
