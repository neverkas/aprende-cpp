#include <iostream>

using namespace std;

struct Auto{
    string nombre;
    string rutaImagen;
    int velocidad;
    float aceleracion;
    float consumo;
    float peso;
    float coeficienteA; // coeficiente aerodinámico
};

template <typename T>
struct Nodo{
    T info;
    Nodo<T> *ant;
    Nodo<T> *sig;
};

//
// # Prototipos
// 
template <typename T> void agregar(Nodo<T> *&, T);
template <typename T> void insertar(Nodo<T> *&, Nodo<T> *, T);
template <typename T> bool vacia(Nodo<T> *);
template <typename T> void mostrar(Nodo<T> *, Nodo<T> *, void (*criterio)(Nodo<T> *, Nodo<T> *));
template <typename T> int tamanio(Nodo<T> *);

template <typename T> Nodo<T> *irA(Nodo<T> *, int);
template <typename T> Nodo<T> *obtener(Nodo<T> *, string);

Auto crearAuto(string, string, int, float, float, float, float);
void cargarAutos(Nodo<Auto> *&);
void cargarDatosAuto(Auto &);

template <typename T> void mostrarPrimeroAlUltimo(Nodo<T> *, Nodo<T> *);
template <typename T> void mostrarUltimoAlPrimero(Nodo<T> *, Nodo<T> *);

void mostrarMenuOpciones();
void mostrarMenu(Nodo<Auto> *, Nodo<Auto> *);

void mostrarInfo(Auto);
void mostrarInfoCompleta(Auto);

//
// # Main
// 
int main(){
    Nodo<Auto> *primero = new Nodo<Auto>;
    Nodo<Auto> *ultimo = new Nodo<Auto>;

    //  
    primero->ant = NULL;
    ultimo->sig = NULL;
    
    // enlazo los extremos
	primero->sig = ultimo;
	ultimo->ant = primero;

    mostrarMenu(primero, ultimo);
    
    return 0;
}

//
// # Funciones
//
void mostrarMenuOpciones(){
    cout << "Ingrese una de las opciones:" << endl;
    cout << "1. Cargar lista predeterminada al final" << endl;
    cout << "2. Agregar un auto al final de la lista" << endl;
    cout << "3. Encontrar un auto por nombre y agregar otro a su derecha" << endl;
    cout << "4. Mostrar informacion de un auto por nombre" << endl;
    cout << "5. Saltear x cantidad de autos y mostrar" << endl;
    cout << "6. Mostrar listado desde el primer auto hasta el ultimo" << endl;
    cout << "7. Mostrar listado desde el ultimo auto hasta el primero" << endl;
    cout << "8. Cantidad de autos" << endl;
    cout << "0. Salir" << endl;
}

void mostrarMenu(Nodo<Auto> *primero, Nodo<Auto> *ultimo){
    Nodo<Auto> *nodoEncontrado = new Nodo<Auto>;
    Auto a;
    int opcion, cantidadSaltos, tamanioLista;
    string nombreAuto;

    mostrarMenuOpciones();

    cout << "ingrese el numero de opcion: ";
    cin >> opcion;

    while(opcion != 0){
        switch(opcion){
            case 1:
                cargarAutos(ultimo);
                cout << "Se ha agregado el listado" << endl;
            break;
            case 2:
                cargarDatosAuto(a);
                agregar(ultimo, a);
                cout << "Se ha agregado el nuevo auto" << endl;
            break;
            case 3:
                if(!vacia(primero)){
                    cout << "Ingrese el nombre del auto a encontrar: ";
                    cin >> nombreAuto;
                    nodoEncontrado = obtener(primero, nombreAuto);

                    if(nodoEncontrado != NULL){
                        cargarDatosAuto(a);
                        // agrego el auto en la lista luego del nodo "nodoEncontrado"            
                        insertar(primero, nodoEncontrado, a);
                        cout << "Se ha agregado el nuevo auto" << endl;
                    }
                    else{
                        cout << "El auto no fue encontrado" << endl;
                    }
                }
                else{
                    cout << "No hay autos cargados en la lista" << endl;
                }
            break;
            case 4:
                // obtengo datos de un determinado nodo segun un campo, en este caso por el nombre
                if(!vacia(primero)){
                    cout << "Ingrese el nombre del auto: ";
                    cin >> nombreAuto;
                    nodoEncontrado = obtener(primero, nombreAuto);

                    if(nodoEncontrado != NULL){
                        mostrarInfoCompleta(nodoEncontrado->info);
                        cout << endl;
                    }
                    else{
                        cout << "El auto no fue encontrado" << endl;
                    }
                }
                else{
                    cout << "No hay autos cargados en la lista" << endl;
                }
            break;
            case 5:
                // realizo saltos en la lista, desde el principio de la misma
                // Ej. si hago 2 saltos, devolverá el tercero
                if(!vacia(primero)){
                    cout << "Ingrese la cantidad de autos que desea saltear: ";
                    cin >> cantidadSaltos;

                    tamanioLista = tamanio(primero);

                    if(cantidadSaltos < tamanioLista){
                        nodoEncontrado = irA(primero, cantidadSaltos);
                        mostrarInfoCompleta(nodoEncontrado->info);
                        cout << endl;
                    }
                    else{
                        cout << "La cantidad de saltos ingresados supera el tamanio de la lista" << endl;
                    }
                }
                else{
                    cout << "No hay autos cargados en la lista" << endl;
                }
            break;
            case 6:
                if(!vacia(primero)){
                // el tercer parametro indica si se mostrara del principio a fin o viceversa
                    cout << "Listado del primero al último:" << endl;
                    mostrar(primero, ultimo, mostrarPrimeroAlUltimo);
                    cout << endl;
                }
                else{
                    cout << "No hay autos cargados en la lista" << endl;
                }
            break;
            case 7:
                if(!vacia(primero)){
                    cout << "Listado del último al primero:" << endl;
                    // el tercer parametro indica si se mostrara del principio a fin o viceversa
                    mostrar(primero, ultimo, mostrarUltimoAlPrimero);
                    cout << endl;
                }
                else{
                    cout << "No hay autos cargados en la lista" << endl;
                }
            break;
            case 8:
                if(!vacia(primero)){
                    tamanioLista = tamanio(primero);
                    cout << "Cantidad de autos: " << tamanioLista << endl;;
                }
                else{
                    cout << "No hay autos cargados en la lista" << endl;
                }
            break;
        } // end switch

        cout << "ingrese el numero de opcion: ";
        cin >> opcion;
    } // end while
}

void cargarDatosAuto(Auto &a){
    cout << "Ingrese los datos del nuevo auto a agregar" << endl;
    cout << "nombre: ";
    cin >> a.nombre;
    cout << "velocidad: ";
    cin >> a.velocidad;
    cout << "aceleracion: ";
    cin >> a.aceleracion;
    cout << "consumo: ";
    cin >> a.consumo;
    cout << "peso: ";
    cin >> a.peso;
    cout << "coeficiente aerodinamico: ";
    cin >> a.coeficienteA;
}

void cargarAutos(Nodo<Auto> *&ultimo){
    Auto a1, a2, a3, a4;
    a1 = crearAuto("Bentley", "imagenes/autos", 500, 60, 25, 500, 10);
    a2 = crearAuto("Acura", "imagenes/autos", 200, 20, 35, 200, 20);
    a3 = crearAuto("Audi", "imagenes/autos", 700, 10, 15, 100, 15);
    a4 = crearAuto("BMW", "imagenes/autos", 700, 10, 15, 100, 15);

    agregar(ultimo, a1);
    agregar(ultimo, a2);
    agregar(ultimo, a3);
    agregar(ultimo, a4);
}

template <typename T> Nodo<T> *obtener(Nodo<T> *primero, string nombre){
    Nodo<T> *aux = primero->sig;
    
    while(aux->sig != NULL && aux->info.nombre != nombre){
        aux = aux->sig;
    }

    return (aux->info.nombre != nombre) ? NULL : aux;
    //return aux;
}

template <typename T> Nodo<T> *irA(Nodo<T> *primero, int saltos){
    Nodo<T> *aux = primero->sig;

    int contarSaltos = 1; // cuento como primer salto, cuando definí aux

    // detener el bucle si la cantidad de saltos es igual o menor que los saltos que se desean    
    while(aux != NULL && contarSaltos <= saltos){
        contarSaltos++;
        aux = aux->sig;        
    }

    return aux;
}

void mostrarInfo(Auto a){    
    cout << a.nombre << " ";
}

void mostrarInfoCompleta(Auto a){
    cout << "Nombre: " << a.nombre << endl;
    cout << "Velocidad: " << a.velocidad << endl;
    cout << "Aceleracion: " << a.aceleracion << endl;
    cout << "Consumo: " << a.consumo << endl;
    cout << "Peso: " << a.peso << endl;
    cout << "Coeficiente Aerodinámico: " << a.coeficienteA << endl;
}

template <typename T>
void mostrarPrimeroAlUltimo(Nodo<T> *primero, Nodo<T> *ultimo){
    Nodo<T> *aux = primero->sig;
    // recorre del principio al final, mientras el siguiente de cada nodo no esté vacío
    while(aux->sig != NULL){
        // imprimo la informacion del nodo actual
        mostrarInfo(aux->info);
        // avanzo al siguiente
        aux = aux->sig;
    }
}

template <typename T>
void mostrarUltimoAlPrimero(Nodo<T> *primero, Nodo<T> *ultimo){
    Nodo<T> *aux = ultimo->ant;
    // recorro del final al principio, mientras el anterior de cada nodo no esté vacío
    while(aux->ant != NULL){
        // imprimo la informacion del nodo actual
        mostrarInfo(aux->info);        
        // avanzo al anterior
        aux = aux->ant;
    }
}

template <typename T>
void mostrar(Nodo<T> *primero, Nodo<T> *ultimo, void (*criterio)(Nodo<T> *, Nodo<T> *)){
    criterio(primero, ultimo);
}

template <typename T>
void insertar(Nodo<T> *&primero, Nodo<T> *encontrado, T info){
    Nodo<T> *aux = primero->sig;
    Nodo<T> *nuevo = new Nodo<T>;
    // recorro la lista hasta encontrar el nodo o hasta que termine la lista
    while(aux->sig != NULL && aux->info.nombre != encontrado->info.nombre){
        aux = aux->sig;
    }

    // cargo la informacion
    nuevo->info = info;
    // le enlazo como siguiente el que era siguiente del encontrado
    nuevo->sig = encontrado->sig;
    // le enlazo como anterior el nodo encontrado
    nuevo->ant = encontrado;
    // al nodo encontrado le asigno como siguiente el nuevo nodo
    encontrado->sig = nuevo;
}

template <typename T>
void agregar(Nodo<T> *&ultimo, T info){
    Nodo<T> *nuevo = new Nodo<T>;
    // le agrego la informacion
    nuevo->info = info;
    // lo enlazo al ultimo nodo
    nuevo->sig = ultimo;
    // lo enlazo con el anterior nodo del ultimo
    nuevo->ant = ultimo->ant;

    // separo el nodo anterior al ultimo
    Nodo<T> *ant = ultimo->ant;
    // agrego el nuevo nodo al ultimo como su anterior
    ultimo->ant = nuevo;
    // al que era anterior al ultimo nodo lo enlazo con el nuevo como su siguiente
    ant->sig = nuevo;
}

Auto crearAuto(string nombre, string rutaImagen, int velocidad, float aceleracion, float consumo, float peso, float coeficienteA){
    // creo el registro
    Auto a;    
    // le asigno los valores pasados por parametro
    a.nombre = nombre;
    a.rutaImagen = rutaImagen;
    a.velocidad = velocidad;
    a.aceleracion = aceleracion;
    a.consumo = consumo;
    a.peso = peso;
    a.coeficienteA = coeficienteA; // coeficiente aerodinámico
    // retorno el registro con todos los cambios
    return a;
}

template <typename T>
bool vacia(Nodo<T> *primero){
    return (primero->sig->sig == NULL);
}

template <typename T>
int tamanio(Nodo<T> *primero){
    Nodo<T> *aux = primero->sig;
    int contar = 0;

    while(aux->sig != NULL){
        contar++;

        aux = aux->sig;
    }

    return contar;
}
