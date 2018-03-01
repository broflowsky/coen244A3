/*
 * CarRentalManagement.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: vpuyf
 */

#include "CarRentalManagement.h"

ostream& operator<<(ostream& out, const CarRentalManagement& c){

	c.print(out);
	return out;
}
void CarRentalManagement::print(ostream& out)const{
	out <<"\nCar Rental System Information"
		<<"\n\tCars in Inventory: "<<listCar.size()
		<<"\n\tCustomers registered: "<<listCustomer.size();
}
CarRentalManagement::CarRentalManagement() {

}

CarRentalManagement::~CarRentalManagement() {
	listCar.clear();
	listCustomer.clear();
}

void CarRentalManagement::addCar(string type, int id)
{
	listCar.push_back(*new Car(type, id));
}
Car* CarRentalManagement::getCar(int id){
	list<Car>::iterator iterator;

		for(iterator = listCar.begin();iterator != listCar.end(); ++iterator)
			if(iterator->getID() == id)
				break;
		if(iterator == listCar.end()){
			cout<<"\nNo match for this ID.\n";//IMPROVE throw exception
			return nullptr;
		}
		else return &*iterator;
}
void CarRentalManagement::removeCar(Car &c)
{
	listCar.remove(c);
}
void CarRentalManagement::removeCar(int id){
	listCar.remove(*getCar(id));
}
void CarRentalManagement::rentCar(Customer * customer,Car *car)
{
	if(customer != nullptr && car != nullptr)
		if(dynamic_cast<Regular*>(customer))
		{
			if(car->getType()=="Luxury")
				cout<<"\nCustomer cannot rent this car.\n";//IMPROVE throw exception
		}
		else{
			car->setAvailability(false);
			customer->setCar(car);
			car->setCustomer(customer);
			cout<<"\nCar successfully rented!.";
		}
	else cout<<"\nInvalid input: nullptr ";//IMPROVE throw exception
}
void CarRentalManagement::rentCar(int customerId, int carId)
{
	Customer*customer = this->findCustomer(customerId);
	Car*car = this->getCar(carId);

	//checking that car and customer exist
	if(car != nullptr && customer != nullptr)
	{
		//checking that customer has no car
		if(&customer->getCar()== nullptr)
		{
			//checking car is available
			if(car->getAvailability() == true)
			{
				//checking if car is luxury and customer is regular
				if(car->getType() == "Luxury" && dynamic_cast<Regular*>(customer))
					cout<<"\nCustomer cannot rent luxury car.\n";//IMPROVE throw exception
				else
				{//rent is valid
					customer->setCar(car);
					car->setCustomer(customer);
					car->setAvailability(false);
					cout<<"\nCar successfully rented!.";
				}
			}
			else cout<<"\nCar is not available.\n";//IMPROVE throw exception
		}
		else cout<<"\nCustomer already has a car.\n";//IMPROVE throw exception
	}
	else cout<<"\nInvalid ID numbers.\n";//IMPROVE throw exception


}
void CarRentalManagement::returnCar(Customer* c){
	if(c != nullptr)
	{//checking that customer exists
		Car* toBeReturned = &c->getCar();
		if(toBeReturned != nullptr)
		{//checking that customer was renting a car
			toBeReturned->setAvailability(true);
			toBeReturned->setCustomer(nullptr);
			c->setCar(nullptr);
			cout<<"\nCar successfully returned!.";
		}
		else cout<<"\nCustomer is not renting any car.\n";//IMPROVE throw exception
	}
	else cout<<"\nCustomer does not exist. (nullptr)\n";//IMPROVE throw exception
}
bool CarRentalManagement::isRented(const Car &c)
{
	return c.getAvailability();						//returns availability of the car
}

string CarRentalManagement::getTypeRentedCar(const Car &c)
{
	return c.getType();								//returns type of car
}
///////////////////////////////Customer//////////////////////////////////

void CarRentalManagement::getListsSizes()
{
	cout << "\n Cars: " << this->listCar.size();
	cout << "\n Customers: " << this->listCustomer.size()<<endl;
}

void CarRentalManagement::addCustomer(int customerID,string name,string address,string tel,bool isVip) //constructor #1
{
	if(isVip)																						//regular OR Vip customer
		listCustomer.push_back(new VipCustomer(customerID,name,address,tel));
	else listCustomer.push_back(new Regular(customerID,name,address,tel));
}
void CarRentalManagement::addCustomer(int customerID,string name,string address,string tel,string companyName,string companyAddress)	//constructor #2
{
	listCustomer.push_back(new CorporateCustomer(customerID,name,address,tel,companyName,companyAddress));
}

void CarRentalManagement::removeCustomer(int customerId)
{
	list<Customer*>::iterator iterator;
	for(iterator = listCustomer.begin();iterator != listCustomer.end(); ++iterator)
		if((*iterator)->getCustomerID() == customerId)
			break;
	if(iterator == listCustomer.end())
		cout<<"\nNo match for this ID.\n";//IMPROVE exception handling
	else
	{
		listCustomer.erase(iterator);
		cout<<"\nCustomer successfully removed!";
	}

}
void CarRentalManagement::removeCustomer(string name){
	list<Customer*>::iterator iterator;

	for(iterator = listCustomer.begin();iterator != listCustomer.end(); ++iterator)
		if(! (*iterator)->getName().compare(name))
			break;
	if(iterator == listCustomer.end())
		cout<<"\nNo match for this ID.\n";//IMPROVE exception handling
	else
	{
		listCustomer.erase(iterator);
		cout<<"\nCustomer successfully removed!";
	}
}
Customer* CarRentalManagement::findCustomer(string name){
	list<Customer*>::iterator iterator;

	for(iterator = listCustomer.begin();iterator != listCustomer.end(); ++iterator)
		if(! (*iterator)->getName().compare(name))
			break;
	if(iterator == listCustomer.end()){
		cout<<"\nNo match for this name.\n";//IMPROVE exception handling
		return nullptr;
	}
	else return *iterator;
}
Customer* CarRentalManagement::findCustomer(int customerId){
	list<Customer*>::iterator iterator;

	for(iterator = listCustomer.begin();iterator != listCustomer.end(); ++iterator)//checking for available room at date entered
		if((*iterator)->getCustomerID() == customerId)
			break;
	if(iterator == listCustomer.end()){
		cout<<"\nNo match for this ID.\n";//IMPROVE throw exception
		return nullptr;
	}
	else return *iterator;
}
int CarRentalManagement::getCustomerPrivilege(Customer& c)const//cant pass as const referece since casting is used
{
	if(dynamic_cast<CorporateCustomer*>(&c))	//false if c is anything but Corporate or derived of Corporate
	//non zero evaluates to true ; cast has local scope
		return CorporateCustomer::getMaxRental();

	else if(dynamic_cast<VipCustomer*>(&c))		//handy little thing right here

		return VipCustomer::getMaxRental();

	else return Regular::getMaxRental();
}

void CarRentalManagement::changePrivilege(int newMaxRentalDuration, Customer& c)//README useful link for this : https://stackoverflow.com/questions/4589226/type-checking-in-c
{
	if(dynamic_cast<CorporateCustomer*>(&c))	//false if c is anything but (Corporate or derived of Corporate)
												//non zero evaluates to true ; cast has local scope
		CorporateCustomer::setMaxRental(newMaxRentalDuration);

	else if(dynamic_cast<VipCustomer*>(&c))

		VipCustomer::setMaxRental(newMaxRentalDuration);

	else Regular::setMaxRental(newMaxRentalDuration);
}
void CarRentalManagement::changePrivilege(int newMaxRentalDuration, string type){
	if(!type.compare("Regular"))
		Regular::setMaxRental(newMaxRentalDuration);
	else if(!type.compare("corporate"))
		CorporateCustomer::setMaxRental(newMaxRentalDuration);
	else if(!type.compare("vip"))
		VipCustomer::setMaxRental(newMaxRentalDuration);
	else cout<<"\nType not recognized.\n";//IMPROVE exception handling
}
bool CarRentalManagement::isRenting(const Customer &c)
{
	return (&c.getCar()!=nullptr);
}

string CarRentalManagement::getCustomerRank(Customer &c)
{
	//if c not of class Corporate, we get a nullptr (0 => false), otherwise get an address(0xXXX => no zero => true)
	if(dynamic_cast<CorporateCustomer*>(&c))
		return "Corporate";
	else if(dynamic_cast<VipCustomer*>(&c))
		return "Vip";
	else return "Regular";
}

