/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void right_to_left(struct node *root,int *arr);
int w = 0;
int find_height1(struct node *root);
void store_at_each_level(struct node *root,int i, int *arr);
int* BSTRighttoLeftRows(struct node* root)
{
	if (root==NULL)
		return NULL;
	int *arr;
	arr = (int *)malloc(100 * sizeof(int));
	right_to_left(root,arr);
	w = 0;
	return arr;
}
void right_to_left(struct node *root,int *arr)
{
	int h;
	h = find_height1(root);
	for (int i = 1; i <= h; i++)
		store_at_each_level(root, i, arr);
}
int find_height1(struct node *t)
{
	int h1, h2;
	if (t == NULL)
		return 0;
	h1 = 1 + find_height1(t->left);
	h2 = 1 + find_height1(t->right);
	return h1 > h2 ? h1 : h2;
}
void store_at_each_level(struct node *root, int level, int *arr)
{
	if (root == NULL)
		return;
	if (level == 1)
		arr[w++] = root->data;
	else if (level>1)
	{
		store_at_each_level(root->right, level -1, arr);
		store_at_each_level(root->left, level - 1, arr);
	}
}