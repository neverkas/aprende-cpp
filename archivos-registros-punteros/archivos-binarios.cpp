#include <iostream>
#include <stdio.h> // fopen, fclose, fread, fwrite, ..
#include <string.h>

using namespace std;

#define ARCHIVO "mensajes.dat"

//
// # Structs
//
struct Mensaje{
    int id;
    char texto[200];
};

struct nodoMensaje{
    Mensaje info;
    nodoMensaje *sgte;
};

struct MensajesRecibidos{
    nodoMensaje *mensajes;
};

struct MensajesEnviados{
    nodoMensaje *mensajes;
};

//
// # Prototipos
//
Mensaje crearMensaje(string texto);
void mostrarDatos(Mensaje m);

void cargarDatos();
void mostrarArchivo();
int cantidadRegistrosArchivo();

void pasarArchivoALista();
void pasarArchivoAVector(Mensaje v[], int len);

void listarVector(Mensaje v[], int len);
void listarLista(nodoMensaje *l);

void ordenarVectorPorIdDesc(Mensaje v[], int len);
void ordenarVectorPorIdAsc(Mensaje v[], int len);

int buscarPorId(Mensaje v[], int len, int id);

//
// # Variables Globales
//

int idMensaje = 100; // ira en incremento, permite ID únicos

//
// # Main
//
int main(){
    cargarDatos();

    cout << "# ARCHIVO BINARIO:" << endl;
    mostrarArchivo();
    cout << endl;

    int len = cantidadRegistrosArchivo();
    Mensaje v[len];
    // pasar datos de un archivo binario/texto a un vector, 
    // mejora y aumenta la velocidad de busqueda de datos
    // si se trata de realizar busquedas en un archivo tardará más (a gran escala es peor)
    pasarArchivoAVector(v, len);
    // ordeno de forma Descendente porque los mensajes se agregan de forma ascendente
    ordenarVectorPorIdDesc(v, len);
    cout << "# VECTOR ORDEN DESCENDENTE:" << endl;    
    listarVector(v, len);
    
    cout << endl;

    ordenarVectorPorIdAsc(v, len);
    cout << "# VECTOR ORDEN ASCENDENTE:" << endl;    
    listarVector(v, len);

    int idBuscar = 102;
    int pos = buscarPorId(v, len, idBuscar);

    if(pos != -1){
        cout << "la posicion del elemento es " << pos << endl;
    }else{
        cout << "el elemento no se encuentra en el vector" << endl;
    }

    return 0;
}

//
// # Funciones
//
int buscarPorId(Mensaje v[], int len, int id){
    // busqueda binaria
    // debe estar ordenado el vector para que funcione
    int pi = 0, pf = len-1, pm = (pi+pf) / 2;
    bool enc = false;

    // itero mientras se cumplan las sig. condiciones:
    // 1. la posicion inicial sea menor o igual a la posición final
    // (cuando la posicion final es mayor a la )
    // 2. mientras el centinela no se cumpla
    while(pi <= pf && !enc){
        // si el dato coincide entonces cambio el valor del centinela para que detenga el while
        if(v[pm].id == id){
            enc = true;
        }
        // si el dato es menor al encontrado por la busqueda
        else if(v[pm].id > id){
            // acorto la busqueda, cambiando la posicion final por la posicion del medio menos 1
            // es menos 1, porque esa posición no era válida
            pf = pm - 1;
        }
        // lo opuesto al anterior condicional
        else if(v[pm].id < id){
            pi = pm + 1;
        }

        // por cada iteración voy a la posicion central del vector
        pm = (pi + pf) / 2;
    }

    // si el elemento fue encontrado retorno su posicion en el vector
    // sino devuelvo -1 para informar que no fue encontrado, como si fuese un error
    return (enc) ? pm : -1;

}

void ordenarVectorPorIdDesc(Mensaje v[], int len){
    // Ordenamiento por Inserción
    int indice;
    Mensaje tmp;

    for(int i=0; i < len; i++){
        indice = i;
        tmp = v[i];

        // <= si queres ordenar de forma Ascendente (de menor a mayor)
        // >= si queres ordenar de forma Descendente (de mayor a menor)
        while(indice > 0 && v[indice-1].id <= tmp.id){
            v[indice] = v[indice-1];
            indice--;
        }

        v[indice] = tmp;
    }
}

void ordenarVectorPorIdAsc(Mensaje v[], int len){
    // Ordenamiento por Inserción
    int indice;
    Mensaje tmp;

    for(int i=0; i < len; i++){
        indice = i;
        tmp = v[i];

        // <= si queres ordenar de forma Ascendente (de menor a mayor)
        // >= si queres ordenar de forma Descendente (de mayor a menor)
        while(indice > 0 && v[indice-1].id >= tmp.id){
            v[indice] = v[indice-1];
            indice--;
        }

        v[indice] = tmp;
    }
}

void listarVector(Mensaje v[], int len){
    for(int i=0; i < len; i++){
        mostrarDatos(v[i]);
    }
}

void pasarArchivoAVector(Mensaje v[], int len){
    FILE *f = fopen(ARCHIVO, "rb");
    Mensaje m;
    
    fread(&m, sizeof(Mensaje), 1, f);
    int i = 0;
    while(!feof(f)){
        v[i] = m;

        i++;
        fread(&m, sizeof(Mensaje), 1, f);
    }

    fclose(f);
}


int cantidadRegistrosArchivo(){
    // otra manera sería recorrer el archivo, y usar un contador por cada registro

    // fseek() cambia el cursor del archivo
    // ftell devuelve el tamaño donde apunta el cursor
    FILE *f = fopen(ARCHIVO, "rb");
    int curr = ftell(f); // guardo la posicion actual

    fseek(f, 0, SEEK_END); // lleva el cursor desde el primer registro, al último
    int tamanio = ftell(f); // obtengo el tamaño total del archivo, de todos los registros

    fseek(f, curr, SEEK_SET); // coloco el puntero a donde estaba en un principio
    fclose(f);

    // divido el tamaño total de todos los registros, por el tamaño de 1 solo
    // para saber cuantos hay
    return tamanio / sizeof(Mensaje);

    // Un ejemplo en vectores sería:
    // int v[5] = {1,2,3,4,5};
    // int tamanioVector = sizeof(v) / sizeof(v[0]);
}

void mostrarArchivo(){
    FILE *f = fopen(ARCHIVO, "rb");
    Mensaje m;

    fread(&m, sizeof(Mensaje), 1, f);
    while(!feof(f)){
        mostrarDatos(m);

        fread(&m, sizeof(Mensaje), 1, f);
    }

    fclose(f);
}

void cargarDatos(){
    FILE *f = fopen(ARCHIVO, "wb");
    Mensaje m;

    m = crearMensaje("hola como estas");
    fwrite(&m, sizeof(Mensaje), 1, f);

    m = crearMensaje("todo bien y vos");
    fwrite(&m, sizeof(Mensaje), 1, f);

    m = crearMensaje("aca estudiando");
    fwrite(&m, sizeof(Mensaje), 1, f);

    fclose(f);
}

Mensaje crearMensaje(string texto){
    Mensaje m;
    m.id = idMensaje;
    strcpy(m.texto, texto.c_str());

    idMensaje++; // incremento la variable global

    return m;
}

void mostrarDatos(Mensaje m){
    cout << m.id << " " << m.texto << endl;
}
