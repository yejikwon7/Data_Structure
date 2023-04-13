#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

/* ���Ḯ��Ʈ �� �տ� ���� */
Node* push(Node* head, int new_data) {
	Node* new_node = (Node*)malloc(sizeof(Node));

	new_node->data = new_data;
	new_node->next = head;

	head = new_node;
	return head;
}

/* prev_node�� �־����� �� ����� ������ �� ��带 ���� */
void insertAfter(Node* prev_node, int new_data) {
	if (prev_node == NULL) {
		printf("the given previous node can't be null");
		return;
	}

	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = new_data;
	new_node->next = prev_node->next;

	prev_node->next = new_node;
}

/* ���� ����Ʈ�� ���� �� ��带 ���� */
Node* append(Node* head, int new_data) {
	Node* new_node = (Node*)malloc(sizeof(Node));

	Node* last = head;

	new_node->data = new_data;
	new_node->next = NULL;

	if (head == NULL) {
		head = new_node;
		return head;
	}
	
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = new_node;
	return head;
}

/* ���� ���� */
void deleteList(Node* node, int del_data) {
	Node* old;

	if (node == NULL) {
		printf("the given node can't be NULL");
		return;
	}

	old = node->next;
	if (old == NULL) {
		return;
	}
	node->next = old->next;

}

void printList(Node* node) {
	while (node != NULL) {
		printf(" %d ", node->data);
		node = node->next;
	}
}


int main() {
	Node* head = NULL;
	head = append(head, 6);

	head = push(head, 7);
	head = push(head, 1);

	head = append(head, 4);
	head = append(head, 3);

	insertAfter(head->next, 8);
	insertAfter(head, 9);

	printf("\n Created linked list is : ");
	printList(head);

	deleteList(head, 9);

	printf("\n Created linked list is : ");
	printList(head);
}