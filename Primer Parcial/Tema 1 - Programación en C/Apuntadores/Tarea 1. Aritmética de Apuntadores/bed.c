/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

typedef struct {
    char * name;
    char * lastnames;
    int age;
    char * phone_number;
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
void search_bed_info(bed*, bed *, int *, int *);
void list_patients(bed *, bed *, int *);
void admit_patient(patient *, patient *, int, bed *, bed *, int *, int *);

int main(int argc, char const *argv[]) {
    bed * beds;
    bed * b;

    patient * hospital;
    patient * p;
    int n_patients = 0;
    hospital = (patient *) malloc(sizeof(patient));
    patient * total_patients = hospital + n_patients;
    
    // Inicialmente nuestro hospital tiene 5 camas disponibles
    int free_beds;
    int * free_ptr = &free_beds;
    *free_ptr = 0;

    int used_beds;
    int * used_ptr = &used_beds;
    *used_ptr = 0;

    // LLevar cuenta de available beds para saber qué tanto debe de crecer beds
    int number_beds;
    int * number_beds_ptr = &number_beds;
    number_beds = free_beds + used_beds;

    int old_beds;
    int * oldn_ptr = &old_beds;
    *oldn_ptr = 0;
    
    // Bed ID
    int bed_id;
    int * bed_id_ptr = &bed_id;
    *bed_id_ptr = 1;

    beds = (bed *) malloc(sizeof(bed) * N);
    bed * total_beds = beds + N;
    create_beds(beds, total_beds, bed_id_ptr, free_ptr, used_ptr, number_beds_ptr, oldn_ptr);
    
    *number_beds_ptr = *free_ptr + *used_ptr;
    // *oldn_ptr = *number_beds_ptr - 5;
    
    int option = 0;
    while(option != 7) {
        printf("\n\n*************** HOSPITAL MANAGEMENT SYSTEM ***************\n\n");
        
        printf("1 - Create beds\n2 - List beds\n3 - Admit patient\n4 - Discharge\n5 - Bed info by ID\n6 - List of patients\n");
        printf("\nSelect an option (1-6): ");
        scanf("%d", &option);
        switch (option) {
        case 1:
            beds = (bed *) realloc(beds, sizeof(bed) * (*oldn_ptr + N));
            total_beds = beds + *oldn_ptr + N;
            
            create_beds(beds, total_beds, bed_id_ptr, free_ptr, used_ptr, number_beds_ptr, oldn_ptr);
            *number_beds_ptr = *free_ptr + *used_ptr;

            printf("N beds: %d", number_beds);
            if(*number_beds_ptr == 5) {
                // *oldn_ptr = 5;
            } else {
                *oldn_ptr = *number_beds_ptr - 5;
            }            
            printf("\nAvailable beds: %d\n", *free_ptr);
            printf("Total number of beds: %d\n\n\n", *number_beds_ptr);
            break;

        case 2:
            list_beds(beds, total_beds, free_ptr, used_ptr, number_beds_ptr);
            break;    
        case 3: 
            n_patients ++;
            hospital = (patient *) realloc(hospital, sizeof(patient) * n_patients);
            total_patients = hospital + n_patients;
            admit_patient(hospital, total_patients, n_patients, beds, total_beds, free_ptr, used_ptr);
            break;
        case 4: 
            discharge_patient(beds, total_beds, free_ptr, used_ptr);
            break;
        case 5:
            search_bed_info(beds, total_beds, free_ptr, used_ptr);
            break;
        case 6:
            list_patients(beds, total_beds, used_ptr);
            break;
        default:
            break;
        }
    }
    return 0;
}

void create_beds(bed * beds, bed * total_beds, int * bed_id_ptr, int * free_ptr, int * used_ptr, int * number_beds_ptr, int * oldn_ptr) {
bed * b;
    int * n = oldn_ptr;

    printf("\n\n*************** BEDS CREATED ***************\n\n");    
    printf("Bed ID \t\tAvailable\n");
    for(b = beds + *n; b < total_beds; ++b) {
        b->id = *bed_id_ptr;
        *bed_id_ptr += 1;
        b->available = (char *) malloc(sizeof(char) * 10);
        b->available = "Yes";
        *free_ptr += 1;
        b->pat = NULL;
        printf("  %d\t\t  %s\n", b->id, b->available);
    }

    *number_beds_ptr = *free_ptr + *used_ptr;
}

void list_beds(bed * beds, bed * total_beds, int * free_ptr, int * used_ptr, int * number_beds_ptr) {
    bed * b;
   
    printf("\n\n*************** LIST OF BEDS ***************\n\n");
    
    for(b = beds; b < total_beds; ++b) {
        if(!b->pat) {
            printf("Patient's name: N/A \nBed ID: %d\n\n",b->id);        
        } else {
            printf("Patient's name: %s %s\nBed ID: %d\n\n", b->pat->lastnames, b->pat->name, b->id);
        }
    }   

    *number_beds_ptr = *free_ptr + *used_ptr;
    printf("------------------------");
    printf("\nAvailable beds: %d", *free_ptr);
    printf("\nUsed beds: %d\n", *used_ptr);
    printf("Total number of beds: %d\n\n", *number_beds_ptr);
}

int assign_bed(patient * p, bed * beds, bed * total_beds, int * free_ptr, int * used_ptr) {
    bed * b;
    bed * aux;

    if(*free_ptr == 0) {
        printf("\nThere are no more beds available\nPress 1 in the following menu\n\n");
    } else {
        for(b = beds; b < total_beds; ++b) {
            if(b->available == "Yes") {
                aux = b;
                b->pat = p;
                b->available = "No";
                *free_ptr -= 1;
                *used_ptr += 1;
                break;
            }
        }    
    }

    // printf("Name: %s %s\nBed ID: %d\n\n", aux->pat->lastnames, aux->pat->name, aux->id);

    return aux->id;
}

void discharge_patient(bed * beds, bed * total_beds, int * free_ptr, int * used_ptr) {
    bed * b;
    int discharge;
    int * available_id = malloc(sizeof(int) * 20);

    printf("\n\n*************** DISCHARGE PATIENT BY BED ID ***************\n\n");
    printf("Type in the Bed ID of the patient you wish to discharge.\nType in -1 to cancel: ");
    scanf("%d", &discharge);

    if(discharge == -1) {
        printf("\nCanceling operation...\n");
    } else {
        for(b = beds; b < total_beds; ++b) {
            if(b->id == discharge) {
                *available_id = b->id;
                printf("\nPatient %s %s has been sucessfully ", b->pat->lastnames, b->pat->name);
                free(b->pat->name);
                free(b->pat->lastnames);
                b->pat = NULL;
                b->available = "Yes";
                *free_ptr += 1;
                *used_ptr -= 1;
                printf("discharged\nBed %d is now available\n\n", *available_id);
                break;
            } else {
                printf("There is no bed with the ID %d", discharge);
                break;
            }
        }
    }

}

void search_bed_info(bed * beds, bed * total_beds, int * free_ptr, int * used_ptr) {
    bed * b;
    int bed_info;

    printf("\n\n*************** SEE BED INFO BY ID ***************\n\n");
    printf("Type in the Bed ID to see its information.\nType in -1 to cancel: ");
    scanf("%d", &bed_info);

    if(bed_info == -1) {
        printf("\nCanceling operation...\n\n");
    } else {
        for(b = beds; b < total_beds; ++b) {
            if(b->id == bed_info) {
                if(b->available == "No") {
                    printf("\nBed %d is currently assigned to patient %s %s\n\n", b->id, b->pat->lastnames, b->pat->name);
                } else if(b->available == "Yes") {
                    printf("\nBed %d is not assigned to any patient\n\n", b->id);
                }
            }
        }
    }

}

void list_patients(bed * beds, bed * total_beds, int * total_patients){
    bed * b;

    printf("\n\n*************** LIST ADMITTED PATIENTS ***************\n\n");
    for(b = beds; b < total_beds; ++b) {
        if(!b->pat) {
            break;        
        } else {
            printf("Name: %s %s\nBed ID: %d\n\n", b->pat->lastnames, b->pat->name, b->id);
        }
    }

    printf("\nTotal number of patients: %d\n\n", *total_patients);
}

void admit_patient(patient * hospital, patient * total_patients, int n_patients, bed * beds, bed * total_beds, int * free_ptr, int * used_ptr) {
    patient * p = hospital + n_patients - 1;
    
    printf("\n\n*************** ADMIT NEW PATIENT ***************\n\n");
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

    int bed_id = assign_bed(p, beds, total_beds, free_ptr, used_ptr);

    printf("\n\n*************** PATIENT WITH ID = %d SAVED ***************\n\n", bed_id);
    printf("Name: %s %s\nAge: %d\nPhone number: %s\nBed ID: %d\n", p->lastnames, p->name, p->age, p->phone_number, bed_id);

}