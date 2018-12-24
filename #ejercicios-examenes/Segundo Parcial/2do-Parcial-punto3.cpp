/*
* 
* SENSORES IOT
* 
* Se debe crear un módulo que recupere la secuencia de mediciones obtenidas desde un conjunto de sensores 
* de temperatura ubicados en posiciones remotas y cuyos enlaces​ ​ de​ ​ comunicaciones​ ​ son​ ​ inestables.
* 
* Se​ ​ pide​ :
* -Crear​ ​ las​ ​ estructuras​ ​ necesarias.
* -Crear la función ​ leer() que lea el archivo de texto donde se guardaron las mediciones (a medida que
* pudieron ser transmitidas) y agregarlas a una estructura de datos en memoria. Para una misma hora
* puede haber ninguna o muchas mediciones, por lo que las mediciones de una misma hora deberán
* ser​ ​ parte​ ​ de​ ​ una​ ​ sublista​ ​ correspondiente​ ​ a ​ ​ esa​ ​ hora.
* -Cada nodo de la lista deberá contener el dato de la hora (entero) y un puntero otra lista cuyos nodos
* deberán​ ​ contener:​ ​ identificador​ ​ del​ ​ sensor​ ​ (entero)​ ​ y ​ ​ medición​ ​ (decimal).
* 
* -Los​ ​ datos​ ​ leídos​ ​ del​ ​ archivo​ ​ de​ ​ texto​ ​ poseen​ ​ el​ ​ siguiente​ ​ formato:
* <id-sensor>,​ ​ <hora:minutos-lectura>,​ ​ <medición>​ ​ (A​ ​ razón​ ​ de​ ​ una​ ​ medición​ ​ por​ ​ línea).
* 
* Mostrar​ ​ por​ ​ pantalla​ ​ el​ ​ contenido​ ​ de​ ​ cada​ ​ nodo/subnodos​ ​ con​ ​ el​ ​ siguiente​ ​ formato:
* <hora0>:​ ​ <id-sensor-1,​ ​ medición1>,​ ​ <id-sensor-2,​ ​ medición2>,​ ​ <id-sensor-N,​ ​ mediciónN>
* <hora1>:​ ​ <id-sensor-1,​ ​ medición1>,​ ​ <id-sensor-2,​ ​ medición2>,​ ​ <id-sensor-N,​ ​ mediciónN>
* 
* Nota​ : El archivo de mediciones es suministrado. Para dividir por el caracter ‘,’ las palabras de la línea
* con las mediciones, se recomienda emplear la función ​ strtok.
* 
*/
#include <iostream>
#include <stdio.h> // fopen, fread, fwrite, ..
#include <string.h> // strtok

using namespace std;

#define ARCHIVO_CSV "mediciones.csv"

//
// # Structs
//
struct Medicion{
    int hora;
    int id;
    float medicion;
};

struct MedicionSubLista{
    int id;
    float medicion;

    MedicionSubLista *sig;
};

struct MedicionLista{
    int hora;

    MedicionSubLista *sublista;
    MedicionLista *sig;
};

//
// # Prototipos
//
void procesarInformacion(char [], Medicion &);
MedicionSubLista *popSubLista(MedicionSubLista *&);
MedicionLista *popLista(MedicionLista *&);
void pushSubLista(MedicionSubLista *&, Medicion);
void pushLista(MedicionLista *&, Medicion);
void leer(MedicionLista *&);
void imprimirLista(MedicionLista *);

//
// # Main
//
int main(){
    MedicionLista *lista = NULL;
    
    leer(lista);
    imprimirLista(lista);
    
    return 0;
}

//
// # Funciones
//
void procesarInformacion(char info[], Medicion &m){
    // defino la cantidad de campos a guardar
    int cantidadCampos = 3;
    // vector donde guardo cada dato por separado
    string listaDatos[cantidadCampos];
    char *datos;
    
    // particiono los datos con strtok() por el caracter ','
    datos = strtok(info, ",");

    // separo el contenido en un vector, para que sea más facil manipular la información
    // recorro las particiones guardadas hasta llegar a la última
    for(int i=0; datos != NULL ;i++){
        // guardo en el vector cada dato obtenido
        listaDatos[i] = datos;
        // avanzo con la siguiente particion
        // (el final y el principio de cada particion esta separada por dato del tipo NULL)
        datos = strtok(NULL, ",");
    }

    // convierto el dato tipo string a int
    sscanf(listaDatos[0].c_str(), "%d", &m.id);
    // convierto el dato tipo string a int
    sscanf(listaDatos[1].c_str(), "%d", &m.hora);
    // convierto el dato tipo string a float
    sscanf(listaDatos[2].c_str(), "%f", &m.medicion);
}

MedicionSubLista *popSubLista(MedicionSubLista *&sublista){
    MedicionSubLista *aux = sublista;
    // apunto al nodo siguiente del actual
    sublista = sublista->sig;

    //delete aux;
    // retorno el actual
    return aux;
}

MedicionLista *popLista(MedicionLista *&lista){
    MedicionLista *aux = lista;
    // apunto al nodo siguiente del actual
    lista = lista->sig;

    //delete aux;
    // retorno el actual
    return aux;
}

void pushSubLista(MedicionSubLista *&sublista, Medicion m){
    MedicionSubLista *nuevo = new MedicionSubLista();
    nuevo->id = m.id;
    nuevo->medicion = m.medicion;
    nuevo->sig = NULL;

    if(sublista == NULL){
        sublista = nuevo;
    }
    else{
        MedicionSubLista *aux = sublista;

        while(aux->sig != NULL){
            aux = aux->sig;
        }

        aux->sig = nuevo;
    } // end while

}

void pushLista(MedicionLista *&lista, Medicion m){
    MedicionLista *nuevo = new MedicionLista();
    // asigno los datos
    nuevo->hora = m.hora;
    // me aseguro que el final de la lista sea NULL
    nuevo->sig = NULL;
    nuevo->sublista = NULL;

    // si la lista está vacía
    if(lista == NULL){
        // inserto el nuevo nodo
        lista = nuevo;
    }
    else{        
        // creo una lista auxiliar para recorrer
        MedicionLista *aux1 = lista, *aux2 = lista;

        // recorro la lista hasta llegar al final
        // verifico que no se repita el dato 'hora'
        while(aux1->sig != NULL && aux1->hora != m.hora){
            // avanzo al siguiente nodo
            aux1 = aux1->sig;    
        }           
        // enlazo al ultimo nodo con el nuevo        
        aux1->sig = nuevo;

        // recorro nuevamente la lista
        while(aux2->sig != NULL){
            // si la hora del elemento a agregar coincide 
            if(aux2->hora == m.hora){
                // lo agrego a la sublista
                pushSubLista(aux2->sublista, m);
            }

            aux2 = aux2->sig;    
        } // end while
 
    } // end if
}

void leer(MedicionLista *&lista){   
    Medicion m;

    FILE *f;
    // determino que cada renglon tendrá un limite de hasta 20 caracteres
    // es lo que va a guardar en 'linea'
    char linea[20];
    // abro el archivo de texto en modo lectura
    f = fopen(ARCHIVO_CSV, "rt");    
    // obtengo la primera linea de texto
    fscanf(f, "%s", linea);
    // recorro el archivo hasta llegar al final del mismo
    while(!feof(f)){
        // proceso la informacion del archivo y la guardo de manera que se pueda manipular con facilidad
        // la informacion procesada se guarda en 'm'
        procesarInformacion(linea, m);

        // inserto sin repetir datos
        pushLista(lista, m);
        
        // obtengo la siguiente linea de texto
        fscanf(f, "%s", linea);
    } // end while
    // cierro el archivo para evitar fallas en el programa
    fclose(f);
}

void imprimirLista(MedicionLista *lista){
    int id, hora;    
    float medicion;
    
    while(lista != NULL){
        MedicionLista *aux1 = popLista(lista);

        printf("<hora%i>: ", aux1->hora);

        while(aux1->sublista != NULL){
            MedicionSubLista *aux2 = popSubLista(aux1->sublista);

            printf("<id-sensor-%i, medicion-%1.0f>", aux2->id, aux2->medicion);

            delete aux2;
        } // end while

        cout << endl;

        // borro de memoria 
        delete aux1;
    } // end while
}
