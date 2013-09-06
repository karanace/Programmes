using namespace std;
#include <iostream>
class BinaryTreeNode
{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;

	public:
		BinaryTreeNode()
		{
			left = NULL;
			right = NULL;
		}
		void setData(int data)
		{
			this->data = data;
		}
		void setLeft(BinaryTreeNode *left)
		{
			this->left = left;
		}
		void setRight(BinaryTreeNode *right)
		{
			this->right = right;
		}
		int getData()
		{
			return data;
		}
		BinaryTreeNode* getLeft()
		{
			return left;
		}
		BinaryTreeNode* getRight()
		{
			return right;
		}
};