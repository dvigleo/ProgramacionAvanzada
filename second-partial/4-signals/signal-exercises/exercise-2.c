#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// Modificar el programa anterior para que al pulsar CTRL+Z tanto el padre como el hijo
// no se detengan sino que den un mensaje advirtiendo de que dichos procesos no pueden
// ser detenidos. 

void gestor(int senial) {
    printf("Oprimiste Ctrl + Z y no hago nada\n\tPID = %d\n", getpid());
}

int main(int argc, const char * argv[]) {
    pid_t pid;
    signal(SIGTSTP, gestor); 
    pid = fork();
    switch(pid) {
        case 0:
            printf("Soy el hijo PID = %d, mi padre es PID = %d y dormiré 2 segundos\n", getpid(), getppid());
            signal(SIGINT, SIG_IGN);
            sleep(2);
            printf("Ahora contaré hasta 10\n");
            int n = 1;
            while(n <= 10) {
                printf("%d\n", n);
                sleep(1);
                n++;
            }
            printf("Soy el hijo y ya voy a terminar\n");
            exit(0);
        default:
            printf("Soy el padre PID = %d, si pulsas CTRL + C solo moriré yo pero mi hijo continará\n", getpid());
            sleep(10);
            printf("Soy el padre y acabo de despertar. Esperaré a que termine mi hijo con PID = %d\n", pid);
            wait(NULL);
            printf("Soy el padre y ya me voy\n.");
    }
    
    return 0;
}
