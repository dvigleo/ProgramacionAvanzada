
/*
    Daniela Vignau
    September 10, 2020

    Exercise 2: Complete
    Escriba un programa en C que genere dos procesos. El primer proceso lee números enteros del teclado y los envía a un pipe para que los lea el otro proceso. El segundo proceso recibirá los números del pipe sumándolos. Cuando se entre el número 0, el proceso hijo debe mostrar el resultado de la suma y ambos procesos deben terminar. 
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char * const * argv) {
    pid_t pid;
    int fd[2];
    pipe(fd);
    int num, total = 0;
    pid = fork();
    if(pid == -1) {
        printf("Error");
    } else if(pid == 0) {
        // Hijo
        while(num != 0) {  // Ciclo infinito para que lea repetidas veces
            close(fd[1]);   // Cerrar la parte de escritura
            read(fd[0], &num, sizeof(int)); // Leer
            total += num; // Creo la suma
            printf("Recibí %d, la suma es = %d\n", num, total); // imprimo
        }
    } else {
        // Padre
        while(num != 0) {
            printf("\nIngrese un numero: ");
            scanf("%d", &num);
            close(fd[0]); // Cerrar la parte de lectura
            write(fd[1], &num, sizeof(int)); // Escribir 
        }
    }
}