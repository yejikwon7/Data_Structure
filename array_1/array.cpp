#include <stdio.h>

main() {
	int array[100][1000];

	printf("%d \n", 1000 * 10 * 4 + 10 * 4); 
	printf("%d", (&array[10][10] - &array[0][0]) * 4);
}