#ifndef ARRAY_OUTPUT
#define ARRAY_OUTPUT
#include <stdlib.h>

void printCommandMessage() {
	printf("\t<<< manual >>>\n h - help (open manual)\n i <array num> - input (input array)\n r <array num> - random input (input random array in range diaposon) \n p <array number> - print (print array)\n c <array number> - insert element by ID\n d <array number> - delete element by ID\n w <first array> <second array> <result array> - work (task function)\n q - quit\n");
}

void printArr(int *arr, int len) {
    if (arr == NULL) {
        puts("output error");
        return;
    }
	for (int i = 0; i < len; ++i) {
		printf("%d ", *(arr+i));
	}
	putchar('\n');
}

#endif
