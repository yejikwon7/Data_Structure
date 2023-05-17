/* program for construction of full binary tree */
/* 시간복잡도 O(h) 
full binary tree 가 complete binary tree 보다 효율성이 좋음 */
#include <stdio.h>
#include <stdlib.h>

/* A binary tree node had data, pointer to left child
and a pointer to right child */
struct node
{
	int data;
	struct node* left;
	struct node* right;
};

// A utility function to create a node
struct node* newNode(int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));

	temp->data = data;
	temp->left = temp->right = NULL;

	return temp;
}

/* A recursive function to construct Full from pre[] and post[]. 
preIndex is used to keep track of index in pre[]. 
I is low index and h is high index for the current subarray in post[] */
struct node* constrcutTreeUtil(int pre[], int post[], int* preIndex,
	int I, int h, int size)
{
	// Base case
	if (*preIndex >= size || I > h)
		return NULL;

	/* The first node in preorder traversal is root. So take the node at
	preIndex from preorder and make it root, and increment preIndex */
	struct node* root = newNode(pre[*preIndex]);
	++* preIndex;

	/* If the current subarray has only one element, no need to recur */
	if (I == h)
		return root;

	/* Search the next element of pre[] in post[] */
	int i;
	for (i = I; i <= h; ++i)
		if (pre[*preIndex] == post[i])
			break;

	/* Use the index of element found in postorder to divide
	postorder array in two parts. Left subtree and right subtree */
	if (i <= h)
	{
		root->left = constructTreeUtil(pre, post, preIndex,
			I, i, size);
		root->right = constructTreeUtil(pre, post, preIndex,
			i + 1, h - 1, size);
	}
	return root;
}