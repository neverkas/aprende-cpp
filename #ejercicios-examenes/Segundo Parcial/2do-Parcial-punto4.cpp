/*
* 
* ANTIVIRUS
* 
* El objetivo es crear el módulo actualizador de firmas desde un archivo. Para ello se debe​ leer 
* el archivo binario firmas.dat (proporcionado) que contiene los siguientes datos:
* a. id (entero)
* b. nombre (cadena de 25 caracteres)
* c. firma (cadena de 25 caracteres)
* El algoritmo que detecta virus analiza los archivos del sistema de archivos (file system del sistema
* operativo) y los compara con la firma de todos los nodos una lista almacenada en memoria.
* 
* Se pide​ :
* -Crear la estructura para leer el archivo de registros.
* -Crear una lista enlazada con los datos leídos del archivo. La función leer() deberá agregar a una lista
* en memoria nodos ordenados alfabéticamente por el campo Firma.
* -Crear el prototipo de la función analizar() que recibe como parámetro un array de cadenas de
* caracteres (archivos) y un puntero a la lista de firmas. Retorna un booleano indicando fue detectado
* un virus.
* -Crear la función guardar() que guardará el archivo firmas.dat con el contenido de la lista actualizada.
* -Recibirá como parámetros un puntero a la lista de firmas y el nombre del archivo a guardar.
* 
*/
#include <iostream>
#include <stdio.h> // archivos

using namespace std;

//
// # Structs
//
template<typename T>
struct Nodo{
	T info;
	Nodo *sig;
};

struct Firma{	
	int id;
	char nombre[25];
	char firma[25];
};

//
// # Prototipos
//
// PREDETERMINADOS PARA LISTAS
//void ordenar(Nodo*& p);
template<typename T> Nodo<T>* insertarOrdenado(Nodo<T>*& p, T v, int(*criterio)(T,T));
template<typename T> void agregarNodo(Nodo<T>*& p, T v);
template<typename T> void mostrar(Nodo<T>* p);
template<typename T> void liberar(Nodo<T>*& p);
int criterioFirma(Firma f1, Firma f2);

// PROPIAS DEL PROGRAMA
void importar(Nodo<Firma> *&, string);
void exportar(Nodo<Firma> *, string);
bool analizar(char [], Nodo<Firma> *);

void leerArchivo(string);
void mostrarRegistro(Firma);

// PROPIOS DEL PROGRAMA

//
// # Main
//
int main(){	
	Nodo<Firma> *lista = new Nodo<Firma>;
	lista = NULL;
		
	// guardo los datos del archivo en la lista
	// se agregan en la lista de manera ordenada
	importar(lista, "FIRMAS.DAT");	

	// verifico que se agregaron los datos de manera correcta a la lista
	// imprimo los datos de la lista
	cout << "LISTA:" << endl;
	mostrar<Firma>(lista);
	cout << endl;

	// guardo los datos de la lista ordenada en el achivo
	exportar(lista, "FIRMAS.DAT");		
	
	// imprimo los datos de archivo
	cout << "ARCHIVO:" << endl;
	leerArchivo("FIRMAS.DAT");

	return 0;

}

//
// # Funciones
//

void leerArchivo(string nombreArchivo){
	FILE *f;
	Firma firma;
	
	// modo lectura
	f = fopen(nombreArchivo.c_str(), "rb");
	// leo el primer registro
	fread(&firma, sizeof(Firma), 1, f);
	// recorro la lista
	while(!feof(f)){
		// imprimo cada registro
		mostrarRegistro(firma);
		// leo cada registro
		fread(&firma, sizeof(Firma), 1, f);		
	}
	
	fclose(f);
	
}

void exportar(Nodo<Firma> *lista, string nombreArchivo){
	// modo escritura
	FILE *f = fopen(nombreArchivo.c_str(), "wb");
	
	Firma firma;
	Nodo<Firma>* aux = lista;
	while(aux!=NULL) {
		firma = aux->info;
		// creo un registro por cada elemento de la lista
		fwrite(&firma, sizeof(Firma), 1, f);
		// avanzo por cada nodo
		aux = aux->sig;
	}
	
	fclose(f);
}
 
void importar(Nodo<Firma> *&lista, string nombreArchivo){
	Firma firma;
	// modo lectura
	FILE *f = fopen(nombreArchivo.c_str(), "rb");
	// leo el primer registro
	fread(&firma, sizeof(Firma), 1, f);
	// recorro todos los registros
	while(!feof(f)){
		// inserto ordenado
		//mostrarRegistro(firma);
		insertarOrdenado(lista, firma, criterioFirma);
		// leo cada registro
		fread(&firma, sizeof(Firma), 1, f);
	}	
	
	fclose(f);
}

int criterioFirma(Firma f1, Firma f2){
	return string(f1.firma).compare(string(f2.firma)) ;
	// return f1.firma<f2.firma?-1:f1.firma>f2.firma?1:0; // otra manera
}


template<typename T>
Nodo<T>* insertarOrdenado(Nodo<T>*& p, T v, int(*criterio)(T,T)) {
	Nodo<T>* nuevo = new Nodo<T>();
	nuevo->info = v;
	nuevo->sig = NULL;
	Nodo<T>* ant = NULL;
	Nodo<T>* aux = p;
	
	while( aux!=NULL && criterio(aux->info, v)<=0) {
		ant = aux;
		aux = aux->sig;
	}
	if( ant==NULL ) {
		p = nuevo;
	} else {
		ant->sig = nuevo;
	}
	
	nuevo->sig = aux;
	return nuevo;
}

template<typename T>
void agregarNodo(Nodo<T>*& p, T x) {
	Nodo<T>* nuevo = new Nodo<T>();
	nuevo->info = x;
	nuevo->sig = NULL;
	if( p==NULL ) {
		p = nuevo;
	}
	else {
		Nodo<T>* aux = p;
		while(aux->sig!=NULL ) {
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}
}

template<typename T>
void mostrar(Nodo<T>* p) {
	Nodo<T>* aux = p;
	while( aux!=NULL ) {
		cout << aux->info.id << " " << aux->info.nombre << " " << aux->info.firma << endl;
		aux = aux->sig;
	}
}

void mostrarRegistro(Firma f) {
	cout << f.id << " " << f.nombre << " " << f.firma << endl;
}

template<typename T>
void liberar(Nodo<T>*& p) {
 Nodo<T>* aux;
 while( p!=NULL ) {
 aux = p;
 p = p->sig;
 delete aux;
 }
}
