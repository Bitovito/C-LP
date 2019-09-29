#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

lista* map(lista* a, dato (*f)(dato)){
    lista* b = (lista *)malloc(sizeof(lista));
    init(b);
    int i;
    for(i = 0 ; i < length(a) ; i++){
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
    float suma = 0;
    int i;
    for(i = 0 ; i < length(a) ; i++){
        dato* informacion = at(a,i);
        char tipo = informacion->tipo;
        if (tipo == 'i'){
            suma += *(int *)informacion->contenido;
        } 
        else if (tipo == 'f'){
            suma += *(float *)informacion->contenido;
        }
        else{
            float innersum = sum(a->actual->info.contenido);
            suma += innersum;
        }
    }
    return suma;
}

void print(lista* a){
	printf("[");
	int i;
	for (i = 0; i < length(a); i++){
		dato *informacion = at(a,i);
		char tipo = informacion->tipo;
        if (i < length(a)-1){
            if (tipo == 'i'){
                printf("%d,",*(int *)informacion->contenido);
            }
            else if (tipo == 'f'){
                printf("%f,",*(float *)informacion->contenido);
            }
            else if (tipo == 'l'){
                lista *l = (lista *)informacion->contenido;
                print(l);
                printf(",");
            }
		}
        else{
            if (tipo == 'i'){
                printf("%d",*(int *)informacion->contenido);
            }
            else if (tipo == 'f'){
                printf("%f",*(float *)informacion->contenido);
            }
            else if (tipo == 'l'){
                lista *l = (lista *)informacion->contenido;
                print(l);
            }
        }
	}
    printf("]");
}

float average(lista* a){
    float suma = 0;
    float suma_inner = 0;
    int n = 0;
    int i;
    for(i = 0 ; i < length(a) ; i++){
        dato* informacion = at(a,i);
        char tipo = informacion->tipo;
        if (tipo == 'i'){
            suma += *(int *)informacion->contenido;
            n++;
        } 
        else if(tipo == 'f'){
            suma += *(float *)informacion->contenido;
            n++;
        }
       	else{
            lista *l = (lista *)informacion->contenido;
            suma_inner += average(l);
            if ((length(l) != 0) && (suma_inner != 0)){
                suma += suma_inner;
                n++;
            }
        }
    }
    if(n != 0){
        return suma/n;
    }
    else{
        return 0;
    }
}

