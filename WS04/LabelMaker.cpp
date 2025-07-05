/*
Name: Jaismin Kaur Sidhu
Email: jksidhu35@myseneca.ca
Student ID: 129603247
Date: June 8, 2025

I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "LabelMaker.h"
#include "Label.h"


using namespace std;

namespace seneca
{
    LabelMaker::LabelMaker(int noOfLabels) {
        m_noOfLabels = noOfLabels; 
        m_labels = new Label[noOfLabels]; // allocate dynamic array of Label objects
    }

// Reads label content from user input for each Label in the array
    void LabelMaker::readLabels() {
        cout << "Enter " << m_noOfLabels << " labels:" << endl;
        for (int i = 0; i < m_noOfLabels; ++i) {
            cout << "Enter label number " << (i + 1) << " > "; // prompt user
            m_labels[i].readLabel(); // read and store label content
        }
    }

// Prints all labels stored in the dynamic array.
    void LabelMaker::printLabels() {
        for (int i = 0; i < m_noOfLabels; ++i) {
            m_labels[i].print() << endl; // print each label followed by a newline
        }
    }

    LabelMaker::~LabelMaker() {
        delete [] m_labels; // deallocate the array memory
    }



} // namespace seneca
