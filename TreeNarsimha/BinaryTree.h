#include "BinaryTreeNode.h"
#include <queue>
#include <iostream>
#include <stack>
class BinaryTree
{
	BinaryTreeNode *root;

	public:
		BinaryTree()
		{
			root = NULL;
		}
		BinaryTreeNode* getRoot()
		{
			return root;
		}
		void insert(int data)
		{
			if(root == NULL)
			{
				root = new BinaryTreeNode();
				root->setData(data);
				root->setLeft(NULL);
				root->setRight(NULL);
			}
			else
			{
				queue< BinaryTreeNode* > nodes;
				nodes.push(root);
				while(!nodes.empty())
				{
					BinaryTreeNode *temp = nodes.front();
					nodes.pop();
					if(temp->getLeft() == NULL)
					{
						temp->setLeft(new BinaryTreeNode);
						temp->getLeft()->setData(data);
						temp->getLeft()->setLeft(NULL);
						temp->getLeft()->setRight(NULL);
						break;

					}
					else
					nodes.push(temp->getLeft());
					if(temp->getRight() == NULL)
					{
						temp->setRight(new BinaryTreeNode);
						temp->getRight()->setData(data);
						temp->getRight()->setLeft(NULL);
						temp->getRight()->setRight(NULL);
						break;
					}
					else
					nodes.push(root->getRight());
				}
								
			}

		}
		void preOrderR(BinaryTreeNode *root)
		{
			if(root)
			{
				cout<<root->getData()<<"\t";
				preOrderR(root->getLeft());
				preOrderR(root->getRight());
			}
		}
		void postOrderR(BinaryTreeNode *root)
		{
			if(root)
			{
				postOrderR(root->getLeft());
				postOrderR(root->getRight());
				cout<<root->getData()<<"\t";
			}
		}
		void inOrderR(BinaryTreeNode *root)
		{
			if(root)
			{
				inOrderR(root->getLeft());
				cout<<root->getData()<<"\t";
				inOrderR(root->getRight());
				
			}
		}
		void preOrderR()
		{
			preOrderR(root);	
		}
		void postOrderR()
		{
			postOrderR(root);
		}
		void inOrderR()
		{
			inOrderR(root);
		}

		void preOrderI()
		{
			stack<BinaryTreeNode*> myStack;
			if(root)
			{
				myStack.push(root);
				while(!myStack.empty())
				{
					BinaryTreeNode *temp = myStack.top();
					cout<<temp->getData()<<"\t";
					myStack.pop();
					if(temp->getRight())
						myStack.push(temp->getRight());
					if(temp->getLeft())
						myStack.push(temp->getLeft());
				}

			}
		}

		void inOrderI()
		{
			stack<BinaryTreeNode*> myStack;
			BinaryTreeNode *temp = root;
			while(1)
			{
				while(temp)
				{
					myStack.push(temp);
					temp = temp->getLeft();
				}

				if(myStack.empty())
				break;	
				temp = myStack.top();
				myStack.pop();
				cout<<temp->getData()<<"\t";
				temp = temp->getRight();

			}

		}
		void levelOrder()
		{
			if(root)
			{
				queue<BinaryTreeNode*> myQueue;
				BinaryTreeNode *temp = root;
				myQueue.push(temp);

				while(!myQueue.empty())
				{
					temp = myQueue.front();
					myQueue.pop();
					cout<<temp->getData()<<"\t";
					if(temp->getLeft())
					myQueue.push(temp->getLeft());
					if(temp->getRight())
					myQueue.push(temp->getRight());

				}
			}
		}
		
};