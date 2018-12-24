/*
* 
* ROUTERS
* 
* El sistema operativo de un router configurado como maestro (master) permite, a
* través de una API*, enviar una serie de comandos a sus routers esclavos (slave). La
* especificación dice que el router debe implementar una función configurar() que lea desde
* un archivo binario (proporcionado) registros con los siguientes atributos:
*   -id (router destino): entero
*   -sec (secuencia): entero
*   -comando: cadena de caracteres [25]
* 
* Esa función debe actualizar los elementos de una estructura array (id routers) de punteros a
* listas de comandos ordenados según el campo “secuencia”.
* Se pide: Crear la función configurar() que deberá:
* 1) leer los comandos del archivo binario,
* 2) actualizar un array de listas con los comandos dirigidos a cada router (máximo = 10
routers).
* Los comandos deberán ser enlazados en el orden del dato secuencia. Crear las
estructuras necesarias.
*
*/
#include <iostream>
#include <stdio.h> // fopen, fwrite, etc..
#include <string.h>

using namespace std;

#define MAX_ROUTERS 10
#define ARCHIVO_COMANDOS "comandos.dat"

//
// # Structs
//
template <typename T>
struct Nodo{
    T info;
    Nodo *sig;
};

struct Router{
    int id;
    char comando[25]; 
};

struct Comando{
    int id; // Comando destino
    int sec; // secuencia
    char comando[25]; 
};

//
// # Prototipos
//
template <typename T> T pop(Nodo<T> *&);
template <typename T> void push(Nodo<T> *&, T);

int criterioSec(Comando, Comando);
void configurar(Nodo<Comando> *[]);
void mostrarConfiguracion(Nodo<Comando> *[]);

//
// # Main
//
int main(){
    // creo un array de listas
    Nodo<Comando> *routers[MAX_ROUTERS] = {NULL};
    

    configurar(routers);
    mostrarConfiguracion(routers);

    return 0;
}

//
// # Funciones
//
int criterioSec(Comando c1, Comando c2){
    return c1.sec-c2.sec;
}

template <typename T>
T pop(Nodo<T> *&p){
    // guardo el nodo actual
    Nodo<T> *aux = p;
    // guardo la informacion del nodo para luego mostrar, caso contrario el delete lo borraria
    T info = p->info;
    // apunto el puntero al siguiente nodo
    p = aux->sig;
    // borro de memoria el nodo actual
    delete aux;
    // retorno la informacion del nodo previamente borrado de memoria
    return info;
}

template <typename T>
Nodo<T>* insertarOrdenado(Nodo<T>*& l, T v, int (*criterio)(T,T) ) {
    Nodo<T>* nuevo = new Nodo<T>();
    nuevo->info = v;
    nuevo->sig = NULL;
    Nodo<T>* aux = l;
    Nodo<T>* ant = NULL;

    while( aux!=NULL && criterio(aux->info,v)<=0 ) {
        ant = aux;
        aux = aux->sig;
    }

    if( ant==NULL ) {
        l = nuevo;
    } else {
        ant->sig = nuevo;
    }

    nuevo->sig = aux;

    return nuevo;
}

void mostrarComandoInfo(Comando c){
    cout << "secuencia: " << c.sec;
    cout << ", comando: " << c.comando;
    cout << endl;
}

void mostrarConfiguracion(Nodo<Comando> *routers[]){
    Comando c;
    // recorro cada elemento del array (c/u tiene listas)   
    for(int i=0; i < MAX_ROUTERS; i++){
    cout << "Router #" << (i+1) << endl;
        // recorro cada lista perteneciente a un elemento del array hasta llegar al ultimo elemento
        while(routers[i] != NULL){
            // obtengo cada nodo de la lista y lo guardo en 'c' para luego mostrarlo
            c = pop<Comando>(routers[i]);
            // muestro los datos
            mostrarComandoInfo(c);
        } // end while

        cout << endl;
    } // end for
    cout << endl;
}

void configurar(Nodo<Comando> *routers[]){
    FILE *f;
    Comando c;
    // abro el archivo binario en modo lectura
    f = fopen(ARCHIVO_COMANDOS, "rb");
    // leo el primer registro 
    fread(&c, sizeof(Comando), 1, f);
    // recorro el archivo mientras no sea el final del archivo
    while(!feof(f)){
        // itero tantas veces segun MAX_ROUTERS (10 en este caso)
        for(int i=0; i < MAX_ROUTERS; i++){
            // inserto cada registro en cada elemento del array de listas
            //push<Comando>(routers[i], c);
            insertarOrdenado<Comando>(routers[i], c, criterioSec);
        } // end for
        // sigo leyendo cada registro (el siguiente)
        fread(&c, sizeof(Comando), 1, f);
    } // end while
    // cierro el archivo
    fclose(f);
}
