


#include<string>
#include<iostream>


#ifndef CAR_H_
#define CAR_H_

 //forward declaration, get errors if i use //#include "Customer.h"
#include "Customer.h"
//class Customer;

using namespace std;

class Car {

	string type;
	int id;
	bool isAvailable;
	Customer* whoIsRenting;

	friend ostream& operator<<(ostream&, const Car&);

public:

	Car(string = "regular", int = 0);	//default and parameter constructor
	Car(const Car&);					//copy constructor
	~Car();								//destructor

	///////////////Setters Getters//////////////
	void setID(int);
	void setType(string);
	void setAvailability(bool);
	void setCustomer(Customer*);

	int getID()const;
	bool getAvailability()const;
	string getType()const;
	Customer& getCustomer()const; //return by reference

	///////////		operator overloads    //////////////
	bool operator==(const Car&) const;
	bool operator!=(const Car& c)const;

};

#endif /* CAR_H_ */
