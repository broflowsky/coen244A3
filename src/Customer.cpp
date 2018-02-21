/*
 * Customer.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: vpuyf
 */

#include "Customer.h"
#include <iostream>
using namespace std;
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
	carRented = nullptr;

}
Customer::Customer(const Customer &c){
	customerId = c.customerId;
	name =c.name;
	address = c.address;
	tel = c.tel;
	carRented = c.carRented;
}
Customer::~Customer() {

}
void Customer::print(ostream& out)const{

	out <<"\tCustomer Info"
		<<"\nname: "<<name
		<<"\naddress: "<<address
		<<"\ntel: "<<tel
		<<"\nis renting a car: "<<(carRented == nullptr?"no":"yes");
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
