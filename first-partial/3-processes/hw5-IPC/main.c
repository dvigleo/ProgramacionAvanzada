/*
    Alumno: Daniela Vignau León
    Fecha: 17 de septiembre de 2020
    Materia: Programación Avanzada
    Profesor: Vicente Cubells
    Tarea 5
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void print_help();

int main(int argc, char * const * argv) {
    char * input = NULL;
    int argument, start = 0, index;
    int n = 0;
    
    while((argument = getopt (argc, argv, "n:h")) != -1)
    
    switch(argument) {
        case 'n':
            input = optarg;
            if(isdigit(*input)) {
                n = atoi(input);
                start = 1;
            } else {
                fprintf(stderr, "-----------------------\nOpción -%s require un número entero como argumento\n", optarg);
            }
            break;
        case 'h':
            print_help();
            break;
        case '?':
            if(optopt == 'n')
                fprintf(stderr, "-----------------------\nOpción -%c require un número entero como argumento\n", optopt);
            else if(isprint (optopt))
                fprintf(stderr, "-----------------------\nOpción desconocida '-%c\n", optopt);
            return 1;
        default:
            abort();
    }
    
    for (index = optind; index < argc; index++) {
        printf ("-----------------------\nEl argumento %s no es una opción válida", argv[index]);
        print_help();
        exit(-1);
    }
        
    if (argc != 3) {
        printf("-----------------------\nError");
        print_help();
        exit(-1);
    }
    
    if(start == 1) {
        pid_t pid;
        int i = 0;
        char m = 'T';
        char t;
        int n_children = 0;
        
        // Create a 2D array of pipes and initiliaze them    
        int * pipes = (int *) malloc(sizeof(*pipes) * (2 * n));
        int * aux = pipes;
        int * end = pipes + n;
        
        for(; i < n; ++i) {
            pipe(&pipes[2 * i]);
        }
        printf("\nSucess! %d pipes have been created\n", n);
    
        // Write the message to the final pipe so the parent can read it and then send it
        int err_write = write(end[1], &m, sizeof(char)); 
        if(err_write == -1){
            printf("Error");
        } else {
            printf("I have written the first message: '%c'\n", m);
        }
        
        printf("\nParent ID = %d\n", getpid());
        
        int start_round = 1;
        i = 0;
        while(i < (n - 1)) {
            pid = fork();
            switch(pid) {
                case -1: 
                    printf("Error. %d procesos hijos creados\n", i + 1);
                    exit(-1);
                case 0: // Child
                    while(1) {
                        close(aux[1]); // Close writing end
                        read(aux[0], &t, sizeof(char));
                        printf("--> I am PID = %d, and have read the message %c. I'll keep it with me for 5 seconds.\n", getpid(), t);
                        sleep(3);
                        
                        // Send the message
                        aux++;
                        close(aux[0]); // Close reading end
                        write(aux[1], &t, sizeof(char));
                        printf("<-- I am PID = %d, and I have sent the message\n\n", getpid());
                        n_children++;
                        // exit(0);
                        printf("\n\nChildren %d\n\n", n_children);
                        if(n_children == (n - 1)) {
                            start_round = 1;
                            n_children = 0;
                            exit(0);
                        }
                    }
                    
                default: // Parent
                    // while(1){
                    
                        if(start_round == 1 ) {
                            aux = end; // This is necessary, otherwise the parent would not be able to read the first message
                            start_round = 0;
                            // Read and receive the message
                            close(aux[1]); // Close writing end from last child
                            read(aux[0], &t, sizeof(char));
                            printf("Parent --> I am PID = %d, and have read the message %c. I'll keep it with me for 5 seconds.\n", getpid(), t);
                            sleep(3);
                                
                            // Send the message
                            aux = pipes; // Restart pointer
                            close(aux[0]); // Close reading end
                            write(aux[1], &t, sizeof(char));
                            printf("<-- I am PID = %d, and I have sent the message\n\n", getpid());
                            wait(NULL);                        
                        } else {
                            wait(NULL);
                        }
                    // }
            
                    
            }
            i++;
        }
        
        printf("\n\nI have created %d children and 1 parent\n", i);
        free(pipes);
        // EOP
    }
    
    return 0;
}

void print_help() {
    printf("\nUse: ./a.out [-n value] [-h]\n");
    printf("Opciones:\n");
    printf("\t-n: Crear n procesos indicados como valor entero\n\t h: Ayuda\n");
}
