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
	Car*c3 = new Car(*c2);
	cout <<*c1<<endl<<*c2<<endl<<*c3;
	return 0;
}
