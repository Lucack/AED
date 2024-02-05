#include <stdio.h>

int main(){

    int x = 20; // literal int
    int y; 

    y = 30;

    const int = 10; // não da pra atribuir outro valor

    char c = 10;    // 8 bits
    long d = 40;    // 64 bits
    float e = 2.2;  // 32 bits 
    double f = 2.0; // 64 bits
    short g = 2;    // 16 bits
    
    printf("int: %ld bits", sizeof(int)*8);

    typedef int inteiro; // renomeia o tipo - Alias

    inteiro x1 = 10;

    return 0;

}