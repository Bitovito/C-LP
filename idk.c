#include <stdio.h>
#include <stdlib.h>
#include "idfk.h"


/*
struct lista* map(struct lista* a, struct dato (*f)(struct dato)){

}

float sum(struct lista* a){

}

void print(struct lista* a){

}

float average(struct lista* a){

}
*/
int main(){
    lista* z = (lista *)malloc(sizeof(lista));
    init(z);
    if(z->actual->next==NULL){
        printf("LOL");
    }
    return 0;
}
