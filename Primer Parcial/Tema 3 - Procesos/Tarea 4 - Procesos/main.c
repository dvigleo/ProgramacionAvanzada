#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/wait.h>
#include <string.h>

#define H 15

typedef struct {
    int pid;
    int average;
    char * histogram;
} proc_t;

int get_average(int, int);

void create_histogram(proc_t *, int);
void print_table(proc_t *, int);

void print_help();
void free_memory(proc_t *, int);

int max = 0;

int main(int argc, char * const * argv) {
    /* Obtaining the number of processes from the command line */
    char * input = NULL;
    int argument, start = 0, help, index; // variables for short arguments
    int n = 0; // number of processes to create
    while((argument = getopt (argc, argv, "n:h")) != -1)
    
    switch(argument) {
        case 'n':
            input = optarg;
            if(isdigit(*input)) {
                n = atoi(input);
                start = 1;
            } else {
                fprintf(stderr, "Opción -%s require un número entero como argumento\n", optarg);
            }
            break;
        case 'h':
            help = 1;
            break;
        case '?':
            if(optopt == 'n')
                fprintf(stderr, "Opción -%c require un número entero como argumento\n", optopt);
            else if(isprint (optopt))
                fprintf(stderr, "Opción desconocida '-%c\n", optopt);
            else
                fprintf(stderr, "Opción desconocida '\\x%x'\n", optopt);
            return 1;
        default:
            abort();
    }
    
    for (index = optind; index < argc; index++)
        printf ("El argumento %s no es una opción válida \n", argv[index]);
    
    if(help == 1) {
        print_help();
    }
    
    if(start == 1) {
        int state;
        pid_t pid;
        proc_t * list = (proc_t *) malloc(sizeof(proc_t) * n);
        int i = 0;
        while(i < n) {
            pid = fork();
            
            if(pid == -1) {
                printf("Error. %d procesos hijos creados\n", i);
            } else if(pid == 0) { 
                int average = get_average(getppid(), getpid());
                printf("Soy el proceso hijo con PID = %d, mi promedio es = %d\n", getpid(), average);
                exit(average);
            } else {
                if (waitpid(pid, &state, 0) != -1) {
                    if (WIFEXITED(state)) {
                        proc_t * proc = list + i;
                        proc->pid = pid;
                        proc->average = WEXITSTATUS(state);
                        
                        if(WEXITSTATUS(state) > max) 
                            max = WEXITSTATUS(state);
                        
                    }
                }
            }
            i++;
        }
        create_histogram(list, n);
        print_table(list, n);
        free_memory(list, n);
    } 
    return 0;
}

int get_average(int ppid, int pid) {
    return (ppid + pid) / 2;
}

void create_histogram(proc_t * list, int n) {
    proc_t * aux = list;
    proc_t * final = list + n;
    int n_chars = 0;
    char * c;
    for(; aux < final; ++aux) {
        n_chars = (aux->average * H) / max;
        aux->histogram = (char *) malloc(sizeof(char) * n_chars);
        strcpy(aux->histogram, "*");
        c = aux->histogram + 1;
        for(; c < aux->histogram + n_chars; ++c) {
            strcpy(c, "*");
        }
    }
}

void print_table(proc_t * list, int n) {
    proc_t * aux = list;
    proc_t * final = list + n;
    printf("\nPID Hijo\tPromedio\tHistograma\n");
    for(; aux < final; ++aux) {
        printf("%d\t\t %d\t\t%s\n", aux->pid, aux->average, aux->histogram);
    }
}

void print_help() {
    printf("\nUse: ./a.out [-n value] [-h]\n");
    printf("Opciones:\n");
    printf("\t-n : Crear n procesos indicados como valor entero\n\th : Ayuda\n");
}

void free_memory(proc_t * list, int n) {
    proc_t * aux = list;
    proc_t * final = list + n;
    for(; aux < final; ++aux) {
        aux->pid = 0;
        aux->average = 0;
        free(aux->histogram);
    }    
    free(list);
    printf("Memory freed correctly\n");
}