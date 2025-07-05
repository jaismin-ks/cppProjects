/*
Name: Jaismin Kaur Sidhu
Email: jksidhu35@myseneca.ca
Student ID: 129603247
Date: June 1, 2025

I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
*/

#ifndef SENECA_CALORIELIST_H
#define SENECA_CALORIELIST_H

#include "Food.h"

namespace seneca {

    /// <summary>
    /// Manages a dynamic list of Food items representing daily calorie consumption.
    /// </summary>
    class CalorieList {
    private:
        Food* m_items;    ///< Pointer to a dynamic array of Food objects
        int m_capacity;   ///< Maximum number of Food items the list can hold
        int m_size;       ///< Current number of Food items added to the list

    public:
        /// <summary>
        /// Initializes the list with the specified capacity and allocates memory.
        /// </summary>
        /// <param name="capacity">Maximum number of Food items allowed</param>
        void init(int capacity);

        /// <summary>
        /// Adds a food item to the list if there is space and the data is valid.
        /// </summary>
        /// <param name="food_name">Name of the food item</param>
        /// <param name="calories">Calories of the food item</param>
        /// <param name="when">Time of day (1-4) indicating when the food was eaten</param>
        /// <returns>True if the item was added successfully, false otherwise</returns>
        bool add(const char* food_name, int calories, int when);

        /// <summary>
        /// Displays the list of food items with formatting, marking invalid items clearly.
        /// </summary>
        void display() const;

        /// <summary>
        /// Frees allocated memory and resets the list to an empty state.
        /// </summary>
        void reset();
    };

}

#endif
