/*
*
* Diseñar e implementar el algoritmo que permita obtener los 8 Grupos del Mundial (identificados con
* las letras de la A a la H). El sistema debe dar la opción al usuario por pantalla para que pueda elegir
* “Sortear Fase de Grupos”, una vez seleccionada esta opción el sistema responde realizando el sorteo
* e informando por pantalla la conformación de los 8 grupos del mundial. Asimismo, se debe generar
* un archivo por cada grupo en donde cada registro debe tener los siguientes campos:
*   -Número de bolillero
*   -Nombre de equipo
*   -Confederación
* El algoritmo, para llevar a cabo esta tarea, debe cumplir con las siguientes reglas y pasos:
*   -Regla 1: Cada grupo está formado por un equipo de cada bolillero.
*   -Regla 2: En cada grupo no pueden existir equipos de la misma Confederación (salvo UEFA Eurocopa
* que puede tener un máximo de 2); en cambio los equipos Sudamericanos del bolillero 2, por
* ejemplo, no podrán integrar los grupos de Brasil ni de Argentina.
*
* Pasos del algoritmo:
*   -Paso 1: Se sortea el bolillero 1. Rusia va al grupo A por ser el anfitrión, los demás irán a los 7 grupos
* restantes en orden de salida (de la B a la H).
*   -Paso 2: Se sortea el bolillero 2. Si un equipo Sudamericano sale sorteado en el grupo de Brasil o
* Argentina, se repite el Paso 2.
*   -Paso 3: Se sortea el bolillero 3. Si un equipo sale sorteado en un grupo que ya tenga un miembro de
* la misma Confederación (o 2 en el caso Europeo), se repite el Paso 3.
*   -Paso 4: Se sortea el bolillero 4. Se repite el proceso dado para el Paso 3.
*
*/
#include <iostream>
#include <stdio.h> // sprintf(), fopen(), fwrite(), fread()
#include <string.h> // NULL, c_str(), strcpy()
#include <time.h> // time()
#include <stdlib.h> // srand()

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
char GRUPO_ARGENTINA, GRUPO_BRASIL; // se reutiliza en sortear_bolillero_2()

//
// # PROTOTIPOS
//
void rellenarLetrasAleatorias(char [], int &);
char elegirNuevaLetraAleatoria(char, char [], int &, int);
char elegirLetraAleatoria(char [], int &, int);

void sortearFaseGrupos(Equipo []);

template <typename T> void modificarListado(T arr[], T v, void (*modificarPorCriterio)(T arr[], T &, char [], int &, int &, bool &));
void modificarCriterio01(Equipo [], Equipo &, char [], int &, int &, bool &);
void modificarCriterio02(Equipo [], Equipo &, char [], int &, int &, bool &);
void modificarCriterio03(Equipo [], Equipo &, char [], int &, int &, bool &);
void modificarCriterio04(Equipo [], Equipo &, char [], int &, int &, bool &);

template <typename T> bool buscar(T arr[], int len, T v, char letra, void (*busquedaCriterio)(T v1, T v2, char, bool &));
void busquedaCriterio001(Equipo, Equipo, char, bool &);

void crearArchivosPorGrupo();
void agregarEquipoAlGrupo(Equipo);
void agregarGruposArchivos();

//
// # MAIN
//
int main(){
    // premite generar valores aleatorios
	srand(time(NULL));
	Equipo equipos[EQUIPOS_TOTAL], listado[EQUIPOS_TOTAL];

	// Creo los archivos para luego agregar los equipos
	crearArchivosPorGrupo();	
	// Modifico el archivo segun los criterios del ejercicio
	sortearFaseGrupos(equipos);
    // Agrego las modificaciones a los archivos de cada grupo
	agregarGruposArchivos();

    return 0;
}

//
// # FUNCIONES
//
template <typename T> void escribir(FILE *archivo, T v){
    // obtengo posicion actual del cursor
    int pos = ftell(archivo)-sizeof(T);
    // cambio la posicion del cursor a la obtenida para modificar 
    // el registro ubicado en esa posicion    
    fseek(archivo,pos,SEEK_SET);
    // reescribo/actualizo los datos del registro en el que me posiciono
    fwrite(&v, sizeof(T), 1, archivo);
}

void crearArchivosPorGrupo(){
    FILE *f;
    char nombreArchivo[30];
    Equipo equipo;

    // Itero tantas veces como grupos haya
    for(int i=0; i < GRUPOS; i++){
        // genero los nombres de los archivos a crear con formato 'grupo_' seguido de una letra
        // con 'A'+i me desplazo en el abecedario a partir de 'A'
        // 'i' representa cuantas letras me desplazare
        sprintf(nombreArchivo, "grupo_%c.dat", 'A'+i);
        f = fopen(nombreArchivo, "wb");        
        fclose(f);
    }    
}

void agregarGruposArchivos(){
	FILE *f1, *f2;
    char nombreArchivo[30];
	Equipo equipo;

	f1 = fopen(ARCHIVO_EQUIPOS_CLASIFICADOS, "rb");
    // verifico que se se pudo abrir el archivo binario
    if(f1 != NULL){
        fread(&equipo, sizeof(Equipo), 1, f1);
        // recorro todos los registros hast el final de archivo
        while(!feof(f1)){
            // recorro todos los grupos
            for(int i=0; i < GRUPOS; i++){
                // genero el nombre de todos los grupos
                sprintf(nombreArchivo, "grupo_%c.dat", 'A' + i);
                // abro cada archivo en modo ab+ para agregar nuevos registros
                f2 = fopen(nombreArchivo, "ab+");
                // verifico que se pueda abrir
                if(f2 != NULL){
                    // Si el atributo grupo de cada equipo es igual al del archivo
                    if(equipo.grupo == 'A' + i){
                        // modifico el registro con los nuevos cambios
                        escribir(f2, equipo);
                    }
                } // end if

                fclose(f2); // cierro el archivo f2
            } // end for

            fread(&equipo, sizeof(Equipo), 1, f1);
        } // end while
    } // end if

    fclose(f1); // cierro el archivo f1
}

void sortearFaseGrupos(Equipo arr[]){
    FILE *f;
    Equipo equipo;    
	char sortear_respuesta;

    f = fopen(ARCHIVO_EQUIPOS_CLASIFICADOS, "rb");

    if(f == NULL){
        cout << "Ocurrio un error con el archivo " << ARCHIVO_EQUIPOS_CLASIFICADOS << endl;
        cout << "Verifique que ejecuto el codigo del Ejercicio 1" << endl;
        exit(1);
    }
    else{
        cout << "Sortear Fase de grupos? S/N: ";
        cin >> sortear_respuesta;
        
        // Si la respuesta es 's'
        if(sortear_respuesta == 'S' || sortear_respuesta == 's'){
            // comienza el sorteo de cada bolillero
            modificarListado(arr, equipo, modificarCriterio01); // Bolillero 1
            modificarListado(arr, equipo, modificarCriterio02); // Bolillero 2
            modificarListado(arr, equipo, modificarCriterio03); // Bolillero 3
            modificarListado(arr, equipo, modificarCriterio04); // Bolillero 4
        }
    }
    
    fclose(f);
}

void busquedaCriterio001(Equipo arrayEquipo, Equipo registroEquipo, char letra, bool &encontrado){
    // compruebo si la letra aleatoria se repite en el atributo 'grupo' de un equipo
    if(letra == arrayEquipo.grupo){
        // verifico si el equipo pertenece al bolillero 1 o 2
        if(arrayEquipo.bolillero == 1 || arrayEquipo.bolillero == 2){
            // chequeo si tienen el mismo atributo 'confederacion'
            if(string(arrayEquipo.confederacion) == string(registroEquipo.confederacion)){
                // modifico la variable 'encontrado' por referencia
                encontrado = true;
            }
        }
    }
}

template <typename T> bool buscar(T arr[], int len, T v, char letra, void (*busquedaCriterio)(T v1, T v2, char, bool &)){
    bool encontrado = false;
    
    for(int i=0; i < len; i++){
        busquedaCriterio(arr[i], v, letra, encontrado);
        
        if(encontrado){
            break;
        }
    }
    
    return encontrado;
}

void modificarCriterio01(Equipo arr[], Equipo &equipo, char letras[], int &letrasCantidad, int &letraPosicionInicial, bool &finalizar){
    char letra;

	if(equipo.bolillero == 1){
        // se le pasa por parametro a elegirLetraAleatoria()
        // defino apartir de que letra comienzo a elegir letras aleatorias
    	letraPosicionInicial = 1;

        // si el equipo es Rusia entonces
        if(string(equipo.nombre) == "Rusia"){
            // le asigno por defecto el grupo A
		    equipo.grupo = 'A';
        }
        // si el equipo no es Rusia entonces
        else{            
            // elijo una letra al azar
        	letra = elegirLetraAleatoria(letras, letrasCantidad, letraPosicionInicial);
            // le asigno al equipo el grupo    
		    equipo.grupo = letra;
		    
            // si el equipo es Argentina            
    		if(string(equipo.nombre) == "Argentina"){
                //  guardo la letra del grupo, para reutilizar en modificarCriterio02()
    			GRUPO_ARGENTINA = letra;
    		}
            // si el equipo es Brasil
    		if(string(equipo.nombre) == "Brasil"){
                //  guardo la letra del grupo, para reutilizar en modificarCriterio02()
    			GRUPO_BRASIL = letra;
    		}
        } // end if
	} // end if
}

void modificarCriterio02(Equipo arr[], Equipo &equipo, char letras[], int &letrasCantidad, int &letraPosicionInicial, bool &finalizar){
    char letra;

    // filtro a los equipos que tiene Bolillero 2
	if(equipo.bolillero == 2){
        // elijo una letra al azar
    	letra = elegirLetraAleatoria(letras, letrasCantidad, letraPosicionInicial);								

        // filtro a los equipos que pertenecen a la conferacion CONMEBOL
    	if(string(equipo.confederacion) == "CONMEBOL"){
            // ejecuto mientras la letra aleatoria sea igual a la de grupo de Brasil o Argentina            
    	    while(letra == GRUPO_ARGENTINA || letra == GRUPO_BRASIL){
                // elijo letras al azar
    	        letra = elegirNuevaLetraAleatoria(letra, letras, letrasCantidad, letraPosicionInicial);
    	    }

            // cuando tengo una letra aleatoria que cumple con las condiciones anteriores
            // se la asigno como valor al Grupo del Equipo
          	equipo.grupo = letra;	
    	}
        // si el equipo no pertenece a la confederacion "CONMEBOL" entonces
    	else{
            // le asigno la letra elegida como valor al Grupo del Equipo
          	equipo.grupo = letra;	
    	}
	} // end if
}

void modificarCriterio03(Equipo arr[], Equipo &equipo, char letras[], int &letrasCantidad, int &letraPosicionInicial, bool &finalizar){
    char letra;

    // filtro los equipos que tienen Bolillero 3
	if(equipo.bolillero == 3){
        // elijo una letra al azar
        letra = elegirLetraAleatoria(letras, letrasCantidad, letraPosicionInicial);            
        
        //equipo.grupo = letra;
        // si un equipo sale sorteado en un grupo que ya tenga un miembro de la misma Confederacion entonces
        while(buscar(arr, EQUIPOS_TOTAL, equipo, letra, busquedaCriterio001)){
            // elijo letras al azar mientras se cumpla la condicion anterior
            letra = elegirNuevaLetraAleatoria(letra, letras, letrasCantidad, letraPosicionInicial);
        }

        // le asigno la letra elegida como valor al Grupo del Equipo
        equipo.grupo = letra;
    } // end if
}

void modificarCriterio04(Equipo arr[], Equipo &equipo, char letras[], int &letrasCantidad, int &letraPosicionInicial, bool &finalizar){
	char letra;

    // filtro los equipos que tienen Bolillero 4
    if(equipo.bolillero == 4){
        // elijo una letra al azar
        letra = elegirLetraAleatoria(letras, letrasCantidad, letraPosicionInicial);            

        //equipo.grupo = letra;
        // si un equipo sale sorteado en un grupo que ya tenga un miembro de la misma Confederacion entonces
        while(buscar(arr, EQUIPOS_TOTAL, equipo, letra, busquedaCriterio001)){
            // elijo letras al azar mientras se cumpla la condicion anterior
            letra = elegirNuevaLetraAleatoria(letra, letras, letrasCantidad, letraPosicionInicial);
        }

        // le asigno la letra elegida como valor al Grupo del Equipo
        equipo.grupo = letra;
    } // end if
}

template <typename T> void modificarListado(T arr[], T v, void (*modificarPorCriterio)(T arr[], T &, char [], int &, int &, bool &)){
    FILE *f;
	bool finalizar = false; // centinela que permite controla la ejecucion del while        
	int letrasCantidad = 8;
	char letras[letrasCantidad] = {'A', 'B','C','D','E','F','G','H'};
    int letraPosicionInicial = 0;

    // abro el archivo en modo rb+ para leer y modificar el archivo binario
    f = fopen(ARCHIVO_EQUIPOS_CLASIFICADOS, "rb+");
    // verifico que se se pudo abrir el archivo binario
    if(f != NULL){
        fread(&v, sizeof(T), 1, f);
        // sigo ejecutando las operaciones mientras se cumplan las siguientes condiciones
        // 1. que aun siga leyendo el archivo binario abierto
        // 2. que finalizar siga valiendo 'false'
        while(!feof(f) && !finalizar){
            // modifico los registros segun los criterios que se pasen
            modificarPorCriterio(arr, v, letras, letrasCantidad, letraPosicionInicial,finalizar);

            // cada vez que elijo una letra al azar, la letra se remueve del listado de letras 
            // y reduzco la cantidad de letras que se pueden elegir 
            // cuando la cantidad de letras a elegir sea igual a cero
            if(letrasCantidad == letraPosicionInicial){
                // activo el centinela que detiene la ejecucion del while
                finalizar = true;
            }

            // modifico el registro con los nuevos cambios
            escribir(f, v);
            fread(&v, sizeof(T), 1, f);    	
        } // end while
    } // end if
    
    fclose(f);
}

char elegirNuevaLetraAleatoria(char letra, char letras[], int &letrasCantidad, int letraPosicionInicial){
    // agrego de nuevo la letra al listado de letras, 
    // porque al elegir una nueva letra de borra del listado
    letras[letrasCantidad] = letra;
    letrasCantidad++;

    // elijo otra letra al azar y la retorno
    return elegirLetraAleatoria(letras, letrasCantidad, letraPosicionInicial);
}

char elegirLetraAleatoria(char letras[], int &letrasCantidad, int posicionInicial){
    int min = posicionInicial;
    // resto la posicionInicial porque el rango se achica
    int max = letrasCantidad - posicionInicial;

    int calcular = max-min;

    // Evito error arimetico, verificando que el valor que divide sea mayor a cero
    if(calcular >= 0){
        // Determino un rango de numeros a elegir entre min-max 
        int x = rand()%(max-min + 1) + min;
        
        // Elijo letras al azar 
    	char letra = letras[x];
        
        // Remuevo la letra del listado, desplazando las letras desde esa posicion 
        for(int i=x; i < letrasCantidad ;i++){
            letras[i] = letras[i+1];
        }
    
        // Reduzco el tamanio del vector en -1, ya que hay una letra menos
    	letrasCantidad--;
    	
    	// retorno la letra elegida al azar
    	return letra;
    }
}