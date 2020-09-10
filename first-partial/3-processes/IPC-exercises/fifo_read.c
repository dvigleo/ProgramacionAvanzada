/*
    Daniela Vignau
    September 10, 2020

    Exercise 4: Unfinished
    Resuelva el problema 1 utilizando FIFO, donde los procesos no tengan relación de parentesco 
    Nota: Para lo anterior debe crear dos procesos diferentes: uno que escribe el número en el FIFO y otro que lo lee para calcular el factorial e imprimir el resultado
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char * const * argv) {
    int fd, r = 1;
    
    fd = open("/advanced-programming/Primer Parcial/Tema 3 - Procesos/Ejercicios de IPC/fifo", O_RDONLY);
    
    int fact = -1;
    
    while(r = read(fd, &fact, sizeof(int))) {
        printf("f = %d\n", fact);
    }
    close(fd);
}
