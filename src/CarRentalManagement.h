/*
 * CarRentalManagement.h
 *
 *  Created on: Feb 21, 2018
 *
 *
 *
 *     Now it is safe to assume than a car can be rented by only one customer at a time,
 *     but can a customer rent multiple cars at once??
 */

#ifndef CARRENTALMANAGEMENT_H_
#define CARRENTALMANAGEMENT_H_

#include "Car.h"
#include "CorporateCustomer.h"
#include "VipCustomer.h"
#include <list>
#include <iostream>
using namespace std;

class CarRentalManagement {
	list<VipCustomer> listCustomer;
	list<Car> listCar;
public:
	CarRentalManagement();
	virtual ~CarRentalManagement();

	//					Car Functions
	void addCar(string type, int id);
	void removeCar(const Car&);
	void rentCar();
	void returnCar();
	void isRented(const Car&);
	string getTypeRentedCar(const Car&);

	//					Customer Functions
	void addCustomer();
	void removeCustomer();
	int getCustomerPrivilege();
	void changePrivilege(int);
	void isRenting(const Customer&);
	string getCustomerRank(const Customer&);

};

#endif /* CARRENTALMANAGEMENT_H_ */
