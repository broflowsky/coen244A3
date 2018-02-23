/*
 * CarRentalManagement.h
 *
 *  Created on: Feb 21, 2018
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

	void getListsSizes();//NOTE what it really does is printing the inventory void printInventory()?
	//					Car Functions
	void addCar(string type, int id);

	void removeCar(Car&);
	void removeCar(int id);

	void rentCar(Customer*,Car*);
	void rentCar(int customerId, int carId);

	Car* getCar(int id);

	void returnCar(Customer*customer);
	bool isRented(const Car&);
	string getTypeRentedCar(const Car&);

	//					Customer Functions
	void addCustomer(int customerID,string name,string address,string tel,bool isVip);//regular or Vip customer
	void addCustomer(int customerID,string name,string address,string tel,string companyName,string companyAddress);//overload for corporateCustomer

	void removeCustomer(string name);
	void removeCustomer(int customerId);

	//NOTE the get and set applies really just to the data members. these functions do more than that, and it d be confusing
	Customer* findCustomer(int customerId);
	Customer* findCustomer(string name);

	int getCustomerPrivilege(Customer&)const;
	void changePrivilege(int newMaxRentalDuration, Customer&);
	void changePrivilege(int newMaxRentalDuration, string type);

	bool isRenting(const Customer&);
	string getCustomerRank(Customer&);

};

#endif /* CARRENTALMANAGEMENT_H_ */
