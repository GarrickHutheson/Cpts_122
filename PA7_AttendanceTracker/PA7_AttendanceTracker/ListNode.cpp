/*
* Programmer: Garrick Hutcheson
* Programming Assignment 7: Attendance Tracker
* Date: 10/23/17
* File: ListNode.cpp
* Description: Attendance Tracker program file
*/

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "ListNode.h"


ListNode::ListNode(string line)
{
	numAbsences = 0;
	string tmp = " ";
	std::stringstream s(line);
	std::getline(s, tmp, ',');
	recordNumber = stoi(tmp);
	std::getline(s, tmp, ',');
	idNumber = stoi(tmp);
	std::getline(s, name, '"');
	std::getline(s, name, '"');
	name = "\"" + name + "\"";
	s.ignore();
	std::getline(s, eMail, ',');
	std::getline(s, units, ',');
	std::getline(s, program, ',');
	std::getline(s, level, ',');
	absences = new Stack<string>;
	while(!s.eof())
	{
		std::getline(s, tmp, ',');
		absences->push(tmp);
		numAbsences++;
	}
}

void ListNode::addAbsence()
{
	std::stringstream ss;
	string date;
	time_t t = time(0);
	struct tm * now = localtime(&t);
	ss << (now->tm_year + 1900) << '-'
		<< (now->tm_mon + 1) << '-'
		<< now->tm_mday;
	date = ss.str();
	absences->push(date);
	numAbsences++;
}

string ListNode::getStudentInfo()
{
	std::stringstream ss;
	ss << (recordNumber) << ',' << idNumber << ',' << name << ',' << eMail
		<< ',' << units << ',' << program << ',' << level;
	string studentInfo = ss.str();
	return studentInfo;
}

string ListNode::getRecentAbsence()
{
	string recentAbsence = " ";
	absences->peek(recentAbsence);
	return recentAbsence;
}

string ListNode::getAllAbsences()
{
	std::stringstream ss;
	string tmp;
	Stack<string>* tmpStack = new Stack<string>;
	while (!absences->isEmpty())
	{
		absences->pop(tmp);
		ss << ',' << tmp;
		tmpStack->push(tmp);
	}
	while (!tmpStack->isEmpty())
	{
		tmpStack->pop(tmp);
		absences->push(tmp);
	}
	string allAbsences = ss.str();
	delete(tmpStack);
	return allAbsences;
}

int ListNode::getNumAbsences()
{
	return numAbsences;
}

ostream & operator <<(ostream& lhs, ListNode& rhs)
{
	return lhs << rhs.getStudentInfo() << rhs.getAllAbsences();
}