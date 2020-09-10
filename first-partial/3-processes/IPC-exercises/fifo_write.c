/*
    Daniela Vignau
    September 10, 2020

    Exercise 4: Unfinished
    Resuelva el problema 1 utilizando FIFO, donde los procesos no tengan
    relación de parentesco. 

    Nota: Para lo anterior debe crear dos procesos diferentes: uno que escribe
    el número en el FIFO y otro que lo lee para calcular el factorial e
    imprimir el resultado. 
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int fact(int);

int main(int argc, char * const * argv) {
    int err = mkfifo("/advanced-programming/Primer Parcial/Tema 3 - Procesos/Ejercicios de IPC/fifo", 0777);
    
    if(err) {
        printf("Error\n")
        exit(-1);
    }
    
    fd = open("/advanced-programming/Primer Parcial/Tema 3 - Procesos/Ejercicios de IPC/fifo", O_WRONLY);
    
    int i = 0;
    
    while (i++ < 10) {
        write(fd, &i, sizeof(int));
    }
    
    close(fd);
    unlink("/advanced-programming/Primer Parcial/Tema 3 - Procesos/Ejercicios de IPC/fifo");
    
}

int fact(int num) {
    int i;
    int f = 1;
    
    for(i = 2; i <= num; ++i)
        f *= i;
        
    return f;
}