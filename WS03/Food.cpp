/*
Name: Jaismin Kaur Sidhu
Email: jksidhu35@myseneca.ca
Student ID: 129603247
Date: June 1, 2025

I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Food.h"

using namespace std;

namespace seneca {

    // Initialize Food object with provided data if valid, else mark invalid
    void Food::add(const char* food_name, int calories, int when) {
        if (food_name != nullptr && food_name[0] != '\0' &&
            calories > 0 && calories <= 3000 &&
            when >= 1 && when <= 4) {
            
            strncpy(m_name, food_name, 30);
            m_name[30] = '\0';  // ensure null-termination
            m_calories = calories;
            m_when = when;
        } else {
            m_name[0] = '\0';  // mark invalid
            m_calories = -1;
            m_when = -1;
        }
    }

    // Check if Food data is valid
    bool Food::isValid() const {
        return m_name[0] != '\0' &&
               m_calories > 0 && m_calories <= 3000 &&
               m_when >= 1 && m_when <= 4;
    }

    // Convert 'when' integer to descriptive string
    const char* whenToString(int when) {
        switch (when) {
            case 1: return "Breakfast";
            case 2: return "Lunch";
            case 3: return "Dinner";
            case 4: return "Snack";
            default: return "";
        }
    }

    // Display Food details in formatted table row
    void Food::display() const {
        char name[31];
        if (isValid()) {
            int len = strlen(m_name);
            strncpy(name, m_name, 30);
            for (int i = len; i < 30; i++) {
                name[i] = '.';
            }
            name[30] = '\0';
        } else {
            for (int i = 0; i < 30; i++) {
                name[i] = 'x';
            }
            name[30] = '\0';
        }

        std::cout << "| " << name << " | ";

        if (isValid()) {
            // Print calories right aligned in 4 spaces
            int cal = m_calories;
            char calStr[5];
            snprintf(calStr, sizeof(calStr), "%d", cal);
            int calLen = strlen(calStr);

            for (int i = 0; i < 4 - calLen; i++) {
                std::cout << ' ';
            }
            std::cout << calStr << " | ";
        } else {
            std::cout << "xxxx | ";
        }

        if (isValid()) {
            // Print 'when' string left aligned in 10 spaces
            const char* whenStr = whenToString(m_when); 
            int len = strlen(whenStr);
            std::cout << whenStr;
            for (int i = 0; i < 10 - len; i++) {
                std::cout << ' ';
            }
        } else {
            std::cout << "xxxxxxxxxx";
        }

        std::cout << " |" << std::endl;
    }

    // Return calories value
    int Food::calories() const {
        return m_calories;
    }

}
