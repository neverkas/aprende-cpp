/*
* 
* El sistema operativo de un televisor “inteligente” posee una lista de fuentes activas (canales) cuyo origen
* son direcciones de Internet. Cada nodo de la lista debe contener a un Canal con los siguientes datos: ID
* (número de canal), la fuente (URL) y la velocidad en Mbps (de 0 a 256). Incorporar al sistema operativo
* las siguientes funcionalidades:
* 1. Agregar canales ordenados por ID
* 2. Eliminar canales cuya velocidad sea inferior a 5
* 3. Buscar un canal por ID
* 4. Listar todos los canales de la lista.
* 
* Casos de prueba:
* A) Agregar los siguientes canales (en el orden que se muestra a continuación):
*     22, http://youtv.com/channel22, 15
*     12, http://vivideo.tv/canal12, 67
*     77, https://localtv.us/stream/news, 4
*     4, http://movies.tv/drama, 0
*     87, https://news.tv/rumania, 127
* B) Eliminar de la lista todos los canales que no alcancen el nivel mínimo de calidad (inactivos o que no alcancen los 5
* Mbps de velocidad).
* C) Buscar el canal 22 y mostrar la fuente (URL) por pantalla.
*
*/
#include <iostream>
#include <stdio.h> // NULL

using namespace std;

//
// # Struct
//
struct Canal{
    int id; // numero de canal
    int vel; // velocidad en mbps 0-256
    string url; // fuente
};

template<typename T>struct Nodo{
    T info;
    Nodo *sig;
};

//
// # Prototipos
//

// prototipos genéricos para listas enlazadas
void insertarOrdenadoPorID(Nodo<Canal> *&p, Canal v);
void eliminar(Nodo<Canal> *&p, Canal v);
Nodo<Canal> *buscarPorID(Nodo<Canal> *p, int v);

// prototipos propios del programa
void eliminarCanalesPorVelocidad(Nodo<Canal> *&p);
void listarCanales(Nodo<Canal> *p);

Canal crearCanal(int id, string url, int vel);
void agregarCanales(Nodo<Canal> *&p, Canal canales[], int cantidad);
void mostrarCanal(Nodo<Canal> *nodo);
void importarFuentes(Nodo<Canal> *p1, Nodo<Canal> *p2, Nodo<Canal> *&p3);    

//
// # Main
//

int main(){
    int cantidadCanales;    
    Nodo<Canal> *canal, *primerLista = NULL, *segundaLista = NULL, *nuevaLista = NULL;


    cantidadCanales = 5;    
    Canal canales[cantidadCanales];
    canales[0] = crearCanal(22, "http://youtv.com/channel22", 15);    
    canales[1] = crearCanal(12, "http://vivideo.tv/canal12", 67);
    canales[2] = crearCanal(77, "https://localtv.us/stream/news", 4);
    canales[3] = crearCanal(4, "http://movies.tv/drama", 0);
    canales[4] = crearCanal(87, "https://news.tv/rumania", 127);

    agregarCanales(primerLista, canales, cantidadCanales);    
    eliminarCanalesPorVelocidad(primerLista);

    cout << "# Primer Listado de Canales: " << endl;
    listarCanales(primerLista);

    cout << "# Datos del Canal con id 22: " << endl;
    canal = buscarPorID(primerLista, 22);
    mostrarCanal(canal);
    cout << endl;

    // se genera nuevo listado
    cantidadCanales = 6;    
    Canal nuevosCanales[cantidadCanales];
    nuevosCanales[0] = crearCanal(28, "http://noticiasdelmundo.tv/canal28", 55);    
    nuevosCanales[1] = crearCanal(8, "https://livetv.com/channel8", 23);
    nuevosCanales[2] = crearCanal(51, "http://sports.tv/football", 89);
    nuevosCanales[3] = crearCanal(112, "https://livenews.tv/newzeland", 3);
    nuevosCanales[4] = crearCanal(54, "http://maspelis.com/comedia", 0);
    nuevosCanales[5] = crearCanal(99, "https://technews.tv/mobileworld", 56);
    agregarCanales(segundaLista, nuevosCanales, cantidadCanales);    
    eliminarCanalesPorVelocidad(segundaLista);

    cout << "# Segundo Listado de Canales: " << endl;
    listarCanales(segundaLista);

    importarFuentes(primerLista, segundaLista, nuevaLista);    
    cout << "# Nuevo Listado de Canales: " << endl;
    listarCanales(nuevaLista);

    return 0;
}

//
// # Funciones
//

// funciones genéricas para listas enlazadas
void insertarOrdenadoPorID(Nodo<Canal> *&p, Canal v){
    Nodo<Canal> *nuevo = new Nodo<Canal>;
    nuevo->info = v;
    nuevo->sig = NULL;

    Nodo<Canal> *ant = NULL;
    Nodo<Canal> *aux = p;

    while(aux != NULL && aux->info.id <= v.id){
        ant = aux;
        aux = aux->sig;
    }

    if(ant == NULL){
        p = nuevo;
    }
    else{
        ant->sig = nuevo;
    }

    nuevo->sig = aux;
}

void eliminar(Nodo<Canal> *&p, Canal v) {
    Nodo<Canal> *aux = p;
    Nodo<Canal> *ant = NULL;

    while(aux!=NULL && aux->info.id != v.id ) {
        ant = aux;
        aux = aux->sig;
    }

    if( ant!=NULL ) {
        ant->sig = aux->sig;
    }
    else {
        p = aux->sig;
    }

    delete aux;
}

Nodo<Canal> *buscarPorID(Nodo<Canal> *p, int v){
    Nodo<Canal> *aux = p;

    while(aux != NULL && aux->info.id != v){
        aux = aux->sig;
    }

    return aux;
}

// funciones propias del programa
Canal crearCanal(int id, string url, int vel){
    Canal c;
    c.id = id;
    c.url = url;
    c.vel = vel;
    
    return c;
}
void agregarCanales(Nodo<Canal> *&p, Canal canales[], int cantidad){
    for(int i=0; i < cantidad; i++){
        insertarOrdenadoPorID(p, canales[i]);
    }
}

void eliminarCanalesPorVelocidad(Nodo<Canal> *&p){
    Nodo<Canal> *aux = p;

    while(aux != NULL){
        if(aux->info.vel < 5){
            eliminar(p, aux->info);
        }

        aux = aux->sig;
    }
}

void listarCanales(Nodo<Canal> *p){
    Nodo<Canal> *aux = p;

    while(aux != NULL){
        mostrarCanal(aux);

        aux = aux->sig;        
    }

    cout << endl;
}

void mostrarCanal(Nodo<Canal> *nodo){
    Canal c = nodo->info;
    cout << c.id << " " << c.url << endl;
}
 
void importarFuentes(Nodo<Canal> *p1, Nodo<Canal> *p2, Nodo<Canal> *&p3){
    Nodo<Canal> *aux01 = p1;
    Nodo<Canal> *aux02 = p2;

    //while(aux01 != NULL && aux02 != NULL && p1->info.id <= p2->info.id){
    while(aux01 != NULL && aux02 != NULL){
        if(p1->info.id <= p2->info.id){
            insertarOrdenadoPorID(p3, aux01->info);
            aux01 = aux01->sig;
        }
        else{
            insertarOrdenadoPorID(p3, aux02->info);
            aux02 = aux02->sig;
        }
    }
    
    while(aux01 != NULL){
        insertarOrdenadoPorID(p3, aux01->info);
        aux01 = aux01->sig;
    }

    while(aux02 != NULL){
        insertarOrdenadoPorID(p3, aux02->info);
        aux02 = aux02->sig;
    }
    
}
