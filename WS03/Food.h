/*
Name: Jaismin Kaur Sidhu
Email: jksidhu35@myseneca.ca
Student ID: 129603247
Date: June 1, 2025

I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
*/

#ifndef SENECA_FOOD_H
#define SENECA_FOOD_H

namespace seneca {

    /// <summary>
    /// Represents a single food item with a name, calorie count, and time eaten.
    /// </summary>
    class Food {
    private:
        char m_name[31];   ///< Name of the food (up to 30 characters + null terminator)
        int m_calories;    ///< Number of calories in the food
        int m_when;        ///< Time of day eaten (1=Breakfast, 2=Lunch, 3=Dinner, 4=Snack)

    public:
        /// <summary>
        /// Sets the food's data if valid.
        /// </summary>
        /// <param name="food_name">Name of the food</param>
        /// <param name="calories">Calories of the food</param>
        /// <param name="when">Time of day the food was eaten</param>
        void add(const char* food_name, int calories, int when);

        /// <summary>
        /// Checks if the food item is valid (proper name, calories, and when).
        /// </summary>
        /// <returns>True if valid, false otherwise</returns>
        bool isValid() const;

        /// <summary>
        /// Displays the food item in formatted output.
        /// </summary>
        void display() const;

        /// <summary>
        /// Returns the calories of the food item.
        /// </summary>
        /// <returns>Calories value</returns>
        int calories() const;
    };

}

#endif
