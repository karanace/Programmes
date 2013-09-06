#include "BinaryTree.h"
#include <limits>
#include <math.h>
int depth(BinaryTreeNode* root);
int main(int argc, char const *argv[])
{
	BinaryTree b;
	for (int i = 1; i < 8; i++)
	{
		b.insert(i);
	}
	int count =depth(b.getRoot()) - 1;
	cout<<"Depth of Binary Tree is "<<count<<endl;
	return 0;
}
int depth(BinaryTreeNode* root)
{
	if(root)
	{
		int leftheight = depth(root->getLeft());
		int rightheight = depth(root->getRight());
		if(leftheight >rightheight)
			return leftheight + 1;
			return rightheight + 1;
	}
	else
		return 0;
}