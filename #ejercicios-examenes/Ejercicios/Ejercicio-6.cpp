#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct Nodo{
    int dato;
    Nodo *sgte;
};

struct Persona{
    string nombre;
    int edad;
};

Nodo *buscaEinsertaOrdenado(Nodo *&l, int x, bool &enc);
Nodo *buscar(Nodo *&l, int x);
void insertar(Nodo *&l, int x);
Nodo *insertarOrdenado(Nodo *&l, int x);
void eliminar(Nodo *&l, int x);
void listar(Nodo *l);
void imprimirPersona(Persona p){
    cout << p.nombre << " " << p.edad << endl;
}

Nodo *lista = NULL;
Nodo *listaOrdenada = NULL;

int main(){
    /*********************************************************/
    // Probando si puedo volcar todo un registro en otro vacio
    Persona p1, p2, p3;
    p1.edad = 3;
    p1.nombre = "carlos";
    imprimirPersona(p1);

    p2 = p1;
    imprimirPersona(p2);

    /*********************************************************/
    // probando insertar y eliminar
    insertar(lista, 5);
    insertar(lista, 7);
    insertar(lista, 2);
    eliminar(lista, 2);

    listar(lista);

    /*********************************************************/
    // probando insertar ordenado
    insertarOrdenado(listaOrdenada, 5);
    insertarOrdenado(listaOrdenada, 6);
    insertarOrdenado(listaOrdenada, 1);
    insertarOrdenado(listaOrdenada, 3);

    listar(listaOrdenada);

    /*********************************************************/
    // probando buscar e insertar sino existe
    
    bool enc = false;
    buscaEinsertaOrdenado(listaOrdenada, 9, enc);

    listar(listaOrdenada);
    
    return 0;
}

Nodo *buscar(Nodo *&l, int x){
    Nodo *aux = l;
    while(aux != NULL && aux->dato != x){
        aux = aux->sgte;
    }

    return aux;
}

Nodo *buscaEinsertaOrdenado(Nodo *&l, int x, bool &enc){
    Nodo *n = buscar(l, x);
    enc = (n != NULL);

    if(!enc){
        n = insertarOrdenado(l, x);
    }

    return n;
}

Nodo *insertarOrdenado(Nodo *&l, int x){
    Nodo *n = new Nodo;
    n->dato = x;
    n->sgte = NULL;

    Nodo *aux = l, *ant = NULL;

    // 1. si la lista no está vacía
    // 2. el dato a insertar es mayor al que apunta la lista
    // # Ej. lista vacía
    // Voy a insertar el número 5, como aux apunta a lo mismo que la lista,
    // y la lista apunta a NULL porque está vacía, entonces la condición del while
    // no se cumple, y no llega a recorrer ningún elemento
    // quedando ant = NULL
    //
    // # Ej con 1 nodo:
    // La lista solo tiene el número 5, la lista apunta al 5, y si agrego el 6, 
    // ese 6 es mayor al dato que apunta la lista que era 5.
    //
    // #Ej con 2 nodos:
    // La lista tiene los números {5,6}, inserto el número 1,
    // como el 1 no es mayor al primer elemento que apunta la lista (el 5)
    // entonces no se cumple una de las condiciones del while, y no lo recorre
    // quedando ant = NULL

    while(aux != NULL && aux->dato <= x){
        ant = aux;
        aux = aux->sgte;
    }

    // si ant == NULL, es xq no entró por el while
    // y puede ser que la lista está vacía ó que el elemento sea menor al primer nodo 
    // que apuntaba la lista
    if(ant == NULL){
        // si esta vacía hago que apunte al nodo
        l = n;
    }
    // si ant != NULL, entonces la lista no está vacía
    else{
        // enlazo el anterior (que es menor al que voy a insertar) con el nodo
        ant->sgte = n;
    }

    // sin importar si la lista está vacía o no
    // (si no pasó por el while ) enlazo como siguiente del nodo, al primero que apuntaba la lista
    // (si entró por el while) enlazo como siguiente al nodo, el que fuese mayor a él
    n->sgte = aux;

    return n;
}


void eliminar(Nodo *&l, int x){
    Nodo *aux = l, *ant = NULL;

    while(aux != NULL && aux->dato != x){
        ant = aux;
        aux = aux->sgte;
    }

    if(ant){
        ant->sgte = aux->sgte;
    }else{
        l = aux->sgte;
    }

    delete aux;
}

void listar(Nodo *l){
    while(l != NULL){
        cout << l->dato << " ";

        l = l->sgte;
    }
    cout << endl;
}

void insertar(Nodo *&l, int x){
    Nodo *n = new Nodo;
    n->dato = x;
    n->sgte = NULL;

    if(l == NULL) l = n;
    else{
        Nodo *aux = l;
        while(aux->sgte != NULL) aux = aux->sgte;
        aux->sgte = n;
    }
}