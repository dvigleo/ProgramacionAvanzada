typedef struct {
    char * name;
    char * lastnames;
    int age;
    char * phone_number;
    int id;
} patient;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

void admit_patient(patient *, patient*, int *);
void discharge_patient(patient *, patient *, int *, int *);
void list_patients(patient *, patient *);
void initialize_patients(patient *, patient *, int *);

int main(int argc, char const *argv[]) {
    patient * hospital;
    patient * p;
    int n_patients;
    int * pat_ptr = &n_patients;
    *pat_ptr = 2;

    int last_patient;
    int * last_ptr = &last_patient;
    last_patient = 0;

    // Bed ID
    int bed_id;
    int * bid_ptr = &bed_id;
    *bid_ptr = 0;

    int total_beds;
    int *t_beds = &total_beds;
    *t_beds = N;

    int available_beds;
    int *a_beds = &available_beds;
    *a_beds = N;

    int used_beds;
    int *u_beds = &used_beds;
    *u_beds = 0;


    hospital = (patient *) malloc(sizeof(patient));
    patient * total_patients = hospital + n_patients;

    int option = 0;
    while(option != 4) {
        printf("\n\n*************** HOSPITAL MANAGEMENT SYSTEM ***************\n\n");
        printf("1 - Admit patient\n2 - Discharge\n3 - List"); 
        printf("\nSelect an option (1-3): ");
        scanf("%d", &option);   

        switch (option) {
        case 1:
            admit_patient(hospital, total_patients, pat_ptr);
            break;
        case 2: 
            discharge_patient(hospital, total_patients, u_beds, a_beds);
            break;
        case 3: 
            list_patients(hospital, total_patients);  
            break;
        }
    }
    return 0;
}

void initialize_patients(patient * hospital, patient * total_patients, int * n_patients) {
    patient * p;
    for(p = hospital + *n_patients - 1; p < total_patients; ++p) {
        p->name = NULL;
        p->id = 0;
    }
    printf("\n\nPatients initialized\n\n");
}

void admit_patient(patient * hospital, patient * total_patients, int * n_patients) {
    printf("\n\n*************** ADMIT PATIENT ***************\n\n");
    printf("Please enter the data below\n");
    *n_patients += 1;
    
    hospital = (patient *) realloc(hospital, sizeof(patient) * (*n_patients));
    total_patients = hospital + *n_patients;
    patient * p;
    initialize_patients(hospital, total_patients, n_patients);
    for(p = hospital + *n_patients - 1; p < total_patients; ++p) {
        if(p->name == NULL && p->id == 0) {
            p->name = (char *) malloc(sizeof(char) * 30);
            printf("\nName (s): ");
            scanf(" %[^\n]", p->name);

            p->lastnames = (char *) malloc(sizeof(char) * 30);
            printf("Lastnames: ");
            scanf(" %[^\n]", p->lastnames);

            printf("Age: ");
            scanf("%d", &p->age);

            p->phone_number = (char *) malloc(sizeof(char) * 30);
            printf("Phone number: ");
            scanf("%s", p->phone_number);
            break;
        }
    }
    printf("\n\n*************** PATIENT SAVED ***************\n\n");
    printf("Name: %s %s\n   Age: %d\n   Phone number: %s\n   Bed ID: %d", p->lastnames, p->name, p->age, p->phone_number, p->id);
    list_patients(hospital, total_patients);
}

void discharge_patient(patient * hospital, patient * total_patients, int * used_beds, int * available_beds) {
    patient * p;
    int discharge;
    int available_id;
    
    printf("\n\n*************** DISCHARGE PATIENT BY BED ID ***************\n\n");
    printf("Type in the ID of the patient you wish to discharge.\nType in -1 to cancel: ");
    scanf("%d", &discharge);

    if(discharge == -1) {
        printf("\nCanceling operation...\n");
    } else {
        for(p = hospital; p < total_patients; ++p) {
            if(p->id == discharge) {
                available_id = p->id;
                printf("\nPatient %s %s has been sucessfully ", p->lastnames, p-> name);
                free(p->lastnames);
                free(p->name);
                p->name = NULL;
                // free(p->phone_number);
                printf("discharged\nBed %d is now available\n", available_id);
                *used_beds -= 1;
                *available_beds += 1;
            }
        }
    }
}

void list_patients(patient * hospital, patient * total_patients){
    patient * p;
    printf("\n\n*************** LIST ADMITTED PATIENTS ***************");
    for(p = hospital; p < total_patients; ++p) {
        printf("Name: %s %s\n ", p->lastnames, p->name);
        if(p->name != NULL) {
            printf("\n-------------------------------------------------------\n");
            printf("\nName: %s %s\n   Age: %d\n   Phone number: %s\n   Bed ID: %d\n", p->lastnames, p->name, p->age, p->phone_number, p->id);      
        }
    }
}