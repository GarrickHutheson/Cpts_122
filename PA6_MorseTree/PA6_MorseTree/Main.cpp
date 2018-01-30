/*
* Programmer: Garrick Hutcheson
* Programming Assignment 6: Morse Tree
* Date: 10/02/17
* File: main.cpp
* Description: instantiates a BST object from the template defined in BST.h
* Uses converts the file convert.txt and echoes conversion to screen using functions from
* morseWriter.cpp
*/

#pragma once
#include "BST.h"
#include "morseWriter.h"
#include <string>

int main()
{
	//instantiate BST of type char, string and fill it with morseTable.txt
	const BST<char, std::string> morseKey("morseTable.txt");
	morseKey.inOrderPrint(); // print out tree in Ascending order
	system("pause"); 
	system("cls");
	//use morseKey BST in conjuction with helper function to convert alpha file to morse
	fileToMorse("convert.txt", "converted.txt", morseKey); 
	system("pause");
	return 0;
}