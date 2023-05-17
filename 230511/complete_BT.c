// 완전 이진 트리인지 판단하는 
/* C program to checks if a binary tree complete or not */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Tree node structure */
struct Node
{
	int key; // 데이터 값
	struct Node* left, * right; // 왼쪽, 오른쪽 서브 트리 노드
};

/* Helper function that allocates a new node with the
given key and NULL left and right pointer. */
struct Node* newNode(char k)
{
	// 새로운 노드 생성
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->key = k;
	node->right = node->left = NULL;
	return node;
}

/* This function counts the numer of nodes in a binary tree */
unsigned int countNodes(struct Node* root)
{
	if (root == NULL)
		return 0;
	return (1 + countNodes(root->left) + countNodes(root->right));
}

/* This function checks if the binary tree is complete or not */
// 이진 트리인지 판별하는 코드
bool isComplete(struct Node* root, unsigned int index,
	unsigned int number_nodes)
{
	// An empty tree is complete
	if (root == NULL)
		return (true);

	// If index assigned to current node is more than
	// number of nodes in tree, then tree is not complete
	if (index >= number_nodes)
		return (false);

	// Recur for left and right subtrees
	return (isComplete(root->left, 2 * index + 1, number_nodes) &&
		isComplete(root->right, 2 * index + 2, number_nodes));
}

int main()
{
	// Le us create tree in the last diagram above
	struct Node* root = NULL;
	root = newNode(1); // 루트 노드의 데이터
	root->left = newNode(2); // 새로운 노드 생성, 루트 왼쪽에 노드 생성
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(6); // : 완전 이진 트리 X
	// if root->right->left : 완전 이진 트리

	unsigned int node_count = countNodes(root);
	unsigned int index = 0;

	if (isComplete(root, index, node_count))
		printf("The Binary Tree is complete \n");
	else
		printf("The Binary Tree is not complete \n");
	return (0);
}