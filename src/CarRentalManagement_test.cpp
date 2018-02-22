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
	KeepAlive k{};

	CarRentalManagement *Coen244CarCompany = new CarRentalManagement();

	cout<<"Car Rental Management System Driver";



	/////////////////////////////////////TESTING CAR //////////////////////////////
	cout << "\n\t\tTESTING CAR CLASS";
	///////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////TESTING CUSTOMER /////////////////////////
	cout << "\n\n\n\t\tTESTING CUSTOMER CLASS";
	///////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////TESTING CRM /////////////////////////////
	cout << "\n\n\n\t\tTESTING CRM CLASS:" << endl;
	Coen244CarCompany->addCustomer(1,"Valentin", "Montreal", "0123456789",false);
	Coen244CarCompany->addCustomer(2,"Arseniy", "Toronto", "321654687", "The Pirate Bay","Somewhere");		//they use to be somewhere in europe in a bunker from cold war. they were smart enough to declare it as 'sovereign cuntry'. all changed after the raid

	cout<<*Coen244CarCompany->findCustomer("Valentin")<<endl
		<<*Coen244CarCompany->findCustomer(2);
	///////////////////////////////////////////////////////////////////////////////


	return 0;
}
