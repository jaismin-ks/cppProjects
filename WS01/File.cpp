/*
Name: Jaismin Kaur Sidhu
Email: jksidhu35@myseneca.ca
Student ID: 129603247
Date: May 13, 2025

I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
*/

#include "File.h"
#include <iostream>

using namespace std;
namespace seneca {
//global variable
FILE* g_sfptr = nullptr;

//constant used in this file
const char* const SHOPPING_DATA_FILE = "ShoppingList.csv";


bool openFileForRead()
{
	g_sfptr = fopen(SHOPPING_DATA_FILE, "r");
	return g_sfptr != nullptr;
}

bool openFileForOverwrite()
{
	g_sfptr = fopen(SHOPPING_DATA_FILE, "w");
	return g_sfptr != nullptr;
}

void closeFile()
{
	if (g_sfptr)
	{
		fclose(g_sfptr);
		g_sfptr = nullptr;
	}
}

bool freadShoppingRec(ShoppingRec* rec)
{
	int flag = 0;
	bool success = fscanf(g_sfptr, "%[^,],%d,%d\n", rec->m_title, &rec->m_quantity, &flag) == 3;
	rec->m_bought = !!flag;
	return success;
}

void fwriteShoppintRec(const ShoppingRec* rec)
{
	fprintf(g_sfptr, "%s,%d,%d\n", rec->m_title, rec->m_quantity, rec->m_bought);
}

}