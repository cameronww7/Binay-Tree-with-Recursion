/*************************************************************************
 * AUTHOR        : Cameron Walters
 * Assignment 	 : Project 7 Binary Search Tree
 * Class         : CS 301
 ************************************************************************/

// Content of TreeNode.h
// Original source attribution available. Modified by Molodowitch
// TreeNode template definition: each TreeNode object contains data,
// left pointer, and right pointer.

#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using namespace std;

template< class ItemType > class Tree;  // forward declarations

template<class ItemType>
class TreeNode
{
   friend class Tree< ItemType >; // make Tree a friend

public:
   TreeNode( ItemType );  // constructor
   TreeNode();					// constructor with data uninitialized
   ItemType getData() const;      // return data in the node
   void inData(ItemType inValue);
private:
   ItemType data;
   TreeNode< ItemType > *leftPtr;
   TreeNode< ItemType > *rightPtr;
};


template<class ItemType>
TreeNode< ItemType >::TreeNode( ItemType newItem )
{
	data     = newItem;
	leftPtr  = NULL;
	rightPtr = NULL;
}

template<class ItemType>
TreeNode< ItemType >::TreeNode( )
{
	leftPtr  = NULL;
	rightPtr = NULL;
}


// Return a copy of the data in the node
template< class ItemType >
ItemType TreeNode< ItemType >::getData() const
{
	return data;
}

template< class ItemType >
void TreeNode< ItemType >::inData(ItemType inValue)
{
	data = inValue;
}


#endif
