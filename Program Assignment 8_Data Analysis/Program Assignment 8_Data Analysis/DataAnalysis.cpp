/*
* Programmer: Garrick Hutcheson
* Programming Assignment 8: Data Analysis
* Date: 11/17/2017
* File: DataAnalysis.cpp
* Description:  Function definitions for DataAnalysis class
*/

#include "DataAnalysis.h"

//analyzes and displays sales data in ascending order and shows
//largest and smallest sales and purchase numbers
void DataAnalysis::runAnalysis()
{
	parseFile();
	displayTrends();
}

//opens "data.csv" file for reading
void DataAnalysis::openFile()
{
	if (mCsvStream.is_open())
	{
		mCsvStream.close();
	}
	mCsvStream.open("data.csv");
}

//data analysis accepts a reference to a line from the file in string& line
//int& units and string& type will be set to data found in this line of file
//bool& purchased will be set to true if this record in .csv is about purchase data
 void DataAnalysis::parseLine(int& units, bool& purchased, std::string& type, std::string& line)
{

	 std::string tmp;
	 std::stringstream s(line);

	 std::getline(s, tmp, ',');

	 units = stoi(tmp);
	 std::getline(s, type, ',');
	 std::getline(s, tmp);
	 if (tmp == "Purchased")
	 {
		 purchased = true;
	 }
	 else
	 {
		 purchased = false;
	 } 
}

 //takes each line of .csv and parses them, then inserts them into appropriate BST
 void DataAnalysis::parseFile()
 {
	 openFile();
	 std::string line;
	 std::getline(mCsvStream, line);
	 int tmpUnits = 0;
	 bool tmpPurchased = 0;
	 std::string tmpType = "";
	 while (!mCsvStream.eof())
	 {
		 std::getline(mCsvStream, line);
		 if (line == "")
			 continue;
		 parseLine(tmpUnits, tmpPurchased, tmpType, line);
		 sortAndInsertNode(tmpUnits, tmpPurchased, tmpType);
	 }
 }

 //Inserts node on BST. If purchased is true, inserts node on purchased tree
 //constructs nodes with  int units and string type
 void DataAnalysis::sortAndInsertNode(const int units, const bool purchased, const std::string type)
 {
	 if (purchased)
	 {
		 mTreePurchased.insert(units, type);
	 }
	 else
	 {
		 mTreeSold.insert(units, type);
	 }
 }

 //outputs sales data to console
 void DataAnalysis::displayTrends()
 {
	 std::cout << "Sold Statistics:" << std::endl;
	 mTreePurchased.inOrderTraversal();

	 TransactionNode pTmp = mTreePurchased.findSmallest();
	 std::cout << "Least Purchased: " << pTmp.getData() << ", " << pTmp.getUnits() << std::endl;

	 pTmp = mTreePurchased.findLargest();
	 std::cout << "Most Purchased: " << pTmp.getData() << ", " << pTmp.getUnits() << std::endl;

	 std::cout << "\nPurchased Statistics:" << std::endl;
	 mTreeSold.inOrderTraversal();

	 pTmp = mTreeSold.findSmallest();
	 std::cout << "Least Sold: " << pTmp.getData() << ", " << pTmp.getUnits() << std::endl;

	 pTmp = mTreeSold.findLargest();
	 std::cout << "Most Sold: " << pTmp.getData() << ", " << pTmp.getUnits() << std::endl;
 }