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
void getInorder(struct node* root, int *arr, int *j)
{
	if (root == NULL)
		return;
	getInorder(root->left, arr, j);
	arr[*j] = root->data;
	*j = *j + 1;
	getInorder(root->right, arr, j);
}
void getPreorder(struct node* root, int *arr, int *j)
{
	if (root == NULL)
		return;
	arr[*j] = root->data;
	*j = *j + 1;
	getPreorder(root->left, arr, j);
	getPreorder(root->right, arr, j);
}
void getPostorder(struct node* root, int *arr, int *j)
{
	if (root == NULL)
		return;
	getPreorder(root->left, arr, j);
	getPreorder(root->right, arr, j);
	arr[*j] = root->data;
	*j = *j + 1;
}
void inorder(struct node *root, int *arr){
	int j = 0;
	if (root == NULL||arr==NULL)
		return;
	getInorder(root, arr, &j);
}
void preorder(struct node *root, int *arr){
	int j = 0;
	if (root == NULL||arr==NULL)
		return;
	getPreorder(root, arr, &j);
}
void postorder(struct node *root, int *arr){
	int j = 0;
	if (root == NULL||arr==NULL)
		return;
	getPostorder(root, arr, &j);
}

