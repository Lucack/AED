#include "array_din.h"
#include <stdlib.h>

#define INITIAL_CAPACITY 10;
struct ArrayDinamico{
    Element *data;
    int size;
    int capacity; // capacidade de armazenamento nem sempre é o size utilizado
};


ArrayDinamico* arraydinamico_create(){

    ArrayDinamico* array = malloc(sizeof(ArrayDinamico)); // alocando struct
    array->capacity = INITIAL_CAPACITY;
    array->data = malloc(sizeof(Element)*array->capacity);
    array->size = 0;
    return array;

};

void arraydinamico_destroy(ArrayDinamico* array){
    // desalocar memoria de dentro pra fora, primeiros os alocados dentro do array
    free(array->data);
    free(array);
}; // passou um atributo, no caso o array para destruir

void arraydinamico_resize(ArrayDinamico* array, int new_capacity){
    Element* new_array = realloc(array->data,sizeof(Element)*new_capacity); //realocando
    // verificando se ela nao mudou o lugar que tava alocado pq tava sem memoria
    if(new_array != NULL){
        array->data = new_array;
        array->capacity = new_capacity;
    }
};


void arraydinamico_add(ArrayDinamico* array, Element element){
    if(array->size == array->capacidade){
        arraydinamico_resize(array, array->capacity*2);
    }
    // na posição size adiciona o elemento, pq o ultimo é size-1
    array->data[array->size] = element; // aloca no array o elemento novo passado na função
    array->size++; // soma  1 no size apos adicionar um elemento
};

void arraydinamico_print(ArrayDinamico* array){
    // ele pegou da aula semena carnaval
};

int arraydinamico_size(ArrayDinamico* array){
    return(array->size)
};

void arraydinamico_set(ArrayDinamico* int pos, Element element){

}; // trocar algum elemento do array

Element arraydinamico_get(ArrayDinamico* array, pos){
    if(pos<0 || pos >= array->size){
        abort(); // ver se importei
    }
    return array->size[pos];
};

