/*
 * CREAR PERSONAJES DE FICCION
 * SIMULAR BATALLAS/ESCENARIOS/CONFRONTAMIENTOS
*/
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

struct Habilidades{
};
	
struct Personaje{
	//char nombre[30];
	string nombre;
	string tipo;
	int vida;
	int fuerza;
	struct Habilidades habilidades_info;
};

// prototipos
Personaje * crear_personaje(string, string,int, int);
void atacar(Personaje *p1, Personaje *p2);
void imprimir(Personaje *p);

int main(){
	Personaje *p1, *p2;
    
	p1 = crear_personaje("Thanos", "villano", 100, 50);
	p2 = crear_personaje("Thor", "heroe", 100, 50);

	cout << "#PERSONAJES: "<<endl;
	imprimir(p1);
	imprimir(p2);

	cout<<endl;
	
	cout << "#SIMULACION DE BATALLA:"<<endl;
	atacar(p1, p2);

	imprimir(p1);
	imprimir(p2);
	
	delete p1;
	delete p2;
}

// funciones
Personaje * crear_personaje(string nombre, string tipo, int vida, int fuerza){
	Personaje * p = new Personaje;
	p->nombre = nombre;
	//strcpy(p->nombre, nombre);
	p->tipo = tipo;
	p->vida = vida;
	p->fuerza = fuerza;
	
	return p;
}

void atacar(Personaje *p1, Personaje *p2){
    //printf("%s ataca a %s !!\n", p1->nombre, p2->nombre);
	cout << p1->nombre << " ataca a " << p2->nombre << "!!" << endl;
	p2->vida-=p2->fuerza;
}

void imprimir(Personaje *p){
	//printf("%s el %s : %i de Fuerza, %i de Vida.\n", p>nombre, p->tipo, p->fuerza, p->vida);    
	cout << "-"<< p->nombre <<" el "<< p->tipo << ": ";
	cout<< p->fuerza <<" de Fuerza, ";
	cout<< p->vida <<" de Vida.";
	cout<<endl;
}
