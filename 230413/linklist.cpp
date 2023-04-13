// linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void print_list(struct Node* n)
{
	while (n != NULL) {
		printf("%d", n->data);
		n = n->next;
	}
	printf("\nNULL");
}


// Driver's code
int main()
{
	struct Node* head = NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;
	struct Node* fourth = NULL;
	struct Node* fifth = NULL;
	struct Node* sixth = NULL;

	// allocate 3 nodes in the heap
	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	fourth = (struct Node*)malloc(sizeof(struct Node));
	fifth = (struct Node*)malloc(sizeof(struct Node));
	sixth = (struct Node*)malloc(sizeof(struct Node));

	head->data = 1; // assign data in first node
	head->next = second; // Link first node with the second node

	second->data = 4;

	// Link second node with the third node
	second->next = third;

	third->data = 0; // assign data to third node
	third->next = fourth;

	fourth->data = 5;
	fourth->next = fifth;

	fifth->data = 0;
	fifth->next = sixth;

	sixth->data = 8;
	sixth->next = NULL;


	print_list(head);

	free(head);
	free(second);
	free(third);
	free(fourth);
	free(fifth);
	free(sixth);

	return 0;
}