#include <stdio.h>

#include "linked_list.h"

void test_insert() {
    LinkedList* list = list_create();

    list_insertFirst(list, 10);
    list_insertFirst(list, 20);
    list_insertFirst(list, 30);

    list_print(list);

    list_insertAfter(list, 1, 40);
    list_insertAfter(list, -1, 50);
    list_insertAfter(list, 25, 60);
    list_insertAfter(list, 0, 70);

    list_print(list);

    list_destroy(list);
}

void test_removeFirst() {
    LinkedList* list = list_create();

    bool res = list_removeFirst(list);
    printf("%s\n", (res) ? "true" : "false");

    list_insertFirst(list, 10);
    list_insertFirst(list, 20);
    list_insertFirst(list, 30);
    list_print(list);

    res = list_removeFirst(list);
    printf("%s\n", (res) ? "true" : "false");
    list_print(list);

    res = list_removeFirst(list);
    printf("%s\n", (res) ? "true" : "false");
    list_print(list);

    res = list_removeFirst(list);
    printf("%s\n", (res) ? "true" : "false");
    list_print(list);

    res = list_removeFirst(list);
    printf("%s\n", (res) ? "true" : "false");
    list_print(list);


    list_destroy(list);
}

void test_removeAt() {
    LinkedList* list = list_create();

    bool res = list_removeAt(list, 3);
    printf("%s\n", (res) ? "true" : "false");

    list_insertFirst(list, 10);
    list_insertFirst(list, 20);
    list_insertFirst(list, 30);
    list_print(list);

    res = list_removeAt(list, -1);
    printf("%s\n", (res) ? "true" : "false");
    res = list_removeAt(list, 5);
    printf("%s\n", (res) ? "true" : "false");

    res = list_removeAt(list, 1);
    printf("%s\n", (res) ? "true" : "false");
    list_print(list);

    res = list_removeAt(list, 1);
    printf("%s\n", (res) ? "true" : "false");
    list_print(list);

    res = list_removeAt(list, 0);
    printf("%s\n", (res) ? "true" : "false");
    list_print(list);

    res = list_removeAt(list, 0);
    printf("%s\n", (res) ? "true" : "false");
    list_print(list);


    list_destroy(list);
}

int main() {

    LinkedList* l1 = list_create();
    list_insertFirst(l1, 5);
    list_insertFirst(l1, 4);
    list_insertFirst(l1, 2);
    list_insertFirst(l1, 1);
    list_insertFirst(l1, 0);
    list_print(l1);
    


    LinkedList* l2 = list_create();
    list_insertFirst(l2, 5);
    list_insertFirst(l2, 9);
    list_insertFirst(l2, 2);
    list_insertFirst(l2, 1);
    list_insertFirst(l2, 0);
    list_print(l2);

    list_printElements(l1,l2);


    bool saida = list_equals(l1,l2);
    printf(saida?"VAMPETA\n":"FAUSTO\n");


    // test_removeFirst();
    //test_removeAt();

    int test = list_isSorted(l2);
    printf("%d\n", test);

    list_printReverse(l1);

    printf("LISTA REVERSA: \n");

    LinkedList* listaReversa = reverse(l1);
    //list_print(listaReversa);

   LinkedList* lTeste = list_create();
   list_insertFirst(lTeste, 10);
    list_insertFirst(lTeste, 20);
    list_insertFirst(lTeste, 20);
    list_insertFirst(lTeste, 10);
    list_insertFirst(lTeste, 30);
    list_insertFirst(lTeste, 10);
    list_insertFirst(lTeste, 20);
    list_insertFirst(lTeste, 20);
    list_insertFirst(lTeste, 10);
    list_insertFirst(lTeste, 30);
    list_print(lTeste);

    list_removeDuplicates(lTeste);
    printf("Removendo Duplicados \n");
    list_print(lTeste);

    return 0;
}