/*
* Programmer: Garrick Hutcheson
* Programming Assignment 8: Data Analysis
* Date: 11/17/2017
* File: TransactionNode.cpp
* Description:  Function Definitions for TransactionNode class
*/
#pragma once
#include "TransactionNode.h"

TransactionNode::TransactionNode(const std::string data, const int units):Node(data)
{
	mUnits = units;
}


void TransactionNode::printData()
{
	std::cout << getData() << ", " << getUnits();
}

void TransactionNode::setUnits(int units)
{
	mUnits = units;
}

int TransactionNode::getUnits()
{
	return mUnits;
}
