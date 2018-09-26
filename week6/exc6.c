#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>

#define TRUE 1

int main(void) {
    pid_t child_pid_1, child_pid_2 = 0;
    int pipe_d[2];
    pipe(pipe_d);
    child_pid_1 = fork();
    if (child_pid_1) {
        // parent turn
        child_pid_2 = fork();
        if (child_pid_2) {
            printf("parent -(pid %d)> of second child to the first child\n", child_pid_2);
            write(pipe_d[1], &child_pid_2, sizeof(child_pid_2));

            int status;
            printf("parent has started waiting for second child\n");
            waitpid(child_pid_2, &status, WUNTRACED);
            printf("parent has received status %d from its second child\n", status);
            if (WIFSTOPPED(status)) {
                printf("parent has discovered that its child was stopped\n");
            } else if (WIFEXITED(status)) {
                printf("parent has discovered that his child stopped normally\n");
            }
            if (WIFSIGNALED(status)) {
                printf("parent has discovered that his child was stoppped by signal %d!\n", WTERMSIG(status));
            }
        } else {
            while (TRUE) {};
        }
    } else {
        // first child turn
        read(pipe_d[0], &child_pid_2, sizeof(child_pid_2));
        printf("the first child received pid %d of the second child\n", child_pid_2);

        sleep(2);
        printf("the first child stops his brother\n");
        kill(child_pid_2, SIGSTOP);
        exit(0);
    }
}
