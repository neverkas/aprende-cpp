#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>

using namespace std;

#define NOMBRE_ARCHIVO "goles-mundial.dat"
#define CANT_EQUIPOS 32
#define CANT_PARTIDOS 64

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

struct GoleadorPorFecha{
    int fecha;
    int cod_equipo;
    Nodo<Goleador> *goleadores;    
    GoleadorPorFecha *sig;
};

void imprimirArchivo();
void mostrarInfoEquipo(Equipo e);
template <typename T>void mostrar(Nodo<T> *p);
template <typename T>void insertar(Nodo<T> *&p, T v);
template <typename T>Nodo<T> *buscar(Nodo<T> *lista, T v, int (criterio(T, T)));
GoleadorPorFecha *buscarFecha(GoleadorPorFecha *lista, int fecha);

int criterioGoleadorCod(Goleador e1, Goleador e2);
int criterioEquipoCod(Equipo e1, Equipo e2);
int criterioGoleadorNombre(Goleador g1, Goleador g2);
int criterioFecha(GoleadorPorFecha f1, GoleadorPorFecha f2);

Nodo<Equipo> *mostrarGolesPorEquipo();
GoleadorPorFecha *mostrarGoleadoresPorFecha();
template <typename T>void mostrar(Nodo<T> *lista, void (*criterio)(T));
GoleadorPorFecha insertarFecha(GoleadorPorFecha *&lista, int fecha);

void mostrarGoleadorInfo(Goleador g);
void mostrarGoleador(GoleadorPorFecha *lista);
void mostrarFechas(GoleadorPorFecha *lista);
template <typename T>void mostrarListaSublista(T *lista, void (*criterio)(T));


int main(){
    Nodo<Equipo> *listaEquipos = NULL;
    GoleadorPorFecha *listaGoleadoresPorFecha = NULL;

    cout << "listado original: " << endl;
    imprimirArchivo();
    cout << endl;

    cout << "listado goles por equipo:" << endl;
    listaEquipos = mostrarGolesPorEquipo();
    mostrar<Equipo>(listaEquipos, mostrarInfoEquipo);
    
    cout << "listado con los goleadores por fecha: " << endl;
    listaGoleadoresPorFecha = mostrarGoleadoresPorFecha();
    mostrarFechas(listaGoleadoresPorFecha);
    //mostrarListaSublista<GoleadorPorFecha>(listaGoleadoresPorFecha, mostrarGoleador);

    return 0;
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

void mostrarGoleadorInfo(Goleador g){
    printf("nombre: %s, cantGoles: %i \n", g.nombre_jugador, g.cantidadGoles);
}

void mostrarGoleador(GoleadorPorFecha *lista){
    cout << "Fecha: " << lista->fecha << endl;
    cout << "Goleadores: " << endl;

    Nodo<Goleador> *aux = lista->goleadores;

    while(aux != NULL){
        mostrarGoleadorInfo(aux->info);

        aux = aux->sig;                 
    }

    cout << endl;
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

void mostrarFechas(GoleadorPorFecha *lista){    
    GoleadorPorFecha *aux = lista;

    while(aux != NULL){        
        mostrarGoleador(aux);
        aux = aux->sig;
    }
}


GoleadorPorFecha *buscarFecha(GoleadorPorFecha *lista, int fecha){
    GoleadorPorFecha *aux = lista;
    while(aux != NULL && aux->fecha != fecha){
        aux = aux->sig;
    }

    return aux;

}

GoleadorPorFecha *mostrarGoleadoresPorFecha(){
    Gol gol;
    GoleadorPorFecha *lista = NULL;

    FILE *f = fopen(NOMBRE_ARCHIVO, "rb");        
    fread(&gol, sizeof(Gol), 1, f);
    while(!feof(f)){
        GoleadorPorFecha goleadorPorFecha;
        goleadorPorFecha.fecha = gol.fecha;
 
        Goleador goleador;
        goleador.cod_equipo = gol.cod_equipo;
        strcpy(goleador.nombre_jugador, gol.nombre_jugador);

        GoleadorPorFecha *encontrarFecha = buscarFecha(lista, gol.fecha);        
        if(encontrarFecha == NULL){
            insertarFecha(lista, gol.fecha);
            encontrarFecha = buscarFecha(lista, gol.fecha);        
        }

        // ARREGLAR ACA
        Nodo<Goleador> *goleadorEncontrado = buscar<Goleador>(encontrarFecha->goleadores, goleador, criterioGoleadorCod);
        //Nodo<Goleador> *goleadorEncontrado = buscar<Goleador>(encontrarFecha->goleadores, goleador, criterioGoleadorNombre);
        
        if(goleadorEncontrado)
            goleadorEncontrado->info.cantidadGoles += 1;
        else{
            goleador.cantidadGoles = 1;
            insertar<Goleador>(encontrarFecha->goleadores, goleador);
        }

        fread(&gol, sizeof(Gol), 1, f);
    }
    fclose(f);

    return lista;
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

void mostrarInfoGoleador(Goleador g){
    printf("goleador: %s, cantidadGoles: %i \n", g.nombre_jugador, g.cantidadGoles);
}

GoleadorPorFecha insertarFecha(GoleadorPorFecha *&lista, int fecha){
    GoleadorPorFecha *nuevo = new GoleadorPorFecha();
    nuevo->fecha = fecha;
    nuevo->sig = NULL;

    if(lista == NULL){
        lista = nuevo;
    }
    else{
        GoleadorPorFecha *aux = lista;
        while(aux->sig != NULL)
            aux = aux->sig;

        aux->sig = nuevo;
    } // end if
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

int criterioGoleadorCod(Goleador e1, Goleador e2){
    return e1.cod_equipo - e2.cod_equipo;
}
int criterioEquipoCod(Equipo e1, Equipo e2){
    return e1.cod_equipo - e2.cod_equipo;
}
int criterioGoleadorNombre(Goleador g1, Goleador g2){
    return (g1.nombre_jugador < g2.nombre_jugador) ? -1 : (g2.nombre_jugador < g1.nombre_jugador) ? 1 : 0;
}

int criterioFecha(GoleadorPorFecha g1, GoleadorPorFecha g2){
    return g1.fecha - g2.fecha;
}