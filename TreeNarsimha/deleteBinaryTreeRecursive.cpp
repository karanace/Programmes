#include "BinaryTree.h"
#include <limits>
#include <stack>
void deleteBinaryTree(BinaryTreeNode* root);
int size(BinaryTreeNode* root);
int main(int argc, char const *argv[])
{
	BinaryTree b;
	for (int i = 1; i < 10; ++i)
	{
		b.insert(i);
	}
	cout<<"Size of Binary Tree is"<<size(b.getRoot())<<endl;
	deleteBinaryTree(b.getRoot());
	cout<<"Size of Binary Tree is"<<size(b.getRoot())<<endl;
	return 0;
}
void deleteBinaryTree(BinaryTreeNode* root)
{
	if(root ==NULL)
	{
			return;
	}
	deleteBinaryTree(root->getLeft());
	deleteBinaryTree(root->getRight());	
	delete(root);
}	
int size(BinaryTreeNode* root)
{
	int count =0;
	if(root)
	{
				queue<BinaryTreeNode*> myQueue;
				BinaryTreeNode *front;
				myQueue.push(root);
				while(!myQueue.empty())
				{
					front = myQueue.front();
					myQueue.pop();
					count++;
					if(front->getLeft())
						myQueue.push(front->getLeft());
					if(front->getRight())
						myQueue.push(front->getRight());
				}
	}
	else
		return 0;
	return count;
	
}