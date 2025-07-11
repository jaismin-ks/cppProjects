/*
Name: Jaismin Kaur Sidhu
Email: jksidhu35@myseneca.ca
Student ID: 129603247
Date: June 8, 2025

I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "Label.h"
#include "Label.h" // intentional
#include "LabelMaker.h"
#include "LabelMaker.h" // intentional

int cout = 0; // won't compile if headers don't follow convention


int main()
{
	int noOfLabels;
	// Create a lable for the program title:
	seneca::Label
		theProgram("/-\\|/-\\|", "Professor's Label Maker Program Tester"),
		EmptyOne1,
		EmptyOne2("ABCDEFGH");
	std::cout << "EmptyOne1\n";
	EmptyOne1.print() << std::endl;
	std::cout << "EmptyOne2" << std::endl;
	EmptyOne2.print() << std::endl;
	theProgram.print() << std::endl << std::endl;
	std::cout << "Enter the follwing information:" << std::endl <<
		"# of Labels > 6\n"
		"1> Applied Problem Solving\n"
		"2> Computer Principles for Programmers\n"
		"3> Communicating Across Contexts (Enriched)\n"
		"4> Introduction to Programming Using C\n"
		"5> Introduction to UNIX/Linux and the Internet\n"
		"6> Computer Programming and Analysis, Co-op (Work-Integrated Learning option only)\n\n";

	// ask for number of labels to get created
	std::cout << "Number of labels to create: ";
	std::cin >> noOfLabels;
	std::cin.ignore(10000, '\n');
	// Create a LabelMaker for the number of 
	// the labels requested
	seneca::LabelMaker lblMkr(noOfLabels);
	// Ask for the label texts
	lblMkr.readLabels();
	// Print the labels
	lblMkr.printLabels();

	return cout;
}