/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};
struct node * array_to_bst(int *arr,int low,int high);
struct node * createnode(int data);
struct node * convert_array_to_bst(int *arr, int len)
{
	int low=0,high=len-1;
	if(arr==NULL)
	   return NULL;
	else
	   return array_to_bst(arr,low,high);
}
struct node * array_to_bst(int *arr,int low,int high)
{
	if(low>high)
	   return NULL;
	else
	{
	   struct node *root;
	   int mid;
	   mid=(low+high)/2;
	   root=createnode(arr[mid]);
	   root->left=array_to_bst(arr,low,mid-1);
	   root->right=array_to_bst(arr,mid+1,high);
	   return root;
    }
}
struct node * createnode(int data)
{
	struct node *t;
	t=(struct node *)malloc(sizeof(struct node));
	t->data=data;
	t->left=NULL;
	t->right=NULL;
	return t;
}
