/*
 * Customer.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: vpuyf
 */

#include "Customer.h"
#include <iostream>
using namespace std;



ostream& operator<<(ostream& out, const Customer& c)
{														//only one overload thanks to the use of a print function
	c.print(out);										//allows in derived classes to call Base::print() and then add out<< what you need to add
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
	delete carRented;
}
void Customer::print(ostream& out)const{

	out <<"\nCustomer Info"
		<<"\n\tname: "<<name
		<<"\n\taddress: "<<address
		<<"\n\ttel: "<<tel
		<<"\n\tis renting a car: "<<(carRented == nullptr?"no":"yes");
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
void Customer::setCar(Car*car)
{
	this->carRented = car;
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
Car& Customer::getCar() const
{
	return *this->carRented;
}
/////////////////////////////////////////
