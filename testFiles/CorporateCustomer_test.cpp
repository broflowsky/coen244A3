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

	cout<<"\tCorporateCustomer Driver\n";

	//Creating customers
	CorporateCustomer *cust1 = new CorporateCustomer();
	CorporateCustomer*cust2 = new CorporateCustomer(10,"Donald","1234 Granville Street","222 213-6598","DonaldEntertainment","1234 Baker Street");


	//Printing info
	cout<<*cust1<<endl
		<<*cust2<<endl;


	//Using the setters
	cust1->setName("newName");
	cust1->setAddress("newAddress");
	cust1->setCompanyName("newCompanyName");
	cust1->setCompanyAddress("newCompanyAddress");
	cust1->setCustomerId(20);
	CorporateCustomer::setMaxRental(30);
	cust1->setTel("111 111 1111");


	//Printing info using the getters
	cout<<"\nPrinting info using getters\n";
	cout<<"\nName:\t"			<<cust1->getName()
		<<"\nAddress:\t"		<<cust1->getAddress()
		<<"\nCompany Name:\t"	<<cust1->getCompanyName()
		<<"\nCompany Address:\t"<<cust1->getCompanyAddress()
		<<"\nID:\t"				<<cust1->getCustomerID()
		<<"\nRental period:\t"  <<CorporateCustomer::getMaxRental()
		<<"\nTel:\t"			<<cust1->getTel();



	return 0;
}

