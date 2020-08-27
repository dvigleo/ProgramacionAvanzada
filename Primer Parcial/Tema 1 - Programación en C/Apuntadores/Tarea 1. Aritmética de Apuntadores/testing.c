#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char * name;
    int age;
} patient;

int main(int argc, char const *argv[]) {
    patient * hospital = (patient *) malloc(sizeof(patient) * 1);
    patient * p = hospital;
    patient * final = hospital + 1;

    // FIRST PATIENT
    p->name = (char *) malloc(sizeof(char) * 30);
    printf("\nName (s): ");
    scanf(" %[^\n]", p->name);

    printf("Age: ");
    scanf("%d", &p->age);

    printf("Name: \t\t%s \nAge: \t\t%d", p->name, p->age);

    // ADD A NEW PATIENT
    int new_patient = 1;

    hospital = (patient *) realloc(hospital, sizeof(patient) * (1 + new_patient));
    final = hospital + 1 + new_patient;

    p->name = (char *) malloc(sizeof(char) * 30);
    printf("\nName (s): ");
    scanf(" %[^\n]", p->name);

    printf("Age: ");
    scanf("%d", &p->age);

    printf("Name: \t\t%s \nAge: \t\t%d\n", p->name, p->age);

    for(p = hospital; p < final; ++p) {
        printf("%s\7%d\n", p->name, p->age);
    }

    for(p = hospital; p < final; ++p) {
        free(p->name);
        free(&p->age);
    }
    free(final);
    free(hospital);

    return 0;
}
