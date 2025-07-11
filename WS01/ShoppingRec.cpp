/*
Name: Jaismin Kaur Sidhu
Email: jksidhu35@myseneca.ca
Student ID: 129603247
Date: May 13, 2025

I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
*/

#include "ShoppingRec.h"
#include "Utils.h"
#include <iostream>

using namespace std;

namespace seneca {
//constants used in this file
const int MAX_QUANTITY_VALUE = 50;


ShoppingRec getShoppingRec()
{
	ShoppingRec R{};
	cout << "Item name: ";
	readCstr(R.m_title, MAX_TITLE_LENGTH);
	cout << "Quantity: ";
	R.m_quantity = readInt(1, MAX_QUANTITY_VALUE);
	return R;
}

void displayShoppingRec(const ShoppingRec* shp)
{
	cout << "[" << (shp->m_bought ? 'X' : ' ') << "]" << shp->m_title <<
		" qty:(" << shp->m_quantity << ")" << endl;
}

void toggleBoughtFlag(ShoppingRec* rec)
{
	rec->m_bought = !rec->m_bought;
}

bool isShoppingRecEmpty(const ShoppingRec* shp)
{
	return shp->m_title[0] == '\0';
}

}