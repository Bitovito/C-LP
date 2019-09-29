#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

lista* map(lista* a, dato (*f)(dato)){
    movetoStart(a);
    lista* b = (lista *)malloc(sizeof(lista));////lista nueva = lista b
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
    movetoStart(a);
    float suma;
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
	movetoStart(a);
	printf("[");
	int i;
	for (i = 0; i < length(a); i++){
		dato *informacion = at(a,i);
		char tipo = informacion->tipo;
		if (tipo == 'i'){
			printf("%d,",*(int *)informacion->contenido);
		}
		else if (tipo == 'f'){
			printf("%f,",*(float *)informacion->contenido);
		}
		else{
			lista *l = (lista *)informacion->contenido;
			print(l);
		}
	}
	printf("]\n");
}

float average(lista* a){
    movetoStart(a);
    float suma;
    int n = 0;
    int i;
    for(i = 0 ; i < length(a) ; i++){
        dato* informacion = at(a,i);
        char tipo = informacion->tipo;
        if (tipo == 'i'){
            printf("%d\n", *(int *)informacion->contenido);////////////////flag
            suma += *(int *)informacion->contenido;
            n++;
        } 
        else if(tipo == 'f'){
            printf("%f\n", *(float *)informacion->contenido);////////////////flag
            suma += *(float *)informacion->contenido;
            n++;
        }
       	else{
            float innersum = sum(a->actual->info.contenido);
            lista *l = (lista *)informacion->contenido;
            if (length(l)!= 0){
		n++;
		suma += (innersum/length(l));
	    }	
        }
    }
    int prom = suma/n;
    return prom;
}

int main(){
    lista* z = (lista *)malloc(sizeof(lista));
    init(z);
    printf("Lista iniciada\n");

    void* v = NULL;
    
    int num = 1337;

    dato dato;
    dato.tipo = 'i';
    v = &num;
    dato.contenido = v;
    append(z, dato);

    int num1 = 69;
    dato.tipo = 'i';
    v = &num1;
    dato.contenido = v;
    append(z, dato);

    printf("Promedio es: %f\n",average(z));
    printf("Suma es: %f\n",sum(z));
    //clear(z);
    print(z);
    
    return 0;
}

