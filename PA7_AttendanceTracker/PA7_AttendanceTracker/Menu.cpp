/*
* Programmer: Garrick Hutcheson
* Programming Assignment 7: Attendance Tracker
* Date: 10/23/17
* File: Menu.cpp
* Description: Attendance Tracker program file
*/

#include "Menu.h"


void Menu::runMenu()
{
	int subSelection = 0;
	int selection = 0;
	cout << "Welcome to the Attendance Tracker program. Please ensure that your class roster .csv"
		" is saved in the local directory with this program as \"classList.csv\""
		" Output will be saved to \"masterList.csv\".";

	/*"\n1.    Import course list\n"
		"2.    Load master list\n"
		"3.    Store master list\n"
		"4.    Mark absences\n"
		"5.    BONUS: Edit absences\n"
		"6.    Generate report\n"
		"7.    Exit\n";*/

	fileToList("classList.csv");
	while (selection != 7)
	{
		displayMainMenu();
		selection = menuPrompt(7);
		switch (selection)
		{
		case 1:
			fileToList("classList.csv");
			break;
		case 2:
			fileToList("masterList.csv");
			break;
		case 3:
			listToFile("masterList.csv");
			break;
		case 4:
			studentList.markAbsences();
			break;
		case 5:
			cout << "MEH.\n";
			break;
		case 6:
			displaySubMenu();
			subSelection = menuPrompt(2);
			if (subSelection == 1)
			{
				studentList.mostRecentAbsence();
			}
			else
			{
				cout << "Display students with absences over: ";
				subSelection = menuPrompt(180);
				studentList.allAbsences(subSelection);
			}
			break;
		case 7:
			listToFile("masterList.csv");
			break;
			
		}
	}

}

void Menu::fileToList(string fileName)
{
	if (inFile.is_open())
	{
		inFile.close();
	}
	inFile.open(fileName);
	if (inFile.good())
	{
		studentList.loadList(inFile);
	}
	else
		cout << "\nNo File in local Directory yet.\n";
}

void Menu::listToFile(string fileName)
{
	if (outFile.is_open())
	{
		outFile.close();
	}
	outFile.open(fileName);
	
	studentList.storeList(outFile);
}

void Menu::displaySubMenu()
{
	cout <<
		"\n1.    All students with most recent absence.\n"
		"2.    All absences of students above a designated number of absences.\n";

}

void Menu::displayMainMenu()
{
	cout <<
		"\n1.    Import course list\n"
		"2.    Load master list\n"
		"3.    Store master list\n"
		"4.    Mark absences\n"
		"5.    BONUS: Edit absences\n"
		"6.    Generate report\n"
		"7.    Exit\n";
}

int Menu::menuPrompt(int numOptions)
{
	string selection = "0";
	while ((!isdigit(selection.at(0)))||stoi(selection) < 1 || stoi(selection) > numOptions)
	{
		cout << "\nPlease enter a number from 1 to " << numOptions << '\n';
		cin >> selection;
		if ((!isdigit(selection.at(0))) || stoi(selection) < 1 || stoi(selection) > numOptions)
		{
			cout << "\n Invalid Entry.";
		}
	}
	return stoi(selection);
}