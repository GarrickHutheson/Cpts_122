/*
* Programmer: Garrick Hutcheson
* Programming Assignment 8: Data Analysis
* Date: 11/17/2017
* File: BST.cpp
* Description:  Function definitions for BST class
*/

#pragma once
#include "BST.h"


BST::~BST()
{
	destroyTree(mpRoot);
}

//recursively deallocates all memory associated with BST
void BST::destroyTree(Node* root)
{
	Node* pDelete = root;
	if (pDelete != nullptr)
	{
		destroyTree(pDelete->getLeft());
		destroyTree(pDelete->getRight());
		delete pDelete;
	}
}

void BST::setRoot(Node* root)
{
	mpRoot = root;
}

Node * BST::getRoot(Node * root)
{
	return nullptr;
}

//creates a dynamically allocated TransactionNode with int units and string type
//inserts a node on to the tree in ascending order by units
void BST::insert(const int units, const std::string type)
{
	TransactionNode* newNode = new TransactionNode(type, units);
	insert(newNode, mpRoot);
}

//interface. displays data of tree in ascending order
void BST::inOrderTraversal()
{
	inOrderTraversal(mpRoot);
}

//accepts pointer to root of BST
//recursivesly traverses tree and displays each Node in order
void BST::inOrderTraversal(Node * cur)
{
	if (cur != nullptr)
	{
		inOrderTraversal(cur->getLeft());
		std::cout << cur->getData() << ", " <<
			dynamic_cast<TransactionNode*>(cur)->getUnits() << '\n';
		inOrderTraversal(cur->getRight());
	}
}

//interface. returns reference to TransactionNode with smallest unit value
TransactionNode & BST::findSmallest()
{
	return findSmallest(mpRoot);
}

//interface. returns reference to TransactionNode with biggest unit value
TransactionNode & BST::findLargest()
{
	return findLargest(mpRoot);
}

//recursively traverses BST to find TransactionNode with smallest unit value
TransactionNode & BST::findSmallest(Node * cur)
{
	if (cur != nullptr)
	{
		if(cur->getLeft() != nullptr)
			return findSmallest(cur->getLeft());
		return *(dynamic_cast<TransactionNode*>(cur));
	}
}

//recursively traverses BST to find TransactionNode with biggest unit value
TransactionNode & BST::findLargest(Node * cur)
{
	if (cur != nullptr)
	{
		if (cur->getRight() != nullptr)
			return findLargest(cur->getRight());
		return *(dynamic_cast<TransactionNode*>(cur));
	}
}

//inserts a node on to the tree in ascending order by int units
//newNode accepts Node to be inserted. cur accepts current node of traversal
void BST::insert(Node * newNode, Node *& cur)
{
	if (cur == nullptr)
	{
		cur = newNode;
	}
	
	else if (dynamic_cast <TransactionNode*>(newNode)->getUnits() <
		dynamic_cast <TransactionNode*>(cur)->getUnits())
	{
		insert(newNode, cur->getLeft());
	}

	else if (dynamic_cast <TransactionNode*>(newNode)->getUnits() >
		dynamic_cast <TransactionNode*>(cur)->getUnits())
	{
		insert(newNode, cur->getRight());
	}

}
