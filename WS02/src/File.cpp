/*
Name: Jaismin Kaur Sidhu
Email: jksidhu35@myseneca.ca
Student ID: 129603247
Date: May 27, 2025

I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "File.h"
#include "Region.h"
#include <iostream>

namespace seneca {

    bool load(const char* filename, Region*& regions, int& count) {
// Open file for reading
        FILE* file = fopen(filename, "r");
// Check if file opened successfully, if not return an error message
        if (!file) {
            std::cout << "Failed to open file: " << filename << std::endl;
            return false;
        }

        count = 0;
        char tempCode[4];
        int tempPop;       

// Count the number of regions in the file
        while (fscanf(file, "%3[^,],%d\n", tempCode, &tempPop) == 2) {
                
            count++;
        }
// If no data found, close the file
        if (count == 0) {
            fclose(file);
            return false;
        }
// Set file pointer back to the beginning
        rewind(file);

// Allocate array of Region objects dynamically
        regions = new Region[count];
// Read each region data and store in array
        for (int i = 0; i < count; ++i) {
            fscanf(file, "%3[^,],%d\n", tempCode, &tempPop);

// Allocate memory for postal code string (3 chars + null)
            regions[i].postalCode = new char[4];
            for (int j = 0; j < 3; ++j) {
                regions[i].postalCode[j] = tempCode[j];
            }
            regions[i].postalCode[3] = '\0';

            regions[i].population = tempPop;
        }

// Close the file after done reading
        fclose(file);
        return true;
    }

}
