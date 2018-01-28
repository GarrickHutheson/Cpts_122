/*
* Programmer: Garrick Hutcheson
* Programming Assignment 3: Digital Music Manager Returns
* Date: 9/24/17
* File: dmm.c
* This file contains the helper functions to my structs and main
* Citation: in my search() and sort() functions I referenced code found in this thread
* to help me learn how to offset a pointer to a member in a struct
* https://stackoverflow.com/questions/2043871/how-can-i-get-set-a-struct-member-by-offset
*/

#include "dmm.h"
// Input: line: a pointer to a string in the format found in musicplaylist.csv
// Allocates space for a Node for a doubly linkedlist on the heap. Uses line
// to initialize values in record. if line is NULL uses editRecord to fill
// record with values of their choosing. Returns pointer to newNode
Node *makeNode(char *line)
{
	Node *pMem = NULL;

	pMem = (Node*)malloc(sizeof(Node));

	if (pMem)
	{
		pMem->pNext = NULL;
		pMem->pPrev = NULL;
		if (line)
			fillRecord(line, pMem);
		else
			editRecord(&pMem->data, 1);
	}
	return pMem;
}
// input: pHead pointer to address of head of list. Line: pointer to line
// in format of musicPlaylist.csv. Null pointer also works.
// inserts an item at the front of the linked list. Uses makenode to
// create and initialize the new node. returns an int indicating success
int insertFront(Node** pHead, char* line)
{
	int success = 0;
	Node *pMem = NULL;
	pMem = makeNode(line);
	if (pMem)
	{
		success = 1;

		if (*pHead == NULL) // dealing with an empty list
		{
			(*pHead) = pMem;
		}
		else // not dealing with empty list
		{
			pMem->pNext = *pHead;
			(*pHead)->pPrev = pMem;
			*pHead = pMem;
		}
	}

	return success;
}

// takes string of length of song and fills duration struct
// Precondition: time passed to function in format "xx:xx"
// Returns pointer to new Duration struct
void fillDuration(char *time, Node* thisNode)
{
	Duration* editDuration = &thisNode->data.songLength;
	char timeCopy[50] = " ";
	strcpy(timeCopy, time);
	editDuration->minutes = atoi(strtok(timeCopy, ":"));
	editDuration->seconds = atoi(strtok(NULL, ":"));
}

// converts data in duration to a string and returns it in the format
// "minutes:seconds". Accepts Record* that contains duration
char* durationToString(Node* thisNode)
{
	Duration *time = &thisNode->data.songLength;
	char durationString[50] = " ";
	sprintf(durationString, "%d:%02d", time->minutes, time->seconds);
	return durationString;
}

// Allocates memory for and fills a record struct that holds information about
// songs in music library. Precondition: string in the following format:
// "artist, album, song, genre, (length) xx:xx, playcount, rating\n"
// Returns pointer to newRecord
void fillRecord(char *line, Node* thisNode)
{
	Record* newRecord = &thisNode->data;
	char timeTemp[7] = "00:00";
	char artist[100] = "\"";
	char lineCopy[800] = " ";

	strcpy(lineCopy, line);
	if (lineCopy[0] == '\"')//Check for quotated artist
	{
		strcat(artist, strtok(lineCopy, "\""));
		strcat(artist, "\"");
	}
	else//artist not in quotations, go straight to tokenizing with comma
		strcpy(artist, strtok(lineCopy, ","));

	strcpy(newRecord->artist, artist);
	strcpy(newRecord->albumTitle, strtok(NULL, ","));
	strcpy(newRecord->songTitle, strtok(NULL, ","));
	strcpy(newRecord->genre, strtok(NULL, ","));
	strcpy(timeTemp, strtok(NULL, ","));
	newRecord->playCount = atoi(strtok(NULL, ","));
	newRecord->rating = atoi(strtok(NULL, ","));
	fillDuration(timeTemp, thisNode);
}

//input: recordEdit, a pointer to the record to be edited
//input:if newRecord = 1 function skips prompt and edits every field
//if called with newRecord = 0,user may edit one or all fields of the 
//record.
void editRecord(Node* thisNode, int newRecord)
{
	char userInput[100] = " ";
	int userCommand = 0;
	int index = 0;
	Record * recordEdit = &thisNode->data;
	int safeness = 0; //this int is used to screen for bad user input
	if (newRecord == 1) //skip prompt and set all fields if new record
		userCommand = 8;
	else
	{
		printf("\nWhat field of the record would you like to edit?\n"
			"(1)   Artist\n"
			"(2)   Album Title\n"
			"(3)   Song Title\n"
			"(4)   Genre\n"
			"(5)   Song Length\n"
			"(6)   Play Count\n"
			"(7)   Rating\n"
			"(8)   All fields\n");
		userCommand = menuPrompt(8);
	}

	switch (userCommand)
	{
	case 1:
	case 8://artist

		while (safeness == 0) // don't let user proceed until input good
		{
			safeness = 1;
			printf("What would you like to set the artist to?\n");
			gets(userInput);
			//check for commas that will affect formatting in csv file
			for (index = 0; userInput[index]; index++)
				if (userInput[index] == ',')
					safeness = 0;
			//if quotations around artist formatting okay
			if (userInput[0] == '\"' &&
				userInput[strlen(userInput) - 1] == '\"')
				safeness = 1;
			//check for an empty string to avoid 2 commas next to each other
			else if (userInput[0] == '\0')
				safeness = 0;
			//if string isn't safe let the user know and prompt again.
			if (safeness == 0)
				printf("If your entry contains commas it must be contained "
					"in quotes. Must also not be empty.\n");
		}
		strcpy(recordEdit->artist, userInput);
		printf("Artist changed to: %s\n", recordEdit->artist);
		printf("Press any key to continue...\n\n");
		getch();
		safeness = 0;
		if (userCommand != 8)
			break;

	case 2://album title
		while (safeness == 0)
		{
			printf("What would you like to set the album title to?\n");
			gets(userInput);
			safeness = screen(userInput);
		}
		strcpy(recordEdit->albumTitle, userInput);
		printf("Album title changed to: %s\n", recordEdit->albumTitle);
		printf("Press any key to continue...\n");
		getch();
		safeness = 0;
		if (userCommand != 8)
			break;
	case 3: //song title
		while (safeness == 0)
		{
			printf("What would you like to set the song title to?\n");
			gets(userInput);
			safeness = screen(userInput);
		}
		strcpy(recordEdit->songTitle, userInput);
		printf("Song title changed to: %s\n", recordEdit->songTitle);
		printf("Press any key to continue...\n");
		safeness = 0;
		if (userCommand != 8)
			break;
	case 4: //genre
		while (safeness == 0)
		{
			printf("What would you like to set the genre to?\n");
			gets(userInput);
			safeness = screen(userInput);
		}
		strcpy(recordEdit->genre, userInput);
		printf("Genre set to: %s\n", recordEdit->genre);
		printf("Press any key to continue...\n");
		getch();
		if (userCommand != 8)
			break;
	case 5: //song length
 		printf("Setting time.\n ");
		printf("How many minutes in this song?\n" //get minutes
			"I won't believe it if you say more than 32766.\n");
		recordEdit->songLength.minutes = menuPrompt(32766);
		printf("How many seconds in this song?\n" //get seconds
			"the number of seconds must be less than 60.\n");
		recordEdit->songLength.seconds = menuPrompt(59);
		strcpy(userInput, durationToString(recordEdit));
		printf("Duration of song set to: %s\n", userInput);
		printf("Press any key to continue...\n");
		getch();
		if (userCommand != 8)
			break;
	case 6: //play count
		printf("How many times have you listened to this song?\n"
			"I won't believe it if you say more than 32766.\n");
		recordEdit->playCount = menuPrompt(32766);
		printf("Play count set to: %d\n", recordEdit->playCount);
		printf("Press any key to continue...\n");
		getch();
		if (userCommand != 8)
			break;
	case 7:
		rate(recordEdit);
		if (userCommand != 8)
			break;
	default:
		break;
	}
}

// returns a string that outputs the data in a record in the format of
// a line of the musicPlayList.csv file
char* recordToString(Node* thisNode)
{
	Record * songInfo = &thisNode->data;
	char recordString[200] = " ";
	char time[7] = " ";
	strcpy(time, durationToString(songInfo));
	//Format the string with commas in between fields
	sprintf(recordString, "%s,%s,%s,%s,%s,%d,%d\n", songInfo->artist, 
			songInfo->albumTitle, songInfo->songTitle, songInfo->genre, 
			time, songInfo->playCount, songInfo->rating);

	return recordString;
}

// creates a linked list and fills it with data from file in local directory
// "musicPlaylist.csv"
// precondition: data in csv file in format:
// "artist,album,song,genre,(length)xx:xx,playcount,rating\n"
// Returns pointer to head of created linked list
Node* load()
{
	FILE *infile = fopen("musicPlayList.csv", "r"); //open file
	char line[200] =" "; //store lines pulled from file
	fgets(line, 200, infile);
	Node *pHead = makeNode(line);
	while(fgets(line, 200, infile))
		insertFront(&pHead, line);
	fclose(infile);//close file

	return pHead;
}

// gives user option to display all records or all songs
// from one artist. 
void display(Node* pHead)
{
	int userCommand = 0;
	printf("Display:\n 1. All records\n 2. Search for a Record\n");
	userCommand = menuPrompt(2);
	if (userCommand == 1)
	{
		printList(pHead);
		printf("\n These are all your songs. Press any key to continue...");
		getch();
	}
	else
		search(pHead);
}

// Stores data contained in linked list in "musicPlaylist.csv"
// Overwrites any data already contained in file
void store(Node* pHead)
{
	char line[200] = " ";
	FILE *outfile = fopen("musicPlayList.csv", "w");
	while (pHead->pNext) //traverse to tail of list
		pHead = pHead->pNext;

	while (pHead) //store lines of data while traversing to head of list
	{
		strcpy(line, recordToString(&pHead->data));
		fprintf(outfile, "%s", line);
		pHead = pHead->pPrev;
	}
	fclose(outfile);
}

// displays contents of all records in list to console.
// accepts a pointer to head of linked list.
void printList(Node *pHead)
{
	char line[200] = " ";
	Node* pCur = pHead;
	while (pCur->pNext) //traverse to tail of list
		pCur = pCur->pNext;
	while (pCur) //print while traversing to head
	{
		strcpy(line, recordToString(pCur));
		printf(line);
		pCur = pCur->pPrev;
	}
}

// searches through the linked list passed to function for a song
// user may define field they wish to search by.
// if successful returns pointer to the record selected by the user
Node* search(Node *pHead)
{ 
	char* pSearchField = NULL;
	size_t addressOffset = 0;
	Node* results[100] = { '\0' }; //holds search results
	char userInput[100]= " ";
	char temp[100] = " ";
	int index = 0;
	int menuIndex = 0;
	int userCommand = 0;

	printf("\nWhat field would you like to search by?\n"
		"(1)   Artist\n"
		"(2)   Album Title\n"
		"(3)   Song Title\n"
		"(4)   Genre\n");
	userCommand = menuPrompt(4);

	//calculate offset of field that user wants to search by
	for (int i = 1; i < userCommand; i++)
		addressOffset += sizeof(char[100]);
	userCommand = 0; //reset menu selection to 0

	printf("\nEnter search criteria: \n"); //get search string
	gets(userInput); 

	while (pHead) //search through list from head to tail
	{
		//set pointer to relevant field of struct by offsetting
		pSearchField = (char*)&pHead->data + addressOffset;
		//pSearchField = (char*)(pSearchField + addressOffset);
		
		//copy string from record and check for matches with user input
		strcpy(temp, pSearchField); 
		if (contains(temp, userInput))
		{
			results[menuIndex] = pHead; //store match in array
			menuIndex++;
		}
		pHead = pHead->pNext;
	}

	//Display results
	if (menuIndex == 0)//no results found
	{
		printf("No Matches Found. Press any key to continue\n\n");
		getch();
	}
	else if (menuIndex == 1)//1 result found
	{
		strcpy(temp, recordToString(results[0]));
		printf("Found 1 result:\n");
		printf("%s\n", temp);
		printf("Press any key to continue\n\n");
		getch();
	}
	else //multiple results found
	{
		printf("Found %d results:\n", (menuIndex));
		while (results[index])
		{
			strcpy(temp, recordToString(results[index]));
			printf("%d. %s\n", index + 1, temp);
			index++;
		}
		printf("Choose a song."); //prompt user to choose a result
		userCommand = menuPrompt(index + 1) - 1; // subtract 1 for array index
		strcpy(temp, recordToString(results[userCommand]));
		printf("%s\n Press any key to continue...\n", temp);
		getch();
	}
	return(results[userCommand]);
}

// Deletes a node from the linked list
// input: double pointer to head of list, and pointer to node to be deleted
int deleteNode(Node** pHead, Node* pDelete)
{
	int success = 0;

	if (pDelete)//something there to delete
	{
		success = 1;
		if (*pHead == pDelete) //head of list
			*pHead = pDelete->pNext;

		if (pDelete->pNext)//not tail of list
			pDelete->pNext->pPrev = pDelete->pPrev;

		if (pDelete->pPrev) // Not head of list
			pDelete->pPrev->pNext = pDelete->pNext;

		free(pDelete);
	}
	return success;
}

//sort function rearranges data in linked list by parameter of user's choosing
// input: pointer to head of the list.
void sort(Node *pHead)
{
	int i = 0, j = 0;
	int userCommand = 0;
	Node* pSorted = pHead;
	Node* pCur = pHead;
	Record tempData = pHead->data;
	char* pTextField = NULL;
	char* pNextTextField = NULL;
	char textField[100] = " ";
	char nextTextField[100] = " ";
	unsigned int* pIntField = 0;
	unsigned int* pNextIntField = 0;
	size_t addressOffset = 0;
	printf("\nWhat field would you like to sort by?\n"
		"(1)   Artist\n"
		"(2)   Album Title\n"
		"(3)   Song Title\n"
		"(4)   Genre\n"
		"(5)   Play Count\n"
		"(6)   Rating\n");
	userCommand = menuPrompt(6);

	//calculate offset of pointer based on user selection.
	for (int i = 1; i < userCommand; i++)
	{
		if (i <= 4)
			addressOffset += sizeof(char[100]);
		else
			addressOffset += sizeof(unsigned int);
	}
	
	//sorting by text field
	if (userCommand <= 4)
	{
		while (pSorted->pNext)
			pSorted = pSorted->pNext; //traverse to end of list


		while (pSorted->pPrev)
		{
			pCur = pHead;
			while (pCur != pSorted)
			{
				//find pertinent fields in Record structs with offset
				pTextField = (char*)&pCur->data + addressOffset;
				pNextTextField = (char*)&pCur->pNext->data + addressOffset;
				
				//make copies of strings
				strcpy(textField, pTextField);
				strcpy(nextTextField, pNextTextField);
				
				//set copies to lower case
				while (textField[j])
				{
					textField[j] = tolower(textField[j]);
					j++;
				}
				j = 0;
				while (nextTextField[j])
				{
					nextTextField[j] = tolower(nextTextField[j]);
					j++;
				}
				j = 0;

				//compare copies
				if (strcmp(textField, nextTextField) < 0)
				{
					tempData = pCur->data;
					pCur->data = pCur->pNext->data;
					pCur->pNext->data = tempData;
				}

				pCur = pCur->pNext;
			}
			pSorted = pSorted->pPrev;
		}
	}

	else //sorting by int field
	{
		while (pSorted->pNext)
			pSorted = pSorted->pNext;


		while (pSorted->pPrev)
		{
			pCur = pHead;
			while (pCur != pSorted)
			{
				//find pertinent fields in Record structs with offset
				pIntField = (char*)(&pCur->data) + addressOffset;
				pNextIntField = (char*)(&pCur->pNext->data) + addressOffset;
				
				//compare int fields
				if (userCommand == 5) //descending for play count
				{
					if (*pIntField > *pNextIntField)
					{
						tempData = pCur->data;
						pCur->data = pCur->pNext->data;
						pCur->pNext->data = tempData;
					}
				}

				else //ascending for rating
				{
					if (*pIntField < *pNextIntField)
					{
						tempData = pCur->data;
						pCur->data = pCur->pNext->data;
						pCur->pNext->data = tempData;
					}
				}
				pCur = pCur->pNext;
			}
			pSorted = pSorted->pPrev;
		}
	}
}

// shuffle "plays the songs in random order
// input: pointer to the head of the list
void shuffle(Node* pHead)
{
	Node* pCur = pHead;
	int success = 1;
	int itinerary = 0, nodeCounter = 0, listPosition = 0, listDestination = 0;
	int i = 0, j = 0, random = 0, temp = 0;
	int* shuffler = NULL;
	char playDisplay[500] = " ";

	while (pCur->pNext)
	{
		pCur = pCur->pNext;
		nodeCounter++;
		listPosition++;
	}
	shuffler = (int*)malloc(sizeof(int) * (nodeCounter+1));

	if (!shuffler) //check for failure allocating memory
		success = 0;
	else
	{	
		success = 1;

		//fill shuffler array
		for (i = 0; i <= nodeCounter; i++)
		{
			*(shuffler + i) = i;
		}
		//swap every position with a random other position
		for (i = 0; i <= nodeCounter; i++)
		{
			random = rand() % nodeCounter;
			temp = *(shuffler + i);
			*(shuffler + i) = *(shuffler + random);
			*(shuffler + random) = temp;
		}
		
		//traverse to positions dictated by array
		for (i = 0; i <= nodeCounter; i++)
		{
			listDestination = *(shuffler + i);
			itinerary = listDestination - listPosition;
			if (itinerary < 0)
			{
				for (j = 0; j > itinerary; j--)
				{
					pCur = pCur->pPrev;
					listPosition--;
				}
			}
			else
			{
				for (j = 0; j < itinerary; j++)
				{
					pCur = pCur->pNext;
					listPosition++;
				}
			}
			strcpy(playDisplay, recordToString(&pCur->data));
			printf("Playing: %s\n", playDisplay);
			Sleep(500);
		}
	}
}


// Takes a node from a linked list and "plays" the contents of it. Traverses
// through the rest of the linked list and plays all entries until the end.
void play(Node* playFrom)
{
	char playDisplay[200] = " ";
	while (playFrom)
	{
		strcpy(playDisplay, recordToString(&playFrom->data));
		printf("Playing: %s\n", playDisplay);
		Sleep(500);
		playFrom = playFrom->pNext;
	}
}

// allows the user to rate a song. Accepts a pointer to the node 
// containing the song to be edited
void rate(Node* thisNode)
{
	Record* pEdit = &thisNode->data;
	printf("What is your rating for this song from 1 - 5?\n");
	pEdit->rating = menuPrompt(5);
	printf("Rating changed to: %d/5", pEdit->rating);
}

// Displays prompt for user input. call after printing options to user that
// can be answered with an integer. numOptions sets range of valid data.
// returns the int selected by the user.
unsigned int menuPrompt(int numOptions)
{
	char userInput[100] = " ";
	int menuEntry = 0;
	while (menuEntry > numOptions || menuEntry <= 0)
	{
		printf("Answer with a number:\n");
		gets(userInput);
		menuEntry = atoi(userInput);
		if (menuEntry > numOptions || menuEntry <= 0)
			printf("invalid entry.\n");
	}
	system("cls");
	return (menuEntry);
}

// this function screens user input for emptiness and commas as either
// can very easily ruin the format of a csv. it accepts a string and returns
// an integer indicating whether the string is safe. 1 = safe, 0 = not safe
int screen(char* userInput)
{
	int safeness = 1;
	int index = 0;

	if (userInput[0] == '\0')
		safeness = 0;
	while (userInput[index])
	{
		if(userInput[index] == ',')
			safeness = 0;
		index++;
	}

	if(safeness == 0)
		printf("Entry may not contain commas and must have something in it.");

	return safeness;
}

// This function checks to see if a substring is contained in a string and 
// ignores case. Warning: strings passed to this function will be set to lower
// case. It accepts two string pointers. returns 1 if contained, 0 if not.
int contains(char* string, char* substring)
{
	int contains = 0;
	int index = 0;
	while (string[index])
	{
		string[index] = tolower(string[index]);
		index++;
	}
	index = 0;//reset index for different use

	while (substring[index])
	{
		substring[index] = tolower(substring[index]);
		index++;
	}
	index = 0;//reset index for different use

	//look for substrings of userInput in artist field at current record
	if (strstr(string, substring))
		contains = 1;
	return contains;
}
