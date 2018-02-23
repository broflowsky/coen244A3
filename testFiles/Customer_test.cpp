/*
 * Customer_test.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: vpuyf
 */

#include "Customer.h"
#include <iostream>
#include <string>
using namespace std;

int main(){

	cout<<"\tCustomer Driver\n";

	//Creating customers
	Customer *cust1 = new Customer();
	Customer*cust2 = new Customer(10,"Donald","1234 Granville Street","222 213-6598");


	//Printing info
	cout<<*cust1<<endl
		<<*cust2<<endl;


	//Using the setters
	cust1->setName("newName");
	cust1->setAddress("newAddress");
	cust1->setCustomerId(20);
	Customer::setMaxRental(30);
	cust1->setTel("111 111 1111");


	//Printing info using the getters
	cout<<"\nPrinting info using getters\n";
	cout<<"\nName:\t"			<<cust1->getName()
		<<"\nAddress:\t"		<<cust1->getAddress()
		<<"\nID:\t"				<<cust1->getCustomerID()
		<<"\nRental period:\t"  <<Customer::getMaxRental()
		<<"\nTel:\t"			<<cust1->getTel();



	return 0;
}

