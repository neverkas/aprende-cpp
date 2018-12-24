/*
*
* Crear la función aJson() donde, a partir de un array de registros Aeronave, cree uno de texto
* de acuerdo a la especificación de la siguiente página y como se ve en este ejemplo:
*
* Aeronave aeronaves[]
*   Id: 456
*   Matrícula: XVI-452
*   Nombre: Tornado
*   Horas de vuelo: 1455
*   Fecha de baja: 0
*
* aeronaves.json
*    {
*        "aeronaves": [
*        {
*        "id": "456",
*        "matricula": "XVI-452",
*        "nombre": "Tornado",
*        "horas-de-vuelo": "1455",
*        "fecha-de-baja: "0",
*        }
*        ]
*    }
*
*/
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

#define NOMBRE_ARCHIVO "aeronaves.json"

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
void cargarAeronaves(Aeronave []);
void exportar(Aeronave [], int);

//
// # Main
//
int main(){	
	int cantidad = 3;
	Aeronave aeronaves[10];
	
	cargarAeronaves(aeronaves);	
	exportar(aeronaves, cantidad);

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

void cargarAeronaves(Aeronave lista[]){
	lista[0] = crearAeronave(455, "XVI444", "TORNADITO", 144, 1);
	lista[1] = crearAeronave(454, "XVI444", "TORNADO2", 147, 1);
	lista[2] = crearAeronave(456, "XVI444", "TORNADO3", 145, 1);
}

void exportar(Aeronave lista[], int cantidad){	
	FILE *f;
    // abro el archivo en modo de escritura
	f = fopen(NOMBRE_ARCHIVO, "w");

    // verifico que pude crear el archivo
    if(f != NULL){
        fprintf(f, "{\n");
        fprintf(f, "\"aeronaves\":[\n");

        for(int i=0; i < cantidad; i++){
            fprintf(f, "\t{\n");
            fprintf(f, "\t\"id\":\"%i\",\n", lista[i].id);
            fprintf(f, "\t\"matricula\":\"%s\",\n", lista[i].matricula);
            fprintf(f, "\t\"nombre\":\"%s\",\n", lista[i].nombre);
            fprintf(f, "\t\"horas-de-vuelo\":\"%i\",\n", lista[i].horasDeVuelo);
            fprintf(f, "\t\"fecha-de-baja\":\"%i\"\n", lista[i].fechaDeBaja);	

            // compruebo si es el ultimo elemento            
            if(i == cantidad-1){
                fprintf(f, "\t}\n");
            }
            else{
                fprintf(f, "\t},\n");
            }
        } // end for

        fprintf(f, "]\n");
        fprintf(f, "}\n");

        cout << "Se exportaron con exito los datos al archivo " << NOMBRE_ARCHIVO << endl;
    } // end if

    fclose(f);
 }