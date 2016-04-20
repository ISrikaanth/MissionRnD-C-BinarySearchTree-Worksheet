/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
int x = 0, y = 0, z = 0;
void inorder(struct node *root, int *arr)
{
	if (root!=NULL)
	{
		inorder(root->left,arr);
		arr[x++] = root->data;
		inorder(root->right,arr);
	}
}
void preorder(struct node *root, int *arr)
{
	if (root != NULL)
	{
		arr[y++] = root->data;
		preorder(root->left, arr);
		preorder(root->right, arr);
	}
}
void postorder(struct node *root, int *arr)
{
	if (root != NULL)
	{
		preorder(root->left, arr);
		preorder(root->right, arr);
		arr[z++] = root->data;
	}
}

