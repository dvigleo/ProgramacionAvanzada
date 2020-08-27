#include <stdio.h>
#include <string.h>

typedef struct {
    char name[30];      // 30 + 30 + 4 = 60 bytes reservados
    char lastname[30];
    int age;
} persona;

// persona e;

// typedef persona {
//     char name[30];
//     char lastname[30];
//     int age;
// } persona;

// struct persona e;

typedef union {
    char name[30];
    char lastname[30];
    int age;    
} persona_u;

int main() {
    persona e;
    persona_u u;

    strcpy(e.name, "Daniela");
    strcpy(e.lastname, "Vignau");
    e.age = 22;

    printf("Struct values\n");
    printf("%s %s %d", e.name, e.lastname, e.age);

    strcpy(u.name, "Daniela");
    strcpy(u.lastname, "Vignau");
    u.age = 89;

    printf("\n\nUnion values\n");
    printf("%s %s %d", u.name, u.lastname, u.age);
    // Imprime la cadena de cararecter que corresponde al código ASCII del caracter 89, es decir, la letra Y

    // Si la ultima asignación es un String... ni el profe sabe bien por qué impprime un número (parece que fuera una dirección de memoria :P)
    return 0;
}

/*
    Prints:
    Struct values
    Daniela Vignau 22

    Union values
    Y Y 89
*/