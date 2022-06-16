#pragma once

#include "patient.h"

typedef struct ListNode             //Komvos Listas
{ 
    Patient* data; 
    struct ListNode *next; 
}ListNode; 

typedef struct List                 //Lista me duo deiktes ston prwto kai sto teleutaio komvo
{
    struct ListNode *last;
    struct ListNode *first;
}List;

void appendList(List* , Patient* );//Prosthikh

void freeList(List* );             //Diagrafh

bool searchListID(List* , char* ); //Elegxos gia diplotupo ID

void printList(List*);             //Ektupwsh

List* initList();                  //Arxikopoihsh