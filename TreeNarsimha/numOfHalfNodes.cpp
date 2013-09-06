#include "BinaryTree.h"
#include <limits>
#include <queue>
int numHalfNodes(BinaryTreeNode* root);
int main(int argc, char const *argv[])
{
	BinaryTree b;
	for (int i = 1; i < 5; ++i)
	{
		b.insert(i);
	}
	cout<<"Number of Half Nodes\t"<<numHalfNodes(b.getRoot())<<endl;
	return 0;
}
int numHalfNodes(BinaryTreeNode* root)
{
	int count;
	if(root)
	{
		queue<BinaryTreeNode*> myQueue;
		BinaryTreeNode *front;
		count = 0;
		myQueue.push(root);
		while(!myQueue.empty())
		{
			front = myQueue.front();
			myQueue.pop();
			if(!front->getLeft() && front->getRight() || front->getLeft() && !front->getRight())
			count++;
			if(front->getRight())
			myQueue.push(front->getRight());
			if(front->getLeft())
			myQueue.push(front->getLeft());	
			
			
		}
	}
	else
		return 0;
		return count;	
}