/*
*
* Procesar los archivos generados en el punto anterior (Ejercicio 2) para cargar un Array donde cada
* elemento tiene la siguiente estructura:
*   -Nombre de Equipo
*   -Letra de Grupo
*   -Confederación
*
* Se solicita mostrar por pantalla el contenido del array ordenado por los siguientes criterios:
*   -Número de Grupo.
*   -Nombre de equipo.
*   -Confederación.
*   -Número de Grupo y confederación.
*   -Número de Grupo, confederación y nombre de equipo
*
*/
#include <iostream>
#include <stdio.h> // sprintf(), fopen(), fwrite(), fread()
#include <iomanip> // setw()
#include <string.h> // NULL

using namespace std;

//
// # STRUCTS
//
struct Equipo{
	int bolillero;
	char nombre[30];
	char confederacion[30];
	char grupo;
};

//
// # VARIABLES GLOBALES
//
#define EQUIPOS 4
#define GRUPOS 8
#define EQUIPOS_TOTAL 32 

//
// # PROTOTIPOS
//
void agregarArchivosArray(Equipo []);

template <typename T> void ordenar(T arr[], int len, int (*criterio)(T,T));
int criterioLetraGrupo(Equipo e1, Equipo e2);
int criterioNombreEquipo(Equipo e1, Equipo e2);
int criterioConfederacion(Equipo e1, Equipo e2);

template <typename T> void mostrarListado(Equipo listado[], int len, void (*mostrarFila)(T));
void mostrarFila(Equipo);

//
// # MAIN
//
int main(){
	Equipo listado[EQUIPOS_TOTAL];
    agregarArchivosArray(listado);

    // Ordeno el vector por Letra de Grupo
    cout << "Listado ordenado por Letra de Grupo:" << endl;
    ordenar(listado, EQUIPOS_TOTAL, criterioLetraGrupo);
    mostrarListado(listado, EQUIPOS_TOTAL, mostrarFila);
    cout << endl;

    // Ordeno el vector por Nombre de Equipo
    cout << "Listado ordenado por Nombre de Equipo:" << endl;
    ordenar(listado, EQUIPOS_TOTAL, criterioNombreEquipo);
    mostrarListado(listado, EQUIPOS_TOTAL, mostrarFila);
    cout << endl;

    // Ordeno el vector por Confederacion
    cout << "Listado ordenado por Confederacion:" << endl;
    ordenar(listado, EQUIPOS_TOTAL, criterioConfederacion);
    mostrarListado(listado, EQUIPOS_TOTAL, mostrarFila);
    cout << endl;

    return 0;
}

//
// # FUNCIONES
//
void agregarArchivosArray(Equipo listado[]){
    FILE *f;
    char nombreArchivo[30];
    Equipo equipo;

    int contadorEquipos = 0;    
    for(int i=0; i < GRUPOS; i++){
        sprintf(nombreArchivo, "grupo_%c.dat", 'A'+i);
        
        // abro el archivo en modo lectura
        f = fopen(nombreArchivo, "rb");

        if(f != NULL){
        fread(&equipo, sizeof(Equipo), 1, f);
            while(!feof(f)){
                listado[contadorEquipos] = equipo;

                fread(&equipo, sizeof(Equipo), 1, f);
                contadorEquipos++;
            }
        }

        fclose(f);
    }    
}

int criterioLetraGrupo(Equipo e1, Equipo e2) {
    return e1.grupo > e2.grupo ? 1 : e1.grupo < e2.grupo ? -1 : 0;
}
int criterioNombreEquipo(Equipo e1, Equipo e2) {
    return string(e1.nombre) > string(e2.nombre) ? 1 : string(e1.nombre) < string(e2.nombre) ? -1 : 0;
}
int criterioConfederacion(Equipo e1, Equipo e2) {
    return string(e1.confederacion) > string(e2.confederacion) ? 1 : string(e1.confederacion) < string(e2.confederacion) ? -1 : 0;
}

template <typename T> void ordenar(T arr[], int len, int (*criterio)(T,T)){
    bool ordenado=false;
    while(!ordenado){
        ordenado=true;
        for(int i=0; i<len-1; i++){
            if( criterio(arr[i],arr[i+1])>0 ){
                T aux = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = aux;
                ordenado = false;
            }
        }
    }
}

template <typename T> void mostrarListado(Equipo listado[], int len, void (*mostrarFila)(T)){
    for(int i=0; i < len; i++){
        mostrarFila(listado[i]);
    }
}

void mostrarFila(Equipo e){
    cout << e.grupo << setw(10) << setw(20) << e.nombre << setw(10) << e.confederacion << endl;
}