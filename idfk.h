struct  lista {
    struct  nodo* actual;
    struct  nodo* head;
    struct  nodo* tail;
    int  length;
};

struct  nodo {
    struct  dato  info;
    struct  nodo* next;
};

struct  dato {
    void* contenido;
    char  tipo;
};

void init(struct lista* a){

}
void clear(struct lista* a){

}
void insert(struct lista* a, int i, dato d){

}
void append(struct lista* a, dato d){

}
void remove(struct lista* a, int i){

}
int length(struct lista a){

}
struct dato* at(struct lista* a, int i){

}