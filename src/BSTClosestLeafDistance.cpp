/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>
int find_min(struct node *temp);
struct node{
  struct node * left;
  int data;
  struct node *right;
};

int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if ((root == NULL) || (temp == NULL))
		return -1;
	int r, r1, count = 0, flag = 0;
	struct node *t, *prev1=NULL, *prev2=NULL, *t2=NULL;
	t = temp;
	r = find_min(temp);
	temp = t;
	if (temp != root)
	{
		if (root->data>temp->data)
			flag = 0;
		else
			flag = 1;
		if (flag == 0)
		{
			while (root->data>temp->data)
			{
				prev1 = root;
				root = root->left;
			}
			t2 = prev1->left;
		}
		if (flag != 0)
		{
			while (root->data<temp->data)
			{
				prev2 = root;
				root = root->right;
			}
			t2 = prev2;
		}
		if (flag == 0)
		{
			while (t2->data != temp->data)
			{
				count++;
				t2 = t2->right;
			}
			r1 = count + find_min(prev1->left);
		}
		if (flag != 0)
		{
			while (t2->data != temp->data)
			{
				count++;
				t2 = t2->right;
			}
			r1 = count + find_min(prev2);
		}
		return r<r1 ? r : r1;
	}
	return r;
}
int find_min(struct node *temp)
{
	int min1, min2;
	if (temp == NULL)
		return -1;
	else
	{
		min1 = 1 + find_min(temp->left);
		min2 = 1 + find_min(temp->right);
		return ((min1 < min2 &&min1 != 0) || min2 == 0) ? min1 : min2;
	}
}