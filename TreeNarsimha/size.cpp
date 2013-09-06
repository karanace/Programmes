#include "BinaryTree.h"
#include <limits>
int size(BinaryTreeNode* root);
int main(int argc, char const *argv[])
{
	BinaryTree b;
	for (int i = 1; i < 10; i+=2)
	{
		b.insert(i*i);
	}
	int count =size(b.getRoot());
	cout<<"Size of Binary Tree is "<<count<<endl;
	return 0;
}
int size(BinaryTreeNode* root)
{
	int count =0;
	if(root)
	{
				queue<BinaryTreeNode*> myQueue;
				BinaryTreeNode *front;
				myQueue.push(root);
				while(!myQueue.empty())
				{
					front = myQueue.front();
					myQueue.pop();
					count++;
					if(front->getLeft())
						myQueue.push(front->getLeft());
					if(front->getRight())
						myQueue.push(front->getRight());
				}
	}
	else
		return 0;
	return count;
	
}