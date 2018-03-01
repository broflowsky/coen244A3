/*
 * CarRentalManagement_test.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: vpuyf
*/

#include "CarRentalManagement.h"
#include <iostream>
#include <string>
using namespace std;

#ifndef KEEP_LIVE					//class for keeping console open after the end of execution
#define KEEP_LIVE
class KeepAlive
{
public:
	KeepAlive(){};
	~KeepAlive() {
		std::cout << "\nPress enter to exit.";
		std::cin.get();
	};
};
#endif
//NOTE Car types: Regular, Luxury CASE SENSITIVE
int main(){


	KeepAlive k; // for final .exe console program

	CarRentalManagement *Coen244CarCompany = new CarRentalManagement();

	cout<<"Car Rental Management System Driver\n";

	//printing info about the company
	cout<<*Coen244CarCompany;


	//adding customers
	cout<<"\n\nadding customers";
	Coen244CarCompany->addCustomer(1,"Valentin", "Montreal", "0123456789",false);						//regular customer
	Coen244CarCompany->addCustomer(2,"Arseniy", "Toronto", "321654687", "The Pirate Bay","Somewhere");	//corporate customer
	Coen244CarCompany->addCustomer(3, "Barack", "United-States", "032 5351 3", true);					//Vip custmer	


	//adding Cars
	cout<<"\nadding cars";
	Coen244CarCompany->addCar("Regular", 3);
	Coen244CarCompany->addCar("Luxury", 10);
	Coen244CarCompany->addCar("Regular", 21);


	//printing info about the company
	cout<<endl<<*Coen244CarCompany;


	//printing info about customers
	cout<<"\n\nprinting info about customers:"
		<<*Coen244CarCompany->findCustomer("Valentin")<<endl 	//finding customer by name
		<<*Coen244CarCompany->findCustomer(2)<<endl				//finding customer by ID number
		<<*Coen244CarCompany->findCustomer("Barack")<<endl;


	//printing info about cars
	cout<<"\nprinting info about cars:"
		<<*Coen244CarCompany->getCar(3)
		<<*Coen244CarCompany->getCar(10)
		<<*Coen244CarCompany->getCar(21);


	//renting Cars
	cout<<"\nRenting cars:";
	Coen244CarCompany->rentCar(2,21);	//corporate customer renting a regular car
	cout<<"\n\nTrying to make an illegal rent (customer does not have the privileges):";
	Coen244CarCompany->rentCar(Coen244CarCompany->findCustomer("Valentin"),Coen244CarCompany->getCar(10)); //regular customer renting a luxury car: program should NOT let it happen


	//testing if customer is renting
	cout<<"\nChecking if a customers are renting:"
		<<"\nIs "<<Coen244CarCompany->findCustomer(2)->getName()<<" renting ? "
		<<(Coen244CarCompany->isRenting(*Coen244CarCompany->findCustomer(2))?"yes.\n":"no.\n")
		<<"\nIs "<<Coen244CarCompany->findCustomer(1)->getName()<<" renting ? "
		<<(Coen244CarCompany->isRenting(*Coen244CarCompany->findCustomer(1))?"yes.\n":"no.\n");


	//testing if cars are rented
	cout<<"\nChecking if cars are rented"
		<<"\nIs Car ID" <<*Coen244CarCompany->getCar(10)<< " rented ? "
		<<(Coen244CarCompany->isRented(*Coen244CarCompany->getCar(10))?"yes.\n":"\nno.");

	//Returning the car rented
	cout<<"\n\nReturning a car";
	Coen244CarCompany->returnCar(Coen244CarCompany->findCustomer(2));

	//testing removeCar()
	cout << "\n\nRemoving car.ID = 3";
	Coen244CarCompany->removeCar(*Coen244CarCompany->getCar(3));
	Coen244CarCompany->print(cout);



	//printing the maximum rental periods (privileges) for each class
	cout<<"\n\nNow getting the maximum rental periods of all types of customers.\n"
		<<"Regular: "<<Coen244CarCompany->getCustomerPrivilege(*Coen244CarCompany->findCustomer(1))
		<<"\nCorporate: "<<Coen244CarCompany->getCustomerPrivilege(*Coen244CarCompany->findCustomer(2))
		<<"\nVip: "<<Coen244CarCompany->getCustomerPrivilege(*Coen244CarCompany->findCustomer(3));


	//changing the privileges of each classes
	//using either an instance of each class to specify which privilege to modify or a string specifying the type
	cout<<"\n\nChanging the maximum rental period to 30,50,60:\n";

	Coen244CarCompany->changePrivilege(30,*Coen244CarCompany->findCustomer("Valentin"));  	//customer Valentin is of type regular
	Coen244CarCompany->changePrivilege(50,*Coen244CarCompany->findCustomer("Arseniy"));		//customer Arseniy is of type corporate
	Coen244CarCompany->changePrivilege(60,"vip");											//using the overloaded function

	//printing the updated privileges
	cout<<"\nNow getting the maximum rental periods of all types of customers:\n"
		<<"Regular: "<<Coen244CarCompany->getCustomerPrivilege(*Coen244CarCompany->findCustomer(1))
		<<"\nCorporate: "<<Coen244CarCompany->getCustomerPrivilege(*Coen244CarCompany->findCustomer(2))
		<<"\nVip: "<<Coen244CarCompany->getCustomerPrivilege(*Coen244CarCompany->findCustomer(3));

	//removing a customer
	cout<<"\n\nRemoving customer id=3";
	Coen244CarCompany->removeCustomer(3);

	//printing info about the company
	cout<<endl<<*Coen244CarCompany;

	cout <<"\n\nChecking that the customer was removed.";
	cout <<(Coen244CarCompany->findCustomer(3)==nullptr?"\nCustomer was erased.":"\nCustomer is still here!");




	return 0;
}
