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
    char * occupied; // 1 = yes, 0 = no
    patient * pat;
} bed;


void admit_patient(patient *, int *, int *, int *, int, patient *);
void list_patients(patient *, patient *);
void exit_program(patient *, patient *);
void bed_info(int, int);

int main(int argc, char const *argv[]) {
    patient * hospital;
    int n_patients = 0;
    
    // Bed ID
    int bed_id;
    int * id_ptr = &bed_id;
    *id_ptr = 0;

    // Available beds
    int a_beds;
    int *a_ptr = &a_beds;
    *a_ptr = 0;

    // Used beds
    int u_beds;
    int *u_ptr = &u_beds;
    *u_ptr = 0;    

    hospital = (patient *) malloc(sizeof(patient) * 1);
    patient * final = hospital + 1;
    
    int option = 0; 
    while(option != 5) {
        printf("\n\n*************** HOSPITAL MANAGEMENT SYSTEM ***************\n\n");
        printf("1 - Admit new patient \n2 - Discharge patient \n3 - See all admitted patients \n4 - See beds information \n5 - Exit program");
        printf("\nSelect an option (1-5): ");
        scanf("%d", &option);
        
        switch(option) {
            case 1: // Admit patient
                n_patients += 1;
                admit_patient(hospital, a_ptr, u_ptr, id_ptr, n_patients, final);
                break;
           
            case 3: // See list of patients
                list_patients(hospital, final);
                break;
           
            case 4: // See bed information
                bed_info(a_beds, u_beds);
                break;

        }
    }

    if(option == 5) {
        exit_program(hospital, final);
    }
    return 0;
}


/*
    Creates a patient, saves the data, updates the number of available and unavailable beds. Create's new beds if there are none available at the moment
*/
void admit_patient(patient * hospital, int * a_beds, int * u_beds, int * bed_id, int n_patients, patient * final) {
    hospital = (patient *) realloc(hospital, sizeof(patient) * (n_patients + 1));
    patient * p = hospital;
    final = hospital + 1 + n_patients; 

    bed * b = (bed *) malloc(sizeof(bed));
    bed * final_b = b + 1;
    bed * aux;
    bed * current_bed = b;
    // patient * p = (patient *) malloc(sizeof(patient));
    
    // Fill out patients data
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
    
    // Create new beds if there are none 
    if(*a_beds == 0) {
        b = (bed *) realloc(b, sizeof(bed) * N);
        final_b = b + N;
        *a_beds = N;
        for(aux = b; aux < final_b; ++aux) {
            *bed_id += 1;
            b->id = *bed_id;
            b->occupied = (char * ) malloc(sizeof(char) * 10);
            b->occupied = "No";
            printf("--N/A--\t\t\t%d\t\t%s\n", b->id, b->occupied);
        }
    }

    // Assign bed to patient
    // int current_bid;
    // current_bid  += 1;
    current_bed->pat = p;
    current_bed->id = b->id;
    current_bed->occupied = "Yes";
    *u_beds += 1;
    *a_beds -= 1;
    
    // Print bed data
    // printf("\n\nPatient\t\t\t\tID\t\tOccupied\n");
    // for(aux = b; aux < final_b; ++aux) {
    //     printf("%s %s\t\t\t%d\t\t%s\n", b->pat->lastnames, b->pat->name, b->id, b->occupied);
    // }


    // Print patient's data
    printf("\n\n*************** PATIENT'S DATA SAVED ***************\n");
    printf("Name: \t\t%s %s \nAge: \t\t%d \nPhone number: \t%s \nBed number: \t%d", p->lastnames, p->name, p->age, p->phone_number, current_bed->id);
}


/*
    Prints the list of patients that are at the hospital
*/
void list_patients(patient * hospital, patient * final) {
    patient * p = hospital;
    printf("\n\n*************** LIST ADMITTED PATIENTS ***************\n\n");

    printf("Name \t\t\t Bed ID\n");
    for(p = hospital; p < final; ++p) {
        printf("%s %s\t\t00\n", p->lastnames, p->name);        
    }
   
}

void bed_info(int available, int unavailable) {
    printf("\n\n*************** BED INFORMATION ***************\n\n");
    printf("Available beds: %d\nUsed beds: %d\nTotal number of beds: %d",available, unavailable, available + unavailable);

    /*Could use patients information  */
}

/*
    Frees the memory and exits the program
*/
void exit_program(patient * hospital, patient * final) {
    patient * p;

    for(p = hospital; p < final; ++p) {
        free(p->name);
        free(p->lastnames);
        free(&p->age);
        free(p->phone_number);
    }
    free(hospital);

    printf("\n\nExiting program...\n\n");
    exit(0);
}