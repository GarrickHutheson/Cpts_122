#ifndef GROCERY_QUEUE_H
#define GROCERY_QUEUE_H
#include <stdio.h>
#include <string.h>
#include <windows.h>

typedef struct data
{
	int customerNumber; 
	int serviceTime;
	int totalTime;
}Data;

typedef struct queueNode
{
	Data *pData;

	struct queueNode *pNexft;
}QueueNode;

typedef struct queue
{
	QueueNode *pHead;
	QueueNode *pTail;
}Queue;

#endif