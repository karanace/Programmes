#include "BinaryTree.h"
#include <limits>
int depth(BinaryTreeNode* root);
int main(int argc, char const *argv[])
{
	BinaryTree b;
	for (int i = 0; i <50 ; i++)
	{
		b.insert(i*i);
	}
	int count =depth(b.getRoot());
	cout<<"Depth of Binary Tree is "<<count<<endl;
	return 0;
}
int depth(BinaryTreeNode* root)
{
	
	
}