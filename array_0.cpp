#include <stdio.h>

int main(void) {
	int array[5][7] = { 1 }; /* 10�� 10���� �迭 ���� */

	printf("%d %d \n", &array[0][0], &array[3][4]); /* �ش� �ε����� ��ġ�� �迭 �ּ� ��� */
}