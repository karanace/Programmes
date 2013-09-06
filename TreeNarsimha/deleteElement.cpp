#include "BinaryTree.h"
#include <limits>
BinaryTreeNode* DeepestNode(BinaryTreeNode* root);
bool DeleteElement(BinaryTreeNode* root,int deleteMe);
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
int main(int argc, char const *argv[])
{
	BinaryTree b;
	for (int i = 0; i < 10; ++i)
	{
		b.insert(i);
	}
	if(DeleteElement(b.getRoot(),5))
		cout<<"Deleted"<<endl;
	else
		cout<<"Not Possible"<<endl;
	LevelOrderReverse(b.getRoot());	
	return 0;
}
bool DeleteElement(BinaryTreeNode* root,int deleteMe)
{
	bool deleted = false;
	if(root)
	{
		
		BinaryTreeNode *myDeepestNode = DeepestNode(root);
		int data = myDeepestNode->getData();
				if(deleteMe == root->getData())
				{
					//return 1;
					root->setData(data);
					myDeepestNode = NULL;
					deleted = true;
				}
				else
				{
					deleted = DeleteElement(root->getLeft(),deleteMe);
					if(!deleted)
					deleted = DeleteElement(root->getRight(),deleteMe);
				}
	}
	if(deleted)
	return true;
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
	

