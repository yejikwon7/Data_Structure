#include <stdio.h>
#include <stdlib.h>

/* 1 Head가 연결 리스트의 맨처음 노드를 가리킨다고 할 때 다음 함수를 호출한 결과는 주어진 연결리스트의 노드들을 어떻게 출력하여 보여주는가?
: 원래 리스트이 반대되는 결과 출력
	재귀함수, 연결리스트 개념 */
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

/* 2 start는 연결리스트 1->2->3->4->5->6의 맨처음 노드를 가리킨다고 하자. 다음 함수를 호출한 결과를 적으시오.*/
void fun(struct node* start) {
	if (start == NULL)
		return;
	printf("%d ", start->data);

	if (start->next != NULL) {
		fun(start->next->next);
	}
	printf("%d ", start->data);
}

/* 3. 다음 함수는 맨마지막 노드의 원소를 연결리스트의 맨 처음으로 이동시켜주면서 기존의 연결리스트를 업데이트하여 반환한다. 아래의 빈 세 줄에 알맞은 코드를 채워넣으시오. */
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
