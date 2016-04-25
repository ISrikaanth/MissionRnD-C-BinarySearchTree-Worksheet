/*Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

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
#include <stdlib.h>
#include <stddef.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};
int x = 0, y = 0, z = 0;
void inorder(struct node *root, int *arr);
void preorder(struct node *root, int *arr);
void postorder(struct node *root, int *arr);
void inorder_wrap(struct node *root, int *arr);
void preorder_wrap(struct node *root, int *arr);
void postorder_wrap(struct node *root, int *arr);
void inorder(struct node *root, int *arr)
{
	int i;
	for (i = 0; i < x; i++)
		arr[i] = '\0';
	x = 0;
	if ((root != NULL) && (arr!=NULL))
		inorder_wrap(root, arr);
}
void preorder(struct node *root, int *arr)
{
	int i;
	for (i = 0; i < y; i++)
		arr[i] = '\0';
	y = 0;
	if ((root != NULL) && (arr != NULL))
		preorder_wrap(root, arr);
}
void postorder(struct node *root, int *arr)
{
	int i;
	for (i = 0; i < z; i++)
		arr[i] = '\0';
	z = 0;
	if ((root != NULL) && (arr != NULL))
		postorder_wrap(root, arr);
}
void inorder_wrap(struct node *root, int *arr)
{
	if (root != NULL)
	{
		inorder_wrap(root->left, arr);
		arr[x] = root->data;
		x += 1;
		inorder_wrap(root->right, arr);
	}
}
void preorder_wrap(struct node *root, int *arr)
{
	if (root != NULL)
	{
		arr[y] = root->data;
		y += 1;
		preorder_wrap(root->left, arr);
		preorder_wrap(root->right, arr);
	}
}
void postorder_wrap(struct node *root, int *arr)
{
	if (root != NULL)
	{
		postorder_wrap(root->left, arr);
		postorder_wrap(root->right, arr);
		arr[z] = root->data;
		z += 1;
	}
}