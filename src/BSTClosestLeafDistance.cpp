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
#define MAX 9999
struct node{
  struct node * left;
  int data;
  struct node *right;
};
int minimum(int x, int y)
{
	if (x < y)
		return x;
	else
		return y;
}

int closestDownDistance(struct node *root)
{
	if (root == NULL)
		return MAX;
	if (root->left == NULL && root->right == NULL)
		return 0;

	return 1 + minimum(closestDownDistance(root->left), closestDownDistance(root->right));
}

int findClosestLeafDistance(struct node *root, struct node* temp , struct node *ancestors[],int index)
{
	if (root == NULL)
		return MAX;

	if (root->data == temp->data)
	{
		int result = closestDownDistance(root);

		for (int i = index - 1; i >= 0; i--)
			result = minimum(result, index - i + closestDownDistance(ancestors[i]));
		return result;
	}

	ancestors[index] = root;
	return minimum(findClosestLeafDistance(root->left, temp, ancestors, index + 1),findClosestLeafDistance(root->right, temp, ancestors, index + 1));

}

int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root==NULL||temp==NULL)
	  return -1;
	struct node *ancestors[100];
	return findClosestLeafDistance(root, temp, ancestors, 0);
}