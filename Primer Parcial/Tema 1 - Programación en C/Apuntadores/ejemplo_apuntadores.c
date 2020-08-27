#include <stdio.h>

int main () {
    int a, b, c;
    int *p1, *p2;       /* Apuntadores a int */
    void *p;

    p1 = &a;                    /* p1 contiene la direción de a */
    *p1 = 1;                    /* a toma el valor de 1 */
    printf("\np1 = &a;\n*p1 = 1;\n\n");
    printf("a = %d\n", a);
    printf("*p1 = %d\n", *p1);  
    printf("&a = %d\n", &a);  
    printf("p1 = %d\n", p1);  
    printf("&p1 = %d\tdireccion de memoria\n\n\n\n", &p1);  /* accedemos a la dirección de memoria */
    
    p2 = &b;                    /* p2 contiene la dirección de b */
    *p2 = 2;                    /* b toma el valor de 2 */
    printf("p2 = &b;\n*p2 = 2;\n\n");
    printf("b = %d\n", b);
    printf("*p2 = %d\n", *p2);  
    printf("&p2 = %d\tdireccion de memoria\n\n\n\n", &p2);  /* Accedemos a la dirección de memoria */
    
    p1 = p2;                    /* p1 toma el mismo valor que p2; ahora vale 2. a y b mantienen sus valores originales */
    printf("p1 = p2;\n\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("*p1 = %d\n", *p1);
    printf("*p2 = %d\n", *p2);
    printf("&p1 = %d\tdireccion de memoria\n", &p1);
    printf("&p2 = %d\tdireccion de memoria\n\n\n\n", &p2);
    
    *p1 = 0;                    /* como p1 apunta ahora a b, se modifica el valor de b y el de *p2 */
    printf("*p1 = 0;\n\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("*p1 = %d\n", *p1);
    printf("*p2 = %d\n", *p2);
    printf("&p1 = %d\tdireccion de memoria\n", &p1);
    printf("&p2 = %d\tdireccion de memoria\n\n\n\n", &p2);
    
    p2 = &c;                    /* p2 contiene la dirección de c */
    printf("p2 = &c;\n\n");
    printf("c = %d\n", c);      /* c = 0, porque *p2 = 0 */
    printf("*p2 = %d\n", *p2);  /* apuntamos a la dirección de c, pero la dirección de p2 sigue siendo la misma */
    printf("&p2 = %d\tdireccion de memoria\n\n\n\n", &p2);  /* accedemos a la dirección de memoria */

    *p2 = 3;                    /* c toma el valor de 3 */
    printf("*p2 = 3;\n\n");
    printf("c = %d\n", c);
    printf("*p2 = %d\n", *p2);  
    printf("&p2 = %d\tdireccion de memoria\n\n\n\n", &p2);  /* accedemos a la dirección de memoria */    
    
    p = &p1;            /* ilegal, queremos cambiar la direccion de memoria */
    printf("p = &p1;\n\n");
    printf("&p = %d\n", &p);  
    printf("p = %d\tdireccion de memoria\n\n\n\n", p);  /* accedemos a la dirección de memoria */    
    
    // *p = p2;            /* p2 toma el valor de p */
    // printf("*p = p2;\n\n");
    // *p1 = 1;            /* a toma el valor de 1 */
    // printf("*p1 = 1;\n\n");
}

/*
    Prints:
    p1 = &a;
    *p1 = 1;

    a = 1
    *p1 = 1
    &a = 6422300
    p1 = 6422300
    &p1 = 6422288   direccion de memoria



    p2 = &b;
    *p2 = 2;

    b = 2
    *p2 = 2
    &p2 = 6422284   direccion de memoria



    p1 = p2;

    a = 1
    b = 2
    *p1 = 2
    *p2 = 2
    &p1 = 6422288   direccion de memoria
    &p2 = 6422284   direccion de memoria



    *p1 = 0;

    a = 1
    b = 0
    *p1 = 0
    *p2 = 0
    &p1 = 6422288   direccion de memoria
    &p2 = 6422284   direccion de memoria



    p2 = &c;

    c = 0
    *p2 = 0
    &p2 = 6422284   direccion de memoria



    *p2 = 3;

    c = 3
    *p2 = 3
    &p2 = 6422284   direccion de memoria



    p = &p1;

    &p = 6422280
    p = 6422288     direccion de memoria

*/