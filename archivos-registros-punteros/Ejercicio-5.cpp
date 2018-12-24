/*
 * Estructura con punteros
*/

#include <iostream>
#include <cstdlib>

using namespace std;

struct Poderes{
};

struct Heroe{
	char nombre[30];
	int fuerza, velocidad;
} heroes[2], *heroe = heroes;

struct Monstruo{
	char nombre[30];
	int fuerza, velocidad;
} m, *monstruo = &m;

int main(){
	cout<<"HEROES:"<<endl;
	for(int i=0; i<2; i++){
		cout<<"-Nombre: ";
		cin>>(heroe+i)->nombre;
	}

	cout<<"MONSTRUO:"<<endl;
	cout<<"-Nombre: ";
	cin>>monstruo->nombre;
	cout<<"-Fuerza: ";
	cin>>monstruo->fuerza;

	cout<<"HEROES:"<<endl;
	for(int i=0; i<2; i++){
		cout<<"* "<<(heroe+i)->nombre<<endl;
	}

	cout << "MONSTRUO:"<<endl;
	cout<<"*"<<monstruo->nombre<<endl;
	return 0;
}
