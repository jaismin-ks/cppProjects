/*
Name: Jaismin Kaur Sidhu
Email: jksidhu35@myseneca.ca
Student ID: 129603247
Date: May 13, 2025

I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
*/

#ifndef SENECA_SHOPPINGREC_H
#define SENECA_SHOPPINGREC_H

namespace seneca {

//constant used in this file
const int MAX_TITLE_LENGTH = 50;

//structure definition
struct ShoppingRec
{
	char m_title[MAX_TITLE_LENGTH + 1];
	int m_quantity;
	bool m_bought;
};

// Function prototypes
ShoppingRec getShoppingRec();
void displayShoppingRec(const ShoppingRec* shp);
void toggleBoughtFlag(ShoppingRec* rec);
bool isShoppingRecEmpty(const ShoppingRec* shp);

}

#endif
