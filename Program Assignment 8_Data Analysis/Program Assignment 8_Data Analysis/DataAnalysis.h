/*
* Programmer: Garrick Hutcheson
* Programming Assignment 8: Data Analysis
* Date: 11/17/2017
* File: DataAnalysis.h
* Description:  Data Analysis object makes two BST's out of a csv file containing statistics
* about the sales at a store.
*/

#pragma once
#include <fstream>
#include <iostream>
#include <ios>
#include "BST.h"
#include <sstream>

class DataAnalysis
{
public:
	//analyzes and displays sales data in ascending order and shows
	//largest and smallest sales and purchase numbers
	void runAnalysis();

private:
	//opens "data.csv" file for reading
	void openFile();

	//parses one line of data and splits it in to different fields which are passed to the function
	//as references
	void parseLine(int& units, bool& purchased, std::string& type, std::string& line);

	//takes each line of .csv and parses them, then inserts them into appropriate BST
	void parseFile();

	//Inserts node on BST. If purchased is true, inserts node on purchased tree
	//creates nodes based on units argument and type argument
	void sortAndInsertNode(const int units, const bool purchased, const std::string type);

	//outputs sales data to console
	void displayTrends();

	//contains data about sold items
	BST mTreeSold;

	//contains data about purchased items
	BST mTreePurchased;

	//ifstream for reading from .csv file
	std::ifstream mCsvStream;
};