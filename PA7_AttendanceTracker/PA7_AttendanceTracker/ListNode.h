/*
* Programmer: Garrick Hutcheson
* Programming Assignment 7: Attendance Tracker
* Date: 10/23/17
* File: Listnode.h
* Description: Attendance Tracker program file
*/

#pragma once

#include "Stack.h"
#include <sstream>
#include <ctime>
#include <iostream>
#include <string>
using std::ostream;
using std::string;

class ListNode
{
	friend class List;
public:
	//constructor
	ListNode(string line);
	//printers
	void addAbsence();
	string getStudentInfo();
	string getRecentAbsence();
	string getAllAbsences();
	//getters
	int getNumAbsences();

private:
	ListNode * mNext;
	Stack<string>* absences;
	int numAbsences;
	int recordNumber;
	int idNumber;
	string name;
	string eMail;
	string units;
	string program;
	string level;
};

ostream & operator<<(std::ostream& lhs, ListNode& rhs);