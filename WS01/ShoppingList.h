/*
Name: Jaismin Kaur Sidhu
Email: jksidhu35@myseneca.ca
Student ID: 129603247
Date: May 13, 2025

I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
*/

#ifndef SENECA_SHOPPINGLIST_H
#define SENECA_SHOPPINGLIST_H

namespace seneca {


// Function declarations
bool loadList();
void displayList();
void removeBoughtItems();
void removeItem(int index);
bool saveList();
void clearList();
void toggleBought();
void addItemToList();
void removeItemfromList();
bool listIsEmpty();

}

#endif
