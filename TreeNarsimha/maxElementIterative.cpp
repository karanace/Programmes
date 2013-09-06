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
	int maxElement = numeric_limits<int>::min();
	queue<BinaryTreeNode*> myQueue;
	if(root)
	{
		myQueue.push(root);
		while(!myQueue.empty())
		{
			BinaryTreeNode *front = myQueue.front();
			if(front->getData() > maxElement)
				maxElement = front->getData();
			myQueue.pop();
			if(front->getLeft())
			{
				myQueue.push(front->getLeft());
			}
			if(front->getRight())
			{
				myQueue.push(front->getRight());
			}

		}

	}
	return maxElement;
}