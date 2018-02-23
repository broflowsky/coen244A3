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
			//NOTE for now: no! it's not a democracy


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
	void removeCar(Car&);
	void rentCar(Customer*customer, Car*car);
	void returnCar(Customer*customer);
	bool isRented(const Car&);
	string getTypeRentedCar(const Car&);
	Car*getCar(int id);
	/*TODO
	 * Car* findCar*()
	 * rentCar() should: check that given customer CAN rent that car (availability, privileges)
	 * 					 update the car availability,
	 * 			 		 add that car to carRented in Customer,
	 * 			 		 add that customer to Car
	 *
	 *returnCar() should : undo the above
	 *
	 *
	 * */
	//DEBUG FUNC/////////////////
	void getListsSizes();



	//					Customer Functions
	void addCustomer(int customerID,string name,string address,string tel,bool isVip);//regular or Vip customer
	void addCustomer(int customerID,string name,string address,string tel,string companyName,string companyAddress);//overload for corporateCustomer

	void removeCustomer(string name);
	void removeCustomer(int customerId);

	//NOTE we should stick to standard convention. if func only returns an object it usually have prefix get-
	Customer* findCustomer(int customerId);
	Customer* findCustomer(string name);	// might be usefull if we want to display info about a customer

	int getCustomerPrivilege(Customer&)const;
	void changePrivilege(int newMaxRentalDuration, Customer&);

	bool isRenting(const Customer&);
	string getCustomerRank(Customer&); // cant use const since dynamic_cast

};

#endif /* CARRENTALMANAGEMENT_H_ */
