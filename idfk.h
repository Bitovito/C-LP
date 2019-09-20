typedef struct  lista {
    struct  nodo* actual;
    struct  nodo* head;
    struct  nodo* tail;
    int  length;
}lista;

typedef struct  dato {
    void* contenido;
    char  tipo;
}dato;

typedef struct  nodo {
    struct  dato  info;
    struct  nodo* next;
}nodo;

void init(lista* a){
    a->head = a->actual = a->tail = (nodo *)malloc(sizeof(nodo));
    a->length = 0;
}
///////////////////////////////////////////
void clear(lista* a){//////////////////////Nosé si
    a->actual = a->head;///////////////////esta 
    clearHelp(a);//////////////////////////wea
    free(a->head);/////////////////////////funcione,
}//////////////////////////////////////////prefiero
///////////////////////////////////////////revisarla
void clearHelp(lista* a){//////////////////porque
    nodo *puntero = a->actual;/////////////no me tinca
    while(a->actual->next->next != NULL){//la 
        clearHelp(a);//////////////////////wea
    }//////////////////////////////////////xdxdxd
    free(puntero->next);///////////////////xdxdxd
}//////////////////////////////////////////xdxdxd
///////////////////////////////////////////
void insert(lista* a, int i, dato d){
    a->actual = a->head;
    for (int x=0;x<i;x++){
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
    nodo *aux = a->actual->next;
    a->actual->next = (nodo *)malloc(sizeof(nodo));
    a->actual->next->info = d;
    a->actual->next->next = aux;
    if (a->actual == a->tail){
        a->tail = a->actual->next;
    }
    a->length++;
}

void erase(lista* a, int i){
    a->actual = a->head;
    for (int x=0;x<i;x++){
        a->actual = a->actual->next;
    }

    nodo *aux = a->actual->next->next;
    free(a->actual->next);
    a->actual->next = aux;
    if (a->actual->next->next == NULL){
        a->tail = a->actual->next;
    }
    a->length--;
}

dato* at(lista* a, int i){
    a->actual = a->head;
    for (int x=0;x<(i+1);x++){
        a->actual = a->actual->next;
    }
    dato* x = &a->actual->info;
    return x;
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
