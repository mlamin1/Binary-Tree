#include <iostream>
#include "BinaryTree.h"
#include <queue>
#include <bits/stdc++.h>
#define COUNT 10

/*******************************************************************************/
//Transplant Function								/
//Receives 2 TreeNode pointers as parameters. The purpose of the 		/
//function is to replace the first parameter with the second.			/
/*******************************************************************************/
void BinaryTree::TransplantNode(TreeNode* U, TreeNode* V)
{
	if(U == root)			//If U is the root of the tree, assign V to U's position
	{
		root = V;
		V->parent = nullptr;
		return;
	}
	else{
		if(U == U->parent->right)		//If U is the right child of the root, put V in U's position
		{
			U->parent->right = V;
		}
		else{					//If U is the left child of the root, put V in U's position
			U->parent->left = V;
		}
		if(V != nullptr)			//check is V is null, if not, make V link to U's parent.
		{
			V->parent = U->parent;
		}
	}
}

/*******************************************************************************/
//Default Constructor								/
//Sets the root to nullptr							/
//										/
/*******************************************************************************/
BinaryTree::BinaryTree()
{
	root = nullptr;
}


/*******************************************************************************/
//Destructor									/
//Gets called when something needs to be deleted				/
//										/
/*******************************************************************************/
BinaryTree::~BinaryTree()
{
	delete root;
}



/*******************************************************************************/
//Recursive Search function							/
//Gets the root and the number, and traverse through the tree			/
//If the number is in tree it returns true else it returns false		/
/*******************************************************************************/
bool BinaryTree::RecsearchTree(TreeNode *root, int num)
{
	TreeNode *cursor = root;
	if(cursor == nullptr)
		return false;
	else if(cursor->key == num)
		return true;
	else{
		if(num < cursor->key)
		{	
			return RecsearchTree(cursor->left, num);
		}
		else{
			return RecsearchTree(cursor->right, num);
		}
	}
}


/*******************************************************************************/
//Print Inorder recursive function						/
//Gets root and traverse through and prints tree in and inorder form		/
//										/
/*******************************************************************************/
void BinaryTree::PrintInorderRec(TreeNode *Node)
{
	TreeNode *cursor = Node;
	if(cursor != nullptr)
	{
		PrintInorderRec(cursor->left);
		std::cout << cursor->key <<" ";
		PrintInorderRec(cursor->right);
	}
}


/*******************************************************************************/
//Insert Tree Function								/
//Gets a number from the main, makes it a node and adds it to the tree.		/
//										/
/*******************************************************************************/
void BinaryTree::InsertTree(int num)
{
	TreeNode* Node = new TreeNode();
	Node->key = num;

	TreeNode* cursor = root;
	TreeNode* temp = nullptr;

	while(cursor != nullptr)					//Traverse through the tree finding the appropriate spot for the number.
	{
		temp = cursor;
		if(Node->key <= cursor->key)				//If the number is less than the present number in tree, the new number gets placed to the left
		{
			cursor = cursor->left;
		}
		else{							//If the number is less than the present number in tree, the new number gets placed to the right
			cursor = cursor->right;
		}
	}

	if(temp == nullptr)						//If the tree is empty, the number becomes the root.
	{
		root = Node;
		Node->parent = nullptr;
	}
	else{								//Validation to put number somewhere in the middle of the tree
		TreeNode* Tempz;
		Tempz = Node;
		Tempz->parent = temp;
		if(Tempz->key <= temp->key)
		{
			temp->left = Tempz;
		}
		else{
			temp->right = Tempz;
		}
	}
}


/*******************************************************************************/
//Search Tree function								/
//Calls the recursive tree and does a validation check based			/
//on the check, it returns the 1 or 0						/
/*******************************************************************************/
int BinaryTree::searchTree(int key)
{
	if(RecsearchTree(this->root, key))					//Calls the recursive tree send the root of the tree.
	{
		return 1;
	}
	else
		return 0;

	return 0;
}


/*******************************************************************************/
//Min Tree function								/
//Starts from the root and goes to the far left of the tree			/
//										/
/*******************************************************************************/
int BinaryTree::minTree()
{
	TreeNode *cursor = root;
	while(cursor->left)
		cursor = cursor->left;

	if(cursor)
		return cursor->key;

	return 0;
}


/*******************************************************************************/
//Max Tree function								/
//starts from the root and goes to the far right of the tree			/
//										/
/*******************************************************************************/
int BinaryTree::maxTree()
{
	TreeNode *cursor = root;
	while(cursor->right)							//Traverse through the tree going only right of the tree
		cursor = cursor->right;

	if(cursor)
		return cursor->key;

	return 0;
}


/*******************************************************************************/
//Successor Function								/
//Search the tree to see if the number is in tree, if so, 			/
//It finds the value that will replace the number if it was to be deleted	/
/*******************************************************************************/
int BinaryTree::SuccessorNode(int num)
{
	int temp;
	TreeNode *cursor = root;
	if(searchTree(num))							//Validation to see if the number is in the tree
	{
		while(cursor && cursor->key != num)				//Traverse tree and find the number given by user.
		{
			if(cursor->key > num)
			{
				cursor = cursor->left;
			}
			else if(cursor->key < num){
				cursor = cursor->right;
			}
		}
		TreeNode *tempz = root;
		if(cursor->right != nullptr)					//The case where the successor is the min of the right child of the number.
		{
			root = cursor->right;
			temp = minTree();
			root = tempz;
		}
		else if(num == maxTree())					//Case where the number is the largest in the tree, in that case there is no successor
		{
			temp = num;
		}
		else if(cursor == cursor->parent->left)			//Case where the successor is the parent of the numbere given, in this case number given is the left child of its successor
		{
			temp = cursor->parent->key;
		}
		else {								//Case where the number given is the max to the right of the root.
			while(cursor->parent != cursor->parent->parent->left)
				cursor = cursor->parent;
			temp = cursor->parent->parent->key;
		}
	}
	else{
		temp = -1;
	}
	return temp;
}


/*******************************************************************************/
//Print Inorder function							/
//Calls the recursive print function to print tree in order			/
//										/
/*******************************************************************************/
void BinaryTree::PrintInorder()
{
	PrintInorderRec(this->root);						//Passes the root so it has access to the tree.
}


/*******************************************************************************/
//Delete Tree function								/
//Gets the number from the user and search the tree for the num			/
//then deletes it and returns the same number					/
/*******************************************************************************/
int BinaryTree::DeleteTree(int num)
{
	TreeNode *cursor = this->root;
	while(cursor != nullptr && cursor->key != num)				//Searches the tree for the position of the value in the tree
	{
		if(cursor->key < num)
			cursor = cursor->right;
		else if(cursor->key > num)
			cursor = cursor->left;
	}

	if(cursor->left == nullptr)						//Check to see if there is only a right child
	{
		TransplantNode(cursor, cursor->right);
	}
	else if(cursor->right == nullptr)					//Check to see if there is only a left child
	{
		TransplantNode(cursor, cursor->left);
	}
	else{
		TreeNode *Y = MinNode(cursor->right);
		if(Y->parent != cursor)						//Root validation before assigning the right side of root to its successor.
		{
			TransplantNode(Y, Y->right);
			Y->right = cursor->right;
			Y->right->parent = Y;
		}
		TransplantNode(cursor, Y);
		Y->left = cursor->left;
		Y->left->parent = Y;
	}
	cursor->left = nullptr;
	cursor->right = nullptr;
	delete cursor;
	return num;
}



/*******************************************************************************/
//Formatted recursive print function						/
//prints the the values in a tree format					/
//										/
/*******************************************************************************/
void BinaryTree::RecPrint(TreeNode* cursor, int levl)
{
	if(cursor == nullptr)
		return;

	levl += 10;

	RecPrint(cursor->right, levl);

	std::cout<< std::endl;

	for(int i = 10; i < levl; i++)
	{
		std::cout << " ";
	}
	std::cout << cursor->key << "\n";
	RecPrint(cursor->left, levl);
}



/*******************************************************************************/
//Formatted print function							/
//Calls a private print function to print					/
//the the values in a tree format						/
/*******************************************************************************/
void BinaryTree::Print()
{
	RecPrint(this->root, 0);

}
