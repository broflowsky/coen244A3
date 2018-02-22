/*
 * VipCustomer.cpp
 *
 *  Created on: Feb 15, 2018
 *      Author: vpuyf
 */

#include "VipCustomer.h"
#include <string>
#include <iostream>
using namespace std;

int VipCustomer::maxRentalPeriod=45;
VipCustomer::VipCustomer(int id,string name,string address,string tel)
						:Customer(id,name,address,tel){
}
VipCustomer::VipCustomer(const VipCustomer &c):Customer(c){
	//nothing to do for now
}
VipCustomer::~VipCustomer() {
}
void VipCustomer::print(ostream& out)const{
	Customer::print(out);
	out<<"\nCustomer is Vip.";
}
void VipCustomer::setMaxRental(int newMax){
	maxRentalPeriod = newMax;
}
int VipCustomer::getMaxRental(){		//cant have const qualifier
	return maxRentalPeriod;
}
