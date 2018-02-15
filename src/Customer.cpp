/*
 * Customer.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: vpuyf
 */

#include "Customer.h"
int Customer::maxRentalPeriod = 20;

ostream& operator<<(ostream& out, const Customer& c){
	c.print(out);
	return out;
}
Customer::Customer(int id,string name,string address,string tel) {
	customerId =id;
	this->name = name;
	this->address = address;
	this->tel = tel;

}
Customer::~Customer() {

}
void Customer::print(ostream& out)const{
	out <<"\tCustomer Info"
		<<"\name: "<<name
		<<"\address: "<<address
		<<"\ntel: "<<tel;
}
//////////////////////////////////////////
////////////     SET     /////////////////
void Customer::setCustomerId(int id){
	customerId=id;
}
void Customer::setName(string name){
	this->name=name;
}
void Customer::setAddress(string address){
	this->address=address;
}
void Customer::setTel(string tel){
	this->tel=tel;
}
//////////////////////////////////////////
////////////     GET     /////////////////
int Customer::getCustomerID()const{
	return customerId;
}
string Customer::getName()const{
	return name;
}
string Customer::getAddress()const{
	return address;
}
string Customer::getTel()const{
	return tel;
}
int Customer::getMaxRental()const{
	return maxRentalPeriod;
}
/////////////////////////////////////////
