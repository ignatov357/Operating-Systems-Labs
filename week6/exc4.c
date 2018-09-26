#include <stdio.h>
#include <unistd.h>
#include <signal.h>

#define TRUE 1

void handler(int sig) {
    printf("Sig number:%d\n", sig);
}

int main() {
    signal(SIGKILL, handler);
    signal(SIGSTOP, handler);
    signal(SIGUSR1, handler);
    while (TRUE) {}
}
