#include "BinaryTree.h"
#include <limits>
#include <queue>
int numFullNodes(BinaryTreeNode* root);
int main(int argc, char const *argv[])
{
	BinaryTree b;
	for (int i = 1; i < 4; ++i)
	{
		b.insert(i);
	}
	cout<<"Number of Full Nodes\t"<<numFullNodes(b.getRoot())<<endl;
	return 0;
}
int numFullNodes(BinaryTreeNode* root)
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
			if(front->getLeft() && front->getRight())
			{
				count++;
				myQueue.push(front->getLeft());
				myQueue.push(front->getRight());	
			}
			else
			{
				if(front->getLeft() != NULL)
				myQueue.push(front->getLeft());
				if(front->getRight() != NULL)
				myQueue.push(front->getRight());	
			}

		}
	}
	else
		return 0;
		return count;	
}