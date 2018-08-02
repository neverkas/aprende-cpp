#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

// STRUCTS
struct Equipo{
	int bolillero;
	char nombre[30];
	char confederacion[30];
	char grupo;
};

// VARIABLES GLOBALES
const int EQUIPOS = 4;
const int GRUPOS = 8;
const int EQUIPOS_TOTAL = (GRUPOS*EQUIPOS);
char GRUPO_ARGENTINA, GRUPO_BRASIL; // se reutiliza en sortear_bolillero_2()
char ARCHIVO_EQUIPOS_CLASIFICADOS[30] = "equipos-clasificados.dat";

// PROTOTIPOS
Equipo cargar_equipo(FILE *, const char []);
Equipo cargar_equipos();
Equipo listado_equipos();
Equipo agregar_equipo_al_grupo(Equipo, char);

void crear_archivos_por_grupo();
void sortear_fase_grupos();
void sortear_bolillero(int);
void sortear_bolillero_1(Equipo);
void sortear_bolillero_2(Equipo);

char letra_random(char [], int &);

// MAIN
int main(){
	srand(time(NULL));
	crear_archivos_por_grupo();
	cargar_equipos();
	sortear_fase_grupos();
	listado_equipos();

   return 0;
}

// FUNCIONES
void crear_archivos_por_grupo(){
    char nombreArchivo[30];
    
    for(int i=0; i<8; i++){
        sprintf(nombreArchivo, "grupo_%c", 'A'+i);
        FILE *archivo = fopen(nombreArchivo, "wb");
        
        fclose(archivo);
    }
}

char letra_random(char letras[], int &letras_cant){
	int x = rand() % letras_cant;
	char letra = letras[x];

	for(int i=x; i<letras_cant-1; i++)
		letras[i]=letras[i+1];
	
	letras_cant--;
	
	return letra;
}

Equipo cargar_equipo(FILE *archivo, int bolillero, const char nombre[], const char confederacion[]){
    Equipo equipo;
	equipo.bolillero = bolillero;
	strcpy(equipo.nombre, nombre);
	strcpy(equipo.confederacion, confederacion);
    fwrite(&equipo, sizeof(Equipo), 1, archivo);
}

Equipo cargar_equipos(){
    FILE *archivo = fopen(ARCHIVO_EQUIPOS_CLASIFICADOS, "wb");
	int bolillero;

	// Bolillero 1
	bolillero = 1;
	cargar_equipo(archivo, bolillero, "Rusia", "CAF");
	cargar_equipo(archivo, bolillero, "Alemania", "CAF");
	cargar_equipo(archivo, bolillero, "Brasil", "CONMEBOL");
	cargar_equipo(archivo, bolillero, "Portugal", "CAF");
	cargar_equipo(archivo, bolillero, "Argentina", "CONMEBOL");
	cargar_equipo(archivo, bolillero, "Belgica", "CAF");
	cargar_equipo(archivo, bolillero, "Polonia", "CAF");
	cargar_equipo(archivo, bolillero, "Francia", "CAF");
	
	// Bolillero 2
	bolillero = 2;
	cargar_equipo(archivo, bolillero, "Espania", "CAF");
	cargar_equipo(archivo, bolillero, "Peru", "CONMEBOL");
	cargar_equipo(archivo, bolillero, "Suiza", "CAF");
	cargar_equipo(archivo, bolillero, "Inglaterra", "CAF");
	cargar_equipo(archivo, bolillero, "Colombia", "CONMEBOL");
	cargar_equipo(archivo, bolillero, "Mexico", "CONMEBOL");
	cargar_equipo(archivo, bolillero, "Uruguay", "CONMEBOL");
	cargar_equipo(archivo, bolillero, "Croacia", "CAF");

	// Bolillero 3	
	bolillero = 3;
	cargar_equipo(archivo, bolillero, "Dinamarca", "CAF");
	cargar_equipo(archivo, bolillero, "Islandia", "CAF");
	cargar_equipo(archivo, bolillero, "Costa Rica", "CAF");
	cargar_equipo(archivo, bolillero, "Suecia", "CAF");
	cargar_equipo(archivo, bolillero, "Tunez", "CAF");
	cargar_equipo(archivo, bolillero, "Egipto", "CAF");
	cargar_equipo(archivo, bolillero, "Senegal", "CAF");
	cargar_equipo(archivo, bolillero, "Iran", "CAF");
	
	// Bolillero 4
	bolillero = 4;
	cargar_equipo(archivo, bolillero, "Serbia", "CAF");
	cargar_equipo(archivo, bolillero, "Nigeria", "CAF");
	cargar_equipo(archivo, bolillero, "Australia", "CAF");
	cargar_equipo(archivo, bolillero, "Japon", "CAF");
	cargar_equipo(archivo, bolillero, "Marruecos", "CAF");
	cargar_equipo(archivo, bolillero, "Panama", "CAF");
	cargar_equipo(archivo, bolillero, "Corea del Sur", "CAF");
	cargar_equipo(archivo, bolillero, "Arabia Saudita", "CAF");

    fclose(archivo);
}


void sortear_fase_grupos(){
	char sortear_respuesta;
	
	cout<<"Sortear Fase de grupos? S/N: ";
	cin>>sortear_respuesta;
	
	if(sortear_respuesta == 'S' || sortear_respuesta == 's'){
		sortear_bolillero(1);
		sortear_bolillero(2);
	}
}

void sortear_bolillero(int bolillero){
	FILE *archivo;
	Equipo equipo;
	
	archivo = fopen(ARCHIVO_EQUIPOS_CLASIFICADOS, "r+b");	
    fread(&equipo, sizeof(Equipo), 1, archivo);
        while(!feof(archivo)){	
		    if(equipo.bolillero == bolillero){
    			switch(bolillero){
    			case 1:
    				sortear_bolillero_1(equipo);				
    				break;
    			case 2:
    				sortear_bolillero_2(equipo);						
    				break;
    			case 3: case 4:
    				//sortear_bolillero_3(equipo);						
    				break;
    			} // end switch
		    } // end if

        fread(&equipo, sizeof(Equipo), 1, archivo);
	} // endwhile
	fclose(archivo);
}

Equipo agregar_equipo_al_grupo(Equipo equipo, char grupo){
    char nombreArchivo[30];
    
    sprintf(nombreArchivo, "grupo_%c", grupo);
    FILE *archivo = fopen(nombreArchivo, "wb");
    fwrite(&equipo, sizeof(Equipo), 1, archivo);
    fclose(archivo);
}

void sortear_bolillero_1(Equipo equipo){
    int posicion;
	int letras_cant = 7;
	char letra, letras[] = {'B','C','D','E','F','G','H'};
	
	string nombre = string(equipo.nombre);

	if(nombre == "Rusia")					
		equipo.grupo = 'A';
	else{
		letra=letra_random(letras, letras_cant);					
		equipo.grupo = letra;

		if(nombre == "Argentina")
			GRUPO_ARGENTINA = letra;
		if(nombre == "Brasil")
			GRUPO_BRASIL = letra;
	} // endif
	// agrego los registros a los archivos
	agregar_equipo_al_grupo(equipo, equipo.grupo);

	//printf("%s %c\n", equipo.nombre, equipo.grupo);

}
void sortear_bolillero_2(Equipo equipo){
	int letras_cant = 8;
	char letra, letras[] = {'A', 'B','C','D','E','F','G','H'};
	
	string confederacion = string(equipo.confederacion);

	letra=letra_random(letras, letras_cant);
	equipo.grupo = letra;

	if(confederacion == "CAF"){
		// si coincide que se repita
		while(letra == GRUPO_ARGENTINA || letra == GRUPO_BRASIL){
			letra=letra_random(letras, letras_cant);					
			equipo.grupo = letra;
		} // endwhile
	}
}

Equipo listado_equipos(){
    FILE *archivo = fopen(ARCHIVO_EQUIPOS_CLASIFICADOS, "rb");
    
    Equipo equipo;
    fread(&equipo, sizeof(Equipo), 1, archivo);
    while(!feof(archivo)){
		printf("%i %s %s\n", equipo.bolillero, equipo.nombre, equipo.confederacion);
        fread(&equipo, sizeof(Equipo), 1, archivo);
    }
    cout<<endl;
    
    fclose(archivo);
}
