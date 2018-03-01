/*
 * Regular.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: vpuyf
 */

#include <iostream>

#include "Regular.h"
using namespace std;


int Regular::maxRentalPeriod = 20;


Regular::Regular(int id,string name,string address,string tel):Customer(id,name,address,tel) {
	//TODO

}
Regular::Regular(const Regular &c):Customer(c){

}
Regular::~Regular() {
	//~Customer();
}
void Regular::print(ostream& out)const{

	out <<"\nRegular Info"
		<<"\n\tname: "<<name
		<<"\n\taddress: "<<address
		<<"\n\ttel: "<<tel
		<<"\n\tis renting a car: "<<(carRented == nullptr?"no":"yes");
}
//////////////////////////////////////////
////////////     SET     /////////////////
void Regular::setCustomerId(int id){
	customerId=id;
}
void Regular::setName(string name){
	this->name=name;
}
void Regular::setAddress(string address){
	this->address=address;
}
void Regular::setTel(string tel){
	this->tel=tel;
}
void Regular::setMaxRental(int newMax){
	maxRentalPeriod = newMax;
}
void Regular::setCar(Car*car)
{
	this->carRented = car;
}
//////////////////////////////////////////
////////////     GET     /////////////////
int Regular::getCustomerID()const{
	return customerId;
}
string Regular::getName()const{
	return name;
}
string Regular::getAddress()const{
	return address;
}
string Regular::getTel()const{
	return tel;
}
int Regular::getMaxRental(){
	return maxRentalPeriod;
}
Car& Regular::getCar() const
{
	return *this->carRented;
}
/////////////////////////////////////////
