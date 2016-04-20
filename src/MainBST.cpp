/*
This Project will seem to be little tougher than before ones .But It can be done very easily
once you completed C-Recursion Project completely .

Note : You can use the functions specified as wrapper functions ,and write new functions 
which might take more parameters .

*/


#include <stdio.h>
#include <stdlib.h>
#include "FunctionHeadersBST.h"

struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct node *newNode(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
struct node * add_node(struct node *root, int data){
	if (root == NULL) return newNode(data);

	if (data < root->data)
		root->left = add_node(root->left, data);
	else if (data > root->data)
		root->right = add_node(root->right, data);
	return root;
}
void swap_nodes1(struct node *a, struct node *b){
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}
int main(){

	//Use it for testing ,Creating BST etc
	struct node *root = NULL;
	int nums[10] = { 7, 5, 10, 8, 6, 4, 1 };

	for (int i = 0; i < 7; i++){
		root = add_node(root, nums[i]);
	}
	struct node *swaplist[2];
	swaplist[0] = root->left->left->left;
	swaplist[1] = root->right;
	swap_nodes1(swaplist[0], swaplist[1]);
	printf("%d %d\n", root->left->left->left->data, root->right->data);
	fix_bst(root);
	printf("%d %d\n", root->left->left->left->data, root->right->data);
	return 0;
}
