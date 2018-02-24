/*
 * CarRentalManagement_test.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: vpuyf
 */
//README
/*Car types:
	Regular
	Luxugy
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
	KeepAlive() {};
	~KeepAlive() {
		std::cout << "\nPress enter to exit.";
		std::cin.get();
	};
};
#endif

int main(){


	KeepAlive k{}; // for final .exe console program

	CarRentalManagement *Coen244CarCompany = new CarRentalManagement();

	cout<<"Car Rental Management System Driver"<<endl;

	//adding customers
	Coen244CarCompany->addCustomer(1,"Valentin", "Montreal", "0123456789",false);						//regular customer
	Coen244CarCompany->addCustomer(2,"Arseniy", "Toronto", "321654687", "The Pirate Bay","Somewhere");	//corporate customer	
																										//NOTE they use to be in a bunker somewhere in europe. they were smart enough to declare to be a sovereign cuntry. it all changed after the raid.
	Coen244CarCompany->addCustomer(3, "Barack", "United-States", "032 5351 3", true);					//Vip custmer	
																										//NOTE isn't he from Kenia?
	//testing addCar()
	Coen244CarCompany->getListsSizes();
	cout << "\nAdd a car: type: regular, ID: 3";
	Coen244CarCompany->addCar("Regular", 3);
	Coen244CarCompany->getListsSizes();
	//testing removeCar()
	cout << "\nRemoving car.ID = 3";
	Coen244CarCompany->removeCar(*Coen244CarCompany->getCar(3));		//FIXME remove car still doesn't remove
	Coen244CarCompany->getListsSizes();
	//testing rentCar()

	cout << "\n\n\n";




	//printing info about customers
	cout<<*Coen244CarCompany->findCustomer("Valentin")<<endl 	//finding customer by name
		<<*Coen244CarCompany->findCustomer(2)<<endl				//finding customer by ID number
		<<*Coen244CarCompany->findCustomer("Barack")<<endl;

	//printing the maximum rental periods (privileges) for each class
	cout<<"\nNow getting the maximum rental periods of all types of customers.\n"
		<<"Regular: "<<Coen244CarCompany->getCustomerPrivilege(*Coen244CarCompany->findCustomer(1))
		<<"\nCorporate: "<<Coen244CarCompany->getCustomerPrivilege(*Coen244CarCompany->findCustomer(2))
		<<"\nVip: "<<Coen244CarCompany->getCustomerPrivilege(*Coen244CarCompany->findCustomer(3));


	//changing the privileges of each classes
	//using either an instance of each class to specify which privilege to modify or a string specifying the type
	cout<<"\n\nChanging the maximum rental period to to 30,50,60:\n";

	Coen244CarCompany->changePrivilege(30,*Coen244CarCompany->findCustomer("Valentin"));  	//customer Valentin is of type regular
	Coen244CarCompany->changePrivilege(50,*Coen244CarCompany->findCustomer("Arseniy"));		//customer Arseniy is of type corporate
	Coen244CarCompany->changePrivilege(60,"vip");											//using the overloaded function

	//printing the updated privileges
	cout<<"\nNow getting the maximum rental periods of all types of customers:\n"
		<<"Regular: "<<Coen244CarCompany->getCustomerPrivilege(*Coen244CarCompany->findCustomer(1))
		<<"\nCorporate: "<<Coen244CarCompany->getCustomerPrivilege(*Coen244CarCompany->findCustomer(2))
		<<"\nVip: "<<Coen244CarCompany->getCustomerPrivilege(*Coen244CarCompany->findCustomer(3));






	return 0;
}
