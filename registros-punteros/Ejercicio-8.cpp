#include <iostream>
#include <cstdio>

using namespace std;

// structs
struct Empleado{
	char nombre[30];
	int edad;
};

// prototipos
void leer();
void escribir();
void menu();

// variables globales
FILE *ARCHIVO;

int CANTIDAD_EMPLEADOS = 2;
Empleado *EMPLEADOS = new Empleado[CANTIDAD_EMPLEADOS];
char ARCHIVO_NOMBRE[20] = "Empleados.dat";

// main
int main(){
	cout<<"Nombre del archivo:";
	cin>>ARCHIVO_NOMBRE;
	/*
	// Comentado porque no funciona variar el tamaño por el momento
	cout<<"Cantidad de Empleados:";
	cin>>CANTIDAD_EMPLEADOS;
	*/
	
	menu();

	delete[] EMPLEADOS;
	
	return 0;
}

// funciones
void menu(){
	int opcion;

	cout<<"1. Leer"<<endl;
	cout<<"2. Escribir"<<endl;
	cout<<"3. Salir"<<endl;
	
	while(opcion != 3){
		cout<<"Escriba la opcion: ";
		cin>>opcion;
		
		switch(opcion){
		case 1:
			leer();
			break;
		case 2:
			escribir();
			break;
		}
	}
}

void leer(){	
	ARCHIVO = fopen(ARCHIVO_NOMBRE, "rb");

	if(ARCHIVO == NULL){
		cout << "El archivo no existe"<<endl;
	}else{
		fread(EMPLEADOS, sizeof(EMPLEADOS), 1, ARCHIVO);

		while(!feof(ARCHIVO)){
			for(int i=0; i<CANTIDAD_EMPLEADOS; i++){
				printf("Nombre: %s, Edad: %i\n", EMPLEADOS[i].nombre, EMPLEADOS[i].edad);
			}
			
			fread(EMPLEADOS, sizeof(EMPLEADOS), 1, ARCHIVO);
		}
	}
	
	fclose(ARCHIVO);
}

void escribir(){	
	ARCHIVO = fopen(ARCHIVO_NOMBRE, "wb");
	
	if(ARCHIVO == NULL){
		cout << "El archivo no existe.. (?)"<<endl;
	}else{		
		for(int i=0; i<CANTIDAD_EMPLEADOS; i++){
			cout<<"Nombre: ";
			cin>>EMPLEADOS[i].nombre;

			cout<<"Edad: ";
			cin>>EMPLEADOS[i].edad;
		}
		
		fwrite(EMPLEADOS, sizeof(EMPLEADOS), 1, ARCHIVO);
	}
	
	fclose(ARCHIVO);
}
