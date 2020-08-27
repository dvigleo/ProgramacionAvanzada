/* 
    Programa que permita entrar a un listado de personas (de cada persona se conoce su nombre, apellidos y edad) y permita:
        - Determinar la edad promedio
        - La persona más joven
        - La persona más vieja
        - Todas las personas que se encuentran en un rango de edad
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    int age;
    char name[20];
    char lastname[20];
} person ;

enum list {
    struct person p,
    p.age = 10,
    strcpy(p.name, "a"),
    strcpy(p.lastname, "b")
};


int main() {
    int n = 1;

    for(int person = 1; person <= n; person++){
        enum list person;
        printf("%d", person);
    }

    struct person p1;
    p1.age = 22;
    strcpy(p1.name, "Daniela");
    strcpy(p1.lastname, "Vignau");

    printf("\nName: %s\nLastname: %s\nAge: %d\n", p1.name, p1.lastname, p1.age);
    return 0;
}