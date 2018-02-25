/*
 * CarRentalManagement.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: vpuyf
 */

#include "CarRentalManagement.h"

ostream& operator<<(ostream& out, const CarRentalManagement& c){

	out <<"\nCar Rental System Information"
		<<"\n\tCars in Inventory: "<<c.listCar.size()
		<<"\n\tCustomers registered: "<<c.listCustomer.size();

	return out;
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
		if(dynamic_cast<Customer*>(customer))
		{
			if(car->getType()=="luxury")
				cout<<"\nCustomer cannot rent this car.\n";//IMPROVE throw exception
		}
		else{
			car->setAvailability(false);
			customer->setCar(car);
			car->setCustomer(customer);
		}
	else cout<<"\nInvalid input: nullptr ";//IMPROVE throw exception
}
void CarRentalManagement::rentCar(int customerId, int carId)
{
	Customer*customerPrt = this->findCustomer(customerId);
	Car*carPtr = this->getCar(carId);
	if (customerPrt==nullptr || carPtr==nullptr)
	{
		cout << "\nInvalid param!";
		return;
	}
	//rentCar() should: check that given customer CAN rent that car(availability, privileges)
	if (&customerPrt->getCar()==nullptr)//checking if customer doesnt have a car
		if (carPtr->getAvailability() == true)
		{
			if (carPtr->getType()=="luxury")
				if(dynamic_cast<Customer*>(customerPrt))
				{
					cout << "\nNo access!";//IMPROVE throw exception
					return;
				}		
		//*add that car to carRented in Customer,
		//*add that customer to Car
			customerPrt->setCar(carPtr);
			carPtr->setCustomer(customerPrt);
		}
		//					 update the car availability,
	carPtr->setAvailability(false);//FIXME that would occur even though the car was not rent
	//NOTE possible solution for rentCar(carID, customerID)
	/*Customer*customer = this->findCustomer(customerId);
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
				if(car->getType() == "luxury" && dynamic_cast<Customer*>(customer))
					cout<<"\nCustomer cannot rent luxury car.\n";//IMPROVE throw exception
				else{
					customer->setCar(car);
					car->setCustomer(customer);
					car->setAvailability(false);
				}
			}
			else cout<<"\nCar is not available.\n";//IMPROVE throw exception
		}
		else cout<<"\nCustomer already has a car.\n"//IMPROVE throw exception
	}
	else cout<<"\nInvalid ID numbers.\n";//IMPROVE throw exception
*/

}

/*TODO
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

