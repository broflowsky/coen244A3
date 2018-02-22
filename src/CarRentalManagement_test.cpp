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
	KeepAlive() {};
	~KeepAlive() {
		std::cout << "\nPress enter to exit.";
		std::cin.get();
	};
};
#endif

int main(){
	KeepAlive k{}; // for VS users
	CarRentalManagement *Coen244CarCompany = new CarRentalManagement();

	cout<<"Car Rental Management System Driver"<<endl;
	/////////////////////////////////////TESTING CAR //////////////////////////////
	cout << "\n\t\tTESTING CAR CLASS";//NOTE we have dedicated drivers for testing those functions
	///////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////TESTING CUSTOMER /////////////////////////
	cout << "\n\n\n\t\tTESTING CUSTOMER CLASS";
	///////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////TESTING CRM /////////////////////////////
	cout << "\n\n\n\t\tTESTING CRM CLASS\n";
	Coen244CarCompany->addCustomer(1,"Valentin", "Montreal", "0123456789",false);						//regular customer
	Coen244CarCompany->addCustomer(2,"Arseniy", "Toronto", "321654687", "The Pirate Bay","Somewhere");	//corporate customer	
																										//NOTE they use to be in a bunker somewhere in europe. they were smart enough to declare to be a sovereign cuntry. it all changed after the raid.
	Coen244CarCompany->addCustomer(3, "Barack", "United-States", "032 5351 3", true);					//Vip custmer	
																										//NOTE isn't he from Kenia?

	cout	<<*Coen244CarCompany->findCustomer("Valentin")<<endl
			<<*Coen244CarCompany->findCustomer(2)<<endl
			<<*Coen244CarCompany->findCustomer("Barack")<<endl;

	cout	<<"\nNow getting the maximum rental periods of all types of customers.\n"
			<<"Regular: "<<Coen244CarCompany->getCustomerPrivilege(*Coen244CarCompany->findCustomer(1))
			<<"\nCorporate: "<<Coen244CarCompany->getCustomerPrivilege(*Coen244CarCompany->findCustomer(2))
			<<"\nVip: "<<Coen244CarCompany->getCustomerPrivilege(*Coen244CarCompany->findCustomer(3));

	cout	<<"\n\nChanging the maximum rental period to to 30,50,60:\n";
			Coen244CarCompany->changePrivilege(30,*Coen244CarCompany->findCustomer("Valentin"));
			Coen244CarCompany->changePrivilege(50,*Coen244CarCompany->findCustomer("Arseniy"));
			Coen244CarCompany->changePrivilege(60,*Coen244CarCompany->findCustomer("Barack"));

	cout	<<"\nNow getting the maximum rental periods of all types of customers:\n"
				<<"Regular: "<<Coen244CarCompany->getCustomerPrivilege(*Coen244CarCompany->findCustomer(1))
				<<"\nCorporate: "<<Coen244CarCompany->getCustomerPrivilege(*Coen244CarCompany->findCustomer(2))
				<<"\nVip: "<<Coen244CarCompany->getCustomerPrivilege(*Coen244CarCompany->findCustomer(3));






	return 0;
}
