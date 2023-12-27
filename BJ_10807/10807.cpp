#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	int a;
	int* arr;
	int count = 0;
	int num;
	scanf("%d", &a);

	arr = (int*) calloc(a, sizeof(int));
	
	for (int i = 0; i < a; ++i) {
		scanf("%d", &arr[i]);
	}

	scanf("%d", &num);

	for (int i = 0; i < a; ++i) {
		if (arr[i] == num) { ++count; }
	}

	printf("%d", count);

	free(arr);

}