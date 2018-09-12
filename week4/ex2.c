#include <stdio.h>
#include <stdlib.h>

int main() {
    for (int j = 0; j < 3; j++) {
        fork();
        sleep(5);
    }
    return 0;
}
