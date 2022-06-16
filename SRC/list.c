#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../HEADERS/list.h"


void appendList(List* lista, Patient* new_data) 
{ 
    
    ListNode* new_node =  malloc(sizeof(ListNode)); 
    new_node->data  = new_data; 
    new_node->next = NULL; 
    
    if (lista->first == NULL)   //eisagwgh sthn arxi an first einai NULL
    { 
        lista->first = new_node;
        lista->last= lista->first;
        lista->first->next = NULL;
    }   
    else                        //eisagwgh ston telos an h lista den einai adeia
    {
        ListNode* tmp = lista->last;
        tmp->next =new_node;
        lista->last =tmp->next;
        lista->last->next = NULL; 
    }  
    

} 


void freeList(List* lista)
{
    ListNode* head= lista->first;

        while (head != NULL)
        {
            ListNode* tmp;
            tmp = head;
            head = head->next;
            deletePatient(tmp->data);
            free(tmp);   
        }
        free(lista);

}

bool searchListID(List* list, char* x) 
{ 
    ListNode* current = list->first;
    while (current != NULL) 
    { 
        if ( (strcmp(current->data->recordID,x)) == 0 ) 
        {    
            return true;
        } 
        else
            current = current->next; 
    } 
    
    return false; 
}

void printList(List *lista) 
{ 
    ListNode* tmp = lista->first;
    while (tmp != NULL) 
    { 
        printPatient(tmp->data);
        tmp = tmp->next;     
    }
   
} 

List *initList()
{
    List* a = malloc(sizeof(List));
    a->first = NULL;
    a->last = NULL;
    return a;
}