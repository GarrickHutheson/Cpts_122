/*
* Programmer: Garrick Hutcheson
* Programming Assignment 4: Grocery Queues
* Date: 10/02/17
* File: GroceryQueues.c
* Collaboration: Andrew O'Fallon's code was used as a starting place for
* Queue, Dequeue, and makeNode functions.
* Description This file contains the helper functions to my program.
*/



#include "GroceryQueues.h"

// Allocates space for and initializes the data struct of a node on the heap
// Parameters: newCust - pointer to a Data struct containing values of new
// customer. Returns a pointer to the new QueueNode 
QueueNode* makeNode(Data* newCust)
{
	// allocates space for a Node only-->two pointers!
	QueueNode *pMem = (QueueNode *)malloc(sizeof(QueueNode));

	if (pMem) // did malloc () fail?
	{
		pMem->pNext = NULL;
		// need to allocate space for the Data!
		pMem->pData = (Data *)malloc(sizeof(Data));

		if (pMem->pData != NULL) // Data struct allocated
		{
			memcpy(pMem->pData, newCust, sizeof(Data));
		}
	}
	return pMem;
}

// Enqueues a node at the end of the Queue
// Parameters: newCust - Data struct containing values of new Customer
// pQ: Pointer to queue the QueuNode will be added to
// returns an int indicating success
int enqueue(Queue* pQ, Data newCust)
{
	QueueNode* pMem = makeNode(&newCust);
	int success = 0;

	if (pMem != NULL) // memory was successfully allocated
	{
		if (pQ->pHead == NULL) // empty?
		{
			// it's an empty queue!
			// connect both the head and tail to the one new node
			pQ->pHead = pQ->pTail = pMem;
			success = 1;
		}
		else // not empty
		{
			pQ->pTail->pNext = pMem;
			pQ->pTail = pMem;
			success = 1;
		}
	}

	return success;
}

// Dequeues node at head of list and frees all data associated with it
// Parameters: pointer to Queue to have front node dequeued
// Returns: a Data struct with data that was removed from Queue
// precondition: queue must not be empty
Data dequeue(Queue* pQ)
{
	Data returnData = { NULL };

	QueueNode *pDelete = pQ->pHead;

	if (pQ->pHead == pQ->pTail) // 1 node in queue?
	{
		returnData = *(pQ->pHead->pData); // make copy of data to return
		pQ->pHead = NULL; // List going to be empty so pointers null
		pQ->pTail = NULL;
		// free memory by freeing pDelete
		free(pDelete->pData);
		free(pDelete);
	}
	else // more than 1 node in queue
	{
		returnData = *(pQ->pHead->pData);
		pQ->pHead = pQ->pHead->pNext; //point Head of list to next node
		free(pDelete->pData);
		free(pDelete);
	}

	// you see common code in the if-else, could factor
	// out and place outside of if-else!!!

	return returnData;
}

// Sums the total service time of nodes currently in queue
// Parameters: Pointer to Queue to be analyzed
// Returns: int that corresponds to total minutes in queue
int getQueueTime(Queue* pQ)
{
	int queueTime = 0;
	QueueNode* pCur = pQ->pHead;

	//sum up serviceTimes of all current QueueNodes
	while (pCur) 
	{
		queueTime += pCur->pData->serviceTime;
		pCur = pCur->pNext;
	}
	return queueTime;
}

// Returns a random number in the range of 3-8, which is how long it takes
// for a customer to arrive to the normal lane or to check out once
// they are being served.
int randNorm()
{
	int random = rand() % 5 + 4;
	return random;
}

// Returns a random number in the range of 1-5, which is how long it takes
// for a customer to arrive to the express lane or to check out once
// they are being served.
int randExp()
{
	int random = rand() % 5 + 1;
	return random;
}

// Prints a readout of the customers Currently in the queue to the console
// Parameter: pointer to Queue to be printed.
void printQueue(Queue* pQ)
{
	QueueNode* pCur = pQ->pHead;
	Data* pData = NULL;

	printf("Customer#\tService Time\tTotal Time");
	printf("\n********************************************");
	while (pCur)
	{
		pData = pCur->pData;
		printf("\n%d\t\t%d\t\t%d\n", pData->customerNumber, pData->serviceTime,
							pData->totalTime);

		pCur = pCur->pNext;
	}

}

// Prints a message about the customer arriving
// parameters: cust- Data struct with information of customer
void printArrival(Data cust)
{
	printf("Customer#%d Got in line\n",
		cust.customerNumber);
}

// Prints a message about the customer checking out
// parameters: cust- Data struct with information of customer
void printCheckout(Data cust)
{
	printf("Checkout: Customer#%d Spent %d minutes in line\n",
		cust.customerNumber, cust.totalTime);
}