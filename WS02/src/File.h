/*
Name: Jaismin Kaur Sidhu
Email: jksidhu35@myseneca.ca
Student ID: 129603247
Date: May 27, 2025

I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
*/

#ifndef SENECA_FILE_H
#define SENECA_FILE_H
#include "Region.h"

namespace seneca {

    /// <summary>
    /// Loads from a file a collection of administrative regions; stores retrieved
    ///   data into a dynamically-allocated array.  Each region will have a "Postal Code"
    ///   and the number of people living there.
    /// </summary>
    /// <param name="filename">the file containing data.</param>
    /// <returns>true if the data was successfully loaded, false otherwise.</returns>
    bool load(const char* filename, Region*& regions, int& count);

}

#endif 