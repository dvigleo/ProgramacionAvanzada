
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

typedef struct {
    char * name;
    char * lastnames;
    int age;
    char * phone_number;
    int id;
} patient;

typedef struct {
    int id;
    char * available;
    patient * pat;
} bed;

void create_beds(bed *, bed *, int *, int *, int *, int *, int *);
void list_beds(bed *, bed *, int *, int *, int *);
int assign_bed(patient *, bed *, bed *, int *, int *);
void discharge_patient(bed *, bed *, int *, int *);
void list_patients(patient *, patient *, int *);
void admit_patient(patient *, patient *, int, bed *, bed *, int *, int *);

int main(int argc, char const *argv[]) {
    bed * beds;
    bed * b;
    int n_patients = 0;
    patient * p;
    patient * hospital = (patient *) malloc(sizeof(patient));
    patient * total_patients = hospital + n_patients;

    beds = (bed *) malloc(sizeof(bed));
    bed * total_beds = beds;

    // Inicialmente nuestro hospital tiene 5 camas disponibles
    int free_beds;
    int * available_beds_ptr = &free_beds;
    *available_beds_ptr = 0;

    int used_beds;
    int * used_beds_ptr = &used_beds;
    *used_beds_ptr = 0;

    // LLevar cuenta de available beds para saber qué tanto debe de crecer beds
    int number_beds;
    int * number_beds_ptr = &number_beds;
    number_beds = free_beds + used_beds;

    int old_beds;
    int * old_n_beds_ptr = &old_beds;
    *old_n_beds_ptr = 0;
    
    // Bed ID
    int bed_id;
    int * bed_id_ptr = &bed_id;
    *bed_id_ptr = 1;

    int first_run = 1;

    int option = 1;
    while(option != 6) {
        if(first_run == 1) {
            option = 1;
            first_run = 0;
        } else {
            printf("\n1 - Create 5 beds\n2 - View all beds\n3 - Admit bed\n4 - Discharge patient\n5 - List of patients\nOption: ");
            scanf("%d", &option);
            if(available_beds_ptr == 0) {
                create_beds(beds, total_beds, bed_id_ptr, available_beds_ptr, used_beds_ptr, old_n_beds_ptr, number_beds_ptr);
                option = 1;
            }
        }
        switch(option) {
                case 1:
                    beds = (bed *) realloc(beds, sizeof(bed) * (*old_n_beds_ptr + N));
                    total_beds = beds + *old_n_beds_ptr + N;

                    create_beds(beds, total_beds, bed_id_ptr, available_beds_ptr, used_beds_ptr, old_n_beds_ptr, number_beds_ptr);
                    break;
                case 2:
                    list_beds(beds, total_beds, available_beds_ptr, used_beds_ptr, number_beds_ptr);
                    break;
                case 3: 
                    n_patients ++;
                    hospital = (patient *) realloc(hospital, sizeof(patient) * n_patients);
                    total_patients = hospital + n_patients;
                    admit_patient(hospital, total_patients, n_patients, beds, total_beds, available_beds_ptr, used_beds_ptr);
                    break;
                case 4:
                    discharge_patient(beds, total_beds, available_beds_ptr, used_beds_ptr);
                    break;
                case 5:
                    list_patients(p, total_patients, used_beds_ptr);
                    break;
            }
    }
    return 0;
}

void create_beds(bed * beds, bed * total_beds, int * bed_id_ptr, int * available_beds_ptr, int * used_beds_ptr, int * new_number_beds, int * old_number_beds) {
    
    bed * b;
    int * n = old_number_beds;

    printf("\n\n*************** BEDS CREATED ***************\n\n");    
    printf("Bed ID \t\tAvailable\n");
    for(b = beds + *n; b < total_beds; ++b) {
        b->id = *bed_id_ptr;
        *bed_id_ptr += 1;
        b->available = (char *) malloc(sizeof(char) * 10);
        b->available = "Yes";
        *available_beds_ptr += 1;
        printf("  %d\t\t  %s\n", b->id, b->available);
    }

    *new_number_beds = *available_beds_ptr + *used_beds_ptr;
    printf("\nOld number of beds: %d\n", *old_number_beds);
    *old_number_beds += N;
    printf("\nOld number of beds: %d\n", *old_number_beds);
}

void list_beds(bed * beds, bed * total_beds, int * available_beds_ptr, int * used_beds_ptr, int * number_beds_ptr) {
    bed * b;
   
    printf("\n\n*************** LIST OF BEDS ***************\n\n");
    
    printf("Bed ID \t\tAvailable\n");
    for(b = beds; b < total_beds; ++b) {
        if(b->available == "Yes" || b->available == "No") {
            printf("  %d\t\t  %s\n", b->id, b->available);
        }
    }

    *number_beds_ptr = *available_beds_ptr + *used_beds_ptr;
    printf("------------------------");
    printf("\nUsed beds: %d\n", *used_beds_ptr);
}

void list_patients(patient* hospital, patient * total_patients, int * used_beds){
    patient * p;
    printf("\n\n*************** LIST ADMITTED PATIENTS ***************");
    for(p = hospital; p < total_patients; ++p) {
        if(p->name != NULL) {
            printf("\n-------------------------------------------------------\n");
            printf("\nName: %s\n   Age: \n   Phone number: \n   Bed ID: %d\n", p->name, p->id);      
        }
    }

    printf("\nTotal number of patients: %d\n\n", *used_beds);
}

int assign_bed(patient * p, bed * beds, bed * total_beds, int * available_beds_ptr, int * used_beds_ptr) {
    bed * b;
    bed * aux;
    for(b = beds; b < total_beds; ++b) {
        if(b->available == "Yes") {
            aux = b;
            b->pat = p;
            b->available = "No";
            *available_beds_ptr -= 1;
            *used_beds_ptr += 1;
            break;
            p->id = aux->id;
        }
    }    
    printf("Name: %s\nBed ID: %d\n\n", aux->pat->name, aux->id);

    return aux->id;
}

void discharge_patient(bed * beds, bed * total_beds, int * available_beds_ptr, int * used_beds_ptr) {
    bed * b;
    int discharge;
    int available_id;

    printf("\n\n*************** DISCHARGE PATIENT BY BED ID ***************\n\n");
    if(*used_beds_ptr == 0){
        printf("\nThere are no patients in the system to be discharged\n");
    } else {
        printf("Type in the Bed ID of the patient you wish to discharge.\nType in -1 to cancel: ");
        scanf("%d", &discharge);

        if(discharge > *used_beds_ptr || discharge < *used_beds_ptr) {
            printf("\nThat bed does not exist\n");
        }

        if(discharge == -1) {
            printf("\nCanceling operation...\n");
        } else {
            for(b = beds; b < total_beds; ++b) {
                if(b->id == discharge) {
                    available_id = b->id;
                    printf("\nPatient %s has been sucessfully ", b->pat->name);
                    free(b->pat->name);
                    b->pat = NULL;
                    b->available = "Yes";
                    *available_beds_ptr += 1;
                    *used_beds_ptr -= 1;
                    printf("discharged\nBed %d is now available\n\n", available_id);
                    break;
                }
            }
        }
    }

}

void admit_patient(patient * hospital, patient * total_patients, int n_patients, bed * beds, bed * total_beds_struct, int * available_beds, int * used_beds) {
    bed * b;
    int replace_patient;
    patient * p;
    patient * aux;
    for(b = beds; b < total_beds_struct; ++b){
        if(b->pat == NULL){
            aux = b->pat;
            replace_patient = 1;
            break;
        } else {
            replace_patient = 0;
        }
    }  
    switch(replace_patient) {
        case 0: // CREATE NEW Patient
            p = hospital + n_patients - 1;
            break;
        case 1: // OVERWRITE 
            p = aux;
            printf("Name: %s %s\n   Age: %d\n   Phone number: %s\n   Bed ID: %d", p->lastnames, p->name, p->age, p->phone_number, p->id);
            break;
    }

    printf("\n\n*************** ADMIT PATIENT ***************\n\n");
    printf("Please enter the data below\n");
    
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
    
    assign_bed(p, beds, total_beds_struct, available_beds, used_beds);
    
    *used_beds += 1;
    *available_beds -= 1;

    printf("\n\n*************** PATIENT SAVED ***************\n\n");
    printf("Name: %s %s\n   Age: %d\n   Phone number: %s\n   Bed ID: %d", p->lastnames, p->name, p->age, p->phone_number, p->id);
}


