/*
    Daniela Vignau
    September 10, 2020

    Exercise 1: Complete
    Escriba un programa en C que reciba por teclado números y cada vez que
    recibe un número, se lo envíe a un proceso hijo a través de un pipe para
    que este calcule e imprima el factorial de ese número. Solo debe existir un
    hijo que calcula. 
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int fact(int);

int main(int argc, char * const * argv) {
    pid_t pid;
    int fd[2];
    pipe(fd);
    int num, total = 0;
    pid = fork();
    
    if(pid == -1) {
        printf("Error");
    } else if(pid == 0) {
        while(num != 0) {
            close(fd[1]);
            read(fd[0], &num, sizeof(int));
            total += num;
            printf("Recibí %d, el factorial es = %d\n", num, fact(num));
        }
    } else {
        while(num != 0) {
            printf("\nIngrese un numero: ");
            scanf("%d", &num);
            close(fd[0]);
            write(fd[1], &num, sizeof(int));
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