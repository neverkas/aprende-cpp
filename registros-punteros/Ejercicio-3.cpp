/*
 * Crear una Estructura Estudiante y crear 2 estudiantes,
 * agregar como atributos:
 * -Nombre
 * -Edad
 * -Materias (que se puedan cargar un máximo de 5)
 * Solicitar al usuario ingresar los datos mencionados por teclado,
 * imprimir la información.
 * 
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
 
using namespace std;

struct Estudiante{
	int numero_documento;
	char nombre[20];
	int edad;
	string materias[5];
};

// Variables globales
const int CANTIDAD_ESTUDIANTES = 2;

// prototipos
void menu();
void menu_opciones();
void agregar_estudiantes(Estudiante [], int);
void imprimir_estudiantes(Estudiante [], int);

void imprimir_estudiante(Estudiante [], int);
int buscar_estudiante(Estudiante [], int);

// VARIABLES GLOBALES
int main(){
	menu();
	
	return 0;
}

// funciones
void menu_opciones(){
	cout<<"##########################################################"<<endl;
	cout<<endl;
	
	cout<<"OPCIONES: "<<endl;
	cout<<"1. Agregar estudiantes (Maximo de 2 estudiantes por carga)"<<endl;
	cout<<"2. Imprimir listado de estudiantes"<<endl;
	cout<<"3. Buscar estudiante"<<endl;
	cout<<"4. Salir"<<endl;
}

void menu(){
	int opcion;
	
	Estudiante estudiantes[2];	
	
	int estudiante_documento_ingresar;
	int estudiante_posicion;

	menu_opciones();
	
	while(opcion != 4){
		//system("clear");
		//menu_opciones();
		
		cout<<"Escriba una opcion del menu: ";
		cin>>opcion;
			
		switch(opcion){
		case 1:
			agregar_estudiantes(estudiantes, CANTIDAD_ESTUDIANTES);
			break;
		case 2:
			imprimir_estudiantes(estudiantes, CANTIDAD_ESTUDIANTES);
			break;
		case 3:
			estudiante_posicion = buscar_estudiante(estudiantes, CANTIDAD_ESTUDIANTES);
			imprimir_estudiante(estudiantes, estudiante_posicion);
			break;
		}
	}
}

int buscar_estudiante(Estudiante estudiantes[], int cantidad){
	int posicion=0;
	int estudiante_documento_ingresar;
	
	cout<<"Numero de Documento del estudiante: ";
	cin>>estudiante_documento_ingresar;
	
	while(estudiantes[posicion].numero_documento != estudiante_documento_ingresar){		
			posicion++;
	}

	return posicion;
}

void agregar_estudiantes(Estudiante estudiantes[], int cantidad){
	for(int i=0; i<cantidad;i++){				
		printf("Estudiante #%i: \n", i);
		
		cout<<"Numero Documento: ";
		cin>>estudiantes[i].numero_documento;
		
		cout<<"Nombre: ";
		cin>>estudiantes[i].nombre;
		
		cout<<"Edad: ";
		cin>>estudiantes[i].edad;
	}
	
	cout<<endl;
}

void imprimir_estudiante(Estudiante estudiantes[], int posicion){
	cout << "# ESTUDIANTE ENCONTRADO: "<<endl;
	printf("Numero de documento: %i \n", estudiantes[posicion].numero_documento);
	printf("Nombre: %s \n", estudiantes[posicion].nombre);
	printf("Edad: %i \n", estudiantes[posicion].edad);
	cout<<endl;
}

void imprimir_estudiantes(Estudiante estudiantes[], int cantidad){
	cout << "# LISTADO DE ESTUDIANTES: "<<endl;
	for(int i=0; i<cantidad;i++){		
		printf("Estudiante #%i: \n", i);
		printf("Numero de documento: %i \n", estudiantes[i].numero_documento);
		printf("Nombre: %s \n", estudiantes[i].nombre);
		printf("Edad: %i \n", estudiantes[i].edad);
		cout<<endl;
	}
	
	//cout<<endl;
}

