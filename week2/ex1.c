#include <stdio.h>
#include <float.h>
#include <limits.h>

int main() {
	int integer = INT_MAX;
	float float_number = FLT_MAX;
	double double_number = DBL_MAX;
	printf("%lu %d\n%lu %f\n%lu %G\n", sizeof(integer), integer, sizeof(float_number), float_number, sizeof(double_number), double_number);

	return 0;
}
