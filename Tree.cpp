#include <iostream>
using namespace std;

struct Tree
{
	int var;
	Tree* left;
	Tree* right;
};

void append(Tree** tree, int var)
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
		preorder(tree->left);
	cout << tree->var << ",";
	if(tree->right != NULL)
		preorder(tree->right);
}

void postorder(Tree* tree)
{
	if(tree->left != NULL)
		preorder(tree->left);
	if(tree->right != NULL)
		preorder(tree->right);
	cout << tree->var << ",";
}


int main() {
	// your code goes here
	Tree* tree = NULL;
	append(&tree, 10);
	append(&tree, 5);
	append(&tree, 20);
	
	preorder(tree);
	cout << endl;
	inorder(tree);
	cout << endl;
	postorder(tree);
	cout << endl;
	return 0;
}
