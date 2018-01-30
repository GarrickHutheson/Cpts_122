/*
* Programmer: Garrick Hutcheson
* Programming Assignment 6: Morse Tree
* Date: 10/23/17
* File: morseWriter.cpp
* Description: Two helper functions to main to be used in conjunction with BST.h
*/
#pragma once
#include "morseWriter.h"
using std::string;



string stringToMorse(const string alpha, const BST <char, string>& morseTree)
{
	string morseString = "";
	char tempUpper = ' ';
	for (int i = 0; i < alpha.length(); i++)
	{
		tempUpper = toupper(alpha.at(i));
		if (tempUpper == ' ') //place 3 spaces between words
			morseString = morseString + "  "; 
		else if (tempUpper == '\n') //keep newlines
			morseString = morseString + '\n';
		else //convert all other characters to morse
		morseString += ' ' + morseTree.search(tempUpper); 
	}
	return morseString;
}

void fileToMorse(const string alphafile, const string morsefile,
						const BST <char, string>& morseTree)
{
	string convert;
	string converted;
	string temp = " ";
	std::ifstream input(alphafile);
	std::ofstream output(morsefile);
	std::getline(input, temp);
	convert = temp;

	
	while (!input.eof()) //put file into string
	{
		//retain formatting by appending new lines to string
		std::getline(input, temp); 
		convert += ("\n" + temp); 
	}
	
	std::cout << "Original file in English: \n" << convert << std::endl;
	converted = stringToMorse(convert, morseTree);
	output << converted;
	std::cout << "\n\nNew file in Morse: \n" << converted << std::endl;
}