#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../HEADERS/list.h"
#include "../HEADERS/patient.h"
#include "../HEADERS/avl.h"
#include "../HEADERS/hash.h"
#include "../HEADERS/date.h"
#include <errno.h>


int main(int argc, char **argv)
{
    size_t      len = 0,size=0;
    ssize_t     read;
    FILE        *file,*file_ref; 
    char        *line=NULL;
    char *tmp,*tmp1,*tmp2,*tmp3,*tmp4,*tmp5,*tmp6,*tmp7,*instruct;
    char *inputString=NULL,*buffer=NULL;

    List* lista = initList();                           //lista
    HashTable* hashtable_disease = initTable(atoi(argv[4]),atoi(argv[8]));    //hashtable gia diseases
    HashTable* hashtable_country = initTable(atoi(argv[6]),atoi(argv[8]));    //hashtable gia countries
    

    file = fopen("TXT/data.txt", "r");      //anoigma arxeiou
    file_ref = file;

    //errors
    if(file==NULL){
        printf("The error is - %s\n", strerror(errno));
        return -1;
    }
    //egkuro arxeio
    if(file)
    {
        while((read = getline( &line, &len, file_ref )  !=-1))          //diabazei grammes
        {   
            Patient *A =  initPatient(line);    //dhmiourgeia asthenwn
            //errors
            if((compare_dates(A->entryDate,A->exitDate)) == 1) // 1 gia date1>date2 / -1 gia date1<date2 / 0 gia date1=date2 / -1 gia -
            {
                printf("exitdate is later than entry date %s %s \n",A->entryDate,A->exitDate);
                deletePatient(A);
            }
            else
            {
                if((searchListID(lista,A->recordID)) == false)
                {
                    appendList(lista,A); 
                    InsertTable(hashtable_disease,A,0);
                    InsertTable(hashtable_country,A,1);
                }
                else if ((searchListID(lista,A->recordID)) == true)
                {
                    printf("Patient with this ID %s already exists\n",A->recordID);
                    deletePatient(A);
                }
            }
        }

    }
    
    //queries
    printf("Pick a query \n");
    while(getline(&buffer,&size,stdin)!=-1)
    {

        inputString = strtok(buffer,"\n");
        tmp = strdup(inputString);
        instruct = strtok(tmp," \n\t");
        tmp1 = strtok(NULL," \n\t");
        tmp2 = strtok(NULL," \n\t");
        tmp3 = strtok(NULL," \n\t");
        tmp4 = strtok(NULL," \n\t");
        tmp5 = strtok(NULL," \n\t");
        tmp6 = strtok(NULL," \n\t");
        tmp7 = strtok(NULL," \n\t");
        
        
        printf("\n");
        //elegxos ths prwths theshs tou pinaka gia na doume poio querie mas dothhke
        if(strcmp(instruct,"/globalDiseaseStats") == 0) 
        {    
            if(tmp1==NULL && tmp2 == NULL)
                globalDiseaseStats(hashtable_disease,NULL,NULL);
            else
                globalDiseaseStats(hashtable_disease,tmp1,tmp2);
        }
        if(strcmp(instruct,"/diseaseFrequency") == 0)
        {
            if(tmp4 == NULL)
                diseaseFrequency(hashtable_disease,tmp1,tmp2,tmp3,NULL);
            else
                diseaseFrequency(hashtable_disease,tmp1,tmp2,tmp3,tmp4);
        }
        if(strcmp(instruct,"/insertPatientRecord") == 0)
        {
            if(tmp7==NULL)
                insertPatientRecord(hashtable_disease,hashtable_country,lista,tmp1,tmp2,tmp3,tmp4,tmp5,tmp6,NULL);
            else
                insertPatientRecord(hashtable_disease,hashtable_country,lista,tmp1,tmp2,tmp3,tmp4,tmp5,tmp6,tmp7);
        }
        if(strcmp(instruct,"/recordPatientExit") == 0)
        {
            recordPatientExit(hashtable_disease,tmp1,tmp2);
        }
        if(strcmp(instruct,"/numCurrentPatients") == 0)
        {
            if(tmp1 == NULL)
                numCurrentPatients(hashtable_disease,NULL);
            else
                numCurrentPatients(hashtable_disease,tmp1);
        }
        if(strcmp(instruct,"/exit") == 0)
        {
            printf("Exit \n");
            //mporoume na ektupwsoume ta hashtables
            printTable(hashtable_disease,0);
            printTable(hashtable_country,1);
            break;
        }

        free(tmp);
        tmp=NULL;
        free(inputString);
        inputString=NULL;
        buffer=NULL;

        printf("\nPick a query \n");
    }

    

    //diagrafes kai kleisimo tou arxeiou
    free(tmp);
    free(inputString);
    buffer=NULL;
    deleteTable(hashtable_disease);
    deleteTable(hashtable_country);
    freeList(lista);
    free(line);
    fclose(file);
    return 0;
}
