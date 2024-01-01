#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main() {
	
	int a;
	int num;
	int* arr;
	int j = 0;
	int temp;
	scanf("%d", &a);
	arr = (int*)calloc(a, sizeof(int));
	memset(arr, '\0', a * sizeof(int));
	scanf("%d" ,&num);
	for (int i = 0; i < a; ++i) {
		scanf("%d",&temp);
		if (temp < num) {
			arr[j] = temp;
			++j;

		}

	}

	j = 0;
	while (arr[j] != '\0') {
		printf("%d ", arr[j]);
		++j;
	}

	free(arr);

	return 0;

	
	
	return 0;
}