/*
 * Regular.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: VALENTIN PUYFOURCAT 40001780
 *      		Arseniy Ivanov 26641512
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

}
void Regular::print(ostream& out)const{

	out <<"\nCustomer Info"
		<<"\n\tname: "<<name
		<<"\n\taddress: "<<address
		<<"\n\ttel: "<<tel
		<<"\n\tis renting a car: "<<(carRented == nullptr?"no":"yes");
}
void Regular::setMaxRental(int newMax){
	maxRentalPeriod = newMax;
}
int Regular::getMaxRental(){
	return maxRentalPeriod;
}
