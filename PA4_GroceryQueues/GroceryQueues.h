/*
* Programmer: Garrick Hutcheson
* Programming Assignment 4: Grocery Queues
* Date: 10/02/17
* File: GroceryQueues.h
* Description This is the header file. It includes library headers and defines
* structs. Also contains prototypes to all functions in GroceryQueues.c
*/

#ifndef GROCERY_QUEUE_H
#define GROCERY_QUEUE_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>


typedef struct data
{
	int customerNumber;
	int serviceTime;
	int totalTime;
} Data;

typedef struct queueNode
{
	Data* pData;
	struct queueNode* pNext;
}QueueNode;

typedef struct queue
{
	QueueNode* pHead;
	QueueNode* pTail;
}Queue;

QueueNode* makeNode(Data* newCust);
int enqueue(Queue* pQ, Data newCust);
Data dequeue(Queue* pQ);
int getQueueTime(Queue* pQ);
int randNorm();
int randExp();
void printQueue(Queue* pQ);
void printArrival(Data cust);
void printCheckout(Data cust);

#endif // !GROCERY_QUEUE_H
