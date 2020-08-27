/*
    Daniela Vignau
    A01021698

    Ejercicio  1:
        Invertir cadena de caracteres
    Ejercicio 2: 
        Obtener la longitd de una cadena
    Ejercicio 3: 
        Copiar cadena de caracteres a otra
    Ejercicio 4:
        Crear una matriz dinámica de N x M, que le pida al usuario los valores de cada posición e imprima los valores guardados en formato matricial

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int string_length(char *);
void inverse_string(char *, int);
void copy_string(char *, char *, int);
long int string_length_ptr(char *);
char * my_strcpy(char *);

int main(int argc, const char * argv[]) {
    char str[20];    
    char copy[20];
    int length = 0; 
    strcpy(str, "Daniela");
    
    printf("\nOriginal string: \t%s\n", str);
    
    length = string_length(str);
    inverse_string(str, length);
    printf("Reverse string: \t%s\nLength of string: \t%d\n", str, length);
    
    inverse_string(str, length);
    copy_string(str, copy, length);
    printf("Copied string:\t\t%s\n\n", copy);

    /************************************************************************/
    // Otra forma de hacer una cadena de characteres, puede tener de 0 a n dependiendo del tamaño de la memoria que nos defina
    char * string; 
    int longitud;
    // char * string[20] <==> char * string = (char *) malloc(sizeof(char) * 20);
    // Automatic memory vs dynamic memory

    printf("\n\n\nType in the max length of the string: ");
    scanf("%d", &longitud);

    /* Setting the size of the string
        - calloc: For matrices, you tell it how many spaces with certain size_t
        - malloc: I have to say exactly how big it is 
            Use sizeof to know how much memory the variables saved in it use;
            Consecutive memory space and returns a pointer to that memory 
            Returns a void *, so we need casting to make it work for characters
    */
    string = (char *) malloc(sizeof(char) * longitud);
    printf("Type in a word: ");
    scanf(" %[^\n]", string); // RegEx -> To read sentences (allows spaces) read until there is a new line (\n). The space at the start, is to avoid the scanf to read endlessly 
    // scanf("%s", string) Reads untils it finds a space \0

    
    printf("\nOriginal string: \t%s\n", string);
    printf("Length of string: \t%d\n", string_length_ptr(string));
    char * destino = my_strcpy(string);
    printf("Copied string: \t\t%s\n", destino);
    
    free(string);
    free(destino);
    return 0;
}

// Todas las funciones están modificando el variable str por referencia, por lo que al salirnos de la función, perdemos la referencia. 

void inverse_string(char * str, int length) {
    char * s_ptr, * e_ptr, current;
    s_ptr = str;
    e_ptr = s_ptr + (length - 1); // Pointer is set at the end of the string

    for(int i = 0; i < length / 2; ++i) {
        current = *e_ptr;
        *e_ptr = *s_ptr;
        *s_ptr = current;
        
        s_ptr ++;
        e_ptr --;
    }
}


int string_length(char * str) {
   int length = 0;
    
    // Del inicio súmame tantos caracteres hasta llegar al final
    while(*(str + length) != '\0')
        length++;
 
    return length;
}

long int string_length_ptr(char * str) {
    char * p = str;
    while(*p++ != '\0') {} 
    /* 
        p: I am merely moving the pointer to the end of the string \0
        str: Is poiting at the start of the string
        -1: is needed to not count the null \0
    */
    return (p - str - 1);
}

void copy_string(char * original, char * copy, int length) {
    char * p = original;
    for(int i = 0; i < length; ++i) {
        *copy = *p;
        p++;
        copy++;
    }
    *copy = '\0';
}
 
char * my_strcpy(char * str) {
    long int size = strlen(str);
    char * destino = (char *) malloc(sizeof(char) * size);

    char * p = str;
    char * d = destino;

    while( (*d++ = *p++) != '\0') {};
    return destino;
}