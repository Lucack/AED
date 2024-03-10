# include <stdio.h>
int main(){
    
    int x = 10;
    int y = 20;
    int z = 30;

    printf("%p\n", &x);
    printf("%p\n", &y);
    printf("%p\n", &z); // %p mostra o endereço do conteúdo & obtem o endereço do proprio ponteiro
    return 0;
};
