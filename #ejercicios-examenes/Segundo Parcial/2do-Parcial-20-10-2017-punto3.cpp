/*
*
* STREAMING
*
* Se debe crear una función que cargue en memoria las canciones más solicitadas desde un
* archivo binario de registros, de modo tal de agilizar el tiempo de respuesta del servicio (caché). El archivo
* posee las canciones que superaron las 10000 reproducciones del día anterior, por lo que la cantidad siempre
* es variable.
* Cada registro de canción posee la siguiente estructura:
* -id_cancion: entero
* -id_album: entero
* -orden: entero
* -audio: cadena de caracteres [2048]
* 
* Donde el campo audio contiene la canción codificada en Base64. La función debe organizar en una
* estructura de datos a todos los registros leídos del archivo, agrupándolos por álbum y en la secuencia
* indicada por el valor del campo orden.
* Se pide: Crear la función cargarCache() que recibe por parámetro la ruta al archivo y deberá:
* 1) leer y agrupar todas las canciones por id_album
* 2) retornar una lista de álbumes con canciones enlazadas ascendentemente (0-9) por el valor del campo orden.
* Tener presente que cada álbum puede tener más de una canción, pero no puede haber repeticiones de un mismo álbum en la estructura.
* Crear las estructuras necesarias.
*
*/
#include <iostream>
#include <stdio.h> // fopen, fwrite, fread, ..
#include <string.h>

using namespace std;

#define ARCHIVO_NOMBRE "miscanciones.dat"

//
// # Structs
//
template <typename T>
struct Nodo{
    T info;
    Nodo *sig;
};

struct Cancion{
	int id_cancion;
	int id_album;
	int orden;
	char audio[2048];
};

struct Album{
	int id_album;
	Nodo<Cancion> *canciones;
	Album *sig;
};

//
// # Prototipos
//
template <typename T> T pop(Nodo<T> *&);
template <typename T> Nodo<T>* insertarOrdenado(Nodo<T>*& l, T v, int (*criterio)(T,T) );
int criterioOrdenAsc(Cancion, Cancion);

Cancion crearCancion(int, int, int , string);
void cargarCanciones();
void cargarCancionesArchivo(string, Nodo<Cancion> *&);
void mostrarCancionesArchivo(string);
void mostrarCancion(Cancion);

Album insertarAlbum(Album *&, int);
Album *buscarAlbum(Album *, int);
Album *cargarCache(string);

void mostrarAlbum(Album *);
void mostrarAlbumes(Album *);    

//
// # Main
//
int main(){
	Album *lista = NULL;    

    //cargarCanciones();    
    lista = cargarCache(ARCHIVO_NOMBRE);

    // muestro los albumes cargados
    mostrarAlbumes(lista);

	return 0;
}

//
// # Funciones
//
int criterioOrdenAsc(Cancion c1, Cancion c2){    
    // ascendente
    // orden: 3, orden:5, 3-5 = -2,     
    return c1.orden-c2.orden;
}

int criterioOrdenDesc(Cancion c1, Cancion c2){    
    // ascendente
    // orden: 3, orden:5, 3-5 = -2,     
    return c1.orden-c2.orden;
}

void mostrarCancion(Cancion c){
    printf("orden: %i, id_album: %i, id_cancion: %i, audio: %s\n", c.orden, c.id_album, c.id_cancion, c.audio);
}

void mostrarAlbum(Album *album){
    cout << "Album: " << album->id_album << endl;
    cout << "Canciones: " << endl;

    Nodo<Cancion> *aux = album->canciones;

    while(aux != NULL){
        mostrarCancion(aux->info);

        aux = aux->sig;                 
    }

    cout << endl;
}

void mostrarAlbumes(Album *lista){    
    Album *aux = lista;

    while(aux != NULL){        
        mostrarAlbum(aux);

        aux = aux->sig;
    }
}

Album *cargarCache(string nombreArchivo){    
    FILE *f;
    Album *lista = NULL;
    Album *albumEncontrado;
    Cancion cancion;

    // abro el archivo en modo lectura
    f = fopen(nombreArchivo.c_str(), "rb");

    // leo el primer registro
    fread(&cancion, sizeof(Cancion), 1, f);

    // itero hasta llegar al final del archivo
    while(!feof(f)){      
        // busco si ya existe un album y guardo los datos
        albumEncontrado = buscarAlbum(lista, cancion.id_album);
        // si el album no se encuentra en el listado
        if(albumEncontrado == NULL){
            // creo un album y lo inserto
            insertarAlbum(lista, cancion.id_album);
            albumEncontrado = buscarAlbum(lista, cancion.id_album);
            insertarOrdenado<Cancion>(albumEncontrado->canciones, cancion, criterioOrdenAsc);
        }
        else{
            // suponiendo que ya existe el album
            // le inserto la canción 
            insertarOrdenado<Cancion>(albumEncontrado->canciones, cancion, criterioOrdenAsc);
        }

        // avanzo al siguiente registro
        fread(&cancion, sizeof(Cancion), 1, f);
    } // end while

    fclose(f);

    return lista;
}

Album *buscarAlbum(Album *lista, int id_album){
    Album *aux = lista;

    while(aux != NULL && aux->id_album != id_album){
        aux = aux->sig;
    }

    return aux;
}

void mostrarCancionesArchivo(string archivoNombre){    
    FILE *f;
    // el tipo de registro que voy a leer y donde guardo los datos
    Cancion c;
    // abro el archivo binario en modo lectura
    f = fopen(archivoNombre.c_str(), "rb");
    // leo el primer registro
    fread(&c, sizeof(Cancion), 1, f);
    // recorro el archivo hasta el ultimo registro
    while(!feof(f)){
        // muestro los datos
        mostrarCancion(c);
        // avanzo al siguiente registro
        fread(&c, sizeof(Cancion), 1, f);
    } // end while

    // cierro la conexion para evitar errores de memoria
    fclose(f);
}

Cancion crearCancion(int id_cancion, int id_album, int orden, string audio){
    Cancion c;
    // cargo los datos
	c.id_cancion = id_cancion;
	c.id_album = id_album;
	c.orden = orden;
    strcpy(c.audio, audio.c_str());
    // retorno todo
    return c;
}

template <typename T> 
T pop(Nodo<T> *&lista){
    Nodo<T> *aux = lista;
    // guardo los datos del nodo actual a mostrar
    T info = lista->info;
    // cambio el puntero al siguiente
    lista = aux->sig;
    // borro de memoria
    delete aux;
    // retorno los datos del nodo previamente guardado
    return info;
}

Album insertarAlbum(Album *&lista, int id_album){
    Album *nuevo = new Album();
    nuevo->id_album = id_album;
    nuevo->sig = NULL;

    // si la lista está vacía
    if(lista == NULL){
        // agrego el nuevo nodo
        lista = nuevo;
    }
    // sino 
    else{
        Album *aux = lista;

        // recorro la lista hasta llegar al final
        while(aux->sig != NULL){
            // avanzo al siguiente
            aux = aux->sig;
        }

        // enlazo al ultimo nodo con el nuevo
        aux->sig = nuevo;
    } // end if
}

void cargarCancionesArchivo(string archivoNombre, Nodo<Cancion> *&canciones){
    FILE *f;

    // abro el archivo binario en modo escritura
    f = fopen(archivoNombre.c_str(), "wb");
    
    // recorro el listado canciones hasta el final
    while(canciones != NULL){
        // guardo en 'c' los datos de cada elemento de la lista
        Cancion c = pop(canciones);
        // lo escribo en el archivo binario
        fwrite(&c, sizeof(Cancion), 1, f);
    } // end while

    // cierro la conexión para evitar errores de memoria
    fclose(f);

}

void cargarCanciones(){
    Nodo<Cancion> *canciones = NULL; // sublista
    // Cargo canciones
    // canciones id_album = 1
	insertarOrdenado(canciones, crearCancion(1, 1, 2, "asdasd12345"), criterioOrdenAsc);
	insertarOrdenado(canciones, crearCancion(2, 1, 1, "asdasd12346"), criterioOrdenAsc);
    // canciones id_album = 2
	insertarOrdenado(canciones, crearCancion(3, 2, 1, "asdasd12347"), criterioOrdenAsc);
	insertarOrdenado(canciones, crearCancion(4, 2, 2, "asdasd12348"), criterioOrdenAsc);
    // canciones id_album = 3
	insertarOrdenado(canciones, crearCancion(5, 3, 1, "asdasd12348"), criterioOrdenAsc);
	insertarOrdenado(canciones, crearCancion(6, 3, 2, "asdasd12349"), criterioOrdenAsc);
    // canciones id_album = 4
	insertarOrdenado(canciones, crearCancion(7, 4, 1, "asdasd12350"), criterioOrdenAsc);
    // canciones id_album = 5
	insertarOrdenado(canciones, crearCancion(8, 5, 1, "asdasd12351"), criterioOrdenAsc);    
    
    // lo ejecuto sólo una vez para cargar las canciones el archivo binario
    cargarCancionesArchivo(ARCHIVO_NOMBRE, canciones);    
    //mostrarCancionesArchivo(ARCHIVO_NOMBRE);
}

template <typename T>
Nodo<T>* insertarOrdenado(Nodo<T>*& l, T v, int (*criterio)(T,T) ) {
    Nodo<T>* nuevo = new Nodo<T>();
    nuevo->info = v;
    nuevo->sig = NULL;
    Nodo<T>* aux = l;
    Nodo<T>* ant = NULL;

    // itera mientras que
    // el metodo criterio tenga valor cero ò negativo
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
