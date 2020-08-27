#include <stdio.h>
#include <string.h>

// ESTRUCTURAS
struct libro {
    int paginas;
    char titulo[25];
    char autor[35];
} libro1;

struct autor {
    char nombre[25];
    char apellido[25];
};

// Estructuras anidadas
struct libro2 {
    int paginas;
    char titulo[25];
    struct autor escritor;
} libro2;





int main() {
    libro1.paginas = 350;
    strcpy(libro1.titulo, "Progra avanzada");
    strcpy(libro1.autor, "Deitel");

    printf("\nLibro 1\nPaginas: %d\nTitulo: %s\nAutor: %s\n", libro1.paginas, libro1.titulo, libro1.autor);

    libro2.paginas = 350;
    strcpy(libro2.titulo, "Progra avanzada");
    strcpy(libro2.escritor.nombre, "Deitel");
    strcpy(libro2.escritor.apellido, "Bjorn");
    
    printf("\nLibro 2\nPaginas: %d\nTitulo: %s\nAutor: %s %s\n", libro2.paginas, libro2.titulo, libro2.escritor.nombre, libro2.escritor.apellido);

    return 0;
}