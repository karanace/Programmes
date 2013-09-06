#include "BinaryTree.h"
#include <limits>
void ReverseEveryLevel(BinaryTreeNode* root);
int main(int argc, char const *argv[])
{
	BinaryTree b;
	for (int i = 1; i < 10; ++i)
	{
		b.insert(i);
	}
	ReverseEveryLevel(b.getRoot());
	return 0;
}
void ReverseEveryLevel(BinaryTreeNode* root)
{
	if(root)
	{
		queue<BinaryTreeNode*> myQueue;
		BinaryTreeNode *front;
		myQueue.push(root);
		while(!myQueue.empty())
		{
			front = myQueue.front();
			cout<<front->getData()<<"\t";
			myQueue.pop();
			if(front->getRight())
				myQueue.push(front->getRight());
			if(front->getLeft())
				myQueue.push(front->getLeft());
		}
		cout<<endl;
	}	
}