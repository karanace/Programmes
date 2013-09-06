#include "BinaryTree.h"
#include <limits>
#include <stack>
void LevelOrderReverse(BinaryTreeNode* root);
int main(int argc, char const *argv[])
{
	BinaryTree b;
	for (int i = 1; i < 10; ++i)
	{
		b.insert(i);
	}
	LevelOrderReverse(b.getRoot());
	return 0;
}
void LevelOrderReverse(BinaryTreeNode* root)
{
	if(root)
	{
		queue<BinaryTreeNode*> myQueue;
		stack<int> myStack;
		BinaryTreeNode *front;
		myQueue.push(root);
		while(!myQueue.empty())
		{
			front = myQueue.front();
			myStack.push(front->getData());
			myQueue.pop();
			if(front->getRight())
				myQueue.push(front->getRight());
			if(front->getLeft())
				myQueue.push(front->getLeft());
		}
		while(!myStack.empty())
		{
			cout<<myStack.top()<<"\t";
			myStack.pop();
		}
		cout<<endl;
		
	}	
}