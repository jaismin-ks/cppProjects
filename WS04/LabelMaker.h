/*
Name: Jaismin Kaur Sidhu
Email: jksidhu35@myseneca.ca
Student ID: 129603247
Date: June 8, 2025

I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
*/

#ifndef SENECA_LABELMAKER_H
#define SENECA_LABELMAKER_H

namespace seneca
{
    class Label; 
    class LabelMaker {
        private:
            Label* m_labels;
            int m_noOfLabels;

        public: 
/// <summary>
/// Creates a dynamically allocated array of objects of type
///   `Label` of size specified as a parameter. Stores the
///   address of the array in an attribute and manages it.
/// </summary>
/// <param name="noOfLabels">The number of labels in the array.</param>
LabelMaker(int noOfLabels);

/// <summary>
/// Reads from keyboard the labels and stores them in the array.
/// 
/// **NOTE**: look in the sample output for hints.
/// </summary>
void readLabels();

/// <summary>
/// Prints to screen all the labels stored in current instance.
/// 
/// **NOTE**: look in the sample output for hints.
/// </summary>
void printLabels();

/// <summary>
/// Clean-up any resource used by the current instance.
/// </summary>
~LabelMaker();
    };

}




#endif