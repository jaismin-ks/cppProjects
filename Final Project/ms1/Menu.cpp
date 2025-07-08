/* Citation and Sources...
Final Project Milestone 1: 
Module: Menu
Filename: menu.cpp
Version 1.0
Author: Jaismin Kaur, StNo: 129603247, Email: jksidhu35@myseneca.ca

Revision History
-----------------------------------------------------------
Date      Reason
2025/7/7  Preliminary release
2025/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include "Menu.h"
#include "constants.h"
#include <cstring>
#include <iostream>

namespace seneca
{   
    bool isWhitespace(char c) {
        return c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r';
    }

    bool isWhitespaceOnly(const char* str) {
        while (*str != '\0') {
            if (!isWhitespace(*str)) {
                return false;
            }
            str++;
        }
        return true;
    }


    void MenuItem::setEmpty() {
        delete[] m_content;
        m_content = nullptr;
        m_noOfIndentations = 0;
        m_indentationSize = 0;
        m_itemNumber = 0;
    }


    MenuItem::MenuItem() {
        setEmpty();
    };

    MenuItem::MenuItem(const char * content, unsigned int noOfIndentations, unsigned int indentationSize, int itemNumber) {
        if(content == nullptr || content[0] == '\0' || isWhitespaceOnly(content) || noOfIndentations > 4 || indentationSize > 4 || itemNumber > static_cast<int>(MaximumNumberOfMenuItems)) { //can not compare signed int to unsigned int
            setEmpty();
        } else {
            m_content = new char[strlen(content) + 1];
            strcpy(m_content, content);
            m_noOfIndentations = noOfIndentations;
            m_indentationSize = indentationSize;
            m_itemNumber = itemNumber;
        }
    };

    std::ostream& MenuItem::display(std::ostream& ostr) const {
        if (m_content == nullptr) {
            ostr << "??????????";
            return ostr;
        }

        if (m_noOfIndentations > 0 && m_indentationSize > 0) {
            ostr.fill(' ');
            ostr.width(m_noOfIndentations * m_indentationSize);
            ostr << "";
        }

        if (m_itemNumber >= 0) {
            ostr.fill(' ');
            ostr.width(2);
            ostr << m_itemNumber;
            ostr << "- ";
        }

        const char* start = m_content;
        while (*start != '\0' && isWhitespace(*start)) {
            ++start;
        }

        ostr << start;

        return ostr;
    }

    MenuItem::operator bool() const {
        return m_content != nullptr;
    }


    MenuItem::~MenuItem() {
        delete[] m_content;
    }
} // namespace seneca
