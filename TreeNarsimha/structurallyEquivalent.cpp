#include "BinaryTree.h"
#include <limits>
#include <queue>
bool areEquivalent(BinaryTreeNode* root1,BinaryTreeNode* root2);
int main(int argc, char const *argv[])
{
	BinaryTree b1,b2;
	for (int i = 1; i < 4; ++i)
	{
		b1.insert(i);
	}
	for (int i = 1; i < 5; ++i)
	{
		b2.insert(i);
	}
	if(areEquivalent(b1.getRoot(),b2.getRoot()))
	cout<<"Are Equivalent"<<endl;
	else
	cout<<"Are Different"<<endl;
	return 0;
}
bool areEquivalent(BinaryTreeNode* root1,BinaryTreeNode* root2)
{
	if(!root1 && !root2)
		return true;
	else
	{
		if(!root1 && root2 ||root1 && !root2)
			return false;
		if(root1->getData() == root2->getData())
		{
			bool x = areEquivalent(root1->getLeft(),root2->getLeft());
			if(x)
			areEquivalent(root1->getRight(),root2->getRight());
			else
			return false;	
		}
	}
}