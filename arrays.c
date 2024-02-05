#include <stdio.h>

int main(){

    char conceitos[4];

    char conceitos2[] = {  // para declarar na mesma linha sem colocar o tamanho
        'A','B','C','D'
    }

    conceitos[0] = 'A';
    conceitos[1] = 'B';
    conceitos[2] = 'C';
    conceitos[3] = 'D';

    for (int i =0; i<4 ; i++){
        printf("Aluno %d: %c \n", i, conceitos[i]);
    }



    return 0;

}