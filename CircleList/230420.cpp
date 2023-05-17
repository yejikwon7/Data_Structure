
#include <stdio.h>
#include <stdlib.h>

//Now define structure of linked list
typedef struct Node {
	int data;
	struct Node* next;
}Node;

//function to convert linear linked list into circular linked list
Node* circular(Node* head) {
	//declaring a new node name start and assigning head to it.
	Node* start = head;

	//now find the last element of the linked list using while loop
	while (head->next != NULL) {
		head = head->next;
	}

	//now assign start i.e head as next to last elementny head->next=start
	head->next = start;
	return start;
}
Node* push(Node* head, int data)
{
	// Allocate dynamic memory for newNode.
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;

	newNode->next = head;

	head = newNode;

	return head;
}

// Function that display the elements of circular linked list.
void displayList(Node* node, char C)
{
	if (C == 'c') {
		Node* start = node;

		while (node->next != start) {
			printf("[%i] [%p]->%p\n", node->data, node, node->next);
			node = node->next;
		}
		printf("[%i] [%p]->%p\n", node->data, node, node->next);
	}
	else {
		while (node) {
			printf("[%i] [%p]->%p\n", node->data, node, node->next);
			node = node->next;
		}
		printf("\n");

	}
}
// Driver program to test the functions
int main()
{
	// Start with empty list
	Node* head = NULL;

	// Using push() function to construct
	// singly linked list
	// 17->22->13->14->15

	head = push(head, 15);
	head = push(head, 14);
	head = push(head, 13);
	head = push(head, 22);
	head = push(head, 17);

	printf("Display linear linked list: \n");
	displayList(head, 's');

	// Call the circular_list function that
	// convert singly linked list to circular
	// linked list.
	circular(head);

	printf("Display circular linked list: \n");
	displayList(head, 'c');

	return 0;
}