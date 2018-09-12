#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>

#define TRUE 1
#define MAX_LENGTH 1024
#define MAX_COUNT_OF_ARGUMENT 16
#define ARGUMENT_SIZE 5
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define SPLIT_CHRS " \t\n\a\0"

int loop_in_shell();

char **split_line(const char *inp);

int execute(char **arguments);

char *get_line() {
    char *inp = malloc(sizeof(char) * MAX_LENGTH);
    if (!inp) {
        fprintf(stderr, "Not enough memory\n");
        exit(EXIT_FAILURE);
    }
    fgets(inp, MAX_LENGTH, stdin);
}

int search_for_char(const char *string, char chr) {
    int iterator = 0;
    while (string[iterator] != chr && string[iterator] != '\0') iterator++;
    return string[iterator] != chr;
}

int main() {
    loop_in_shell();
}

char **split_line(const char *inp) {
    char **outp = malloc(sizeof(char *) * MAX_COUNT_OF_ARGUMENT);

    if (!outp) {
        fprintf(stderr, "Not enough memory\n");
        exit(EXIT_FAILURE);
    }
    int position = 0, args_pos = 0, chr_pos = 0, args_size = ARGUMENT_SIZE, args_count = MAX_COUNT_OF_ARGUMENT;
    while (inp[position] != '\0') {
        args_size = ARGUMENT_SIZE;
        outp[args_pos] = malloc(sizeof(char) * ARGUMENT_SIZE);
        while (search_for_char(SPLIT_CHRS, inp[position])) {
            outp[args_pos][chr_pos] = inp[position];
            chr_pos++;
            if (chr_pos >= args_size) {
                args_size += ARGUMENT_SIZE;
                outp[args_pos] = realloc(outp[args_pos], sizeof(char) * args_size);
                if (!outp[args_pos]) {
                    fprintf(stderr, "Not enough memory\n");
                    exit(EXIT_FAILURE);
                }
            }
            position++;
        }
        outp[args_pos][chr_pos] = '\0';
        chr_pos = 0;

        position++;
        args_pos++;

        if (args_pos >= args_size) {
            args_count += MAX_COUNT_OF_ARGUMENT;
            outp = realloc(outp, sizeof(char *) * args_count);
            if (!outp) {
                fprintf(stderr, "Not enough memory\n");
                exit(EXIT_FAILURE);
            }
        }

    }
    outp[args_pos] = NULL;
    return outp;
}

int execute(char **arguments) {
    int condition_of_state;
    int is_back = 0;
    int pid;

    for (int i = 0; arguments[i] != NULL; i++)
    if (arguments[i - 1][0] == '&') {
        is_back = 1;
        arguments[i - 1] = NULL;
    }
    if (strcmp(arguments[0], "exit") == 0) exit(EXIT_SUCCESS);
    pid = fork();
    if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            fprintf(stderr, "Execution error\n");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) fprintf(stderr, "Error while forking\n");
    else {
        if (is_back) fprintf(stdout, "Jobs %s is running in background\n", arguments[0]);
        else do waitpid(pid, &condition_of_state, WUNTRACED);
        while (!WIFEXITED(condition_of_state) && !WIFSIGNALED(condition_of_state));
    }
    return 1;
}

int loop_in_shell() {
    char *input;
    char **arguments;
    while (TRUE) {
        printf("-> ");

        input = get_line();
        arguments = split_line(input);
        execute(arguments);

        free(input);
        free(arguments);
    }
}
