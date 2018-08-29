#include <stdio.h>
#include <stdlib.h>

void print_triangle(int n) {
	for(int i = 0; i < n; i++) {
		for(int i2 = 0; i2 < n - i - 1; i2++) {
			printf(" ");
		}
                for(int i2 = 0; i2 < 2 * i + 1; i2++) {
                        printf("*");
                }
                for(int i2 = 0; i2 < n - i - 1; i2++) {
                        printf(" ");
                }
		printf("\n");
	}
}

void print_square(int n) {
        for(int i = 0; i < n; i++) {
                for(int i2 = 0; i2 < n; i2++) {
                        printf("*");
                }
                printf("\n");
        }
}

void print_right_triangle(int n) {
        for(int i = 0; i < n; i++) {
                for(int i2 = 0; i2 < i + 1; i2++) {
                        printf("*");
                }
                printf("\n");
        }
}

void print_transposed_triangle(int n) {
        for(int i = 0; i < n; i++) {
                for(int i2 = 0; i2 < i + 1; i2++) {
                        printf("*");
                }
                printf("\n");
        }
        for(int i = n - 1; i >= 0; i--) {
                for(int i2 = 0; i2 < i + 1; i2++) {
                        printf("*");
                }
                printf("\n");
        }
}

int main(int argc, char *argv[]) {
	if(argc < 3) {
		printf("./ex3 [n] [figure_type]\nfigure_type - triangle, right_triangle, transposed_triangle, square\n");
		return -1;
	}

        int n = atoi(argv[1]);
	if(argv[2] == "triangle") {
        	print_triangle(n);
	} else if(argv[2] == "right_triangle") {
		print_right_triangle(n);
	} else if(argv[2] == "transposed_triangle") {
                print_transposed_triangle(n);
        } else if(argv[2] == "square") {
                print_square(n);
        } else {
		print_triangle(n);
	}

        return 0;
}

