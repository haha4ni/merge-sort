#include <iostream>
using namespace std;

struct Tree
{
	int var;
	Tree* left;
	Tree* right;
};

void appendNode(Tree** tree, int var)
{
	Tree* node = new(Tree);
	node->var = var;
	node->left = NULL;
	node->right = NULL;
	
	Tree** temp = tree;
	while(*temp != NULL)
	{
		if(var < (*temp)->var)
			temp = &((*temp)->left);
		else
			temp = &((*temp)->right);
	}
	
	*temp = node;
}

void deleteNode(Tree** tree, int var)
{
	Tree** temp = tree;
	while(*temp != NULL)
	{
		if(var < (*temp)->var)
			temp = &((*temp)->left);
		else if(var > (*temp)->var)
			temp = &((*temp)->right);
		else
		{
			if((*temp)->left == NULL && (*temp)->right == NULL)
			{
				delete(*temp);
				*temp = NULL;
				return;
			}
			else if((*temp)->left == NULL)
			{
				Tree* deleteNode = *temp;
				*temp = (*temp)->right;
				delete(deleteNode);
				return;
			}
			else if((*temp)->right == NULL)
			{
				Tree* deleteNode = *temp;
				*temp = (*temp)->left;
				delete(deleteNode);
				return;
			}
			else
			{
				Tree** rightMin = &(*temp)->right;
				while((*rightMin)->left != NULL)
				{
					rightMin = &((*rightMin)->left);
				}
				(*temp)->var = (*rightMin)->var;
				delete(*rightMin);
				*rightMin = NULL;
				return;
			}
		}
	}
}


void preorder(Tree* tree)
{
	cout << tree->var << ",";
	if(tree->left != NULL)
		preorder(tree->left);
	if(tree->right != NULL)
		preorder(tree->right);
}

void inorder(Tree* tree)
{
	if(tree->left != NULL)
		inorder(tree->left);
	cout << tree->var << ",";
	if(tree->right != NULL)
		inorder(tree->right);
}

void postorder(Tree* tree)
{
	if(tree->left != NULL)
		postorder(tree->left);
	if(tree->right != NULL)
		postorder(tree->right);
	cout << tree->var << ",";
}


int main() {
	// your code goes here
	Tree* tree = NULL;
	appendNode(&tree, 10);
	appendNode(&tree, 5);
	appendNode(&tree, 20);
	appendNode(&tree, 3);
	appendNode(&tree, 17);
	
	deleteNode(&tree, 10);
	
	preorder(tree);
	cout << endl;
	inorder(tree);
	cout << endl;
	postorder(tree);
	cout << endl;
	return 0;
}
