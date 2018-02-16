/*
 * Car_test.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: vpuyf
 */

#include "Car.h"
#include <iostream>

using namespace std;


int main(){

	Car*c1 = new Car();
	Car*c2 = new Car("Luxe",1000);

	*c1==*c1?cout<<'y':cout<<'n';
	cout<<'\n'<<c2->getType();
	return 0;
}
