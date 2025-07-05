/*
Name: Jaismin Kaur Sidhu
Email: jksidhu35@myseneca.ca
Student ID: 129603247
Date: June 13, 2025

I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include "Mark.h"
#include "Mark.h" // intentional

int cout = 0; // won't compile if headers don't follow convention


int main()
{
	seneca::Mark m, n(25), k(200), p(-10);
	{
		std::cout << "T1: Testing conversion-to-int operator\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		std::cout << int(m) << std::endl;
		std::cout << int(n) << std::endl;
		std::cout << int(k) << std::endl;
		std::cout << int(p) << std::endl;
	}

	{
		std::cout << "\nT2: Testing addition-assignment operator\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		std::cout << int(m += 20) << std::endl;
		std::cout << int(n += 20) << std::endl;
		std::cout << int(k += 20) << std::endl;
		std::cout << int(n += 60) << std::endl;
	}

	{
		std::cout << "\nT3: Testing the assignment operator\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		std::cout << int(m = 80) << std::endl;
		std::cout << int(n = 120) << std::endl;
		std::cout << int(k = 70) << std::endl;
	}

	m = 50; n = 80; k = 120;

	{
		std::cout << "\nT4: Testing conversion-to-double operator\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		std::cout << double(m) << std::endl;
		std::cout << double(n) << std::endl;
		std::cout << double(k) << std::endl;
	}

	{
		std::cout << "\nT5: Testing conversion-to-char operator\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		std::cout << char(m) << std::endl;
		std::cout << char(n) << std::endl;
		std::cout << char(k) << std::endl;
	}

	{
		std::cout << "\nT6: Testing addition-assignment operator\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		int val = 60;

		std::cout << (val += n) << std::endl;
		std::cout << (val += k) << std::endl;
	}

	{
		std::cout << "\nT7: Testing all values\n";
		std::cout << "==========:==========:==========:==========:==========\n";
		p = 41;
		int val = 0;
		for (int i = 0; i < 12; i++)
		{
			p += 5;
			val += p;
			std::cout << int(p) << ": " << char(p) << ", " << double(p) << std::endl;
		}
		p = val / 12;
		std::cout << "Average: " << int(p) << " GPA: " << double(p) << std::endl;
	}

	return cout;
}