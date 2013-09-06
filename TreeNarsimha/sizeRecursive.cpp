#include "BinaryTree.h"
#include <limits>
int size(BinaryTreeNode* root);
int main(int argc, char const *argv[])
{
	BinaryTree b;
	for (int i = 1; i < 10; i+=2)
	{
		b.insert(i*i);
	}
	int count =size(b.getRoot());
	cout<<"Size of Binary Tree is "<<count<<endl;
	return 0;
}
int size(BinaryTreeNode* root)
{
	if(root)
	{
		return 1 + size(root->getLeft()) + size(root->getRight()); 
	}
	else
		return 0;
}