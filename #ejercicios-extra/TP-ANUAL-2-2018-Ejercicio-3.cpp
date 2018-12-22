#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define NOMBRE_ARCHIVO "goles-mundial.dat"

template <typename T>
struct NodoArbol {
    T info;
    int contador;
    NodoArbol *izq;
    NodoArbol *der;
};

template <typename T>
struct Nodo{
    T info;
    Nodo *sig;
};

struct Gol{
    int id_gol;
    int cod_equipo;
    int fecha;
    char nombre_jugador[20];
    int id_partido;
};

struct Equipo{
    int cod_equipo;
    int cantidadGoles;    
};

struct Goleador{
    char nombre_jugador[20];
    int cod_equipo;
    int cantidadGoles;    
    Nodo<Goleador> *sig;
};

void imprimirArchivo();
void mostrarInfoEquipo(Equipo e);
template <typename T>void mostrar(Nodo<T> *p);
template <typename T>void insertar(Nodo<T> *&p, T v);
template <typename T>Nodo<T> *buscar(Nodo<T> *lista, T v, int (criterio(T, T)));

int criterioGoleadorCod(Goleador e1, Goleador e2);
int criterioEquipoCod(Equipo e1, Equipo e2);
int criterioGoleadorNombre(Goleador g1, Goleador g2);
int criterioEquipoGoles(Equipo e1, Equipo e2);

Nodo<Equipo> *mostrarGolesPorEquipo();
template <typename T>void mostrar(Nodo<T> *lista, void (*criterio)(T));

void mostrarGoleadorInfo(Goleador g);
template <typename T>void mostrarListaSublista(T *lista, void (*criterio)(T));
template <typename T>void insertarNodo(NodoArbol<T> *&nodo, T v, int(*criterio)(T, T));
template <typename T>void inOrden(NodoArbol<T>* nodo, void(*criterio)(T));

int main(){
    Nodo<Equipo> *lista = mostrarGolesPorEquipo();
    NodoArbol<Equipo> *raiz = NULL;

    while(lista != NULL){
        Equipo equipo = lista->info;
        insertarNodo(raiz, equipo, criterioEquipoGoles);
        lista = lista->sig;
    }

    inOrden<Equipo>(raiz, mostrarInfoEquipo);

    return 0;
}

template <typename T>
void insertarNodo(NodoArbol<T> *&nodo, T v, int(*criterio)(T, T)) {
    if(nodo==NULL) {
        nodo = new NodoArbol<T>();

        if(nodo!=NULL) {            
            nodo->info = v;
            nodo->contador = 1;
            nodo->izq=NULL;
            nodo->der=NULL;
        }
    }
    else {
        if(criterio(v, nodo->info) <= 0){
         insertarNodo(nodo->izq,v, criterio);
        }else{
            if(criterio(nodo->info, v) <= 0){
                insertarNodo(nodo->der,v, criterio);
            }          
            else{
                nodo->contador++;
            }
        }
    }
}

template <typename T>
void inOrden(NodoArbol<T>* nodo, void(*criterio)(T)) {
    if(nodo!=NULL) {
        inOrden(nodo->izq, criterio);
        criterio(nodo->info);
        //cout << nodo->contador << endl;
        inOrden(nodo->der, criterio);
    }
}

Nodo<Equipo> *mostrarGolesPorEquipo(){
    Gol gol;
    Nodo<Equipo> *lista = NULL;

    FILE *f = fopen(NOMBRE_ARCHIVO, "rb");        
    fread(&gol, sizeof(Gol), 1, f);
    while(!feof(f)){
        Equipo equipo;
        equipo.cod_equipo = gol.cod_equipo;
        Nodo<Equipo> *equipoEncontrado = buscar<Equipo>(lista, equipo, criterioEquipoCod);        
        
        if(equipoEncontrado)
            equipoEncontrado->info.cantidadGoles += 1;
        else{
            equipo.cantidadGoles = 1;
            insertar<Equipo>(lista, equipo);
        }

        fread(&gol, sizeof(Gol), 1, f);
    }
    fclose(f);

    return lista;
}

template <typename T>
void mostrar(Nodo<T> *lista, void (*criterio)(T)){
    Nodo<T> *aux = lista;
    while(aux != NULL){
        criterio(aux->info);

        aux = aux->sig;
    }
}
template <typename T>
void mostrarListaSublista(T *lista, void (*criterio)(T)){
    T *aux = lista;

    while(aux != NULL){
        //criterio(aux);
        aux = aux->sig;
    }
}


void imprimirArchivo(){
   Gol gol;
   FILE *f = fopen(NOMBRE_ARCHIVO, "rb");
   fread(&gol, sizeof(Gol), 1, f);
   while(!feof(f)){
       printf("id_gol:%i, cod_equipo:%i, id_partido:%i \n", gol.id_gol, gol.cod_equipo, gol.id_partido);

       fread(&gol, sizeof(Gol), 1, f);
   }
   fclose(f);
}

void mostrarInfoEquipo(Equipo e){
    printf("cod_equipo: %i, cantGoles: %i \n", e.cod_equipo, e.cantidadGoles);
    cout << endl;
}

template <typename T>
void insertar(Nodo<T> *&p, T v){
    Nodo<T> *nuevo = new Nodo<T>();
    nuevo->info = v;
    nuevo->sig = NULL;

    if(p == NULL)
        p = nuevo;
    else{
        Nodo<T> *aux = p;
        while(aux->sig != NULL){
            aux = aux->sig;
        }
        aux->sig  = nuevo;
    }

}

template <typename T>
Nodo<T> *buscar(Nodo<T> *lista, T v, int (criterio(T, T))){
    Nodo<T> *aux = lista;
    while(aux != NULL && criterio(aux->info, v) != 0){
        aux = aux->sig;
    }

    return aux;
}

int criterioEquipoCod(Equipo e1, Equipo e2){
    return e1.cod_equipo - e2.cod_equipo;
}
int criterioEquipoGoles(Equipo e1, Equipo e2){
    return e1.cantidadGoles - e2.cantidadGoles;
}
