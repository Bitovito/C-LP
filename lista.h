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

void init(lista *a);
void clear(lista *a);
void insert(lista *a,int i,dato d);
void append(lista *a,dato d);
void remov(lista *a,int i);
int length(lista *a);
dato* at(lista *a,int i);
void movetoStart(lista *a);
dato dataList(lista *);
void clearHelp(lista *);
