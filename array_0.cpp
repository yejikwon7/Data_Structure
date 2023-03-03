#include <stdio.h>

int main(void) {
	int array[5][7] = { 1 }; /* 10행 10열의 배열 선언 */

	printf("%d %d \n", &array[0][0], &array[3][4]); /* 해당 인덱스에 위치한 배열 주소 출력 */
}