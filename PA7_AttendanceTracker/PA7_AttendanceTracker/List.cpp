/*
* Programmer: Garrick Hutcheson
* Programming Assignment 7: Attendance Tracker
* Date: 10/23/17
* File: List.cpp
* Description: Attendance Tracker program file
*/

#include "list.h"


void List::insertAtFront(ListNode* newNode)
{
	ListNode* pTemp = mHead;
	mHead = newNode;
	mHead->mNext = pTemp;
	
}

//writes data from file to list;
void List::loadList(std::ifstream& inFile)
{
	destroyList();
	string line;
	getline(inFile, line);
	while (!inFile.eof())
	{
		getline(inFile, line);
		if (line != "")
		{
			ListNode * newNode = new ListNode(line);
			insertAtFront(newNode);
		}
	}
}

void List::storeList(std::ofstream& outFile)
{

	ListNode* pCur = mHead;
	while (pCur != nullptr)
	{
		outFile << *pCur << endl;
		pCur = pCur->mNext;
	}
}
List::~List()
{
	destroyList();
}

void List::markAbsences()
{
	ListNode* pCur = mHead;
	string input = "";

	while (pCur != nullptr)
	{
		cout << "Was " << pCur->name << " present in class today? (y or n)" << endl;
		cin >> input;
		if (tolower(input.at(0)) == 'n')
		{
			pCur->addAbsence();
		}
		pCur = pCur->mNext;
	}
}

void List::allAbsences(int min)
{
	string output = " ";
	ListNode* pCur = mHead;
	while (pCur != nullptr)
	{
		if (pCur->numAbsences >= min)
			output = pCur->getStudentInfo();
			output += pCur->getAllAbsences();
		pCur = pCur->mNext;
		cout << output << endl;
	}
}

void List::mostRecentAbsence()
{
	string output = " ";
	ListNode* pCur = mHead;
	while (pCur != nullptr)
	{
		output = pCur->getStudentInfo();
		output += ',' + pCur->getRecentAbsence() + '\n';
		cout << output;
		pCur = pCur->mNext;
	}
}

void List::destroyList(ListNode * const pMem)
{
	if (pMem != nullptr)
	{
		destroyList(pMem->mNext);
		delete pMem;    // delete from the back of list to the front!
	}
}

void List::destroyList()
{
	destroyList(mHead);
	mHead = nullptr;
}