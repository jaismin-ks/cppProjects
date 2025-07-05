/*
Name: Jaismin Kaur Sidhu
Email: jksidhu35@myseneca.ca
Student ID: 129603247
Date: May 27, 2025

I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "Region.h"
#include "File.h" 

namespace seneca {

    Region* g_region = nullptr;  // Global region array pointer
    int g_regionCount = 0;       // Number of regions loaded

// Copy C-string from src to des
    void strCpy(char* des, const char* src) {
        int i = 0;
        while (src[i] != '\0') {
            des[i] = src[i];
            i++;
        }
        des[i] = '\0';
    }

// Load data from the file and store in global variables
    bool load(const char* filename) {
        cleanUp();

        FILE* file = fopen(filename, "r");
        if (!file) {
            std::cout << "Failed to open file: " << filename << std::endl;
            return false;
        }

        g_regionCount = 0;
        char tempCode[4];
        int tempPop;

        while (fscanf(file, "%3[^,],%d\n", tempCode, &tempPop) == 2) {
            g_regionCount++;
        }

        if (g_regionCount == 0) {
            fclose(file);
            return false;
        }

        rewind(file);

        g_region = new Region[g_regionCount];

// Read data and copy into global array
        for (int i = 0; i < g_regionCount; ++i) {
            fscanf(file, "%3[^,],%d\n", tempCode, &tempPop);

            g_region[i].postalCode = new char[4];
            strCpy(g_region[i].postalCode, tempCode);
            g_region[i].population = tempPop;
        }

        fclose(file);
        return true;
    }

// Free all dynamically allocated memory and reset globals
    void cleanUp() {
        if (g_region) {
            for (int i = 0; i < g_regionCount; ++i) {
                delete[] g_region[i].postalCode;
            }
            delete[] g_region;
            g_region = nullptr;
            g_regionCount = 0;
        }
    }

// Display the list of regions with optional sorting
    void display(const char* areaName, Region*& regions, int& count, bool sorted) {
        if (count == 0 || regions == nullptr) {
            std::cout << "No data to display.\n";
            return;
        }
        
// Sort by population if requested (bubble sort)
        if (sorted) {
            for (int i = 0; i < count - 1; ++i) {
                for (int j = 0; j < count - i - 1; ++j) {
                    if (regions[j].population > regions[j + 1].population) {
                        Region temp = regions[j];
                        regions[j] = regions[j + 1];
                        regions[j + 1] = temp;
                    }
                }
            }
        }

        std::cout << "#. Postal Code -> Population\n";
        std::cout << "------------------------------\n";

        int totalPop = 0;
        for (int i = 0; i < count; ++i) {
            std::cout << (i + 1) << ". " << regions[i].postalCode << " -> " << regions[i].population << "\n";
            totalPop += regions[i].population;
        }

        std::cout << "------------------------------\n";
        std::cout << "Population of " << areaName << ": " << totalPop << "\n";
    }

    void display(const char* areaName, bool sorted) {
        display(areaName, g_region, g_regionCount, sorted);
    }

}
