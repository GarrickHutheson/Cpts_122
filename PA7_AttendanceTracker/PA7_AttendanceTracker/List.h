/*
* Programmer: Garrick Hutcheson
* Programming Assignment 7: Attendance Tracker
* Date: 10/23/17
* File: List.h
* Description: Attendance Tracker program file
*/

#pragma once
#include "ListNode.h" 
#include <iostream>
#include <fstream>

class List
{
public:
	~List();
	void destroyList();
	void insertAtFront(ListNode* newNode);
	void loadList(std::ifstream& inFile);
	void storeList(std::ofstream& outFile);
	void markAbsences();
	void allAbsences(int min);
	void mostRecentAbsence();


private:
	void destroyList(ListNode* const pMem);
	ListNode* mHead;
};