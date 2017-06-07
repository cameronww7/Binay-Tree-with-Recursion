/*************************************************************************
 * AUTHOR        : Cameron Walters
 * Assignment 	 : Project 7 Binary Search Tree
 * Class         : CS 301
 ************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <limits>
#include <ios>

#include "TreeNode.h"
#include "BinarySearchTree.h"


using namespace std;


void PrintTree(Tree<int> &binTree);
void GenerateList(Tree<int> &binTree);

char menuPrompt(const string MENU_PROMPT);
int NumberError(const string MENU_FORMAT,	// IN & OUT		- output string
		 	 	const int IN_MIN,			// IN & OUT		- minimum option
		 	 	const int IN_MAX);			// IN & OUT		- maximum optio

#endif /* HEADER_H_ */
