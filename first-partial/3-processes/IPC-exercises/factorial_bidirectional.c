/*
    Daniela Vignau
    September 10, 2020

    Exercise 3: Complete
    Modifique el ejercicio 1 para que el hijo no imprima el factorial, sino que
    en su lugar, utilizando otro pipe, se lo comunique al padre y sea este
    quien imprima los resultados.

    Nota: Recuerde que para la comunicación bidireccional debe utilizar dos
    pipes.

*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int fact(int);

int main(int argc, char * const * argv) {
    pid_t pid;
    int fd1[2];
    pipe(fd1);
    
    int fd2[2];
    pipe(fd2);
    
    int num = 1;
    int f;
    pid = fork();
    if(pid == -1) {
        printf("Error");
    } else if(pid == 0) {
        while(num != 0) {
            close(fd1[1]); // Close writing end from pipe 1
            close(fd2[0]); // Close reading end from pipe 2
            read(fd1[0], &num, sizeof(int)); // Read from pipe 1
            f = fact(num);
            write(fd2[1], &f, sizeof(int));  // Write into pipe 2
        }
    } else {
        while(num != 0) {
            printf("\nIngrese un numero: ");
            scanf("%d", &num);
            close(fd1[0]);  // Close reading end from pipe 1
            close(fd2[1]);  // Close writing end from pipe 2
            write(fd1[1], &num, sizeof(int)); // Write into pipe 1
            read(fd2[0], &f, sizeof(int)); // Read ffrom pipe 2
            printf("f(%d) = %d\n", num, f);
        }
    }    
    
}

int fact(int num) {
    int i;
    int f = 1;
    
    for(i = 2; i <= num; ++i)
        f *= i;
        
    return f;
}