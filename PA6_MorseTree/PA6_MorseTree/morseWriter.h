#pragma once
#include <string>
#include <ios>
/*
* Programmer: Garrick Hutcheson
* Programming Assignment 6: Morse Tree
* Date: 10/23/17
* File: morseWriter.h
* Description: Two helper functions to main to be used in conjunction with BST.h
* I couldn't think of a way to make these generic due to the specific nature of output needed.
* 3 spaces between every morse word and one space between every morse character seemed like
* too specific a formatting to template for.
*/
#include <fstream>
#include "BST.h"
using std::string;

// takes an alphanumeric string and returns a morse code string.
string stringToMorse(const string alpha, const BST <char, string>& morseTree);
//takes a file in alphanumeric characters and outputs to another file in morse code. 
void fileToMorse(const string alphafile, const string morsefile, const BST <char, string>& morseTree);
