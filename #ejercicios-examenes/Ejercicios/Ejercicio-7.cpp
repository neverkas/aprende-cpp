#include <iostream>

using namespace std;

struct Cliente{
    int id;
};

struct Nodo{
    Cliente info;
    Nodo *sgte;
};

int busquedaBinaria(Cliente c[], int len, int id);
int listaCantNodos(Nodo *l);
void listaAVector(Nodo *l, Cliente c[]);
void vectorALista(Cliente c[], int len, Nodo *&l);
void insertar(Nodo *&l, Cliente c);
void listar(Nodo *l);
void listarVector(Cliente v[], int len);

Nodo *lista = NULL;

int main(){
    Cliente c;
    // Inserto y listo
    c.id = 1;
    insertar(lista, c);
    c.id = 2;
    insertar(lista, c);
    c.id = 3;
    insertar(lista, c);
    c.id = 4;
    insertar(lista, c);

    listar(lista);

    /************************************************/
    // pruebo pasar una lista a un vector
    int len = listaCantNodos(lista);
    cout << "len:" << len << endl;
    Cliente v[len];

    listaAVector(lista, v);
    listarVector(v, len);
    
    /************************************************/
    // pruebo hacer busqueda binaria en vectores
    int pos;
    pos = busquedaBinaria(v, len, 3);
    cout << pos << endl;

    /**********************************************/
    // pruebo pasar un vector a una lista
    Nodo *lista2 = NULL;
    vectorALista(v, len, lista2);
    listar(lista2);

    return 0;
}

void vectorALista(Cliente v[], int len, Nodo *&l){     
    for(int i=0; i < len; i++) insertar(l, v[i]);
}

int busquedaBinaria(Cliente v[], int len, int id){
    int pi = 0, pf = len-1, pm = (pi + pf) / 2;
    bool enc = false;

    while(pi <= pf && !enc){
        if(v[pm].id == id) enc = true;
        else if(v[pm].id < id) pi = pm + 1;
        else if(v[pm].id > id) pf = pm -1;
        pm = (pi + pf) / 2;
    }

    return (enc) ? pm : -1;
}

void listarVector(Cliente v[], int len){
    for(int i=0; i < len; i++) cout << v[i].id << " ";
    cout << endl;
}

void listaAVector(Nodo *l, Cliente v[]){
    int i = 0;
    while(l != NULL){
        v[i] = l->info;
        i++;

        l = l->sgte;
    }    
}

int listaCantNodos(Nodo *l){
    int i = 0;
    while(l != NULL){
        l = l->sgte;
        i++;
    }

    return i;
}

void listar(Nodo *l){
    while(l!=NULL){
        cout << l->info.id << " ";
        l = l->sgte;
    }
    cout << endl;
}

void insertar(Nodo *&l, Cliente c){
    Nodo *n = new Nodo;
    n->info = c;
    n->sgte = NULL;

    if(l == NULL) l = n;
    else{
        Nodo *aux = l;
        while(aux->sgte != NULL){
            aux = aux->sgte;
        }

        aux->sgte = n;

    }
}