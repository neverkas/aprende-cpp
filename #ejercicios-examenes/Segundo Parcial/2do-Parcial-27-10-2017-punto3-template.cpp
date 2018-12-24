/*
*
* VIDEOJUEGO
*
* Se debe crear una función que cargue en memoria el historial de partidos de fútbol disputado
* por cada equipo desde un archivo binario de registros. El videojuego agrupa los datos históricos en un array
* de hasta 255 equipos, donde se espera que cada elemento del array permita acceder al conjunto de registros
* históricos de cada equipo ordenados por el campo fecha. El archivo posee registros con los datos de todos
* los partidos jugados por cada equipo.
* Cada registro de partido posee la siguiente estructura:
*
* -id_equipo:entero (0-254)
* -id_partido: entero
* -fecha: entero largo
* -puntos: entero
* -jugadores: array de enteros [18]
*
* El campo fecha contiene el resultado de llamar a la función time(NULL) de la biblioteca time.h, por lo tanto
* es un valor entero desde donde es posible obtener la secuencia de partidos.
* Se pide: Crear la función cargarHistorico() que recibe por parámetro, el array (con todos los elementos
* inicializados en NULL), la ruta al archivo y deberá:
* 1) leer y agrupar todos los registros de partidos por id_equipo
* 2) enlazar todos los partidos ascendentemente (0-9) según el valor del campo fecha, siendo
* que los registros pueden haber sido guardados en el archivo sin contemplar ningún tipo de orden.
* Crear las estructuras necesarias.
*
*/

#include <iostream>
#include <stdio.h> // fopen(), fwrite(), fread(), etc..
#include <time.h>
#include <string.h> // c_str()

using namespace std;

#define ARCHIVO_NOMBRE "historial-partidos.dat"
#define CANT_JUGADORES 4 // enunciado: 18
#define CANT_EQUIPOS 5 // enunciado: 255

template <typename T>
struct Nodo{
    T info;
    Nodo *sig;
};

struct Equipo{
    int id_equipo;
    int id_partido;
    int fecha;
    int puntos;
    int jugadores[CANT_JUGADORES];
};

Equipo crearEquipo(int id_equipo, int id_partido, int fecha, int puntos, int jugadores[]){
    Equipo e;
    e.id_equipo = id_equipo;
    e.id_partido = id_partido;
    e.fecha = fecha;
    e.puntos = puntos;

    for(int i=0; i < CANT_JUGADORES; i++){
        e.jugadores[i] = jugadores[i];
    }

    return e;
}

void asignarJugadores(int arr[], int n1, int n2, int n3, int n4){
    arr[0] = n1;
    arr[1] = n2;
    arr[2] = n3;
    arr[3] = n4;
}

void crearEquipos(Equipo arr[]){
    int jugadores[CANT_JUGADORES];
    int id_partido;

    // crearEquipo(int id_equipo, int id_partido, int fecha, int puntos, int jugadores[])

    // # partido 1
    id_partido = 1;
    asignarJugadores(jugadores, 1,2,3,4);
    arr[0] = crearEquipo(1, id_partido, time(NULL), 10, jugadores);

    asignarJugadores(jugadores, 1,2,3,4);
    arr[1] = crearEquipo(2, id_partido, time(NULL), 5, jugadores);

    asignarJugadores(jugadores, 1,2,3,4);
    arr[2] = crearEquipo(3, id_partido, time(NULL), 3, jugadores);

    // # partido 2;
    id_partido = 2;

    asignarJugadores(jugadores, 1,2,3,4);
    arr[3] = crearEquipo(4, id_partido, time(NULL), 10, jugadores);

    asignarJugadores(jugadores, 1,2,3,4);
    arr[4] = crearEquipo(5, id_partido, time(NULL), 10, jugadores);
}

void cargarEquiposArchivo(string nombre, Equipo equipos[], int cantEquiposCargados){
    FILE *f;
    f = fopen(nombre.c_str(), "wb");
    //fwrite(&equipo, sizeof(Equipo), cantEquiposCargados, f);
    for(int i=0; i < cantEquiposCargados; i++){
        fwrite(&equipos[i], sizeof(Equipo), 1, f);
    }
    fclose(f);
}

void mostrarArchivo(string nombre){
    FILE *f;
    Equipo equipo;
    f = fopen(nombre.c_str(), "rb");

    fread(&equipo, sizeof(Equipo), 1, f);
    while(!feof(f)){
        printf("fecha: %i, id_equipo: %i, id_partido: %i, puntos: %i, ", equipo.fecha, equipo.id_equipo, equipo.id_partido, equipo.puntos);
        cout << "jugadores:";
        for(int i=0; i < CANT_JUGADORES; i++){
            cout << equipo.jugadores[i] << "-";
        }
        cout << endl;

        fread(&equipo, sizeof(Equipo), 1, f);
    }
    fclose(f);
}

template <typename T>
T *insertarOrdenado(Nodo<T> *&lista, T v, int (*criterio)(T, T)){
    Nodo<T> *nuevo = new Nodo<T>();
    nuevo->info = v;
    nuevo->sig = NULL;
    
    Nodo<T> *aux = lista;
    Nodo<T> *ant = NULL;
    
    while(aux != NULL && criterio(aux->info, v) <= 0){
        ant = aux;
        aux = aux->sig;
    }

    if(ant == NULL){
        lista = nuevo;
    }
    else{
        ant->sig = nuevo;
    }

    nuevo->sig = aux;
    
}

int criterioIdEquipoAsc(Equipo e1, Equipo e2){    
    return e1.id_equipo - e2.id_equipo;
}

void cargarHistorico(Nodo<Equipo> *equipos[], string nombreArchivo){
    FILE *f;
    Equipo equipo;
    f = fopen(nombreArchivo.c_str(), "rb");

    fread(&equipo, sizeof(Equipo), 1, f);
    while(!feof(f)){
        insertarOrdenado<Equipo>(equipos[equipo.id_equipo], equipo, criterioIdEquipoAsc);

        fread(&equipo, sizeof(Equipo), 1, f);
    }
    fclose(f);
}

void mostrarHistorico(Nodo<Equipo> *listado[]){
    for(int i=0; i<CANT_EQUIPOS; i++){
        Nodo<Equipo> *aux = listado[i];
        
        while(aux != NULL){
            Equipo equipo = aux->info;
            //cout << aux->info.id_partido << endl;
            printf("fecha: %i, id_equipo: %i, id_partido: %i, puntos: %i \n", equipo.fecha, equipo.id_equipo, equipo.id_partido, equipo.puntos);

            aux = aux->sig;
        }
    }
}

int main(){
    /*
    // creo el array donde asignar los equipos
    Equipo equipo, equipos[CANT_EQUIPOS];
    int cantEquiposCargados;
    // asigno los equipos al array   
    crearEquipos(equipos);
    cantEquiposCargados = sizeof(equipos) / sizeof(equipos[0]);
    // cargarEquiposArchivo() lo utilizo una única vez para cargar los equipos al archivo binario
    cargarEquiposArchivo(ARCHIVO_NOMBRE, equipos, cantEquiposCargados);
    cout << "ARCHIVO BINARIO: " << endl;
    mostrarArchivo(ARCHIVO_NOMBRE);
    cout << endl;
    */

    Nodo<Equipo> *equipos[CANT_EQUIPOS] = {NULL};
    cargarHistorico(equipos, ARCHIVO_NOMBRE);
    mostrarHistorico(equipos);

    return 0;
}