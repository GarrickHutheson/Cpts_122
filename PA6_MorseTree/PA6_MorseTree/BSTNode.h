#pragma once
/*
* Programmer: Garrick Hutcheson
* Programming Assignment 6: Morse Tree
* Date: 10/23/17
* File: BSTNode.h
* Description: Template for a BSTNode class with two data types in each node
*/

template <class T, class T2>
class Node
{
public:
	//constructor
	Node(T data1, T2 data2);

	//getters
	Node*& getLeft();
	Node*& getRight();
	T getData1();
	T2 getData2();
	
private:
	Node * mLeft;
	Node * mRight;
	T mData1;
	T2 mData2;
};

//constructor
template <class T, class T2>
Node<T, T2>::Node(T data1, T2 data2)
{
	mLeft = nullptr;
	mRight = nullptr;
	mData1 = data1;
	mData2 = data2;
}

//getters
template <class T, class T2>
Node<T,T2>*& Node<T, T2>::getLeft()
{
	return mLeft;
}
template <class T, class T2>
Node<T,T2>*& Node<T, T2>::getRight()
{
	return mRight;
}
template <class T, class T2>
T Node<T, T2>::getData1()
{
	return mData1;
}
template <class T, class T2>
T2 Node<T, T2>::getData2()
{
	return mData2;
}

