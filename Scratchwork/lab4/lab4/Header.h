#pragma once
#include <stdlib.h>

typedef struct node {
	double data;
	struct node * pNext;
}Node;

typedef struct queue {
	Node * pHead;
	Node * pTail;
}Queue;

Node * makeNode(double data)
{
	Node * temp = (Node *)malloc(sizeof(Node));
	temp->pNext = NULL;
	temp->data = data;
}

int isEmpty(Node* pHead)
{
	return !pHead;
}

int queueIsEmpty(Queue * q)
{
	return (q && !q->pHead);
}

int enqueue(Queue * q, double data)
{
	if (q)
	{
		if (q->pTail)
		{
			q->pTail->pNext = makeNode(data);
			q->pTail = q->pTail->pNext;
		}
		else {
			q->pTail = makeNode(data);
		}
		return 1;
	}
	return 0;
}

int dequeue(Queue * q)
{
	double value;
	Node * pTemp = NULL;
	if (q && q->pHead)
	{
		pTemp = q->pHead;
		value = q->pTail->data;
		q->pHead = q->pHead->pNext;
		free(pTemp);
		return value;
	}
	return -1;
}