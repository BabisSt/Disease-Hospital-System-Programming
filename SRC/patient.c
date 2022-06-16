#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../HEADERS/patient.h"



Patient* initPatient (char* line)
{

//Diabazoume mia gramh apo to arxeio kai kovoume to string katallhla.


    Patient* patient;
    patient = malloc(sizeof(Patient));
    char *token;
    
            token   = strtok(line, " \t\n");
            patient->recordID = strdup(token);
             
            token   = strtok(NULL, " \t\n");
            patient->patientFirstName = strdup(token); 

            token   = strtok(NULL, " \t\n");
            patient->patientLastName = strdup(token); 
            
            token   = strtok(NULL, " \t\n");
            patient->diseaseID = strdup(token); 
            
            token   = strtok(NULL, " \t\n");
            patient->country = strdup(token);
            
            token   = strtok(NULL, " \t\n");
            patient->entryDate = strdup(token);
        
            token   = strtok(NULL, " \t\n");
            patient->exitDate = strdup(token);
            
       return patient;     
}

void printPatient(Patient* patient)
{
    printf("%s \n",patient->recordID);
    printf("%s \n",patient->patientFirstName);
    printf("%s \n",patient->patientLastName);
    printf("%s \n",patient->diseaseID);
    printf("%s \n",patient->country);
    printf("%s \n",patient->entryDate);
    printf("%s \n",patient->exitDate);

}

void deletePatient(Patient* patient)
{
    free((*patient).recordID);  //theloume * giati einai dieuthinsh ston patient
    free((*patient).patientFirstName);
    free((*patient).patientLastName);
    free((*patient).diseaseID);
    free((*patient).country);
    free((*patient).entryDate);
    free((*patient).exitDate);
    free(patient);
}