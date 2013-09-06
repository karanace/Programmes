#include "BinaryTree.h"
#include <limits>
bool SearchElement(BinaryTreeNode* root,int findMe);
int main(int argc, char const *argv[])
{
	BinaryTree b;
	for (int i = 0; i < 10; ++i)
	{
		b.insert(i);
	}
	if(SearchElement(b.getRoot(),5))
	cout<<"FOUND!!!"<<endl;
	else
	cout<<"NOT FOUND!!!"<<endl;

	return 0;
}
bool SearchElement(BinaryTreeNode* root,int findMe)
{
	if(root)
	{
				queue<BinaryTreeNode*> myQueue;
				BinaryTreeNode *front;
				myQueue.push(root);
				while(!myQueue.empty())
				{
					front = myQueue.front();
					if(front->getData() == findMe)
						return true;
					myQueue.pop();
					if(front->getLeft())
						myQueue.push(front->getLeft());
					if(front->getRight())
						myQueue.push(front->getRight());
				}
	}
	else
		return false;
	return false;
	
}