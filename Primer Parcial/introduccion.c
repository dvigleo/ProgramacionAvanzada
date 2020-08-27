/*
 * Librería que maneja todo lo de entrada y salida.
 * El # señala una directiva para el preprocesador
 */

#include <stdio.h> 

/*
 * Función principal que inicia la ejecución del programa. Puede o no
 * recibir parámetros
 */
int main() {
    // No existen valores booleanos ni String. El String es una cadena de caracteres
    int entero1;
    int entero2;
    int suma;

    /*
     * scanf
     *      - Se especifica la dirección de la variable
     *      - El & significa la dirección de memoria mas no su contenido
     */ 
    printf("Introduzca el primer entero\n");
    scanf("%d", &entero1); 

    printf("Introduzca el segundo entero\n");
    scanf("%d", &entero2);

    suma = entero1 + entero2;

    printf("La suma es %d\n", suma);

    return 0;
}