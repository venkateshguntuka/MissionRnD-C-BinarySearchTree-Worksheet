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

int findHeight(struct node* root)
{
	if (root == NULL)
		return 0;
	int leftHeight = findHeight(root->left);
	int rightHeight = findHeight(root->right);
	if (leftHeight <= rightHeight)
		return rightHeight + 1;
	else
		return leftHeight + 1;
}
int count(struct node* root)
{
	int cnt = 1;
	if (root == NULL)
		return 0;
	cnt += count(root->left);
	cnt += count(root->right);
	return cnt;
}

int * printCurrentLevel(struct node* root, int height, int *arr, int *index)
{
	if (root == NULL)
		return NULL;
	if (height == 1)
	{
		arr[*index] = root->data;
		*index = *index + 1;
	}
	else if (height>1)
	{
		printCurrentLevel(root->right, height - 1, arr, index);
		printCurrentLevel(root->left, height - 1, arr, index);
	}
	return arr;
}

int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)
		return NULL;
	int height = findHeight(root);
	int i, len;
	len = count(root);
	int *arr = (int*)malloc(sizeof(int)*len);
	int index = 0, *res;
	for (i = 1; i <= height; i++)
	{
		printCurrentLevel(root, i, arr, &index);
	}
	return arr;

}