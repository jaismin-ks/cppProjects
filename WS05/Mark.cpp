/*
Name: Jaismin Kaur Sidhu
Email: jksidhu35@myseneca.ca
Student ID: 129603247
Date: June 13, 2025

I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
*/
#include "Mark.h"

namespace seneca {

// set mark to value if valid, else mark invalid (-1)
Mark::Mark(int value) {
    if (value >= 0 && value <= 100)
        m_value = value;
    else
        m_value = -1;  // invalid mark
}

// Add value to current mark if valid, else do nothing
// If new mark goes out of valid range, mark becomes invalid
Mark& Mark::operator+=(int value) {
    if (isValid()) {
        m_value += value;
        if (m_value < 0 || m_value > 100)
            m_value = -1;  // invalidate if out of range
    }
    return *this;
}

// Assign new value to mark; if invalid, mark becomes invalid (-1)
Mark& Mark::operator=(int value) {
    if (value >= 0 && value <= 100)
        m_value = value;
    else
        m_value = -1;
    return *this;
}

// Convert Mark to int: return mark if valid, else 0
Mark::operator int() const {
    return isValid() ? m_value : 0;
}

// Convert Mark to char grade according to given scale
// Return 'X' if invalid mark
Mark::operator char() const {
    if (!isValid()) return 'X';
    if (m_value < 50) return 'F';
    if (m_value < 60) return 'D';
    if (m_value < 70) return 'C';
    if (m_value < 80) return 'B';
    return 'A';
}

// Convert Mark to GPA (double) according to given scale
// Return 0.0 if invalid mark
Mark::operator double() const {
    if (!isValid()) return 0.0;
    if (m_value < 50) return 0.0;
    if (m_value < 60) return 1.0;
    if (m_value < 70) return 2.0;
    if (m_value < 80) return 3.0;
    return 4.0;
}

// Check if mark is valid (between 0 and 100)
bool Mark::isValid() const {
    return m_value >= 0 && m_value <= 100;
}

// Non-member operator+= overload
// Adds mark value to an int if mark is valid
int& operator+=(int& value, const Mark& theMark) {
    if (theMark.isValid()) {
        value += int(theMark);  // add mark's integer value
    }
    return value;
}

} // namespace seneca
