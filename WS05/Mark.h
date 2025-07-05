/*
Name: Jaismin Kaur Sidhu
Email: jksidhu35@myseneca.ca
Student ID: 129603247
Date: June 13, 2025

I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
*/
#ifndef SENECA_MARK_H
#define SENECA_MARK_H

namespace seneca
{
    class Mark
    {
    private:
        int m_value;
    public:
/// <summary>
/// Initializes the current instance with setting the mark to
///   the value of the parameter.
/// </summary>
/// <param name="value">An integer representing the mark.  This
///   parameter is optional, with a default value of 0. Only values
///   between 0 and 100 are considered valid.</param>
Mark(int value = 0);

/// <summary>
/// Increase the mark by the value received as parameter.  If the current
///   mark is not valid, this operator does nothing.
/// </summary>
/// <param name="value">An integer, representing how much to increase
///   the current mark.</param>
/// <returns>A reference to the current instance.</returns>
Mark& operator+=(int value);

/// <summary>
/// The assignment operator sets the mark to the value received as parameter.
/// </summary>
/// <param name="value">An integer, representing the new mark.</param>
/// <returns>A reference to the current instance.</returns>
Mark& operator=(int value);


/// <summary>
/// A conversion-to-integer operator overload. Returns the number representing
///   the mark in the interval [0, 100]. If the mark is not valid, this
///   operator returns 0.
/// </summary>
operator int() const;

/// <summary>
/// A conversion-to-char operator overload. Returns the letter representation
///   of the mark (see the provided table). If the mark is not valid, this
///   operator returns `X`.
/// </summary>
operator char() const;

/// <summary>
/// A conversion-to-double operator overload. Returns the GPA equivalent of the
///   mark (see the provided table). If the mark is not valid, this operator
///   returns 0.
/// </summary>
operator double() const;

bool isValid() const;

    };
    
int& operator+=(int& value, const Mark& theMark);

    
} // namespace seneca


#endif