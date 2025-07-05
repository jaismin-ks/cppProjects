/*
Name: Jaismin Kaur Sidhu
Email: jksidhu35@myseneca.ca
Student ID: 129603247
Date: May 27, 2025

I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "Region.h"
#include "Region.h" // intentional

int cout = 0; // won't compile if headers don't follow convention


int main()
{
	// Test 1
	std::cout << "T1: Load Some Data\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	if (seneca::load("toronto.csv"))
		seneca::display("Toronto");

	// Test 2: Discard old data, load new data
	std::cout << "\nT2: Discard Old Data; Load New Data\n";
	std::cout << "==========:==========:==========:==========:==========\n";
	seneca::cleanUp();
	if (seneca::load("canada.csv"))
		seneca::display("Canada", true);

	seneca::cleanUp();

	return cout;
}
