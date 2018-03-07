/*
 * CorporateCustomer.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: VALENTIN PUYFOURCAT 40001780
 *      		Arseniy Ivanov 26641512
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
	out <<"\n\tCompany name: "<<companyName
		<<"\n\tCompany address: "<<companyAddress;

}
//////////////////////////////////////////
////////////     SET     /////////////////
void CorporateCustomer::setCompanyAddress(string address){
	this->companyAddress=address;
}
void CorporateCustomer::setCompanyName(string name){
	this->companyName=name;
}
void CorporateCustomer::setMaxRental(int newMax){
	maxRentalPeriod = newMax;
}
//////////////////////////////////////////
////////////     GET     /////////////////
string CorporateCustomer::getCompanyName()const{
	return companyName;
}
string CorporateCustomer::getCompanyAddress()const{
	return companyAddress;
}
int CorporateCustomer::getMaxRental(){
	 return maxRentalPeriod;
 }
//////////////////////////////////////////

