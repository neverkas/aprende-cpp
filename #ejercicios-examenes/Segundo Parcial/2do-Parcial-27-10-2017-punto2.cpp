/*
*
* CHAT
*
* Un sistema de atención al público necesita poner en espera las solicitudes de conversación con los
* representantes. Como la demanda supera a la cantidad de operadores, el objetivo es que los clientes queden
* en espera manteniendo el orden de llegada. Cada cliente es representado en el sistema con los siguientes
* datos:
* -id_cliente:entero
* -nickname: cadena de caracteres
* 
* Se pide: Crear un programa que agregue clientes a una estructura de datos desde la función
* agregarCliente() a medida que se van registrando en el sistema.
* También implementar la función atenderProximo() que retorne los datos del siguiente cliente a atender.
* Crear las estructuras necesarias.
*
*/
#include <iostream>

using namespace std;

struct Cliente{
    int id_cliente;
    string nickname;
};

struct Nodo{
    Cliente info;
    Nodo *sig;    
};

Cliente crearCliente(int id_cliente, string nickname){
    Cliente c;
    c.id_cliente = id_cliente;
    c.nickname = nickname;

    return c;
}

void agregarCliente(Nodo *&frente, Nodo *&fin, Cliente cliente){
    Nodo *nuevo = new Nodo();
    nuevo->info = cliente;
    nuevo->sig = NULL;

    // si el frente está vacío, la lista está vacía
    if(frente == NULL){
        // inserto el primer nodo al frente
        frente = nuevo;
    }
    // si hay 1 o más nodos
    else{
        // enlazo al siguiente deĺ último nodo, el nuevo nodo
        fin->sig = nuevo;
    }

    // actualizo el puntero, y agrego el nuevo puntero como último
    // el que estaba como último, ahora es el anterior al nuevo 
    fin = nuevo;
}

Cliente atenderProximo(Nodo *&frente, Nodo *&fin){
    // creo un puntero auxiliar, guardo el nodo al que apunta, que luego lo borrare
    Nodo *aux = frente;
    // guardo la informacion a retornar
    Cliente info = aux->info;
    // actualizo el puntero apuntando al siguiente nodo
    frente = aux->sig;

    // si el frente está vacío, entonces la lista está vacía
    if(frente == NULL){
        // el fin debe estar vacío también
        fin = NULL;
    }
    
    // borro de memoria 
    delete aux;
    // retorno la informacion
    return info;
}

int main(){
    Cliente cliente;
    Nodo *frente = NULL;
    Nodo *fin = NULL;

    agregarCliente(frente, fin, crearCliente(1, "Pedro"));
    agregarCliente(frente, fin, crearCliente(2, "Fede"));
    agregarCliente(frente, fin, crearCliente(3, "Mariano"));

    cliente = atenderProximo(frente, fin);
    cout << cliente.id_cliente << " " << cliente.nickname << endl;

    cliente = atenderProximo(frente, fin);
    cout << cliente.id_cliente << " " << cliente.nickname << endl;

    return 0;
}