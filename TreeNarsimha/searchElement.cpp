#include "BinaryTree.h"
#include <limits>
int SearchElement(BinaryTreeNode* root,int findMe);
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
int SearchElement(BinaryTreeNode* root,int findMe)
{
	if(root)
	{
				if(findMe == root->getData())
				{
					return 1;
				}
					
				else
				{
					int temp = SearchElement(root->getLeft(),findMe);
					if(temp!=0)
						return temp;
					else
						return SearchElement(root->getRight(),findMe);
				}
	}
	else
		return 0;
}
	
	

