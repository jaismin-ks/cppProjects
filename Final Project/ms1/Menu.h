/* Citation and Sources...
Final Project Milestone 1: 
Module: Menu
Filename: menu.h
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
#ifndef SENECA_MENU_H
#define SENECA_MENU_H

#include <iostream> 

namespace seneca
{
    class MenuItem
{
private:
    char * m_content = nullptr;
    unsigned int m_noOfIndentations = 0;
    unsigned int m_indentationSize = 0;
    int m_itemNumber = 0;

    void setEmpty();

public:
    MenuItem();
    MenuItem(const char * content, unsigned int noOfIndentations, unsigned int indentationSize, int itemNumber);
    std::ostream& display(std::ostream& ostr = std::cout) const;
    ~MenuItem();

    operator bool() const;
    MenuItem(const MenuItem&) = delete;
    MenuItem& operator=(const MenuItem&) = delete;
};
} // namespace seneca



#endif