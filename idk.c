#include <stdio.h>
#include <stdlib.h>
#include "idfk.h"



lista* map(lista* a, dato (*f)(dato)){
    a->actual = a->head;
    a->actual = a->actual->next;

    lista* b = (lista *)malloc(sizeof(lista));////lista nueva = lista b
    init(b);





    int i;
    for(i = 0 ; i < length(a) ; a->actual = a->actual->next){
        
        
        
        
        dato* informacion = at(a,i);
        char tipo = informacion->tipo;
        if (tipo == 'i' || tipo == 'f'){
            dato newData = f(*informacion);
            insert(b,i,newData);
        }
        
        
        
        else{
            lista* innerList = map(a->actual->info.contenido, f);
            dato newlist = dataList(innerList);
            insert(b,i,newlist);
        }
    }





    return b;
}
/*
float sum(lista* a){

}

void print(lista* a){

}

float average(lista* a){

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
