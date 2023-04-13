//중간고사 범위
// C code to delete a node from linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int number;
	struct Node* next;
}Node;

Node* Push(Node* head, int A)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->number = A;
	new_node->next = head;
	head = new_node;
	return head;
}

Node* deleteN(Node* head, int D)
{
	Node* cur_prev = NULL;
	Node* cur = head;

	int search = 0;

	while (cur != NULL) {

		if (cur->number == D) {
			search = 1;
			break;
		}
		cur_prev = cur;
		cur = cur->next;
	}
	if (search == 1)
	{
		printf("%d를 삭제합니다.\n", D);

		if (cur == head) head = cur->next;
		else cur_prev->next = cur->next;

		free(cur);
	}
	else
	{
		printf("%d를 찾을 수 없습니다.\n", D);
	}

	return head;
}

void printList(Node* head)
{
	while (head) {
		printf("[%i] [%p] -> %p\n", head->number, head, head->next);
		head = head->next;
	}
	printf("\n");
}

// Drivers code
int main()
{
	Node* list = NULL;

	list = Push(list, 1);
	list = Push(list, 2);
	list = Push(list, 3);
	list = Push(list, 4);

	printList(list);
	printf("Print Linked List Done!\n");

	// Delete any position from list

	list = deleteN(list, 7);

	list = deleteN(list, 6);

	list = deleteN(list, 5);

	list = deleteN(list, 1);
	printList(list);

	list = deleteN(list, 3);
	printList(list);

	list = deleteN(list, 2);
	printList(list);

	list = deleteN(list, 0);
	printList(list);

	list = deleteN(list, 4);
	printList(list);

	return 0;
}