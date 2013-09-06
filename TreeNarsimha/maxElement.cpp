#include "BinaryTree.h"
#include <limits>
int findMax(BinaryTreeNode* root);
int main(int argc, char const *argv[])
{
	BinaryTree b;
	for (int i = 0; i < 10; ++i)
	{
		b.insert(i);
	}
	cout<<findMax(b.getRoot())<<endl;

	return 0;
}
int findMax(BinaryTreeNode *root)
{
	int root_val,left,right,maxElement = numeric_limits<int>::min();
	if(root)
	{
		root_val = root->getData();
		left = findMax(root->getLeft());
		right = findMax(root->getRight());

		if(left>right)
			maxElement = left;
		
		else
			maxElement = right;
		if(root_val> maxElement)
			maxElement = root_val;
	}
	return maxElement;
}