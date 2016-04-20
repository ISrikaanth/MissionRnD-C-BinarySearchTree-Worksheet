/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};
int j = 0;
struct node *fixfirst = NULL, *fixsecond = NULL;
void create_array(struct node *root, int *arr)
{
	if (root != NULL)
	{
		create_array(root->left, arr);
		arr[j] = root->data;
		j += 1;
		create_array(root->right, arr);
	}
}
void find_childs(struct node *root, int a)
{
	if (root != NULL)
	{
		find_childs(root->left, a);
		if (root->data == a)
			fixfirst = root;
		find_childs(root->right, a);
		if (root->data == a)
			fixfirst = root;
	}
}
void find_parents(struct node *root, int a)
{
	if (root != NULL)
	{
		if (((root != NULL) && (root->left != NULL) && (root->left->data == a)) || ((root != NULL) && (root->right != NULL) && (root->right->data == a)))
			fixsecond = root;
		find_parents(root->left, a);
		find_parents(root->right, a);
	}
}
void swap_nodes2(struct node *a, struct node *b){
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}
void fix_bst(struct node *root)
{
	if (root == NULL)
		return;
	struct node *first, *second, *prev1, *prev2;
	int *arr, fix1, fix2, i, flag = 0;
	arr = (int *)malloc(1000 * sizeof(int));
	create_array(root, arr);
	for (i = 0;i<j-1; i++)
	{
		if (arr[i]>arr[i + 1])
		{
			fix1 = arr[i];
			break;
		}
	}
	for (i = i + 1; i<j - 1; i++)
	{
		if (arr[i]>arr[i + 1])
		{
			flag = 1;
			fix2 = arr[i + 1];
			break;
		}
	}
	if (flag == 0)
	{
		fix2 = arr[i - 1];
		if (fix2 == fix1)
			fix2 = arr[i];
	}
	find_childs(root, fix1);
	if (root->data == fix1)
		fixsecond = root;
	else
		find_parents(root, fix1);
	first = fixfirst;
	prev1 = fixsecond;
	find_childs(root, fix2);
	if (root->data == fix2)
		fixsecond = root;
	else
		find_parents(root, fix2);
	second = fixfirst;
	prev2 = fixsecond;
	swap_nodes2(first, second);
	if ((prev1->data)>(first->data))
		prev1->left = first;
	else
		prev1->right = first;
	if ((prev2->data)>(second->data))
		prev2->left = second;
	else
		prev2->right = second;
	j = 0;
	fixfirst = NULL;
	fixsecond = NULL;
}