#include<bits/stdc++.h>
using namespace std;

struct node
{
	int val;
	struct node* left;
	struct node* right;
	node(int value)
	{
		val = value;
		struct node* left = NULL;
		struct node* right = NULL;
	}

	void print()
	{
		cout<<val;
	}
};


void print_inorder(struct node* root)
{
	if(root!=NULL)
	{
		print_inorder(root->left);
		cout<<root->val<<' ';
		print_inorder(root->right);
	}
}

void print_preorder(struct node* root)
{
	if(root!=NULL)
	{
		cout<<root->val<<' ';
		print_preorder(root->left);
		print_preorder(root->right);
	}	
}

void print_postorder(struct node* root)
{
	if(root!=NULL)
	{
		print_postorder(root->left);
		print_postorder(root->right);
		cout<<root->val<<' ';
	}	
}

int main()
{
	// construct a simple tree
	struct node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);

	cout<<"\nPreorder: ";
	print_preorder(root);
	cout<<"\nInorder: ";
	print_inorder(root);
	cout<<"\nPostorder: ";
	print_postorder(root);
		
	return 0;
}