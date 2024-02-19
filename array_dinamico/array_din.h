#ifndef ARRAY_DIN_H
#define ARRAY_DIN_H

#include "element.h"

typedef struct ArrayDinamico ArrayDinamico;

ArrayDinamico* arraydinamico_create();
void arraydinamico_destroy(ArrayDinamico* array); // passou um atributo, no caso o array para destruir
void arraydinamico_add(ArrayDinamico* array, Element element);
void arraydinamico_print(ArrayDinamico* array);
int arraydinamico_size(ArrayDinamico* array);
void arraydinamico_set(ArrayDinamico* int pos, Element element); // trocar algum elemento do array
Element arraydinamico_get(ArrayDinamico* array, pos);


#endif 
