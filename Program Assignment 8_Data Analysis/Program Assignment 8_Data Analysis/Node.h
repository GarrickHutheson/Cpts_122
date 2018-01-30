/*
* Programmer: Garrick Hutcheson
* Programming Assignment 8: Data Analysis
* Date: 11/17/2017
* File: Node.h
* Description:  Node class works with BST class
*/
#pragma once
#include <string>
#include <iostream>
class Node
{
public:
	//constructor for node
	Node(std::string data);
	//pure virtual function to print data of inherited classes
	virtual void printData() =0;

	//setters
	void setData(std::string data);
	void setLeft(Node* left);
	void setRight(Node* right);

	//getters
	std::string getData();
	Node*& getLeft();
	Node*& getRight();
protected:
	std::string mData; //stores type of product
	Node* mpLeft;
	Node* mpRight;
};
