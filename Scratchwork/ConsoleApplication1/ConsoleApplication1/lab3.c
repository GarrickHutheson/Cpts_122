#include "Header.h"
int isEmpty(Node * stack)
{
	return (!stack);
}

void push(Node ** stack, int data)
{
	Node * pNew = (Node *)malloc(sizeof(Node));
	pNew->pNext = NULL;
	pNew->data - data;

	pNew->pNext = *stack;
	*stack = pNew;
}

//pre: Stack not empty
//call isEmpty() before pop
int pop(Node ** stack)
{
	int temp = (*stack) ->data; //grab data
	Node *pTemp = *stack; //make pointer to pointer to be deleted
	*stack = (*stack)->pNext; //assign new head to node after current head
	free(pTemp); //delete old head 

	return temp;
}

//pre: Stack not empty
int peek(Node * stack)
{
	return stack->data;
}

int traverse(char maze[][8], int x, int y) {

}