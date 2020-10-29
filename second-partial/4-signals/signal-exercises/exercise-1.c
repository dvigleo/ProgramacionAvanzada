#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// Crear un proceso hijo, el cual ignorará la pulsación CTRL+C y a continuación:
// • Se pondrá a dormir 2 segundos, dará un mensaje indicando su PID y el de su padre, y
// contará desde 10 hasta 1, a intervalos de 1 segundo.
// • Antes de terminar, dará un mensaje similar al antes mencionado.
// • Por su parte, el padre indicará su PID y advertirá que si se pulsa CTRL+C sólo morirá
// el padre. A continuación se pondrá a dormir 10 segundos, y finalmente, esperará a que
// el hijo termine, si es que no ha terminado aún.
// • Tanto el padre como el hijo ignorarán la pulsación de CTRL+Z. 


int main(int argc, const char * argv[]) {
    pid_t pid;
    signal(SIGTSTP, SIG_IGN); // Aquí tanto el padre como el hijo ignorarán Ctrl+Z
    pid = fork();
    switch(pid) {
        case 0:
            signal(SIGINT, SIG_IGN); // Aquí solo el hijo es el que está ignorando Ctrl+C
            printf("Soy el hijo PID = %d, mi padre es PID = %d y dormiré 2 segundos\n", getpid(), getppid());
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
            printf("Soy el padre PID = %d, si pulsas CTRL + C solo moriré yo pero mi hijo continuará\n", getpid());
            sleep(10);
            printf("Soy el padre y acabo de despertar. Esperaré a que termine mi hijo con PID = %d\n", pid);
            wait(NULL);
            printf("Soy el padre y ya me voy\n.");
    }
    
    return 0;
}
