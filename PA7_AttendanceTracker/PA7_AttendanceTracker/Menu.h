/*
* Programmer: Garrick Hutcheson
* Programming Assignment 7: Attendance Tracker
* Date: 10/23/17
* File: Menu.h
* Description: Attendance Tracker program file
*/

#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "List.h"
using std::string;
using std::cout;

class Menu
{
public:
	void runMenu();

	//public for now


	//void absencesAbove(int absences); //displays all absences above a certain threshold
	//void wholeList(); //displays entire list with only most recent absence
	int menuPrompt(int numOptions); //user input getter thing
	//void absenceMenu();

private:
	void displayMainMenu();
	void displaySubMenu();
	void listToFile(string filename);
	void fileToList(string filename);
	List studentList;
	std::ifstream inFile;
	std::ofstream outFile;
};