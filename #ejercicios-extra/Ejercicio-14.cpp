/*
* Crear la función exportar() que a partir de un archivo binario de registros,
* cree otro de texto con los atributos de cada registro de Aeronave separados por
* comas* (,).
* Por ejemplo:
*
* aeronaves.dat
*   id: 456
*   matricula: XVI-452
*   nombre: Tornado
*   horas de vuelo: 1455
*   fecha de baja: 0
*
* aeronaves.csv
*   456,XVI-452,Tornado,1455,0
*
*/
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//
// # Variables Globales
//
#define ARCHIVO_BINARIO "aeronaves.dat"
#define ARCHIVO_CSV "aeronaves.csv"

struct Aeronave{
	int id;
	char matricula[30];
	char nombre[30];
	int horasDeVuelo;
	int fechaDeBaja;
};

//
// # Prototipos
//
Aeronave crearAeronave(int, string, string, int, int);
void cargarAeronaves(Aeronave [], int &);
void cargarAeronave(Aeronave [], int &, int, string, string, int, int);
void cargarAeronavesArchivo(string, Aeronave [], int);
void exportar(string, string);

//
// # Main
//
int main(){	
	int cantidad = 0;
	Aeronave aeronaves[10];
	
	cargarAeronaves(aeronaves, cantidad);
	cargarAeronavesArchivo(ARCHIVO_BINARIO, aeronaves, cantidad);
	exportar(ARCHIVO_BINARIO, ARCHIVO_CSV);
	
	return 0;
}

//
// # Funciones
//
Aeronave crearAeronave(int id, string matricula, string nombre, int horasDeVuelo, int fechaDeBaja){
	Aeronave a;
	
	a.id = id;
	strcpy(a.matricula, matricula.c_str()); 
	strcpy(a.nombre, nombre.c_str());
	a.horasDeVuelo = horasDeVuelo;
	a.fechaDeBaja = fechaDeBaja;
	
	return a;
}

void cargarAeronave(Aeronave lista[], int &cantidad, int id, string matricula, string nombre, int horasDeVuelo, int fechaDeBaja){
	lista[cantidad] = crearAeronave(id, matricula, nombre, horasDeVuelo, fechaDeBaja);

	cantidad++;
}
    
void cargarAeronaves(Aeronave lista[], int &cantidad){
    cargarAeronave(lista, cantidad, 455, "XVI441", "TORNADITO", 144, 1);
    cargarAeronave(lista, cantidad, 456, "XVI441", "TORNADITO", 145, 1);
    cargarAeronave(lista, cantidad, 457, "XVI441", "TORNADITO", 146, 1);
}

void cargarAeronavesArchivo(string nombreArchivo, Aeronave lista[], int cantidad){
    FILE *f;
    Aeronave a;
    // abro el archivo en modo escritura para binario
    f = fopen(nombreArchivo.c_str(), "wb");
    // verifico que puedo abrir el archivo
    if(f != NULL){
        fwrite(lista, sizeof(Aeronave), cantidad, f);
    }
    fclose(f);
}

void exportar(string nombreArchivo1, string nombreArchivo2){
	FILE *f1, *f2;
	Aeronave a;

	// abro el archivo en modo lectura para binario
	f1 = fopen(nombreArchivo1.c_str(), "rb");
    // abro el archivo en modo escritura de texto plano
	f2 = fopen(nombreArchivo2.c_str(), "w");

    // verifico que puedo abrir ambos archivos
    if(f1 != NULL && f2 != NULL){
        // obtengo la primera linea del archivo f1
        fread(&a, sizeof(Aeronave), 1, f1);
        // ejecuto el while hasta llegar al final del archivo f1
        while(!feof(f1)){
            // le doy formato a los registros del archivo f1 (archivo binario)
            // y los guardo en el archivo f2 (texto plano)
            fprintf(f2, "%i, %s, %s, %i, %i \n", a.id, a.matricula, a.nombre, a.horasDeVuelo, a.fechaDeBaja);
            // obtengo cada linea del archivo f1
            fread(&a, sizeof(Aeronave), 1, f1);
        }
    }    

	fclose(f1);
	fclose(f2);
}
