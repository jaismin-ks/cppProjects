/***********************************************************************
// OOP244 Project, milestone 1: tester program
//
// File	ms1.cpp
// Version 1.0
// Date 2024-9-11
// Author Fardad
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//   
/////////////////////////////////////////////////////////////////
***********************************************************************/

/* Citation and Sources...
Final Project Milestone 1: 
Module: ms1
Filename: ms1.cpp
Version 1.0
Author: Jaismin Kaur, StNo: 129603247, Email: jksidhu35@myseneca.ca

Revision History
-----------------------------------------------------------
Date      Reason
2025/7/7  Preliminary release
2025/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include "Menu.h"
#include <iostream>
using namespace std;
using namespace seneca;
int main() {
   if (std::is_copy_assignable<MenuItem>::value) {
      cout << "You did not prevent the copy assignment" << endl;
   }
   if (std::is_copy_constructible<MenuItem>::value) {
      cout << "You did not prevent the copy construction" << endl;
   }
   MenuItem(nullptr, 1, 1, 1).display() <<  endl;
   if (MenuItem(nullptr, 1, 1, 1) == false) cout << "This is an invalid MenuItem" << endl;
   for (size_t row = 0; row < 11; row+=5) {
      for (size_t i = 0; i < 5; i++) {
         MenuItem(" \t\v\r\f\nThe Menu Item", i, i + 1, int(row + i)-1).display() << endl;
         
      }
   }
   return 0;
}
