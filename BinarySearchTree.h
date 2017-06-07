/*************************************************************************
 * AUTHOR        : Cameron Walters
 * Assignment 	 : Project 7 Binary Search Tree
 * Class         : CS 301
 ************************************************************************/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <fstream>
#include "TreeNode.h"

using namespace std;

  //The following enumerated type declaration should be included.

	enum TraversalOrderType {preorder, inorder, postorder};


template< class ItemType >
class Tree
{
public:

	// Constructor used before any operations are done on the list.
	// Initializes the list to empty.
	//Preconditions: None.
	//Postconditions: Tree is an empty Tree.
   Tree();

   //Destructor
   //Precondition: Tree exists, but may be empty.
   //Postcondition: makeEmpty is called to ensure the tree is empty
   // when the destructor is called.
   ~Tree();

   //Returns True if the tree is empty, otherwise returns false
   //Postcondition: Tree is unchanged.
   bool isEmpty() const;

   //Makes the tree empty if it is not empty already.
   //Preconditions:  The tree exists.
   //Postconditions: Tree is now empty. Any dynamically allocated
   // memory which is no longer used is returned to the system.
   void makeEmpty();

   // Inserts a copy of newItem in the tree.
   //Precondition: The tree exists, but may be empty. It has binary
   // search property. ItemType has comparison operators defined.
   //Postcondition: if the tree already has an item where item ==
   // newItem, the function returns false and the tree is unchanged.
   // Otherwise, the newItem is inserted in the tree preserving and the
   // binary search property is maintained.
   bool insert(ItemType newItem);

   // Given a searchItem, it tries to retrieve as foundItem, an item
   // in the tree where the item == searchItem.
   // Precondition: The tree exists and has the binary search property.
   //  It may be empty. ItemType has comparison operators defined.
   // Postcondition: If the tree already has an item where item ==
   //  searchItem, foundItem is set to that item, and the function
   //  returns true. If the tree has no such item, the function returns
   //  false and foundItem remains unchanged.  The tree is unchanged.
	bool retrieve(ItemType & searchItem);

   // Given a deleteItem, it deletes from the tree any item where item
   //  == deleteItem.
   // Precondition: Tree exists and has binary search property.
   //  ItemType has comparison operators defined.
   // Postcondition: If the tree has an item where item == deleteItem,
   //  that item is removed from the tree, and the function returns
   // true, and the binary search property is maintained. If the tree
   //  has no such item, the function returns false and the tree
   //  remains unchanged.
   bool deleteItem (ItemType deleteItem);


	//Prints the information about all the items in the Tree in order
 	// to an ostream object Outstream.  The function should print nothing
    // (No messages!) if the Tree is empty.  The particular order
 	// (preorder, inorder, or postorder) is given by order, a variable of
    //  TraversalOrderType.
	// Preconditions: Outstream has been assigned and opened for writing
    //  to. The insertion operator (<<) has been defined for objects of
    //  class ItemType.
	// Postconditions:  Tree is unchanged.  The information for all
    //  items has been written out to Outstream in the order specified
    //  by order.
   void print(ostream & Outstream, TraversalOrderType order );

private:

   TreeNode< ItemType > * rootPtr;  // pointer to the root

   //utility functions
  void printHelper( TreeNode< ItemType > *, ostream &, TraversalOrderType );
  bool insertHelper( TreeNode< ItemType > * & , ItemType );
  bool deleteHelper( TreeNode< ItemType > * & , ItemType );
  void deleteNode( TreeNode<ItemType > * & );
  bool retrieveHelper(TreeNode< ItemType > * &,
		  	  	  	  	  	  	ItemType & searchItem );
  void makeEmptyHelper (TreeNode< ItemType > * & ptr);

};

// Constructor used before any operations are done on the list.
// Initializes the list to empty.
//Preconditions: None.
//Postconditions: Tree is an empty Tree.
template< class ItemType >
Tree<ItemType>::Tree()
{
	rootPtr = NULL;
}

//Destructor
//Precondition: Tree exists, but may be empty.
//Postcondition: makeEmpty is called to ensure the tree is empty
// when the destructor is called.
template< class ItemType >
Tree<ItemType>::~Tree()
{
	if(!isEmpty())
	{
		makeEmptyHelper(rootPtr);
		rootPtr = NULL;
	}
}

//Returns True if the tree is empty, otherwise returns false
//Postcondition: Tree is unchanged.
template< class ItemType >
bool Tree<ItemType>::isEmpty() const
{
	bool empty = false;

	if(rootPtr == NULL)
	{
		empty = true;
	}

	return empty;
}

//Makes the tree empty if it is not empty already.
//Preconditions:  The tree exists.
//Postconditions: Tree is now empty. Any dynamically allocated
// memory which is no longer used is returned to the system.
template< class ItemType >
void Tree<ItemType>::makeEmpty()
{
	makeEmptyHelper(rootPtr);
}

// Inserts a copy of newItem in the tree.
//Precondition: The tree exists, but may be empty. It has binary
// search property. ItemType has comparison operators defined.
//Postcondition: if the tree already has an item where item ==
// newItem, the function returns false and the tree is unchanged.
// Otherwise, the newItem is inserted in the tree preserving and the
// binary search property is maintained.
template< class ItemType >
bool Tree<ItemType>::insert(ItemType newItem)
{
	bool wasInserted = false;

	wasInserted = insertHelper(rootPtr,newItem);

	return wasInserted;
}

// Given a searchItem, it tries to retrieve as foundItem, an item
// in the tree where the item == searchItem.
// Precondition: The tree exists and has the binary search property.
//  It may be empty. ItemType has comparison operators defined.
// Postcondition: If the tree already has an item where item ==
//  searchItem, foundItem is set to that item, and the function
//  returns true. If the tree has no such item, the function returns
//  false and foundItem remains unchanged.  The tree is unchanged.
template< class ItemType >
bool Tree<ItemType>::retrieve(ItemType & searchItem)
{
	bool isItFound = false;

	isItFound = retrieveHelper(rootPtr,searchItem);

	return isItFound;
}

// Given a deleteItem, it deletes from the tree any item where item
//  == deleteItem.
// Precondition: Tree exists and has binary search property.
//  ItemType has comparison operators defined.
// Postcondition: If the tree has an item where item == deleteItem,
//  that item is removed from the tree, and the function returns
// true, and the binary search property is maintained. If the tree
//  has no such item, the function returns false and the tree
//  remains unchanged.
template< class ItemType >
bool Tree<ItemType>::deleteItem (ItemType deleteItem)
{
	bool isItFound = false;

	isItFound = deleteHelper(rootPtr, deleteItem);

	return isItFound;
}

//Prints the information about all the items in the Tree in order
// to an ostream object Outstream.  The function should print nothing
// (No messages!) if the Tree is empty.  The particular order
// (preorder, inorder, or postorder) is given by order, a variable of
//  TraversalOrderType.
// Preconditions: Outstream has been assigned and opened for writing
//  to. The insertion operator (<<) has been defined for objects of
//  class ItemType.
// Postconditions:  Tree is unchanged.  The information for all
//  items has been written out to Outstream in the order specified
//  by order.
template< class ItemType >
void Tree<ItemType>::print(ostream & Outstream, TraversalOrderType order )
{
	printHelper(rootPtr, Outstream, order );
}

//utility functions
template< class ItemType >
void Tree<ItemType>::printHelper( TreeNode< ItemType > * ptr,
								  ostream & oStream,
								  TraversalOrderType requestedOrder)
{
	if(ptr != NULL)
	{
		switch(requestedOrder)
		{
			case preorder :oStream << endl << ptr->getData();
						   printHelper(ptr->leftPtr, oStream, requestedOrder);
						   printHelper(ptr->rightPtr, oStream, requestedOrder);
			    break;
			case inorder : printHelper(ptr->leftPtr , oStream, requestedOrder);
						   oStream << endl << ptr->getData();
						   printHelper(ptr->rightPtr, oStream, requestedOrder);
				break;
			case postorder :printHelper(ptr->leftPtr , oStream, requestedOrder);
							printHelper(ptr->rightPtr, oStream, requestedOrder);
			   	   	   	    oStream << endl << ptr->getData();
				break;
		}
	}
}

template< class ItemType >
bool Tree<ItemType>::insertHelper( TreeNode< ItemType > * & ptr  ,
											 ItemType newItem)
{
	bool wasInserted = false;

	if(ptr == 0)
	{
		ptr = new TreeNode< ItemType > (newItem);
		wasInserted = true;
	}
	else if(newItem == ptr->getData())
	{
		cout << "item with key is already in the tree.\n\n";
		wasInserted = false;
	}
	 else if ( newItem < ptr->getData() )
	 {	// insert in left subtree
		 wasInserted = insertHelper( ptr->leftPtr, newItem);
	 }
	 else
	 {	// insert in right subtree
		 wasInserted =  insertHelper( ptr->rightPtr, newItem);
	 }

	return wasInserted;
}

template< class ItemType >
bool Tree<ItemType>::deleteHelper( TreeNode< ItemType > * & ptr,
											 ItemType searchItem)
{
	bool found = false;

	if(ptr == NULL)
	{
		found = false;
	}
	else if(ptr->getData() == searchItem)
	{
		found = true;
		deleteNode(ptr);
	}
	else if(searchItem < ptr->getData())
	{
		found = deleteHelper(ptr->leftPtr, searchItem);
	}
	else
	{
		found = deleteHelper(ptr->rightPtr, searchItem);
	}

	return found;
}

template< class ItemType >
void Tree<ItemType>::deleteNode( TreeNode< ItemType > * & ptr )
{
	if (ptr->leftPtr == NULL)
	{
		TreeNode<ItemType> * temp = ptr;
		ptr = ptr->rightPtr;
		delete temp;
	}
	else if (ptr->rightPtr == NULL)
	{
		TreeNode<ItemType> * temp = ptr;
		ptr = ptr->leftPtr;
		delete temp;
	}
	else
	{
		TreeNode<ItemType> * temp = ptr->leftPtr;
		if (temp->rightPtr == NULL) // the node pointed to by root->leftPtr
									// has the largest value in the subtree
		{
			ptr->data = temp->data;  // copy largest value in left subtree
										 // to root node
			ptr->leftPtr = temp->leftPtr; // bypass temp node Error corrected
			delete temp;
		}
		else
		{
			while (temp->rightPtr->rightPtr == NULL)
			{
				temp = temp->rightPtr;	// look for the node with largest value
			}

			TreeNode<ItemType> * deletePtr = temp->rightPtr; // deletePtr points to node
												   // with largest value
			ptr->data = deletePtr->data; //copy largest value to root node

			temp->rightPtr = deletePtr->leftPtr; // bypass node to be deleted
			delete deletePtr;    // delete node
		}
	}
}

template< class ItemType >
bool Tree<ItemType>::retrieveHelper(TreeNode< ItemType > * & ptr,
											  ItemType & searchItem)
{
	bool found = false;

	if(ptr == NULL)
	{
		found = false;
	}
	else if(ptr->getData() == searchItem)
	{
		searchItem = ptr->data;
		found = true;
	}
	else if(searchItem < ptr->getData())
	{
		found = retrieveHelper(ptr->leftPtr, searchItem);
	}
	else
	{
		found = retrieveHelper(ptr->rightPtr, searchItem);
	}

	return found;
}

template< class ItemType >
void Tree<ItemType>::makeEmptyHelper (TreeNode< ItemType > * & ptr)
{
	if(ptr->leftPtr != NULL)
	{
		makeEmptyHelper(ptr->leftPtr);
		delete ptr;
	}
	else if(ptr->rightPtr != NULL)
	{
		makeEmptyHelper(ptr->rightPtr);
		delete ptr;
	}
	ptr = NULL;
}


#endif
