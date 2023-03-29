#include <stdio.h>

//營敝л熱
int Recursion(int n) {
	if (n <= 1)
		return 1;
	else
		return (n * Recursion(n - 1));
};

//學熱 �蝦� 掘ж晦
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
	printf("營敝л熱 : %d\n", Recursion(num));
	printf("學熱 �蝦� : %d", Handshake(num));
};