#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define NUM 9

int main() {
	int* arr;
	int max;
	short index;
	arr = (int*)calloc(NUM, sizeof(int));
	memset(arr, NULL, NUM * sizeof(int));

	for (int i = 0; i < NUM; ++i) {
		scanf("%d", &arr[i]);
		if (i == 0) {
			max = arr[i];
			index = 0;
		}
		if (arr[i] > max) {
			max = arr[i];
			index = i;
		}

	}

	printf("%d\n%d", max, index);
	
	free(arr);

	
}