/*
 * VipCustomer_test.cpp
 *
 *  Created on: Feb 15, 2018
 *      Author: vpuyf
 */

#include "VipCustomer.h"
#include <iostream>
using namespace std;

int main(){
	cout<<"\tVipCustomer Driver\n";

	//Creating customers
	VipCustomer *cust1 = new VipCustomer();
	VipCustomer*cust2 = new VipCustomer(10,"Donald","1234 Granville Street","222 213-6598");


	//Printing info
	cout<<*cust1<<endl
		<<*cust2<<endl;


	//Using the setters
	cust1->setName("newName");
	cust1->setAddress("newAddress");
	cust1->setCustomerId(20);
	VipCustomer::setMaxRental(99);
	cust1->setTel("111 111 1111");


	//Printing info using the getters
	cout<<"\nPrinting info using getters\n";
	cout<<"\nName:\t"			<<cust1->getName()
		<<"\nAddress:\t"		<<cust1->getAddress()
		<<"\nID:\t"				<<cust1->getCustomerID()
		<<"\nRental period:\t"  <<VipCustomer::getMaxRental()
		<<"\nTel:\t"			<<cust1->getTel();



	return 0;
}
