#include "BinaryTree.h"
#include <limits>
#include <queue>
int numLeaves(BinaryTreeNode* root);
int main(int argc, char const *argv[])
{
	BinaryTree b;
	for (int i = 1; i < 10; ++i)
	{
		b.insert(i);
	}
	cout<<"Number of leaves\t"<<numLeaves(b.getRoot())<<endl;
	return 0;
}
int numLeaves(BinaryTreeNode* root)
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
			if(front->getLeft() == NULL && front->getRight() == NULL)
				count++;
			else
			{
				if(front->getLeft())
				myQueue.push(front->getLeft());
				if(front->getRight())
				myQueue.push(front->getRight());	
			}
				
		}
	}
	else
		return 0;
		return count;
}	
