/*
 * Estructuras anidadas
 * Crear una estructura Hechicero y anidar una estructura Mascota,
 * 
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct Mascota{
	char nombre[20];
	char tipo[20];
};

struct Hechicero{
	char nombre[20];
	int vitalidad;
	struct Mascota mascota_info;
} Hechiceros[2];

int main(){
	for(int i=0; i<2; i++){
		cout<<"Nombre: ";
		cin>>Hechiceros[i].nombre;
		cout<<"Vitalidad: ";
		cin>>Hechiceros[i].vitalidad;
		
		cout<<"Mascota";
		cout<<"-Nombre: ";
		cin>>Hechiceros[i].mascota_info.nombre;
		cout<<"-Tipo: ";
		cin>>Hechiceros[i].mascota_info.tipo;
		cout<<endl;
	}
	cout<<endl;
	
	for(int i=0; i<2; i++){
		cout<<"Nombre: "<<Hechiceros[i].nombre;
		cout<<"Vitalidad: "<<Hechiceros[i].vitalidad;
		
		cout<<"Mascota"<<endl;
		cout<<"-Nombre: "<<Hechiceros[i].mascota_info.nombre;
		cout<<"-Tipo: "<<Hechiceros[i].mascota_info.tipo;
		cout<<endl<<endl;
	}
	
	return 0;
}
