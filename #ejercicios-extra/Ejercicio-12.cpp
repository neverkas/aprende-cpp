/*
*
* 1) Crear un programa que defina la estructura de tipo Aeronave cuyos atributos sean:
*   identificador (entero)
*   matrícula (cadena de caracteres)
*   nombre (cadena de caracteres)
*   horasDeVuelo (entero)
*   fechaBaja (entero).
* 2) El programa debe permitir dar de alta n aeronaves (n<=10) y debe almacenarlas en un array de 10 elementos.
* 3) También deberá mostrar por pantalla el listado de matrículas de las aeronaves que aún no fueron dadas 
* de baja (aeronaves[i].fechaBaja == 0), junto con las horas de vuelo de cada una.
* 4) Modularizar el programa con las funciones cargarAeronaves() y listarActivas().
* 5) Incorporar al programa gestor de aeronaves  la posibilidad de buscar aeronaves por identificador o por matrícula.
* 6) Incorporar al programa de la clase anterior (Aeronaves) la plantilla de función ordenar() y agregar 
* criterios que permitan ordenar ascendentemente aeronaves por:
*   a. Horas de Vuelo
*   b. Matrícula
* Invocar esta nueva función desde la principal, primero pasando como parámetro el criterio (a) y luego el (b)
* y mostrar ambos resultados por pantalla. 
*
*/
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//
// # Variables Globales
//
#define ARCHIVO_NOMBRE "AERONAVES.DAT"
#define CANTIDAD_AERONAVES 7

//
// # Struct
//
struct Aeronave {
    int identificador;
    char matricula[30];
    char nombre[30];
    int fechaBaja;
    int horasDeVuelo;
};

/*********************************************************************************/

//
// # Prototipos
//
Aeronave crearAeronave(int, char, char, int, int);
void cargarAeronaves(Aeronave []);
void listarActivas(Aeronave [], int);
void cargarAeronavesArchivo(Aeronave [], int);
void mostrarAeronave(Aeronave);

void mostrarMenuOpciones();
void mostrarMenu(Aeronave [], int);
    
template <typename T>int buscarAeronave(FILE *f, Aeronave a, int (*criterioBusqueda)(T, T));
Aeronave mostrarAeronavePorRegistro(FILE *, int);

int criterioIdentificadorAsc(Aeronave, Aeronave);
int criterioHorasVueloAsc(Aeronave, Aeronave);
int criterioMatriculaAsc(Aeronave, Aeronave);

void mostrarFila(Aeronave);

// Prototipos de la Catedra
template <typename T> T read(FILE* f);
template <typename T> void write(FILE* f, T v);
template <typename T> void seek(FILE* arch, int n);
template <typename T> long fileSize(FILE* f);

template <typename T, typename K>int busquedaBinaria(FILE* f, K v, int (*criterio)(T, K));
template <typename T> void ordenar(T arr[], int len, int (*criterio)(T, T));
template <typename T> void mostrar(T arr[], int len, void (*mostrarFila)(T));

/*********************************************************************************/

//
// # Main
//
main(){
    Aeronave aeronaves[CANTIDAD_AERONAVES];
    
    // Cargo los datos en el vector 'aeronaves'    
    cargarAeronaves(aeronaves);

    mostrarMenu(aeronaves, CANTIDAD_AERONAVES);

    return 0;
}

/*********************************************************************************/

//
// # Funciones
//
void mostrarMenuOpciones(){
	cout << "Elija una opcion: " << endl;
	cout << "1: Buscar por identificador" << endl;
	cout << "2: Buscar por matricula" << endl;
	
	cout << "3: Mostrar listado ordenado por Horas de vuelo" << endl;
	cout << "4: Mostrar listado ordenado por Matricula" << endl;
	
	cout << "0: Salir" << endl;
}

void mostrarMenu(Aeronave lista[], int cantidad){
    int opcion; // Lo utilizo como centinela, para controlar la ejecucion del bucle
    FILE *f;
    Aeronave a;
    int numeroRegistro;
    
    mostrarMenuOpciones();
    cout << "Ingrese el numero de opcion del menu: ";
    cin >> opcion;
    
    // Ejecuto el bucle while mientras que el centinela 'opcion' sea diferente a cero
    while(opcion != 0){    
    	switch(opcion){
    	    case 1:
    	        // Ordeno el vector por Identificador
            	ordenar(lista, cantidad, criterioIdentificadorAsc);
            	// Creo un archivo binario y guardo el vector ordenado
            	cargarAeronavesArchivo(lista, cantidad);

            	cout << "Ingrese el identificador de la aeronave a buscar: ";
            	cin >> a.identificador;
            	// Guardo el numero del registro encontrado para luego mostrar
            	numeroRegistro = buscarAeronave(f, a, criterioIdentificadorAsc);

            	if(numeroRegistro != -1){
                	// Muestro los datos del registro encontrado
                    mostrarAeronavePorRegistro(f, numeroRegistro);
                }
                else{
                    cout << "No se encuentra en la lista una aeronave con dicho Identificador" << endl;
                }
    	    break;
    	    case 2:
    	        // Ordeno el vector por Identificador
            	ordenar(lista, cantidad, criterioMatriculaAsc);
            	// Creo un archivo binario y guardo el vector ordenado
            	cargarAeronavesArchivo(lista, cantidad);
            	
            	cout << "Ingrese la matricula de la aeronave a buscar: ";
            	cin >> a.matricula;
            	// Guardo el numero del registro encontrado para luego mostrar
            	numeroRegistro = buscarAeronave(f, a, criterioMatriculaAsc);

            	if(numeroRegistro != -1)
                	// Muestro los datos del registro encontrado
                    mostrarAeronavePorRegistro(f, numeroRegistro);
                else
                    cout << "No se encuentra en la lista una aeronave con dicha Matricula" << endl;
    	    break;
    	    case 3:
            	// Listado ordenado por horasDeVuelo de manera Ascendente
            	cout << "Ordenados por Horas de vuelo: " << endl;
            	ordenar(lista, cantidad, criterioHorasVueloAsc);
            	mostrar(lista, cantidad, mostrarFila);
            	cout << endl;
    	    break;
    	    case 4:
            	// Listado ordenado por Matricula de manera Ascendente
            	cout << "Ordenados por matricula: " << endl;
            	ordenar(lista, cantidad, criterioMatriculaAsc);
            	mostrar(lista, cantidad, mostrarFila);
            	cout << endl;
    	    break;
    	} // end switch
    	

        cout << "Ingrese el numero de opcion del menu: ";
        cin >> opcion;
    } //end while
}

Aeronave mostrarAeronavePorRegistro(FILE *f, int numeroRegistro){
    Aeronave a;
    
	f = fopen(ARCHIVO_NOMBRE,"rb");

    if(f != NULL){
        // posiciono el cursor hasta ese registro
        seek<Aeronave>(f, numeroRegistro);
        // obtengo el contenido del registro
        fread(&a, sizeof(Aeronave), 1, f);
        // lo imprimo
        mostrarAeronave(a);
    }

    fclose(f);
}

template <typename T>int buscarAeronave(FILE *f, Aeronave a, int (*criterioBusqueda)(T, T)){
    int numeroRegistro;
    
    // abro el archivo en modo lectura
	f = fopen(ARCHIVO_NOMBRE,"rb");
    // verifico que pude abrir el archivo
    if(f != NULL){
        // busco si existe el registro y guardo su posicion
        numeroRegistro = busquedaBinaria(f, a, criterioBusqueda);
    }

    fclose(f);

    // retorno la posicion del registro encontrado    
    return numeroRegistro;
}

int criterioIdentificadorAsc(Aeronave a1, Aeronave a2){
	return a1.identificador - a2.identificador;
}

int criterioHorasVueloAsc(Aeronave a1, Aeronave a2){
	return a1.horasDeVuelo - a2.horasDeVuelo;
}
int criterioMatriculaAsc(Aeronave a1, Aeronave a2){
	return string(a1.matricula) > string(a2.matricula) ? 1 : string(a1.matricula) < string(a2.matricula) ? -1 : 0;
}

void mostrarFila(Aeronave a){
	cout << a.identificador << " " << a.matricula << " " << a.horasDeVuelo << endl;
}

void mostrarAeronave(Aeronave a){
	cout << a.identificador << " " << a.matricula << " " << a.horasDeVuelo << endl;
}

Aeronave crearAeronave(int identificador, string matricula, string nombre, int fechaBaja, int horasDeVuelo){
	Aeronave a;
    a.identificador = identificador;
    strcpy(a.matricula,matricula.c_str()); 
    strcpy(a.nombre,nombre.c_str()); 
    a.fechaBaja = fechaBaja;
    a.horasDeVuelo = horasDeVuelo;
    
    return a;
}

void cargarAeronavesArchivo(Aeronave lista[], int cantidad){
	FILE* f;
	
    // abro el archivo en modo escritura
	f = fopen(ARCHIVO_NOMBRE,"wb");
    // verifico que pude abrir el archivo
    if(f != NULL){
        // agrego el vector 'lista' al archivo
        fwrite(lista, sizeof(Aeronave), cantidad, f);
    }
    fclose(f);
}

void cargarAeronaves(Aeronave lista[]){	   
  	lista[0]=crearAeronave(15,"AF01","nomb",0,20);        
    lista[1]=crearAeronave(10,"AF02","nomb",0,90);   
    lista[2]=crearAeronave(25,"AF05","nomb",0,20);   
    lista[3]=crearAeronave(35,"AF03","nomb",0,40);   
    lista[4]=crearAeronave(40,"AF07","nomb",0,50);   
    lista[5]=crearAeronave(52,"AF06","nomb",0,10);   
    lista[6]=crearAeronave(61,"AF04","nomb",0,50);   
}

// Funciones de la catedra
template <typename T> T read(FILE* f){
    T buff;
    fread(&buff, sizeof(T), 1, f);
    return buff;
}
template <typename T> void write(FILE* f, T v){
    fwrite(&v, sizeof(T), 1, f);
    return;
}
template <typename T>void seek(FILE* arch, int n){
    fseek(arch, n * sizeof(T), SEEK_SET);
}
template <typename T>long fileSize(FILE* f){
    long curr = ftell(f);
    fseek(f, 0, SEEK_END);
    long ultimo = ftell(f);
    fseek(f, curr, SEEK_SET);
    return ultimo / sizeof(T);
}

template <typename T, typename K>int busquedaBinaria(FILE* f, K v, int (*criterio)(T, K)){
    int i = 0;
    int j = fileSize<T>(f) - 1;
    int k = (i + j) / 2;
    seek<T>(f, k);
    T r = read<T>(f);
    while (i <= j && criterio(r, v) != 0) {
        if (criterio(r, v) > 0) {
            j = k - 1;
        }
        else {
            if (criterio(r, v) < 0) {
                i = k + 1;
            }
        }
        k = (i + j) / 2;
        seek<T>(f, k);
        r = read<T>(f);
    }
    return i <= j ? k : -1;
}

template <typename T> void ordenar(T arr[], int len, int (*criterio)(T, T))
{
    bool ordenado = false;
    while (!ordenado) {
        ordenado = true;
        for (int i = 0; i < len - 1; i++) {
            if (criterio(arr[i], arr[i + 1]) > 0) {
                T aux = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = aux;
                ordenado = false;
            }
        }
    }
}

template <typename T> void mostrar(T arr[], int len, void (*mostrarFila)(T)) {
	for(int i=0; i<len; i++){
		mostrarFila(arr[i]);
	}
} 
