/*
Name: Jaismin Kaur Sidhu
Email: jksidhu35@myseneca.ca
Student ID: 129603247
Date: June 1, 2025

I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include "CalorieList.h"

using namespace std;

namespace seneca {

    // Initialize dynamic array with given capacity
    void CalorieList::init(int capacity) {
        if (capacity > 0) {
            m_capacity = capacity;
            m_size = 0;
            m_items = new Food[m_capacity];
        } else {
            m_items = nullptr;
            m_capacity = 0;
            m_size = 0;
        }
    }

    // Add a Food item if capacity allows; return validity of added item
    bool CalorieList::add(const char* food_name, int calories, int when) {
        if (m_size < m_capacity) {
            m_items[m_size].add(food_name, calories, when);
            bool valid = m_items[m_size].isValid();
            m_size++; 
            return valid;
        }
        return false;
    }

    // Display the list and total calories, marking invalid items with 'x's
    void CalorieList::display() const {
        bool allValid = true;
        int totalCalories = 0;

        // Check validity and sum calories of valid items only
        for (int i = 0; i < m_size; i++) {
            if (!m_items[i].isValid()) {
                allValid = false;
            } else {
                totalCalories += m_items[i].calories();
            }
        }

        bool isComplete = (m_size == m_capacity && m_capacity > 0);

        std::cout << "+----------------------------------------------------+" << std::endl;

        if (!allValid || !isComplete) {
            std::cout << "| Invalid Calorie Consumption list                   |" << std::endl;
        } else {
            std::cout << "|  Daily Calorie Consumption                         |" << std::endl;
        }

        std::cout << "+--------------------------------+------+------------+" << std::endl;
        std::cout << "| Food name                      | Cals | When       |" << std::endl;
        std::cout << "+--------------------------------+------+------------+" << std::endl;

        // Print each item or a row of 'x's if invalid or out of range
        for (int i = 0; i < m_capacity; i++) {
            if (i < m_size) {
                if (m_items[i].isValid()) {
                    m_items[i].display();
                } else {
                    std::cout << "| ";
                    for (int j = 0; j < 30; j++) std::cout << 'x';
                    std::cout << " | ";
                    for (int j = 0; j < 4; j++) std::cout << 'x';
                    std::cout << " | ";
                    for (int j = 0; j < 10; j++) std::cout << 'x';
                    std::cout << " |" << std::endl;
                }
            } else {
                std::cout << "| ";
                for (int j = 0; j < 30; j++) std::cout << 'x';
                std::cout << " | ";
                for (int j = 0; j < 4; j++) std::cout << 'x';
                std::cout << " | ";
                for (int j = 0; j < 10; j++) std::cout << 'x';
                std::cout << " |" << std::endl;
            }
        }

        std::cout << "+--------------------------------+------+------------+" << std::endl;

        // Calculate number length for right alignment
        int width = 7;
        int len = 0;
        int temp = totalCalories;
        if (temp == 0) len = 1;
        else {
            while (temp > 0) {
                temp /= 10;
                len++;
            }
        }

        // Print total calories or invalid message accordingly
        if (!allValid || !isComplete) {
            std::cout << "|    Invalid Calorie Consumption list                |" << std::endl;
        } else {
            std::cout << "|    Total Calories for today:  ";
            for (int i = 0; i < width - len; i++) std::cout << ' ';
            std::cout << totalCalories << " |            |" << std::endl;
        }

        std::cout << "+----------------------------------------------------+" << std::endl;
    }

    // Free dynamic memory and reset members
    void CalorieList::reset() {
        delete[] m_items;
        m_items = nullptr;
        m_capacity = 0;
        m_size = 0;
    }

}

