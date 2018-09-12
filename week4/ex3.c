#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define MAX_LENGTH 10

int main() {
    char cmd[MAX_LENGTH];
    while (TRUE) {
        printf("-> ");
        scanf("%s", cmd);
        system(cmd);
    }
}
