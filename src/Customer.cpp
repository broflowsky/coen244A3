/*
 * Customer.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: vpuyf
 */

#include "Customer.h"

Customer::Customer(int id,string name,string address,string tel) {
	customerId =id;
	this->name = name;
	this->address = address;
	this->tel = tel;

}

Customer::~Customer() {
	// TODO Auto-generated destructor stub
}

