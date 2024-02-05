#include <stdio.h>

int main(){

       struct Data {
        unsigned short dia; // Só positivo - 16 bits, se n tivesse isso, precisasse do neg, ficariam 15 bits - 2^^15, só positivo é 2^^16 pq o bit de sinal não é utilizado
        unsigned short mes;
        unsigned short ano;

    };

    struct Aluno { //Declaração da struct
    char nome[100];
    int idade;
    char conceito;
    struct Data nascimento; // struct dentro da struct
    }; 

 


    struct Aluno a1 = { // Criação de um elemento da Struct
    .nome = "Joao",
    .idade = 20,
    .conceito = 'D'
    .nascimento = {
        .dia = 1,
        .mes = 4,
        .ano = 2001
        };
    }; 

    printf("%s tem %d anos, nasceu em %d/%d/%d e tirou %c.\n", a1.nome, a1.idade, a1.nascimento.dia, a1.nascimento.mes, a1.nascimento.ano, a1.conceito);


    return 0;
}