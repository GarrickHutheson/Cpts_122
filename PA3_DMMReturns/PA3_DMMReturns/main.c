/*
* Programmer: Garrick Hutcheson
* Programming Assignment 3: Digital Music Manager Returns
* Date: 9/24/17
* File: main.c
* Main is just the structure of the menu. it calls other helper functions
* From dmm.c to carry out the commands of the user.
*/

#include "dmm.h"

int main()
{
	Node* pHead = NULL;
	Node* pMem = NULL;
	int userCommand = 0;
	int success = 0;
	while (userCommand != 11)//menu only terminates at option 11
	{
		system("cls");
		printf("What would you like to do? Please enter a number.\n"
			"(1)   load\n"
			"(2)   store\n"
			"(3)   display\n"
			"(4)   insert\n"
			"(5)   delete\n"
			"(6)   edit\n"
			"(7)   sort\n"
			"(8)   rate\n"
			"(9)   play\n"
			"(10)  shuffle\n"
			"(11)  exit\n");
		userCommand = menuPrompt(11);
		if (!pHead && (userCommand != 1) )
		{
			userCommand = 1;
			printf("No songs loaded. Attempting to load songs first.\n");
		}
		switch (userCommand)
		{
		case 1: //load
			pHead = load();
			if (pHead)
				printf("Songs Loaded. ");
			else
				printf("No songs Loaded. Ensure musicPlayList.csv "
					"in local memory.");
			printf("\nPress any key to continue...");
			getch();
			break;
		case 2: //store
			store(pHead);
			printf("Songs stored. Press any key to continue.");
			getch();
			break;
		case 3: //display
			display(pHead);
			break;
		case 4:	//insert
			success = insertFront(&pHead, NULL);
			if (success)
				printf("Song added to library. Press any key to continue...");
			break;
		case 5: //deleteNode
			printf("Choose a song to delete.\n");
			pMem = search(pHead);
			deleteNode(&pHead, pMem);
			break;
		case 6: //edit
			printf("Choose a song to edit.\n");
			pMem = search(pHead);
			editRecord(pMem, 0);
			break;
		case 7: //sort
			sort(pHead);
			printf("Records sorted. Here is new order.\n");
			printList(pHead);
			printf("\nPress any key to continue...");
			getch();
			break;
		case 8: //rate
			printf("Choose a song to rate.\n");
			pMem = search(pHead);
			rate(pMem);
			break;
		case 9:	//play
			printf("Choose a song to start playing at.\n");
			pMem = search(pHead);
			play(pMem);
			break;
		case 10: //shuffle
			shuffle(pHead);
			printf("Press any key to continue...");
			getch();
			break;
		case 11: //exit
			printf("Saving Music Library and exiting.\n");
			store(pHead);
			break;
		default:
			break;
		}
	}
	return 1;
}