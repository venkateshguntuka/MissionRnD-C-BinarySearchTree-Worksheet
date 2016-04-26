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
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
void correctBST(struct node* root, struct node** first,struct node** middle, struct node** last,struct node** prev)
{
	if (root)
	{
		correctBST(root->left, first, middle, last, prev);
		if (*prev && root->data < (*prev)->data)
		{
			if (*middle==NULL)
			{
				*first = *prev;
				*middle = root;
			}

			else
				*last = root;
		}
		*prev = root;
		correctBST(root->right, first, middle, last, prev);
	}
}
void fix_bst(struct node *root){
	struct node *first, *mid, *last, *prev;
	first = mid = last = prev = NULL;
	correctBST(root, &first, &mid, &last, &prev);

	
	if (first && last)
		swap(&(first->data), &(last->data));
	else if (first && mid)
		swap(&(first->data), &(mid->data));
}
