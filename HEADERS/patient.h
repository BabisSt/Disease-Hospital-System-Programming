#pragma once

typedef struct Patient
{
    char* recordID;
    char* patientFirstName;
    char* patientLastName;
    char* diseaseID;
    char* country;
    char* entryDate;
    char* exitDate;

}Patient;


Patient* initPatient (char*);   //Arxikopoihsh Asthenh

void printPatient(Patient*);    //Ektupwsh Asthenh

void deletePatient(Patient*);   //Diagrafh Asthenh