#include <stdio.h>
#include <stdlib.h>
int main() {
 int pid = fork(), n = 337;
 if (pid > 0) printf("Hello from parent [%d - %d]\n", pid, n); 
 else if (pid == 0) printf("Hello from child [%d - %d]\n", pid, n);
 else return 1;

 return 0;
}
