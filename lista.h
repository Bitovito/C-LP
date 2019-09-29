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

void init(lista *);
void clear(lista *);
void insert(lista *,int,dato);
void append(lista *,dato);
void remov(lista *,int);
int length(lista *);
dato* at(lista *,int);
void movetoStart(lista *);
dato dataList(lista *);
