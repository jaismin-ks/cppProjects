/*
Name: Jaismin Kaur Sidhu
Email: jksidhu35@myseneca.ca
Student ID: 129603247
Date: May 27, 2025

I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
*/

#ifndef SENECA_REGION_H
#define SENECA_REGION_H

namespace seneca {

// A custom type storing information about a single region.
    struct Region {
        char* postalCode; // Dynamically allocated 3 character long string + null terminator
        int population;
    };

    // Global pointer to dynamically allocated array of regions
    extern Region* g_region;
    // Global count of regions loaded
    extern int g_regionCount;

    // Used from exercise from week 2
    void strCpy(char* des, const char* src);

    /// <summary>
    /// Loads from a file a collection of administrative regions; stores retrieved
    ///   data into a dynamically-allocated array.  Each region will have a "Postal Code"
    ///   and the number of people living there.
    /// </summary>
    /// <param name="filename">the file containing data.</param>
    /// <returns>true if the data was successfully loaded, false otherwise.</returns>
    bool load(const char* filename);

    /// <summary>
    /// Deallocated all the dynamic memory used by the program.
    /// </summary>
    void cleanUp();

    /// <summary>
    /// Prints to screen the collection of regions loaded from a file.
    /// </summary>
    /// <param name="areaName">the name of administrative area where those regions
    ///    are located (i.e., the city, province, country, etc.)</param>
    /// <param name="sorted">optional parameter to specify if the regions should
    ///   be sorted based on the population or not. The default value is `false`.</param>
    void display(const char* areaName, Region*& regions, int& count, bool sorted);
    void display(const char* areaName, bool sorted = false);

}

#endif
