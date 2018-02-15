/*
 * Car.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: vpuyf
 */

#include "Car.h"
ostream& operator<<(ostream& out, const Car& c){

	 out <<"###################################"
		 <<"\n\tCar Info"
		 <<"\nCar type: "<<c.type
		 <<"\nID:"<<c.id
		 <<"\nThis car is "<<(c.isAvailable?"available.":"not available.");
	return out;
}
Car::Car(string type, int id){
	this->type=type;
	this->id=id;
	isAvailable = true;

}
Car::~Car() {
	// TODO Auto-generated destructor stub
}
void Car::setAvailability(bool available){
	isAvailable=available;
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
