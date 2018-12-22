#include <iostream>
#include <stdio.h> // fopen, fclose, fread, fwrite, ..
#include <string.h>

using namespace std;

//
// # Variables Globales
//
#define ARCHIVO "MENSAJES.DAT"

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
void buscarMostrarMensaje(int);

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
    cout << endl;

    cout << "# BUSCAR ELEMENTO POR ID:" << endl;
    int idBuscar = 102;
    int pos = buscarPorId(v, len, idBuscar);
    buscarMostrarMensaje(pos);

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
    // abro la conexión a un archivo del tipo binario en modo lectura
    // ya que solo voy a leer los datos y volcarlos en un vector, no necesito realizar
    // modificaciones
    FILE *f = fopen(ARCHIVO, "rb");
    // creo un variable tipo Mensaje, que utilizaré de buffer, para guardar los datos de los 
    // registros que iré leyendo del archivo binario
    Mensaje m;
    
    int i = 0; // lo utilizo como contador, y para indicar los indices de los elementos del vector

    // leo el primer registro del archivo
    fread(&m, sizeof(Mensaje), 1, f);
    // itero mientras que no haya llegado al final del archivo
    // la funcion feof() retorna TRUE si llegó al final, al utilizar en combinación con el
    // NOT que es el signo de exlamación !, actua como condición de recorrer mientras no se llegue
    // al final del archivo
    while(!feof(f)){
        // guardo cada registro recorrido del archivo en el vector
        // utilizando el contador 'i' como indice
        v[i] = m;
        // incremento el contador
        i++;
        // leo el siguiente registro
        fread(&m, sizeof(Mensaje), 1, f);
    }
    // cierro la conexión, para evitar errores 
    fclose(f);
}

// esta función solo sirve para el archivo binario que contiene registros del tipo Mensaje
// si se quiere analizar más archivos, es necesario utilizar templates,
// ó crear una función de este tipo por cada archivo
int cantidadRegistrosArchivo(){
    // otra manera sería recorrer el archivo, y usar un contador por cada registro
    // (aunque considero que no est an correcta como esta otra)

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
    // abro la conexión a un archivo binario en modo lectura
    FILE *f = fopen(ARCHIVO, "rb");
    // creo una variable del tipo Mensaje, que utilizaré como buffer para guardar los datos
    // de cada registro leido del archivo binario
    Mensaje m;

    // leo el primer registro
    fread(&m, sizeof(Mensaje), 1, f);
    // itero mientras no haya llegado al final del archivo
    while(!feof(f)){
        // llamo a una función que le paso por parametro el registro
        // e imprimirá por pantalla los datos del registro
        mostrarDatos(m);
        // leo el siguiente registro
        fread(&m, sizeof(Mensaje), 1, f);
    }
    // cierro la conexión al archivo
    fclose(f);
}

void cargarDatos(){
    // abro la conexión a un archivo del tipo binario en modo escritura
    // ya que voy a agregar nuevos registro a modo de ejemplo
    FILE *f = fopen(ARCHIVO, "wb");
    // creo una variable del tipo Mensaje que utilizaré de buffer
    Mensaje m;

    // creo los mensajes que escribiré en el archivo
    m = crearMensaje("Hola buen dia Sarah");
    fwrite(&m, sizeof(Mensaje), 1, f);

    m = crearMensaje("Como has estado");
    fwrite(&m, sizeof(Mensaje), 1, f);

    m = crearMensaje("Deberiamos volver a vernos");
    fwrite(&m, sizeof(Mensaje), 1, f);

    // cierro la conexión al archivo 
    fclose(f);
}

Mensaje crearMensaje(string texto){
    Mensaje m;
    m.id = idMensaje;
    // por lo general los archivos tienen problemas con los datos tipo string
    // recurro a utilizar datos del tipo char
    // y utilizo la funcion strcpy() para pasar la información
    // y c_str() para convertir un string en una cadena de char
    strcpy(m.texto, texto.c_str());

    idMensaje++; // incremento la variable global

    return m;
}

void mostrarDatos(Mensaje m){
    cout << m.id << " " << m.texto << endl;
}

void buscarMostrarMensaje(int pos){
    if(pos != -1){
        cout << "La posicion del elemento encontrado es " << pos << endl;
    }else{
        cout << "El elemento no se encuentra en el vector" << endl;
    }
}