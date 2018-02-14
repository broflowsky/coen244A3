/*
 * CorporateCustomer.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: vpuyf
 */

#include "CorporateCustomer.h"

CorporateCustomer::CorporateCustomer(int id,string name,string address,string tel,
									string companyName,string companyAddress):
									Customer(id,name,address,tel)
{

}

CorporateCustomer::~CorporateCustomer() {
	// TODO Auto-generated destructor stub
}

