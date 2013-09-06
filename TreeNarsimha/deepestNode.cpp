#include "BinaryTree.h"
#include <limits>
#include <stack>
BinaryTreeNode* DeepestNode(BinaryTreeNode* root);
int main(int argc, char const *argv[])
{
	BinaryTree b;
	for (int i = 1; i < 10; ++i)
	{
		b.insert(i);
	}
	if(DeepestNode(b.getRoot()) !=0)
	cout<<DeepestNode(b.getRoot())->getData();
	return 0;
}
BinaryTreeNode* DeepestNode(BinaryTreeNode* root)
{
	BinaryTreeNode *front;
	if(root)
	{
		queue<BinaryTreeNode*> myQueue;
		stack<int> myStack;
		
		myQueue.push(root);
		while(!myQueue.empty())
		{
			front = myQueue.front();
			myQueue.pop();
			if(front->getLeft())
			myQueue.push(front->getLeft());
			if(front->getRight())
			myQueue.push(front->getRight());

		}
	}
	else
	return root;
	return front;	
}