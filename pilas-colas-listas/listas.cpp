#include <iostream>

using namespace std;

//
// # Structs
//
struct Estudiante{
    int dni;
    string nombre;    
};

struct Nodo{
    Estudiante info;
    Nodo *sgte;
};

//
// # Variables Globales
//
Nodo *LISTA = NULL; // Variables global

//
// # Prototipos
//
// prototipos básicos
Estudiante crearEstudiante(int dni, string nombre);
void mostrarDatos(Estudiante e);

// prototipos para listas
Nodo *insertarAlFinal(Nodo *&l, Estudiante e);
Nodo *insertarOrdenado(Nodo *&l, Estudiante e);
void ordenarLista(Nodo *&l);
void listarLista(Nodo *l);
void eliminar(Nodo *&l, int v);
Estudiante eliminarPrimerNodo(Nodo *&l);
Nodo *buscar(Nodo *&l, int v);
Nodo *buscaEInserta(Nodo *&l, int v);

//
// # Main
//
int main(){
    insertarAlFinal(LISTA, crearEstudiante(109, "pedro"));
    insertarAlFinal(LISTA, crearEstudiante(105, "carlos"));
    insertarAlFinal(LISTA, crearEstudiante(104, "meme"));
    insertarAlFinal(LISTA, crearEstudiante(101, "julian"));

    eliminar(LISTA, 109);
    ordenarLista(LISTA);    
    listarLista(LISTA);

    /*
    Nodo *estudiante = buscar(LISTA, 101);
    mostrarDatos(estudiante->info);

    buscaEInserta(LISTA, 104);
    buscaEInserta(LISTA, 102);

    listarLista(LISTA);
    */

    return 0;
}

//
// # Funciones
//
Estudiante eliminarPrimerNodo(Nodo *&l){
    Estudiante e = l->info;
    Nodo *aux = l;
    l = l->sgte;
    delete aux;

    return e;
}

void ordenarLista(Nodo *&l){
    Nodo *listaOrdenada = NULL;

    while(l != NULL){
        Estudiante e = eliminarPrimerNodo(l);
        insertarOrdenado(listaOrdenada, e);
    }

    l = listaOrdenada;
}

Nodo *insertarOrdenado(Nodo *&l, Estudiante e){
    Nodo *nuevo = new Nodo;
    nuevo->info = e;
    nuevo->sgte = NULL;

    Nodo *aux = l, *ant = NULL;

    while(aux != NULL && aux->info.dni <= e.dni){
        ant = aux;
        aux = aux->sgte;
    }

    if(ant == NULL){
        l = nuevo;
    }
    else{
        ant->sgte = nuevo;
    }

    nuevo->sgte = aux;

    return nuevo;
}

Nodo *buscaEInserta(Nodo *&l, int v){
    Nodo *nodo = buscar(l, v);
    bool enc = (nodo != NULL);

    if(!enc){
        insertarAlFinal(l, crearEstudiante(v, ""));
    }

    return nodo;
}

Nodo *buscar(Nodo *&l, int v){
    Nodo *aux = l;

    while(aux != NULL && aux->info.dni != v){
        aux = aux->sgte;
    }

    // si lo encuentra retorna el nodo,
    // sino lo encuentra retorna NULL porque llegó al final de la lista auxiliar que apunta a NULL
    return aux;
}

void eliminar(Nodo *&l, int v){
    Nodo *aux = l, *ant = NULL;

    while(aux != NULL && aux->info.dni != v){
        ant = aux;
        aux = aux->sgte;
    }

    // si no tiene anterior
    // entonces es el primer elemento    
    if(ant == NULL){
        // hago que el principio de la lista apunte al siguiente del primer nodo
        l = aux->sgte;
    }
    else{
        ant->sgte = aux->sgte;
    }

    delete aux;
}

void listarLista(Nodo *l){
    while(l != NULL){
        mostrarDatos(l->info);

        l = l->sgte;
    }
}

Nodo *insertarAlFinal(Nodo *&l, Estudiante v){
    Nodo *nuevo = new Nodo;
    nuevo->info = v;
    nuevo->sgte = NULL;

    if(l == NULL){
        l = nuevo;
    }
    else{
        Nodo *aux = l;

        while(aux->sgte != NULL){
            aux = aux->sgte;
        }

        aux->sgte = nuevo;
    }

}

void mostrarDatos(Estudiante e){
    cout << e.dni << ", " << e.nombre << endl;
}

Estudiante crearEstudiante(int dni, string nombre){
    Estudiante e;
    e.dni = dni;
    e.nombre = nombre;

    return e;
}