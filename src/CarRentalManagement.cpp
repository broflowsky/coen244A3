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
	listCar.push_back(*new Car(type, id));
}
Car* CarRentalManagement::getCar(int id){
	list<Car>::iterator iterator;

		for(iterator = listCar.begin();iterator != listCar.end(); ++iterator)//checking for available room at date entered
			if(iterator->getID() == id)										//NOTE what with the comment above? it's everywhere
				break;
		if(iterator == listCar.end()){
			cout<<"\nNo match for this ID.\n";//IMPROVE throw exception
			return nullptr;
		}
		else return &*iterator;
		//NOTE is this a 'conversion' to a simple pointer? and waht for? there is ._Prt member of iterator
}
void CarRentalManagement::removeCar(Car &c)
{	//NOTE ~if you are passing the car by ref, you can simply do listCar.remove(c)
	//~since .remove does the search for you. But practically you wont have that reference, hence the findCar(id)
	//NOTE I tried few combinations. it didn't work. I thought it didn't work beyound simple types like int and such.
	listCar.remove(c);
}
void CarRentalManagement::removeCar(int id){
	listCar.remove(*getCar(id));
}

void CarRentalManagement::rentCar(Customer * customer,Car *car)
{
	if(dynamic_cast<Customer*>(customer))
	{
		if(car->getType()=="luxe")
			cout<<"\nCustomer cannot rent this car.\n";
	}
	else{
		car->setAvailability(false);
		customer->setCar(car);
		car->setCustomer(customer);
	}
}

void CarRentalManagement::rentCar(int customerId, int carId)
{
	Customer*cuPrt = this->findCustomer(customerId);
	Car*caPtr = this->getCar(customerId);
	if (cuPrt==nullptr || caPtr==nullptr)
	{
		cout << "\nInvalid param!";
		return;
	}
	//rentCar() should: check that given customer CAN rent that car(availability, privileges)
	if (&cuPrt->getCar()==nullptr)
		if (caPtr->getAvailability() == true)
		{
			if (caPtr->getType()=="Luxury")
				if(dynamic_cast<Customer*>(cuPrt))
				{
					cout << "\nNo access!";
					return;
				}		
		//*add that car to carRented in Customer,
		//*add that customer to Car
			cuPrt->setCar(caPtr);
			caPtr->setCustomer(cuPrt);
		}
		//* 					 update the car availability,
	caPtr->setAvailability(false);

}

/*TODO NOTE
 * Car* findCar*()
 *returnCar() should : undo the above
 *
 *
 * */
void CarRentalManagement::returnCar(Customer*customer)
{
	Car*modelT = &customer->getCar();			//get a pointer to the car

	if (&modelT->getCustomer()==customer)
	{
		modelT->setCustomer(nullptr);			//clear the customer assigned with the car
		customer->setCar(nullptr);				//clear the car assigned to customer
	}
	else if (&modelT->getCustomer()==nullptr)
	{
		cout << "\nCar " << modelT->getID() << " already returned";
		customer->setCar(nullptr);				//clearing association on customer side
	}
	else
	{
		cout << "\nCar " << modelT->getID() << " is associated with different customer. \nReturn car anyway?(y/n)";
		char temp;
		cin >> temp;
		if (temp == 'y' || temp == 'Y')
		{
			modelT->setCustomer(nullptr);			//clear the customer assigned with the car
			customer->setCar(nullptr);				//clear the car assigned to customer
		}
	}
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
	else listCustomer.push_back(new Customer(customerID,name,address,tel));
}
void CarRentalManagement::addCustomer(int customerID,string name,string address,string tel,string companyName,string companyAddress)	//constructor #2
{
	listCustomer.push_back(new CorporateCustomer(customerID,name,address,tel,companyName,companyAddress));
}

void CarRentalManagement::removeCustomer(int customerId)
{
	list<Customer*>::iterator iterator;
	list<Customer*>::iterator end;

		for(iterator = listCustomer.begin(),end = listCustomer.end();iterator != end; ++iterator)
			if((*iterator)->getCustomerID() == customerId)
				break;
		if(iterator == end)
			cout<<"\nNo match for this ID.\n";//IMPROVE exception handling
		else listCustomer.erase(iterator);

}
void CarRentalManagement::removeCustomer(string name){
	list<Customer*>::iterator iterator;
	list<Customer*>::iterator end;

		for(iterator = listCustomer.begin(),end = listCustomer.end();iterator != end; ++iterator)
			if(! (*iterator)->getName().compare(name))
				break;
		if(iterator == end)
			cout<<"\nNo match for this ID.\n";//IMPROVE exception handling
		else listCustomer.erase(iterator);
}
Customer* CarRentalManagement::findCustomer(string name){
	list<Customer*>::iterator iterator;
	list<Customer*>::iterator end;

	for(iterator = listCustomer.begin(),end = listCustomer.end();iterator != end; ++iterator)
		if(! (*iterator)->getName().compare(name))
			break;
	if(iterator == end){
		cout<<"\nNo match for this name.\n";//IMPROVE exception handling
		return nullptr;
	}
	else return *iterator;
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
int CarRentalManagement::getCustomerPrivilege(Customer& c)const//cant pass as const referece since casting is used
{
	if(dynamic_cast<CorporateCustomer*>(&c))	//false if c is anything but Corporate or derived of Corporate
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

	else if(dynamic_cast<VipCustomer*>(&c))

		VipCustomer::setMaxRental(newMaxRentalDuration);

	else Customer::setMaxRental(newMaxRentalDuration);
}
void CarRentalManagement::changePrivilege(int newMaxRentalDuration, string type){
	if(!type.compare("regular"))
		Customer::setMaxRental(newMaxRentalDuration);
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
	else return "regular";
}

