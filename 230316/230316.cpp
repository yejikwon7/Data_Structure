#include <stdio.h>

void main() {
	int a = 0, i = 1000;

	while (i > 0) {
		a += i;
		i /= 2;
		printf("%d \n", i);
	}
}