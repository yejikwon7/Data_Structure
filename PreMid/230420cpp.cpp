#include <stdio.h>
#include <stdlib.h>

/* 1 Head�� ���� ����Ʈ�� ��ó�� ��带 ����Ų�ٰ� �� �� ���� �Լ��� ȣ���� ����� �־��� ���Ḯ��Ʈ�� ������ ��� ����Ͽ� �����ִ°�?
: ���� ����Ʈ�� �ݴ�Ǵ� ��� ���
	����Լ�, ���Ḯ��Ʈ ���� */
void fun1(struct node* head) {
	if (head == NULL)
		return;

	fun1(head->next);
	printf("%d ", head->data); 
}

int main() {
	node* start = NULL;
	fun(start);
}

/* 2 start�� ���Ḯ��Ʈ 1->2->3->4->5->6�� ��ó�� ��带 ����Ų�ٰ� ����. ���� �Լ��� ȣ���� ����� �����ÿ�.*/
void fun(struct node* start) {
	if (start == NULL)
		return;
	printf("%d ", start->data);

	if (start->next != NULL) {
		fun(start->next->next);
	}
	printf("%d ", start->data);
}

/* 3. ���� �Լ��� �Ǹ����� ����� ���Ҹ� ���Ḯ��Ʈ�� �� ó������ �̵������ָ鼭 ������ ���Ḯ��Ʈ�� ������Ʈ�Ͽ� ��ȯ�Ѵ�. �Ʒ��� �� �� �ٿ� �˸��� �ڵ带 ä�������ÿ�. */
typedef struct node {
	int value;
	struct node* next;
}Node;

Node* move_to_front(Node* head) {
	Node* p, * q;
	if ((head == NULL) || (head->next == NULL))
		return head;
	q = NULL; p = head;
	while (p->next != NULL) {
		q = p;
		p = p->next;
	}

	q->next = NULL;
	p->next = head;
	head = p;
	return head;
}
