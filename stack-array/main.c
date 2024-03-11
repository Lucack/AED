#include "stack.h"

#include <stdio.h>

Stack* copy(Stack* s){

        Stack* hist =  stack_create(stack_size(s));
        Stack* cop =  stack_create(stack_size(s));
        while(!stack_isEmpty(s)){
            stack_push(hist,stack_pop(s));
            
        }
        while(!stack_isEmpty(hist)){
            int temp = stack_pop(hist);
            stack_push(s,temp);
            stack_push(cop,temp);
            
        }
       
        stack_destroy(hist);
        return cop;
    }

int main() {
    Stack* stack = stack_create(10);

    stack_push(stack, 1);
    stack_push(stack, 2);
    stack_push(stack, 3);

    stack_print(stack);
    //printf("Stack size: %d\n", stack_size(stack));

    //printf("Stack peek: ");
    //element_print(stack_peek(stack));
    //printf("\n");

    //printf("Stack pop: ");
    //element_print(stack_pop(stack));
    //printf("\n");
    //stack_print(stack);


    //printf("Stack size: %d\n", stack_size(stack));

    

    Stack* stk = copy(stack);
    printf("Printando copia \n");
    stack_print(stk);
    

    return 0;
}