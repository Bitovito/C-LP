#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void init(lista* a){
    a->head = a->actual = a->tail = (nodo *)malloc(sizeof(nodo));
    a->length = 0;
}

void clear(lista *a){;
    a->actual = a->head;
    while (a->length > 2){
        nodo *aux = a->actual->next;
        a->actual->next = a->actual->next->next;
        a->length--;
        free((void *)aux);
    }
    if (a->length == 2){
        free((void *)a->actual->next->next);
        a->length--;
    }
    if (a->length == 1){
        free((void *)a->actual->next);
        a->length--;
    }
    if (a->length == 0){
        free((void *)a);
    }
}

void insert(lista* a, int i, dato d){
    a->actual = a->head;
    int x;
    for (x=0;x<i;x++){
        a->actual = a->actual->next;
    }

    nodo *aux = a->actual->next;
    a->actual->next = (nodo *)malloc(sizeof(nodo));
    a->actual->next->info = d;
    a->actual->next->next = aux;
    if (a->actual == a->tail){
        a->tail = a->actual->next;
    }
    a->length++;
}

int length(lista* a){
    int x = a->length;
    return x;
}

void append(lista* a, dato d){
    a->tail->next = (nodo *)malloc(sizeof(nodo));
    a->tail->next->info = d;
    a->tail = a->tail->next;
    a->tail->next = NULL;
    a->length++;
}

void remov(lista* a, int i){
    a->actual = a->head;
    int x;
    for (x=0;x<i;x++){
        a->actual = a->actual->next;
    }

    if(a->length == 0){
        return;
    }
    nodo *aux = a->actual->next;
    a->actual->next = a->actual->next->next;
    if (aux == a->tail){
        a->tail = a->actual;
    }
    else if ((a->actual == a->tail)&&(a->length != 1)){
        nodo *temp;
        temp = a->head;
        while (temp->next != a->actual) {
            temp = temp->next;
        }
        a->actual = temp;
        a->tail = a->actual;
    }
    a->length--;
    free((void *)aux);
}

dato* at(lista* a, int i){
    a->actual = a->head;
    int x;
    for (x=0;x<(i+1);x++){
        a->actual = a->actual->next;
    }
    dato* y = &a->actual->info;
    return y;
}

/*
dataList
Genera un nuevo "dato" con una lista en su contenido para poder ser insertado.
-------------------------------------------------
Inputs:
lista* l: Lista a ser guardada como contenido de la funcion.
-------------------------------------------------
Output:
dato: Nuevo "dato" generado a partir de la lista
*/
dato dataList(lista* l){
    dato datazo;
    datazo.contenido = l;
    datazo.tipo = 'l';
    return datazo;
}
