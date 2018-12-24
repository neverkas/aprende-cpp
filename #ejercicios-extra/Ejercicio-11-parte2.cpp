/*
*
* Se debe incorporar la posibilidad de importar lotes de fuentes. Ahora, al invocar a la función importarFuentes(),
* el sistema operativo recibe una lista complementaria de canales
* que debe incorporar a la existente en memoria pero conservando el orden por número de canal.
* Se pide: A la lista de canales del caso de prueba “A” del EJ1, agregar la lista del caso “D” de forma tal
* que ambas se fusionen sin perder nodos (canales) y manteniendo el orden (por ID).
*
* Nueva lista de canales:
*   28, http://noticiasdelmundo.tv/canal28, 55
*   8, https://livetv.com/channel8, 23
*   51, http://sports.tv/football, 89
*   112, https://livenews.tv/newzeland, 3
*   54, http://maspelis.com/comedia, 0
*   99, https://technews.tv/mobileworld, 56
* 
* Nota: Antes de fusionar, se deberán eliminar los canales que no alcancen el nivel mínimo de calidad.
*
*/

#include <iostream>
#include <stdio.h> // NULL
#include <iomanip> // setw

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
void agregarNodo(Nodo<Canal> *&, Canal);
void insertarOrdenadoPorID(Nodo<Canal> *&p, Canal);
void eliminar(Nodo<Canal> *&, Canal);
Nodo<Canal> *buscarPorID(Nodo<Canal> *, int);

// prototipos propios del programa
void eliminarCanalesPorVelocidad(Nodo<Canal> *&);
void listarCanales(Nodo<Canal> *);

void insertarCanalOrdenado(Nodo<Canal> *&, int, string, int);
void agregarCanalesA(Nodo<Canal> *&);
void agregarCanalesD(Nodo<Canal> *&);
void mostrarCanal(Nodo<Canal> *);

void importarFuentes(Nodo<Canal> *&, Nodo<Canal> *&, Nodo<Canal> *&);    

void menu();
void menuOpciones();

//
// # Main
//

int main(){
    menu();

    return 0;
}

//
// # Funciones
//

void menuOpciones(){
    cout << "Eliga una de las opciones: " << endl;
    cout << "1. Agregar lista de Canales A" << endl;
    cout << "2. Agregar lista de Canales D" << endl;
    cout << "3. Eliminar canales de baja calidad" << endl;
    cout << "4. Fusionar listas" << endl;
    cout << "5. Buscar Canal" << endl;
    cout << "6. Imprimir todos los canales" << endl;
    cout << "0. Salir" << endl;    
}

void menu(){
    Nodo<Canal> *canal, *primerLista = NULL, *segundaLista = NULL, *nuevaLista = NULL;
    int ingresarCanalID;
    int opcion;
    
    menuOpciones();

    cout << "Ingrese el numero de opcion: ";
    cin >> opcion;

    while(opcion != 0){
        switch(opcion){
            case 1:
                agregarCanalesA(primerLista);    
                cout << "Se ha agregado la lista de canales A" << endl;
            break;
            case 2:
                agregarCanalesD(segundaLista);    
                cout << "Se ha agregado la lista de canales D" << endl;
            break;
            case 3:
                if(primerLista != NULL)
                    eliminarCanalesPorVelocidad(primerLista);
                if(segundaLista != NULL)
                    eliminarCanalesPorVelocidad(segundaLista);
            break;
            case 4:
                if(primerLista != NULL &&  segundaLista != NULL){
                    importarFuentes(primerLista, segundaLista, nuevaLista);   
                    cout << "Se han fusionado ambas listas" << endl; 
                }
                else{
                    if(primerLista == NULL)
                        cout << "No se ha agregado los canales de la lista A" << endl;                    
                    if(segundaLista == NULL)
                        cout << "No se ha agregado los canales de la lista D" << endl;                    
                }
            break;
            case 5:
                if(nuevaLista != NULL){
                    cout << "Ingrese el numero de id del canal a buscar:";
                    cin >> ingresarCanalID;
                    canal = buscarPorID(nuevaLista, ingresarCanalID);
                
                    if(canal != NULL){
                        cout << "ID" << setw(10) << "VELOCIDAD" << setw(10) << "URL" << endl;
                        mostrarCanal(canal);                        
                    }else{
                        cout << "No se ha encontrado el canal ingresado" << endl;                        
                    }
                }
                else{
                    cout << "No se han encontrado canales, pruebe agregar los listados y fusionarlos" << endl;
                }
            break;
            case 6:
                if(nuevaLista != NULL){
                    cout << "Listado de Canales: " << endl;
                    listarCanales(nuevaLista);
                }
                else{
                    cout << "No se han encontrado canales, pruebe agregar los listados y fusionarlos" << endl;
                }

            break;
        }

        cout << "Ingrese el numero de opcion: ";
        cin >> opcion;
    }
}

// funciones genéricas para listas enlazadas
void agregarNodo(Nodo<Canal> *&p, Canal v){
    Nodo<Canal>* nuevo = new Nodo<Canal>();
    nuevo->info = v;
    nuevo->sig = NULL;
    
    if( p==NULL ) {
        p = nuevo;
    }
    else {
        Nodo<Canal> *aux = p;
    
        while(aux->sig!=NULL ) {
            aux = aux->sig;
        }

        aux->sig = nuevo;
    }
}

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
void insertarCanalOrdenado(Nodo<Canal> *&p, int id, string url, int vel){
    Canal c;
    c.id = id;
    c.url = url;
    c.vel = vel;
    
    insertarOrdenadoPorID(p, c);
    cout << "Se ha agregado el canal con ID #" << id << endl;
}

void agregarCanalesA(Nodo<Canal> *&p){
    insertarCanalOrdenado(p, 22, "http://youtv.com/channel22", 15);    
    insertarCanalOrdenado(p, 12, "http://vivideo.tv/canal12", 67);
    insertarCanalOrdenado(p, 77, "https://localtv.us/stream/news", 4);
    insertarCanalOrdenado(p, 4, "http://movies.tv/drama", 0);
    insertarCanalOrdenado(p, 87, "https://news.tv/rumania", 127);
}

void agregarCanalesD(Nodo<Canal> *&p){
    insertarCanalOrdenado(p, 28, "http://noticiasdelmundo.tv/canal28", 55);    
    insertarCanalOrdenado(p, 8, "https://livetv.com/channel8", 23);
    insertarCanalOrdenado(p, 51, "http://sports.tv/football", 89);
    insertarCanalOrdenado(p, 112, "https://livenews.tv/newzeland", 3);
    insertarCanalOrdenado(p, 54, "http://maspelis.com/comedia", 0);
    insertarCanalOrdenado(p, 99, "https://technews.tv/mobileworld", 56);
}

void eliminarCanalesPorVelocidad(Nodo<Canal> *&p){
    Nodo<Canal> *aux = p;

    while(aux != NULL){
        if(aux->info.vel < 5){
            cout << "Se ha eliminado el canal con ID #" << aux->info.id << endl;

            eliminar(p, aux->info);
        }

        aux = aux->sig;
    }
}

void listarCanales(Nodo<Canal> *p){
    Nodo<Canal> *aux = p;

    cout << "ID" << setw(10) << "VELOCIDAD" << setw(10) << "URL" << endl;

    while(aux != NULL){
        mostrarCanal(aux);

        aux = aux->sig;        
    }

    cout << endl;
}

void mostrarCanal(Nodo<Canal> *nodo){
    Canal c = nodo->info;

    cout << c.id << setw(5) << c.vel << "Mbps" << setw(30) << c.url;
    cout << endl;
}
 
void importarFuentes(Nodo<Canal> *&p1, Nodo<Canal> *&p2, Nodo<Canal> *&p3){
    Nodo<Canal> *aux01 = p1;
    Nodo<Canal> *aux02 = p2;

    //while(aux01 != NULL && aux02 != NULL && p1->info.id <= p2->info.id){
    while(aux01 != NULL && aux02 != NULL){
        if(p1->info.id <= p2->info.id){
            agregarNodo(p3, aux01->info);
            eliminar(p1, aux01->info);
            aux01 = aux01->sig;
        }
        else{
            agregarNodo(p3, aux02->info);
            eliminar(p2, aux02->info);
            aux02 = aux02->sig;
        }
    }
    
    while(aux01 != NULL){
        agregarNodo(p3, aux01->info);
        eliminar(p1, aux01->info);
        aux01 = aux01->sig;
    }

    while(aux02 != NULL){
        agregarNodo(p3, aux02->info);
        eliminar(p2, aux02->info);
        aux02 = aux02->sig;
    }
    
}
