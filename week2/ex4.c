#include <stdio.h>
#include <stdlib.h>

void swap(int *n1, int *n2) {
	int tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

int main() {
	int n1, n2;
	printf("Enter the first number: ");
	scanf("%d", &n1);
        printf("Enter the second number: ");
        scanf("%d", &n2);

	swap(&n1, &n2);
	
	printf("%d %d\n", n1, n2);

	return 0;
}
