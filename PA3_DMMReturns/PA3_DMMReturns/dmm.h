/*
* Programmer: Garrick Hutcheson
* Programming Assignment 2: Digital Music Manager returns
* Date: 9/24/17
* File: dmm.h
* This is the header file. It contains the prototypes for the functions in
* dmm.c and defines the structs used to store the data of the
* digital music manager
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>


typedef struct duration
{
	unsigned int minutes;
	unsigned int seconds;
}Duration;

typedef struct record
{
	char artist[100];
	char albumTitle[100];
	char songTitle[100];
	char genre[100];
	unsigned int playCount;
	unsigned int rating;
	Duration songLength;
}Record;

typedef struct node
{
	Record data;
	struct node *pPrev;
	struct node *pNext;
}Node;

Node *makeNode(char *song);
int insertFront(Node** pHead, char* song);
void fillDuration(char *time, Duration *pMem);
char* durationToString(Record* thisRecord);
void fillRecord(char *line, Node *newNode);
void editRecord(Record* recordEdit, int newRecord);
char* recordToString(Node *thisNode);
Node* load();
void display(Node *pHead);
void store(Node *pHead);
void printList(Node *pHead);
Node* search(Node *pHead);
int deleteNode(Node** pHead, Node* pDelete);
void sort(Node *pHead);
void shuffle(Node* pHead);
void play(Node* playFrom);
void rate(Record* song);
int screen(char* userInput);
int contains(char* string, char* substring);