#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    Element element;
    struct Node* next;
} Node;

struct LinkedList {
    Node* head;
    int size;
};

LinkedList* list_create() {
    LinkedList* list = malloc(sizeof(LinkedList));

    list->head = NULL;
    list->size = 0;

    return list;
}

void list_destroy(LinkedList* list) {
    Node* cur = list->head;

    while (cur != NULL) {
        Node* trash = cur;

        cur = cur->next;
        free(trash);
    }
    free(list);
}

void list_insertFirst(LinkedList* list, Element element) {
    Node* newNode = malloc(sizeof(Node));

    newNode->element = element;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void list_insertAfter(LinkedList* list, int pos, Element element) {
    if (list->head == NULL || pos < 0) {
        list_insertFirst(list, element);
    } else {
        Node* cur = list->head;
        int i = 0;

        while (i < pos && cur->next != NULL) {
            cur = cur->next;
            i++;
        }

        Node* newNode = malloc(sizeof(Node));

        newNode->element = element;
        newNode->next = cur->next;
        cur->next = newNode;
        list->size++;
    }    
}

void list_print(LinkedList* list) {
    Node* cur = list->head;

    while (cur != NULL) {
        element_print(cur->element);
        cur = cur->next;
        if (cur != NULL) {
            printf(" -> ");
        }        
    }
    printf("\n");
}

bool list_removeFirst(LinkedList* list) {
    if (list->head == NULL) {
        return false;
    }

    Node* trash = list->head;

    list->head = list->head->next;
    free(trash);
    list->size--;

    return true;
}

bool list_removeAt(LinkedList* list, int pos) {
    // caso 0: posicao invalida
    if (pos < 0 || pos >= list->size) {
        return false;
    }

    // caso 1: lista vazia
    if (list == NULL) {
        return false;
    }

    // caso 2: remocao na cabeca
    if (pos == 0) {
        return list_removeFirst(list);
    } else { // caso 3: remocao na cauda
        Node* prev = list->head;
        int i = 0;

        while (i < pos - 1) {
            prev = prev->next;
            i++;
        }

        Node* trash = prev->next;

        prev->next = prev->next->next;
        free(trash);  
        list->size--;

    }

    return true;    
}

void list_printElements(LinkedList* l1, LinkedList* l2){

    Node* num = l1->head;
    Node* cur = l2->head;

    printf("Resultado: \n");
    bool printed = false;
    int i = 0;
    while (i<l2->size){

        if(num->element == i){
            element_print(cur->element);
            printf(" ");
            printed = true;
            cur = cur->next;
            if (num->next != NULL ){num = num->next;}
            
        } else if (printed==false) {
            cur = cur->next;
        }
        printed = false;
        i++;

    }
    
    printf("\n");
}

bool list_equals(LinkedList* l1, LinkedList* l2){
    Node* num = l1->head;
    Node* cur = l2->head;
    if (l1->size != l2->size){return false;}
    for (int i = 0; i<l1->size ; i++) {

        if (num->element != cur->element){
            return false;
        } else {
            cur = cur->next;
            num = num->next;
        }
    }
    return true;
}

int list_isSorted(LinkedList* l){

    Node* cur = l->head;
    Node* prox = l->head->next;
    bool isAsc = true;

    if (prox->element > cur->element) {isAsc = true;} else {isAsc = false;}

    while (prox != NULL){

        if(isAsc && prox->element < cur->element) {

           return 0;

        } else if (!isAsc && prox->element > cur->element) {

            return 0;
        }

        cur = cur->next;
        prox = prox->next;

    }
    if (isAsc){return 1;}else{return 2;} 
}

void list_printReverse(LinkedList* l){

    Node* cur = l->head;

    int retorno[l->size];
    int i=0;

    while(cur!=NULL){
        retorno[i] = cur->element;
        i++;
        cur = cur->next;
    }
    
    for (i = (l->size)-1 ; i!=0;  i--){
        printf("%d ",retorno[i]);
    }
    printf("\n");
}

LinkedList* reverse(LinkedList* l){

    LinkedList* novaLista = list_create();

    Node* cur = l->head;


    while(cur!=NULL){

        list_insertFirst(novaLista, (Element)cur->element); 
        cur = cur->next;
    }
    list_print(novaLista);
}

void list_removeDuplicates(LinkedList* l){

    Node* cur = l->head;
    Node* read = l->head;


    
   
    while (cur!=NULL) {
        read=cur->next;
        int i = 1;
        while(read!=NULL){

            if(cur->element == read->element){
                bool a = list_removeAt(l, i);
                if(a==false){
                    printf("falsofasfasf");
                    
                    list_removeAt(l, (l->size));}
                printf("REVMOVENDO ");
            }
            i++;
            read=read->next;

        }

        cur=cur->next;
    }

}