#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>              
#include <unistd.h>
#include <sys/wait.h>

void usage(const char *prog) {
    fprintf(stderr, "Usage : %s <integer> [> 2]\n", prog);
    exit(1);
}

int main(int argc, const char * argv[]) {
    if(argc != 2) {
        usage(argv[0]);
    }

    int number_process = atoi(argv[1]);
    if(number_process < 2) {
        usage(argv[0]);
    }

    printf("Création de %d processus pour une élection : \n", number_process);
    // Flush stdout before fork.
    fflush(stdout);

    // Do not cast the result of malloc
    // Use sizeof(*pipes) instead of sizeof(int)
    // Prefer descriptive variable names
    int *pipes = malloc((2 * number_process) * sizeof(*pipes));
    if (!pipes) {
        perror("malloc");
        exit(1);
    }

    // Scope loop variables in the loop
    for (int i = 0; i < number_process; i++) {
        int r = pipe(&pipes[2*i]);
        if (r == -1) {
            perror("pipe");
            exit(1);
        }
    }

    for (int i = 0; i < number_process; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(1);
        }
        if (pid == 0) {
            // Let's avoid copy/pasting 2*i and (2*i+3)%(number_process*2)
            // everywhere, which is hard to read
            int infd = pipes[2*i];
            int outfd = pipes[(2*i+3)%(number_process*2)];
            for (int j = 0; j < number_process*2; j++) {
                if (pipes[j] != infd && pipes[j] != outfd) {
                    close(pipes[j]);
                }
            }

            int self = getpid();
            ssize_t amt;
            amt = write(outfd, &self, sizeof(int));
            if (amt == -1) {
                perror("write");
                exit(1);
            }

            int in;
            ssize_t r = read(pipes[i*2], &in, sizeof(int));
            if (r == -1) {
                perror("read");
                exit(1);
            }
            printf("%d : %d\n", in, (int)getpid()); 

            exit(0);
        }
    }
    // Close pipes and wait for children to finish
    for (int i = 0; i < number_process * 2; i++) {
        close(pipes[i]);
    }
    for (int i = 0; i < number_process; i++) {
        wait(NULL);
    }

    // Return at end of main() is implicitly "return 0".
}