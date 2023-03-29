#include <stdio.h>

//Àç±ÍÇÔ¼ö
int Recursion(int n) {
	if (n <= 1)
		return 1;
	else
		return (n * Recursion(n - 1));
};

//¾Ç¼ö È½¼ö ±¸ÇÏ±â
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
	printf("Àç±ÍÇÔ¼ö : %d\n", Recursion(num));
	printf("¾Ç¼ö È½¼ö : %d", Handshake(num));
};