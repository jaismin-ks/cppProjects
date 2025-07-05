/*
Name: Jaismin Kaur Sidhu
Email: jksidhu35@myseneca.ca
Student ID: 129603247
Date: June 8, 2025

I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <cstring>
#include "Label.h"

using namespace std;

namespace seneca {

    Label::Label() {
        strncpy(m_frame, "+-+|+-+|", 8); // sets default frame
        m_frame[8] = '\0'; // add a null terminator to the end of string
        m_content = nullptr; 
    }

    Label::Label(const char* frame) : Label() {
        if (frame != nullptr && strlen(frame) >= 8) {
            strncpy(m_frame, frame, 8); // sets frame to user entered frame
            m_frame[8] = '\0';  // add a null terminator to the end of string
        }
    }

    Label::Label(const char* frame, const char* content) : Label(frame) {
        if (content != nullptr && content[0] != '\0') {
        int len = strlen(content); //checks the content of string entered
        if (len <= 70) {
            m_content = new char[len + 1]; // dynamically allocates memory for content depending on it's size
            strcpy(m_content, content); // copies content into dynamic array
            m_content[len] = '\0';
        } else {
            m_content = new char[71]; //  dynamically allocates memory for content, max 70 characters, and one for null terminator
            strncpy(m_content, content, 70); // copies up to 70 characters into new dynamic array
            m_content[70] = '\0'; // null terminates the string
        }
        } else {
            m_content = nullptr;
        }
    };

    Label::~Label() {
        delete[] m_content; // deallocates memory assigned for dynamic array for content of the label
    };

    void Label::readLabel() {
    char temp[71]; // Temporary buffer to hold input (max 70 chars + null terminator)
    cin.getline(temp, 71);  // Read a line of input up to 70 characters
    
    delete[] m_content; // Free previously allocated memory for content to avoid memory leak

    int len = strlen(temp); // gets length of the string
    if (len > 0) {
        m_content = new char[len + 1]; // allocates enough memory for content
        strcpy(m_content, temp); // copies input into dynamic array
    } else {
        m_content = nullptr;
    }
}

    ostream& Label::print() const {
        if (m_content == nullptr || m_content[0] == '\0') {
            return cout;
        }

        int len = strlen(m_content);

        // Top border
        cout << m_frame[0];  // left corner
        cout.fill(m_frame[1]); // horizontal 
        cout.width(len + 2); // content + 2 spaces
        cout << ""; // flush width with fill
        cout << m_frame[2] << endl; // right corner

        // Empty line above content
        cout << m_frame[7];
        cout.fill(' ');
        cout.width(len + 2); // content + 2 spaces
        cout << ""; // flush width with fills
        cout << m_frame[3] << endl;

        // Middle line with content
        cout << m_frame[7] << ' ' << m_content << ' ' << m_frame[3] << endl;

    // Empty line below content
        cout << m_frame[7];
        cout.fill(' ');
        cout.width(len + 2); // content + 2 spaces
        cout << ""; // flush width with fills
        cout << m_frame[3] << endl;
        
        // Bottom border
        cout << m_frame[6];
        cout.fill(m_frame[5]);
        cout.width(len + 2);
        cout << "";
        cout << m_frame[4];

        return cout;
    }


}
