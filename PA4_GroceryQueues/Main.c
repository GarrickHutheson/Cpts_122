/*
* Programmer: Garrick Hutcheson
* Programming Assignment 4: Grocery Queues
* Date: 10/02/17
* File: GroceryQueues.c
* Description This file carries out the main logic of the Grocery Queue
* simulation/
*/

#include "GroceryQueues.h"



int main()
{
	srand(time(NULL));
	char userInput[100] = " ";
	int timeRunning = 0, currentTime = 0, totalTime = 0;
	int runTime = 0, randTime = 0, displayTime = 0, serviceTime = 0;
	int customerNumber = 1;
	int nextExpCust = 0, nextNormCust = 0;
	Data newCust = { 0, 0 ,0 }, finCust = { 0, 0, 0 };
	Queue expQ = { NULL, NULL };
	Queue normQ = { NULL, NULL };

	printf("Welcome to the Grocery Queue Simulation! Lets get started.\n"
		"How long would you like to run the simulation for?\n");

	//prompt user for input and screen for bad entries
	while(runTime <= 0)
	{
		printf("Please answer with a number that corresponds to simulated"
			" minutes: ");
		gets(userInput);
		runTime = atoi(userInput);
		if (runTime <= 0)
			printf("invalid entry.\n");
	}
	system("cls");
	
	//first customers shopping
	nextExpCust = randExp();
	nextNormCust = randNorm();

	//perform rest of simulation
	while (timeRunning <= runTime)
	{
		// reset clock and customer numbers at beginning of new day
		if (currentTime % 1440 == 0)
		{
			customerNumber = 1;
			currentTime = 0; 
		}

		//Print Queues and clear screen every 10 minutes
		if (displayTime == 9)
		{
			system("cls");
			printf("Express Queue:\n\n");
			printQueue(&expQ);
			printf("\nNormal Queue: \n\n");
			printQueue(&normQ);
			printf("\nActivity Log:\n");
			displayTime = 0;
		}
			
		//Express Arrival
		if (nextExpCust == 0)
		{
			nextExpCust = randExp();
			serviceTime = randExp();
			totalTime = getQueueTime(&expQ) + serviceTime;
			newCust = (Data) { customerNumber, serviceTime, totalTime };
			enqueue(&expQ, newCust);
			printf("Express Lane Arrival: At %d:%02d ",
					currentTime/60, currentTime%60); 
			printArrival(newCust);
			customerNumber++;
		}
		//Express Checkout
		if (expQ.pHead && expQ.pHead->pData->serviceTime == 0)
		{
			finCust = dequeue(&expQ);
			printf("Express Lane ");
			printCheckout(finCust);
		}
		//Normal Arrival
		if (nextNormCust == 0)
		{
			nextNormCust = randNorm();
			serviceTime = randNorm();
			totalTime = getQueueTime(&normQ) + serviceTime;
			newCust = (Data){customerNumber, serviceTime, totalTime};
			enqueue(&normQ, newCust);
			customerNumber++;
			printf("Normal Lane Arrival: At %d:%d ", 
					currentTime / 60, currentTime % 60);
			printArrival(newCust);
		}
		//Normal Checkout
		if (normQ.pHead && normQ.pHead->pData->serviceTime == 0)
		{
			finCust = dequeue(&normQ);
			printf("Normal Lane ");
			printCheckout(finCust);
		}
		
		
		Sleep(300); //sleep to display things
		//decrement counters that trigger new customer arrival
		nextExpCust--;
		nextNormCust--;
		//decrement serviceTime of customers being served
		if(expQ.pHead)
			expQ.pHead->pData->serviceTime--;
		if(normQ.pHead)
			normQ.pHead->pData->serviceTime--;
		//clock moves forward
		currentTime++;
		displayTime++;
		timeRunning++;
	}

}