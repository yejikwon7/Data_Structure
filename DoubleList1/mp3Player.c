/* 헤더파일 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> /* malloc을 위함 */
#include <string.h> /* 노래 제목을 위한 string 헤더파일 선언 */

typedef char element[100];
typedef struct DListNode {	// 이중연결 노드 타입
	element data;
	struct DListNode* prev;
	struct DListNode* next;
} DListNode;

DListNode* current; /* 현재 플레이되고 있는 곡 */

// 이중 연결 리스트를 초기화
/* 나 자신의 주소를 넣어줌 */
void init(DListNode* phead)
{
	phead->prev = phead;
	phead->next = phead;
}

// 이중 연결 리스트의 노드를 출력
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
// 노드 newnode를 before노드의 오른쪽에 삽입한다.
void dinsert(DListNode* before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));

	/* 새로운 노드의 데이터를 데이터로 카피 */
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

	/* 삭제할 노드 찾기 위해 removed 노드 생성 */
	DListNode* removed = (DListNode*)malloc(sizeof(DListNode));
	removed = head;

	printf("key = %s\n", key);

	/* 문자열 비교 */
	/* 같을 때까지 곡 찾음 */
	while (strcmp(removed->data, key) != 0) {
		if (removed->prev == head) {
			printf("List doesn't have node with value = %s", key);
			return;
		}
		removed = removed->prev;
		printf("removed: %p, removed->data = %s\n", removed, removed->data);
		printf("removed->prev: %p, removed->prev->data = %s\n", removed->prev, removed->prev->data);
	}

	/* 찾으면 removed 노드 삭제 */
	if (removed == head) return;
	removed->prev->next = removed->next;
	removed->next->prev = removed->prev;
	free(removed);
}


// 이중 연결 리스트 테스트 프로그램
int main(void)
{
	char ch;
	/* head는 더 이상 NULL이 아니게 됨, head 주소 생김 */
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
		printf("\n명령어를 입력하시오(<, >, q): ");
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