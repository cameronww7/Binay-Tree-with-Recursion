/*************************************************************************
 * AUTHOR        : Cameron Walters
 * Assignment 	 : Project 7 Binary Search Tree
 * Class         : CS 301
 ************************************************************************/
#include "header.h"

/************************************************************************
 *
 * _______________________________________________________________________
 *
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *
 * POST-CONDITIONS
 *
 ************************************************************************/
int main()
{
	char      option; //Users menu choice
	int  	  value = 0;

	Tree< int> binTree;

	option = menuPrompt("\n\tA for Add\n"
			   	   	      "\tD for Delete\n"
			   	   	      "\tS for Delete all\n"
			   	   	      "\tP for Print\n"
						  "\tR for Retrieve\n"
						  "\tG for a Generated List\n"
						  "\tQ for Quit\n"
						  "\tEnter your Choice : ");

	while(option != 'Q')
	{
		switch(option)
		{
			//Adds to the front of the list
			case 'A' : value = NumberError("\tEnter any Integer "
										   "(between 0-1000): ",
											         0, 1000);
			       	   if(binTree.insert(value))
			       	   {
			       		   cout << "\n\tThe Value of : " << value
			       				   << " was Inserted\n";
			       	   }
			       	   else
			       	   {
			       		   cout << "\n\tThe Value of : " << value
			       				   << " was NOT Inserted\n";
			       	   }
				break;
			//Deletes a searched item and lets the user know if it is deleted
			case 'D' :	if(!binTree.isEmpty())
						{
							value = NumberError("\tEnter Item to Be Deleted: ",
													0, 1000);
							if(binTree.deleteItem(value))
							{
								cout << "\n\tThe Value of : " << value
									 << " was Deleted\n";
							}
							else
							{
							   cout << "\n\tThe Value of : " << value
								    << " was NOT Deleted\n";
							}
						}
						else
						{
							cout << "\n\t>> List is Empty <<\n";
						}

				break;
			//this makes the entire tree empty and back to NULL
			case 'S' :	if(!binTree.isEmpty())
						{
							cout << "\n\t>> Clearing the List <<\n";
							binTree.makeEmpty();
						}
						else
						{
							cout << "\n\t>> List is Empty <<\n";
						}
				break;
			//this looks and retrieves a value and lets you know if its there
			case 'R' :	if(!binTree.isEmpty())
						{
							value = NumberError("\tEnter SearchItem : ",
														 0, 1000);
							if(binTree.retrieve(value))
							{
								cout << "\n\tThe Value of : " << value
									 << " was Found\n";
							}
							else
							{
								cout << "\n\tThe Value of : " << value
									 << " was Not Found\n";
							}
						}
						else
						{
							cout << "\n\t>> List is Empty <<\n";
						}
				break;
			//Prints the entire binary tree in the order specified
			case 'P' : 	if(!binTree.isEmpty())
						{
							cout << "\n\t>> Printing List << \n";
							PrintTree(binTree);
						}
						else
						{
							cout << "\n\t>> List is Empty <<\n";
						}
				break;
			// generates a list with the numbers, 0,5,10,15,20
			case 'G' : 	if(binTree.isEmpty())
						{
							cout << "\n\tCreating a Generated List with 5 Values\n";
							GenerateList(binTree);
						}
						else
						{
							cout << "\n\t>> List must be Empty <<\n";
						}

				break;
		}// end of Switch

		option = menuPrompt("\n\tA for Add\n"
						 	"\tD for Delete\n"
							"\tS for Delete all\n"
						  	"\tP for Print\n"
							"\tR for Retrieve\n"
						  	"\tG for a Generated List\n"
						  	"\tQ for Quit\n"
							"\tEnter your Choice : ");
	}// end of While

	cout << "\n\nThank You, and Have a Wonderful Day";
	return 0;
}

void GenerateList(Tree<int> &binTree)
{
		binTree.insert(15);
		binTree.insert(0);
		binTree.insert(10);
		binTree.insert(25);
		binTree.insert(20);
		binTree.insert(5);
		binTree.insert(99);
		binTree.insert(-99);
}

void PrintTree(Tree<int> & inTree)
{
	int value = -1;
	cout << "\n\tOptions to Print"
			"\n\tPre-Order  : 1"
			"\n\tIn-Order   : 2"
			"\n\tPost-Order : 3";
	value = NumberError("\n\tEnter your Option: ",
							      1, 3);

	switch(value)
	{
	case 1: inTree.print(cout,preorder);
		break;
	case 2: inTree.print(cout,inorder);
		break;
	case 3: inTree.print(cout,postorder);
		break;
	}

}

/************************************************************************
 *  int NumberError
 * _______________________________________________________________________
 * This function outputs the menu and tracks if the user inputs an
 *	invaild character or number within the range that was passed.
 * _______________________________________________________________________
 * PRE-CONDITIONS
 *		MENU_FORMAT : menu format needs to be predetermined
 *		IN_MIN 		: minimum input option needs to be predetermined
 *		IN_MAX		: maximum input option needs to be predetermined
 * POST-CONDITIONS
 * 		Returns a valid user choice (option) to the calling function
 ************************************************************************/
int NumberError(const string MENU_FORMAT,	// IN & OUT		- output string
		 	 	const int IN_MIN,			// IN & OUT		- minimum option
		 	 	const int IN_MAX)			// IN & OUT		- maximum option
{
	bool someBool;					// PROCESSING	- determines whether
									// 				  the menu is output
	int option;						// IN & OUT		- user input choice

	do
	{
		someBool = false;

		// OUTPUT - the menu
		cout << MENU_FORMAT;

		/*****************************************************************
		 * This is a check for the user's input. It will first check
		 * 	if the user has put in a vaild number, if invaild it will
		 *	clear the input then reoutput the menu until and do the
		 *	check's until the user puts in a vaild entry.
		 *****************************************************************/
		if(!(cin >> option))
		{
			cout << "\n**** Please input a NUMBER between " << IN_MIN
				 << " and " << IN_MAX << " ****";
			cin.clear();

			someBool  = true;
			cout << endl << endl;
		}
		else if (option > IN_MAX || option < IN_MIN)
		{
			cout << endl;
			cout << "**** The number " << option << " is an invalid "
					"entry     ****\n";
			cout << "**** Please input a number between "
				 << IN_MIN << " and " << IN_MAX << " ****\n";
			cout << endl;
			someBool = true;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}while(someBool);

	return option;
}

char menuPrompt(const string MENU_PROMPT)
{

	bool someBool;					// PROCESSING	- determines whether
									// 				  the menu is output
	char option;					// IN & OUT		- user input choice

	do
	{
		someBool = false;

		// OUTPUT - the menu
		cout << MENU_PROMPT;
		cin.get(option);
		option = toupper(option);

		if (  option == 'A' ||
			  option == 'D' ||
			  option == 'P' ||
		      option == 'Q' ||
		      option == 'S' ||
		      option == 'G' ||
		      option == 'R'
		      )
		{
			someBool = true;
		}
		else
		{
			cout << "\n * Error *  Please Enter one choice Of A,D,P,Q,S,G,R \n";
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}while(!someBool);

	return option;

}

