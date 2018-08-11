/*
 * 
 * Mediciones.
 * Una estructura de datos de tipo array de 30 elementos almacena las
 * mediciones (sin decimales) de las muestras de un experimento.
 * Se pide: Crear un programa que gestione las Altas, Bajas y Modificaciones (ABM
 * o CRUD en ingles) de mediciones. Modularizar con subprogramas para que
 * desde una funcion principal se invoque a una especifica para cada funcionalidad
 * desde un menu de opciones. Tambien se debera ofrecer la posibilidad de ordenar
 * el array y mostrarlo.
 *
 * Observacion:
 * La manera correcta de manejar el tamanio de arreglos es mediante punteros,
 * pero se evita en este ejercicio para no confundir.
 * 
 */
#include <iostream>

using namespace std;

//
// # variables Globales
//
#define VECTOR_TAMANIO 30


//
// # Prototipos
//
void mostrarMediciones(int [], int);
void agregarMedicion(int [], int &, int);
void modificarMedicion(int [], int, int);
void eliminarMedicion(int [], int &, int);
void ordenar(int [], int);

//
// # Main
//
int main(){
	//
	// # Defino variables
	//
	int mediciones[VECTOR_TAMANIO] = {4,9,3,1,6};
	int len = 5;
	int medicion, posicion = 0;
	int menuOpcion;

	cout << "Ingrese el numero de la funcion a realizar" << endl;
	cout << "0: Finalizar programa " << endl;
	cout << "1: Agregar " << endl;
	cout << "2: Modificar " << endl;
	cout << "3: Eliminar " << endl;
	cout << "4: Ordenar " << endl;
	cout << "5: Mostrar todos los elementos " << endl;
	
	cout << "Opcion: ";
	cin >> menuOpcion;	
		
	while(menuOpcion != 0){		
		switch(menuOpcion){
			case 1: // Crear
				cout << "Ingrese la nueva medicion: "; 
				cin >> medicion;
				
				agregarMedicion(mediciones, len, medicion);
			break;
			case 2: // Modificar
				cout << "Ingrese la posicion de la medicion a modificar: "; 
				cin >> posicion;

				cout << "Ingrese la nueva medicion: "; 
				cin >> medicion;

				modificarMedicion(mediciones, posicion, medicion);
			break;
			case 3: // Eliminar
				cout << "Ingrese la posicion de la medicion a eliminar: "; 
				cin >> posicion;
				
				eliminarMedicion(mediciones, len, posicion);
			break;	
			case 4: // Ordenar
				ordenar(mediciones, len);
			break;
			case 5: // Mostrar Mediciones
				mostrarMediciones(mediciones, len);
			break;
		} // end switch
		
		cout << "Opcion: ";
		cin >> menuOpcion;
	} // end while
	
	return 0;
}

//
// # Funciones
//
void mostrarMediciones(int mediciones[], int len){
	cout << "Mediciones: ";
	
	// recorro el vector unidimensional 'mediciones'
	for(int i=0; i < len; i++){
	    // imprimo cada elemento del vector
	    // utilizando el incremental 'i' como indice de cada elemento
		cout << mediciones[i] << ", ";
	}
	
	cout << endl;
}

void agregarMedicion(int mediciones[], int &len, int medicion){
	// Si no supera el tamanio del vector
	if(len < VECTOR_TAMANIO){
    // agrego al vector unidimensional 'mediciones' un nuevo elemento
	mediciones[len] = medicion;
	
    // incremento en +1 por cada llamada a la funcion
    // aumentando el tamanio del vector
	len++;
	}
}

void eliminarMedicion(int mediciones[], int &len, int posicion){	
    // recorro el vector unidimensional 'mediciones'
    // comienzo desde el final del vector y voy desplazando cada elemento
    // hacia la derecha hasta llegar al vector que deseo remover
	for(int i=posicion; i > len ; i--){
	    // al elemento actual le asigno el valor del elemento anterior
		mediciones[i] = mediciones[i-1];
	}
	
	// por cada llamado a la funcion decremento el valor de 'len'
	// reduciendo el tamanio del vector
	len--;
}

void modificarMedicion(int mediciones[], int posicion, int nuevaMedicion){
    // Modifico un elemento a partir de su indice/posicion en el arreglo
    mediciones[posicion] = nuevaMedicion;
}

void ordenar(int mediciones[], int len){
    // Ordenamiento por insercion
    // 3,4,5,1
    // 3,4,5,(1)
    // 

    int aux, i, j;
    
    // recorro todos los elementos
    for(int i=0; i < len; i++){
        // guardo el valor de cada elemento hasta que se cumpla la condicion del segundo bucle for
        aux = mediciones[i];
        // Ejecuto el segundo for mientras se cumplan las sig condiciones:
        // -Si el valor del elemento anterior es mayor al del elemento actual
        // -Si la posicion es mayor a cero (porque no tiene sentido analizar un elemento que no 
        // esta en el vector)
        // *Mientras se cumplan ambas condiciones recorro desde donde me detuve hacia la izquierda
        for(j=i; j > 0 && mediciones[j-1] > aux; j--){
            // desplazo los elementos de mayor valor hacia la derecha
            // reemplazo el elemento actual(de menor valor) por el anterior(de mayor valor)
            mediciones[j] = mediciones[j-1];
        } // end for
        
        // cuando la condicion del segundo bucle se deja de cumplir
        // modifico el elemento hasta donde se detuvo
        mediciones[j] = aux;
    } // end for
}
