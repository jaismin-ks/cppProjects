/*
Name: Jaismin Kaur Sidhu
Email: jksidhu35@myseneca.ca
Student ID: 129603247
Date: June 8, 2025

I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
*/
#ifndef SENECA_LABEL_H
#define SENECA_LABEL_H

namespace seneca
{
    class Label
    {
    private:
         char * m_content;
        char m_frame[9];
    public:
/// <summary>
/// Creates an empty label with the frame `"+-+|+-+|"`.
/// </summary>
Label();

/// <summary>
/// Creates an emtpy label specified frame.
/// </summary>
/// <param name="frame">The frame for the label.</param>
Label(const char* frame);

/// <summary>
/// Creates a label with specified frame and content.
/// </summary>
/// <param name="frame">The frame for the label.</param>
/// <param name="content">The text to be displayed inside the label.
///   Must be stored dynamically in an attribute.</param>
Label(const char* frame, const char* content);

/// <summary>
/// Clean-up any dynamic memory used by the current instance.
/// </summary>
~Label();

/// <summary>
/// Reads the label from console up to 70 characters and
///   stores it in the current object.
/// </summary>
void readLabel();

/// <summary>
/// Prints the label to screen by drawing the frame around the content.
/// 
/// Note that no newline is printed after the last line.
/// </summary>
/// <returns>`std::cout`</returns>
std::ostream& print() const;
    };
    
    
} 




#endif