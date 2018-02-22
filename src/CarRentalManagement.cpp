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
	//listCar.push_back((new Car(type, id)));
	// i guess you can just do that
	//listCar.push_back(*new Car(type, id));
}

void CarRentalManagement::removeCar(const Car &c)
{
	listCar.remove(c);							//don't know if this the right way to do it (works as is)
}

void CarRentalManagement::rentCar(Customer*customer,Car*car)
{
	customer->setCar(car);						//create relation between the two
	car->setCustomer(customer);
}

void CarRentalManagement::returnCar(Customer*customer)
{
	Car*modelT = &customer->getCar();			//get a pointer to the car
	
	if (modelT!=nullptr)
	{
		modelT->setCustomer(nullptr);			//clear the customer assigned with the car
	}
	else
	{
		cout << "\nCustomer " << customer->getName() << ", " << customer->getCustomerID() << " does not have a car assigned to.";

	}
}

bool CarRentalManagement::isRented(const Car &)
{
	return false;
}

string CarRentalManagement::getTypeRentedCar(const Car &)
{
	return string();
}
///////////////////////////////Customer//////////////////////////////////

void CarRentalManagement::addCustomer(int customerID,string name,string address,string tel,bool isVip)//regular OR Vip customer
{
	if(isVip)
		listCustomer.push_back(new VipCustomer(customerID,name,address,tel));
	else listCustomer.push_back(new Customer(customerID,name,address,tel));
}
void CarRentalManagement::addCustomer(int customerID,string name,string address,string tel,string companyName,string companyAddress){
	listCustomer.push_back(new CorporateCustomer(customerID,name,address,tel,companyName,companyAddress));
}

void CarRentalManagement::removeCustomer(int customerId){
	list<Customer*>::iterator iterator;
	list<Customer*>::iterator end;

		for(iterator = listCustomer.begin(),end = listCustomer.end();iterator != end; ++iterator)//checking for available room at date entered
			if((*iterator)->getCustomerID() == customerId)
				break;
		if(iterator == end)
			cout<<"\nNo match for this ID.\n";
		else listCustomer.erase(iterator);

}
void CarRentalManagement::removeCustomer(string name){
	list<Customer*>::iterator iterator;
	list<Customer*>::iterator end;

		for(iterator = listCustomer.begin(),end = listCustomer.end();iterator != end; ++iterator)//checking for available room at date entered
			if(! (*iterator)->getName().compare(name))
				break;
		if(iterator == end)
			cout<<"\nNo match for this ID.\n";
		else listCustomer.erase(iterator);

}
Customer* CarRentalManagement::findCustomer(string name){
	//unfortunately i cant re use findCustomer() in removeCustomer()
	list<Customer*>::iterator iterator;
	list<Customer*>::iterator end;

	for(iterator = listCustomer.begin(),end = listCustomer.end();iterator != end; ++iterator)//checking for available room at date entered
		if(! (*iterator)->getName().compare(name))
			break;
	if(iterator == end){
		cout<<"\nNo match for this name.\n";
		return nullptr;
	}
	else return *iterator;

	//README
	/*
	 * Alright a bit of explaining
	 * Note that i changed my list<Customer> to list<Customer*> because of static/dynamic binding
	 *
	 * problem was i couldnt get inherited classes to use their overriden functions
	 * now problem is solved
	 *
	 * before that i had to write that god awefully amazing &*iterator but whatever
	 *
	 * i dont think you need to worryy about that since there isnt any inheritance with Car
	 * */
	//	else return &*iterator; //hahahahahahahahahahahahahahahahahahahahahahahahahhaaha
	//converts iterator to pointer
	// *iterator is a reference, so &*iterator gives the address of the reference
	//which is essentially a pointer to that reference
	//it s actually pretty straight forward
}
Customer* CarRentalManagement::findCustomer(int customerId){
	list<Customer*>::iterator iterator;
	list<Customer*>::iterator end;

		for(iterator = listCustomer.begin(),end = listCustomer.end();iterator != end; ++iterator)//checking for available room at date entered
			if((*iterator)->getCustomerID() == customerId)
				break;
		if(iterator == end){
			cout<<"\nNo match for this ID.\n";//IMPROVE throw exception
			return nullptr;
		}
		else return *iterator;
}
int CarRentalManagement::getCustomerPrivilege(Customer& c)const//cant pass const ref since casting is used
{														  //ref cant be null

	if(dynamic_cast<CorporateCustomer*>(&c))	//false if c is anything but (Corporate or derived of Corporate)
	//non zero evaluates to true ; cast has local scope
		return CorporateCustomer::getMaxRental();

	else if(dynamic_cast<VipCustomer*>(&c))		//handy little thing right here

		return VipCustomer::getMaxRental();

	else return Customer::getMaxRental();
}

void CarRentalManagement::changePrivilege(int newMaxRentalDuration, Customer& c)//README useful link for this : https://stackoverflow.com/questions/4589226/type-checking-in-c
{
	if(dynamic_cast<CorporateCustomer*>(&c))	//false if c is anything but (Corporate or derived of Corporate)
												//non zero evaluates to true ; cast has local scope
		CorporateCustomer::setMaxRental(newMaxRentalDuration);

	else if(dynamic_cast<VipCustomer*>(&c))		//handy little thing right here

		VipCustomer::setMaxRental(newMaxRentalDuration);

	else Customer::setMaxRental(newMaxRentalDuration);
}
bool CarRentalManagement::isRenting(const Customer &c)
{

	return (&c.getCar()==nullptr);//FIXME i have not tested this!!
}

string CarRentalManagement::getCustomerRank(const Customer &c)
{
	return string();//TODO getCustRank function
}

