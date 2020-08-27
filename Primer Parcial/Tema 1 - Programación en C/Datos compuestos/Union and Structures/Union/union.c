#include <stdio.h>
#include <string.h>

// UNIONES
union libro {
    int paginas;
    char titulo[25];
    char autor[35];
} libro;

int main() {
    libro.paginas = 450;
    strcpy(libro.titulo, "Pillars of the Earth");
    printf("\nLibro 3\nTitulo: %s", libro.titulo);
    strcpy(libro.autor, "Ken Follet");
    printf("\nAutor: %s", libro.autor);

    printf("\nSe sobreescribre el AUTOR en TITULO: %s", libro.titulo);

    return 0;
}