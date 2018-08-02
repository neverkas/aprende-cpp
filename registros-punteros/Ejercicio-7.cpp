/*
 * ESTRUCTURA DINAMICA (CON PUNTEROS)
*/
#include <iostream>
#include <cstdio>

using namespace std;

struct Empleado{
	int id;
	char nombre[20];
	float sueldo;
};

// prototipos
int crear(Empleado e);
int modificar(Empleado e);

int main(){
	int cantidad, *numeros;	

	cout<<"Cantidad: ";
	cin>>cantidad;

	cout<<"# PRUEBA 1 (vector dinamico tipo INT):"<<endl;
	// -El puntero es *numeros, pero al asignar valores
	// se puede hacer llamando a la variable sin el *,
	// se debe declarar con el asterisco.
	// -Al puntero le asigno un vector dinamico del tipo int
	// 'cantidad' asigna el tamaño al vector
	numeros = new int[cantidad];

	for(int i=0; i<cantidad; i++){
		cout<<"Ingrese un numero: ";
		cin>>numeros[i];
	}
	
	for(int i=0; i<cantidad; i++){
		// -Con el asterisco *, retorna el valor
		// -Sin el asterisco *, retorna la posicion en memoria en hexadecimal
		cout<< *(numeros+i) << " ";
	}
	
	cout<<endl;
	
	cout<<"# PRUEBA 2 (vector dinamico tipo STRUCT):"<<endl;

	/*
	 * Empleado *empleados = new Empleado[cantidad];
	 *
	 * Defino el puntero *empleados con la estructura Empleado,
	 * y le asigno un Arreglo dinámico con la estructura Empleado
	 * (es dinámico porque su tamaño se modifica por el valor de 'cantidad')
	 * Se utiliza 'new' para reservar un espacio en memoria, que dependerá
	 * del tamaño del vector que se genere.
	 * Sino se hace mediante 'new', puede pisar espacio en memoria que se utiliza
	 * para otra cosa.
	 */
	
	Empleado *empleados = new Empleado[cantidad];
	for(int i=0; i<cantidad; i++){
		empleados[i].id = i; // asigno un ID
		
		cout<<"Nombre: ";
		cin>>empleados[i].nombre;
		
		cout<<"Sueldo: ";
		cin>>empleados[i].sueldo;
	}

	cout<<"EMPLEADOS: "<<endl;
	for(int i=0; i<cantidad; i++){
		printf("-%s $%4.2f\n", empleados[i].nombre, empleados[i].sueldo);
	}

	cout<<endl;
				
	// Limpio el espacio en memoria que ocupaba el vector dinamico
	// si es un array agregar delete[]
	delete[] numeros;
	delete[] empleados;
	
	return 0;
}
