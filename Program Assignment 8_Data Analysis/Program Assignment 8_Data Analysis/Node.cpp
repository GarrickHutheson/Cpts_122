/*
* Programmer: Garrick Hutcheson
* Programming Assignment 8: Data Analysis
* Date: 11/17/2017
* File: Node.cpp
* Description: Fucntion Definitions from Node.cpp
*/

#pragma once
#include "Node.h"

Node::Node(std::string data)
{
	mData = data;
	mpRight = nullptr;
	mpLeft = nullptr;
}

void Node::setData(std::string data)
{
	mData = data;
}

void Node::setLeft(Node* left)
{
	mpLeft = left;
}

void Node::setRight(Node* right)
{
	mpRight = right;
}

std::string Node::getData()
{
	return mData;
}

Node*& Node::getLeft()
{
	return mpLeft;
}

Node*& Node::getRight()
{
	return mpRight;
}