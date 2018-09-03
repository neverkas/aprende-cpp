/*
*
* El sorteo de la fase de grupos del Mundial de Fútbol se inicia agrupando a los 32 equipos clasificados
* en 4 bolilleros de 8 equipos cada uno, ordenados de acuerdo al FIFA ranking. Los mejores
* pertenecen al bolillero 1 (salvo Rusia que es el anfitrión), los equipos que están por debajo en el
* ranking se asignan al bolillero 4; conforme a este ranking se forma la siguiente Tabla: 
*
* BOLILLERO 1 BOLILLERO 2 BOLILLERO 3 BOLILLERO 4
* Rusia 		España 		Dinamarca 	Serbia
* Alemania 		Perú 		Islandia 	Nigeria
* Brasil 		Suiza 		Costa Rica 	Australia
* Portugal 		Inglaterra 	Suecia 		Japón
* Argentina 	Colombia 	Túnez 		Marruecos
* Bélgica 		México 		Egipto 		Panamá
* Polonia 		Uruguay 	Senegal 	Corea del Sur
* Francia 		Croacia 	Irán Arabia Saudita
*
* Se solicita generar un archivo binario con los equipos clasificados al mundial conforme a la tabla
* detallada precedentemente. Cada registro debe contener como mínimo los siguientes campos:
* 	-Número de bolillero
* 	-Nombre de equipo
* 	-Confederación
* Se debe generar ordenado por número de bolillero.
* Las Confederaciones continentales aglutinan a un conjunto de países, son seis (6) y se detallan a continuación:
* 	-AFC: Copa Asiática (países de Asia, excepto Israel , Kazajistán y Turquía ; más Australia, Islas
* Marianas del Norte y Guam).
* 	-CAF: Copa Africana de Naciones (países de África).
* 	-Concacaf: Copa Concacaf (América del Norte, América Central, las islas del Caribe, Guyana, Surinam y Guayana Francesa).
* 	-Conmebol: Copa América (países de América del Sur, excepto Guyana, Surinam y Guayana Francesa, más dos invitados).
* 	-OFC: Copa de las Naciones (países de Oceanía excepto Australia, Islas Marianas del Norte, Guam y Palaos).
* 	-UEFA: Eurocopa (países de Europa, Israel , Kazajistán y Turquía).
*
*/

#include <iostream>
#include <stdio.h> // fopen(), fwrite(), fread()
#include <string.h> // NULL, c_str(), strcpy()

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
#define ARCHIVO_EQUIPOS_CLASIFICADOS "equipos-clasificados.dat"

//
// # PROTOTIPOS
//
void cargarEquiposArchivo(Equipo []);
Equipo crearEquipo(int, string, string);
void cargarEquipos(Equipo []);

//
// # MAIN
//
int main(){
	Equipo equipos[EQUIPOS_TOTAL];
	// Creo los equipos y los guardo en 'equipos'
	cargarEquipos(equipos);
	// Creo un archivo y guardo 'equipos'
	cargarEquiposArchivo(equipos);

    return 0;
}

//
// # FUNCIONES
//
void cargarEquiposArchivo(Equipo equipos[]){
	FILE *f;
	// abro el archivo en modo 'wb' para crear el archivo binario y escribir en el mismo
	f = fopen(ARCHIVO_EQUIPOS_CLASIFICADOS, "wb");

	if(f != NULL){
		fwrite(equipos, sizeof(Equipo), EQUIPOS_TOTAL, f);
		cout << "Se ha creado el archivo " << ARCHIVO_EQUIPOS_CLASIFICADOS << " con los equipos clasificados." << endl;
	}
	
	fclose(f);
}

Equipo crearEquipo(int bolillero, string nombre, string confederacion){
    Equipo equipo;
	equipo.bolillero = bolillero;
	strcpy(equipo.nombre, nombre.c_str());
	strcpy(equipo.confederacion, confederacion.c_str());	
	
	return equipo;
}

void cargarEquipos(Equipo equipos[]){
	int bolillero;

	// Bolillero 1
	bolillero = 1;
	equipos[0] = crearEquipo(bolillero, "Rusia", "UEFA");
	equipos[1] = crearEquipo(bolillero, "Alemania", "UEFA");
	equipos[2] = crearEquipo(bolillero, "Brasil", "CONMEBOL");
	equipos[3] = crearEquipo(bolillero, "Portugal", "UEFA");
	equipos[4] = crearEquipo(bolillero, "Argentina", "CONMEBOL");
	equipos[5] = crearEquipo(bolillero, "Belgica", "UEFA");
	equipos[6] = crearEquipo(bolillero, "Polonia", "UEFA");
	equipos[7] = crearEquipo(bolillero, "Francia", "UEFA");
	
	// Bolillero 2
	bolillero = 2;
	equipos[8] = crearEquipo(bolillero, "Espania", "UEFA");
	equipos[9] = crearEquipo(bolillero, "Peru", "CONMEBOL");
	equipos[10] = crearEquipo(bolillero, "Suiza", "UEFA");
	equipos[11] = crearEquipo(bolillero, "Inglaterra", "UEFA");
	equipos[12] = crearEquipo(bolillero, "Colombia", "CONMEBOL");
	equipos[13] = crearEquipo(bolillero, "Mexico", "CONCACAF");
	equipos[14] = crearEquipo(bolillero, "Uruguay", "CONMEBOL");
	equipos[15] = crearEquipo(bolillero, "Croacia", "UEFA");

	// Bolillero 3	
	bolillero = 3;
	equipos[16] = crearEquipo(bolillero, "Dinamarca", "UEFA");
	equipos[17] = crearEquipo(bolillero, "Islandia", "UEFA");
	equipos[18] = crearEquipo(bolillero, "Costa Rica", "CONCACAF");
	equipos[19] = crearEquipo(bolillero, "Suecia", "UEFA");
	equipos[20] = crearEquipo(bolillero, "Tunez", "CAF");
	equipos[21] = crearEquipo(bolillero, "Egipto", "CAF");
	equipos[22] = crearEquipo(bolillero, "Senegal", "CAF");
	equipos[23] = crearEquipo(bolillero, "Iran", "AFC");
	
	// Bolillero 4
	bolillero = 4;
	equipos[24] = crearEquipo(bolillero, "Serbia", "UEFA");
	equipos[25] = crearEquipo(bolillero, "Nigeria", "CAF");
	equipos[26] = crearEquipo(bolillero, "Australia", "AFC");
	equipos[27] = crearEquipo(bolillero, "Japon", "AFC");
	equipos[28] = crearEquipo(bolillero, "Marruecos", "CAF");
	equipos[29] = crearEquipo(bolillero, "Panama", "CONCACAF");
	equipos[30] = crearEquipo(bolillero, "Corea del Sur", "AFC");
	equipos[31] = crearEquipo(bolillero, "Arabia Saudita", "AFC");    
}