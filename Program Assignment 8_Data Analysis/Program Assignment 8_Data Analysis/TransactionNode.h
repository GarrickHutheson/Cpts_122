/*
* Programmer: Garrick Hutcheson
* Programming Assignment 8: Data Analysis
* Date: 11/17/2017
* File: TransactionNode.h
* Description:  TransactionNode inherits from Node.h and represents
* a node specifically about Transaction data from some sort of store
*/
#pragma once
#include "Node.h"
class TransactionNode : public Node
{
public:
	TransactionNode(const std::string data,const int units);
	void printData();
	//setters
	void setUnits(int units);
	int getUnits();
private:
	int mUnits;
};