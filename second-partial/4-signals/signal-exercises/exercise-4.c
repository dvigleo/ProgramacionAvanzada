#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>


void gestor_ctrlc1(int);
void gestor_ctrlc2(int);

void contar(char *, void (* handler_t)(int));


int main(int argc, const char * argv[]) {
    
    // Obtener manejador anterior
    printf("Guardando manejador anterior\n");
    struct sigaction gestor;
    sigaction(SIGINT, NULL, &gestor);
    // El NULL es porque no se quiere modificar aún
    
    contar("ovejitas", gestor_ctrlc1);
    
    contar("trineos", gestor_ctrlc2);
    
    contar("cabritas", gestor_ctrlc1);   
    
    // Restaurar manejador inicial
    printf("Restaurando manejador inicial\n");
    sigaction(SIGINT, &gestor, NULL);
    
    return 0;
}

void contar(char * texto, void (* handler_t)(int)) {
    struct sigaction gestor;
    gestor.sa_handler = handler_t;
    sigaction(SIGINT, &gestor, NULL);
    int i = 1; 
    while (i <= 10) {
        printf("%d  %s...\n", i, texto);
        i++;
        sleep(1);
    }
}

void gestor_ctrlc1(int sid) {
    printf("  Estoy aprendiendo a manejar señales\n");
}

void gestor_ctrlc2(int sid) {
    printf("  Ahora cambié de manejador...\n");
}