/*
* Programmer: Garrick Hutcheson
* Programming Assignment 8: Data Analysis
* Date: 11/17/2017
* File: BST.h
* Description: BST to sort sales statistics from data.csv
*/
#pragma once
#include "TransactionNode.h"
#include <ios>
#include <iostream>

class BST
{
public:
	~BST();
	void setRoot(Node* root);
	Node* getRoot(Node* root);

	//inserts a node on to the tree in ascending order by int units
	void insert(const int units, const std::string type);

	//returns data of tree in ascending order
	void inOrderTraversal();

	//returns the node with smallest units value
	TransactionNode& findSmallest();

	//returns the node with largest units value
	TransactionNode& findLargest();

private:
	TransactionNode& findSmallest(Node* cur);
	TransactionNode& findLargest(Node* cur);
	void inOrderTraversal(Node* cur);
	void insert(Node* newNode, Node*& cur);

	//recursively deallocates all memory associated with BST
	void destroyTree(Node* root);
	Node* mpRoot;
};