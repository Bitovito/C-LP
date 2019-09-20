#include <stdio.h>
#include <stdlib.h>
#include "idfk.h"



lista* map(lista* a, dato (*f)(dato)){
    movetoStart(a);
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

float sum(lista* a){
    movetoStart(a);
    float suma;
    int i;
    for(i = 0 ; i < length(a) ; a->actual = a->actual->next){
        dato* informacion = at(a,i);
        char tipo = informacion->tipo;
        if (tipo == 'i' || tipo == 'f'){
            suma += *(float *)informacion->contenido;
        } 
        else{
            float innersum = sum(a->actual->info.contenido);
            suma += innersum;
        }
    }
    return suma;
}
/*
void print(lista* a){

}
*/
float average(lista* a){
    movetoStart(a);
    float suma;
    int n = 0;
    int i;
    for(i = 0 ; i < length(a) ; a->actual = a->actual->next){
        dato* informacion = at(a,i);
        char tipo = informacion->tipo;
        if (tipo == 'i' || tipo == 'f'){
            suma += *(float *)informacion->contenido;
            n++;
        } 
        else{
            float innersum = sum(a->actual->info.contenido);
            suma += innersum;
            n++;
        }
    }
    int prom = suma/n;
    return prom;
}

int main(){
    lista* z = (lista *)malloc(sizeof(lista));
    init(z);
    if(z->actual->next==NULL){
        printf("LOL");
    }
    return 0;
}
