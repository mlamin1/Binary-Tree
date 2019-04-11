#include <iostream>
#ifndef BINARY_H
#define BINARY_H

class BinaryTree{

	private:
		struct TreeNode{
			int key;
			TreeNode* left = nullptr;
			TreeNode* right = nullptr;
			TreeNode* parent = nullptr;	

			~TreeNode()
			{
				if(left){
					delete left;

				}if(right){
					delete right;
				}
			}
		};


		TreeNode* root;

		TreeNode *MinNode(TreeNode* root)
		{
			TreeNode *cursor = root;
			while(cursor->left != nullptr)
				cursor = cursor->left;
			return cursor;
		}
		void TransplantNode(TreeNode *, TreeNode *);
		void PrintInorderRec(TreeNode *);
		bool RecsearchTree(TreeNode *, int);
		void RecPrint(TreeNode*, int);

	public:
		BinaryTree();
		~BinaryTree();
		void InsertTree(int);
		int searchTree(int);
		int minTree();
		int maxTree();
		int SuccessorNode(int);
		void PrintInorder();
		int DeleteTree(int);
		void Print();
};

#endif
