#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define N 20 // We are not saving memory, it's simply telling the compiler to substitute the letter N for 20 everytime he finds it in the code
int val; // Static memory, its a global variable

/*
    Operador de dirección &     -> Regresa una dirección de memoria
    Operador de indireccion *   -> Obtiene el CONTENIDO de una dirección de memoria, o para definir un apuntador a una dirección de memoria

    Ejemplo:

    int n = 0;
    int *ptr_n = &n     // tienen la misma direccion de memoria
    n = 50              // ahora n = 50
    *ptr_n = 90         // ahora n = 90

    int ptr_n = &n         // int = int * !! Diferentes tupis de datos porque la direccion de memoria no es un int 
        int ptr_n = *(&n) // int = int !! se crea un nuevo espacio de memoria par ptr_n
        int *ptr_n = &n     // int * = int *

            dirección   variable
            #FFFF

  ptrn_n -> #FF00       n - 0

            #00FF

            #0000       ptr_n - #FF00
*/

void imprime(int *, int *);

int main(int argc, const char * argv[]) {
    int n = 0; // Automatic memory

    /* Read the number of elemnents*/
    printf("Enter the value of n: ");
    scanf("%d", &n);

}