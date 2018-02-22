/*
 * Car.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: vpuyf
 */

#include "Car.h"
#include <iostream>
using namespace std;
ostream& operator<<(ostream& out, const Car& c){

	 out <<"\n\tCar Info"
		 <<"\nCar type: "<<c.type
		 <<"\nID:"<<c.id
		 <<"\nThis car is "<<(c.isAvailable?"available.":"not available.");
	return out;
}
bool Car::operator==(const Car& c)const{
	if(&c != this){//check self assignment
		if(id != c.id)
			return false;
		if(isAvailable != c.isAvailable)
			return false;
		if(type != c.type)
			return false;
	}
	return true;
}
Car::Car(string type, int id){
	this->type=type;
	this->id=id;
	isAvailable = true;
	whoIsRenting = nullptr;

}
Car::Car(const Car& c){
	type = c.type;
	id = c.id;
	isAvailable = c.isAvailable;
	whoIsRenting = c.whoIsRenting;
}
Car::~Car() {
	delete whoIsRenting;
}
void Car::setAvailability(bool available){
	isAvailable=available;
}
void Car::setCustomer(Customer *customer)
{
	this->whoIsRenting = customer;
}
void Car::setID(int id){
	this->id=id;
}
void Car::setType(string type){
	this->type=type;
}
int Car::getID()const{
	return id;
}
bool Car::getAvailability()const{
	return isAvailable;
}
string Car::getType()const{
	return type;
}
Customer& Car::getCustomer()const{
	//damn you, precedence!
	return *this->whoIsRenting;	//we might want to make a copy of that customer and return it
}
