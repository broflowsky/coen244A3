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
private:
	list<Customer*> listCustomer;	//dynamic binding
	list<Car> listCar;				//static binding
public:
	CarRentalManagement();
	virtual ~CarRentalManagement();

	//					Car Functions
	void addCar(string type, int id);
	void removeCar(const Car&);
	void rentCar(Customer*customer, Car*car);
	void returnCar();
	bool isRented(const Car&);
	string getTypeRentedCar(const Car&);


	//					Customer Functions
	void addCustomer(int customerID,string name,string address,string tel,bool isVip);//regular or Vip customer
	void addCustomer(int customerID,string name,string address,string tel,string companyName,string companyAddress);//overload for corporateCustomer

	void removeCustomer(string name);
	void removeCustomer(int customerId);

	Customer* findCustomer(int customerId);
	Customer* findCustomer(string name);	// might be usefull if we want to display info about a customer

	int getCustomerPrivilege(const Customer&);
	void changePrivilege(int newMaxRentalDuration, int customerType);// 0 reg, 1 corporate, 2 Vip
	bool isRenting(const Customer&);
	string getCustomerRank(const Customer&);

};

#endif /* CARRENTALMANAGEMENT_H_ */
