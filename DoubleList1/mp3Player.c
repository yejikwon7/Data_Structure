/* ������� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> /* malloc�� ���� */
#include <string.h> /* �뷡 ������ ���� string ������� ���� */

typedef char element[100];
typedef struct DListNode {	// ���߿��� ��� Ÿ��
	element data;
	struct DListNode* prev;
	struct DListNode* next;
} DListNode;

DListNode* current; /* ���� �÷��̵ǰ� �ִ� �� */

// ���� ���� ����Ʈ�� �ʱ�ȭ
/* �� �ڽ��� �ּҸ� �־��� */
void init(DListNode* phead)
{
	phead->prev = phead;
	phead->next = phead;
}

// ���� ���� ����Ʈ�� ��带 ���
void print_dlist(DListNode* phead)
{
	DListNode* p = phead;

	printf("\n MP3 Playlist:\n");
	printf("\n phead: %p\n", phead);

	for (p = phead->next; p != phead; p = p->next) {
		if (p == current)
			printf("<-| #%s# |-> ", p->data);
		else
			printf("<-| %s |-> ", p->data);
	}
	printf("\n");
}
// ��� newnode�� before����� �����ʿ� �����Ѵ�.
void dinsert(DListNode* before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));

	/* ���ο� ����� �����͸� �����ͷ� ī�� */
	strcpy(newnode->data, data);

	newnode->prev = before;
	newnode->next = before->next;
	before->next->prev = newnode;
	before->next = newnode;

	printf("\n *before: %p\n", before);
	printf("\n *newnode: %p, newnode->data: %s\n", newnode, newnode->data);

}

void ddelete(DListNode* head, element key)
{
	// if list is empty
	if (head == NULL) return;

	/* ������ ��� ã�� ���� removed ��� ���� */
	DListNode* removed = (DListNode*)malloc(sizeof(DListNode));
	removed = head;

	printf("key = %s\n", key);

	/* ���ڿ� �� */
	/* ���� ������ �� ã�� */
	while (strcmp(removed->data, key) != 0) {
		if (removed->prev == head) {
			printf("List doesn't have node with value = %s", key);
			return;
		}
		removed = removed->prev;
		printf("removed: %p, removed->data = %s\n", removed, removed->data);
		printf("removed->prev: %p, removed->prev->data = %s\n", removed->prev, removed->prev->data);
	}

	/* ã���� removed ��� ���� */
	if (removed == head) return;
	removed->prev->next = removed->next;
	removed->next->prev = removed->prev;
	free(removed);
}


// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
int main(void)
{
	char ch;
	/* head�� �� �̻� NULL�� �ƴϰ� ��, head �ּ� ���� */
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);

	dinsert(head, "DNA");
	dinsert(head, "Dynamite");
	dinsert(head, "Butter");
	dinsert(head, "Fake Love");
	dinsert(head, "Persona");
	dinsert(head, "Dreamers");

	current = head->next;
	print_dlist(head);

	ddelete(head, "Butter");
	print_dlist(head);

	ddelete(head, "DNA");
	print_dlist(head);

	dinsert(head, "Proof");
	print_dlist(head);

	do {
		printf("\n��ɾ �Է��Ͻÿ�(<, >, q): ");
		ch = getchar();
		if (ch == '<') {
			current = current->prev;
			if (current == head)
				current = current->prev;
		}
		else if (ch == '>') {
			current = current->next;
			if (current == head)
				current = current->next;
		}
		print_dlist(head);
		getchar();
	} while (ch != 'q');

	free(head);
}