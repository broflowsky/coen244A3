/*
 * CorporateCustomer.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: vpuyf
 */

#include "CorporateCustomer.h"
#include <iostream>
using namespace std;

int CorporateCustomer::maxRentalPeriod = 35;

CorporateCustomer::CorporateCustomer(int id,string name,string address,string tel,
									string companyName,string companyAddress):
									Customer(id,name,address,tel)
{
	this->companyName=companyName;
	this->companyAddress=companyAddress;
}
CorporateCustomer::CorporateCustomer(const CorporateCustomer& c):Customer(c){
	companyName = c.companyName;
	companyAddress = c.companyAddress;
}
CorporateCustomer::~CorporateCustomer() {

}
void CorporateCustomer::print(ostream& out)const{
	Customer::print(out);
	out <<"\nCompany name: "<<companyName
		<<"\nCompany address: "<<companyAddress;

}
//////////////////////////////////////////
////////////     SET     /////////////////
void CorporateCustomer::setCompanyAddress(string address){
	this->address=address;
}
void CorporateCustomer::setCompanyName(string name){
	this->name=name;
}
void CorporateCustomer::setMaxRental(int newMax){
	maxRentalPeriod = newMax;
}
//////////////////////////////////////////
////////////     GET     /////////////////
string CorporateCustomer::getCompanyName()const{
	return name;
}
string CorporateCustomer::getCompanyAddress()const{
	return address;
}
int CorporateCustomer::getMaxRental(){
	 return maxRentalPeriod;
 }
//////////////////////////////////////////

