#include <stdio.h>

//����Լ�
int Recursion(int n) {
	if (n <= 1)
		return 1;
	else
		return (n * Recursion(n - 1));
};

//�Ǽ� Ƚ�� ���ϱ�
int Handshake(int n) {
	if (n <= 1) {
		return 0;
	}
	else {
		return ((n - 1) + Handshake(n - 1));
	}
};

int main() {
	int num;
	scanf_s("%d", &num);
	printf("����Լ� : %d\n", Recursion(num));
	printf("�Ǽ� Ƚ�� : %d", Handshake(num));
};