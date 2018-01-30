/*
* Programmer: Garrick Hutcheson
* Programming Assignment 6: Morse Tree
* Date: 10/23/17
* File: BST.h
* Description:  This template creates a binary search tree with 2 data types in each node
* out of a .txt file formatted as "(Data of Type1) (Data of Type2) (Data of Type1) etc..." 
* As such it functions as a good look up table for conversion. 
*/
#pragma once
#include "BSTNode.h"
#include <string>
#include <fstream>
#include <iostream>

template <class T, class T2>
class BST
{
public:
	//Constructor makes binary search tree out of file
	//precondition : .txt file must be formatted correctly
	//example: "int char int char"
	BST(std::string fileName);
	
	//Destructor only calls recursiveDestruct to delet all nodes in tree
	~BST();

	//recursively does postorder traversal and deletes all nodes in tree
	void recursiveDestruct(Node<T, T2>* root);

	//public interface to recursive search algorithm
	T2 search(const T data1) const;

	//public interface to recursive print algortithm
	void inOrderPrint() const;



private:
	Node<T,T2> * mRoot; //BSTnode of same type as templated BST

	//inserts a node in order
	//no public interface needed as only called by constructor
	bool insert(const T &data1, const T2 &data2, Node<T,T2> *& pCur);

	//search function returns T2 to corresponding T1 searched for
	T2 search(T data1, Node<T,T2>* pCur) const;

	//print fucntion prints tree in ascending order of T1
	void inOrderPrint(Node<T,T2>* pCur) const;
};

//constructor creates data from text file.
template<class T, class T2>
BST<T, T2>::BST(std::string filename)
{
	T data1;
	T2 data2;
	std::ifstream input(filename);
	input >> data1;
	input >> data2;
	mRoot = new Node<T,T2>(data1, data2); //construct root node
	while (!input.eof()) //construct all other nodes
	{
		input >> data1;
		input >> data2;
		insert(data1, data2, mRoot);
	}
	input.close();
}

//deconstructor only calls recursiveDestruct to delet all nodes in tree
template<class T, class T2>
BST<T, T2>::~BST()
{
	recursiveDestruct(mRoot);
}

//recursively does postorder traversal and deletes all nodes in tree
template<class T, class T2>
void BST<T, T2>::recursiveDestruct(Node<T, T2>* root)
{
	Node<T, T2>* pDelete = root;
	if (pDelete != nullptr)
	{
		recursiveDestruct(pDelete->getLeft());
		recursiveDestruct(pDelete->getRight());
		delete pDelete;
	}
}

//inserts data in to node on tree in order of data type T.
template<class T, class T2>
bool BST<T, T2>::insert(const T &data1, const T2 &data2, Node<T, T2> *& pCur)
{
	bool success = false;
	if (pCur == nullptr) //unassigned pointer -- no node here yet
	{
		Node<T, T2> * pMem = nullptr; // make pointer for new node.
		pMem = new Node<T,T2>(data1, data2); // pMem points to new node on heap
		if (pMem != nullptr) //check for success
		{
			success = true;
			pCur = pMem; // node now connected to tree.
		}
	}
	else if (data1 > (pCur->getData1())) //traverse right if greater
		success = insert(data1, data2, pCur->getRight());

	else if (data1 < (pCur->getData1())) //traverse left if less
		success = insert(data1, data2, pCur->getLeft());

	else //will only end up here if there are duplicates in file
	{
		std::cout << "Duplicate found. Check your data." << std::endl;
	}
	return success;
}

// search looks for data of type T in tree and returns corresponding
// data of type T2
template<class T, class T2>
T2 BST<T, T2>::search(const T data1) const
{
	return search(data1, mRoot);
}

//private implementation of T2 BST<T,T2>::search()
template<class T, class T2>
T2 BST<T, T2>::search(const T data1, Node<T,T2> * pCur) const
{
	T2 found;
	if(pCur == nullptr)
		std::cout << "data not found" << std::endl;
	else if (pCur->getData1() == data1)
		found = pCur->getData2();
	else if (data1 < pCur->getData1())
		found = search(data1, pCur->getLeft());
	else if (data1 > pCur->getData1())
		found = search(data1, pCur->getRight());

	return found;
}

// does an inorder traversal and prints BST in ascending order of T.
template<class T, class T2>
void BST<T, T2>::inOrderPrint() const
{
	inOrderPrint(mRoot);
}

// private implementation of BST<T,T2>::inOrderPrint()
template<class T, class T2>
void BST<T, T2>::inOrderPrint(Node<T,T2> * pCur) const
{
	if (pCur != nullptr)
	{
		inOrderPrint(pCur->getLeft());
		std::cout << pCur->getData1() << pCur->getData2() << std::endl;
		inOrderPrint(pCur->getRight());
	}
}
