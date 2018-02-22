/*
 * CarRentalManagement.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: vpuyf
 */

#include "CarRentalManagement.h"

CarRentalManagement::CarRentalManagement() {

}

CarRentalManagement::~CarRentalManagement() {
	listCar.clear();
	listCustomer.clear();
}

void CarRentalManagement::addCar(string type, int id)
{
	Car*newCar = new Car(type, id);
	listCar.push_back(*newCar);
	//listCar.push_back((new Car(type, id)));	//can't make it work without declaring extra pointer
}

void CarRentalManagement::removeCar(const Car &c)
{
	listCar.remove(c);							//don't know if this the right way to do it (works as is)
}

void CarRentalManagement::rentCar(Customer*customer,Car*car)
{

}

void CarRentalManagement::returnCar()
{
}

void CarRentalManagement::isRented(const Car &)
{
}

string CarRentalManagement::getTypeRentedCar(const Car &)
{
	return string();
}

void CarRentalManagement::addCustomer()
{
}

void CarRentalManagement::removeCustomer()
{
}

int CarRentalManagement::getCustomerPrivilege()
{
	return 0;
}

void CarRentalManagement::changePrivilege(int)
{
}

void CarRentalManagement::isRenting(const Customer &)
{
}

string CarRentalManagement::getCustomerRank(const Customer &)
{
	return string();
}

