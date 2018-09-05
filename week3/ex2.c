#include <stdio.h>

void swap(int* v1, int* v2) {
	int tmp = *v1;
	*v1 = *v2;
	*v2 = tmp;
}

void bubble_sort(int* array, int size) {
	int flag = 1;
	while(flag) {
		flag = 0;
		for(int i = 1; i < size; i++) {
			if(array[i - 1] > array[i]) {
				swap(&array[i - 1], &array[i]);
				flag = 1;
			}
		}
	}
}

int main() {
	int array[] = {1, 94, 2, 99, 93, 94, 92, 11, 43, 66};
	bubble_sort(array, 10);
	for(int i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}