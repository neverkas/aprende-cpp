#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

// variables globales
int REGISTROS_CANT = 5;
char ARCHIVO_NOMBRE[20] = "registros.dat";

// struct
struct Registro{
  char nombre[30];
};

// main
int main (){
  FILE *f1, *f2;
  Registro *r = new Registro[REGISTROS_CANT];
	
  int personas_cant = 3;
  char personas[3][30] = {"Carlitos", "Pedrito", "Jorgito"};
	
  // cargo info
  for(int i=0; i<personas_cant; i++)
      strcpy (r[i].nombre, personas[i]);
	
  // escritura
  f1 = fopen (ARCHIVO_NOMBRE, "wb");
  fwrite (r, sizeof (r), personas_cant, f1);
  fclose (f1);
	
  // lectura
  f2 = fopen (ARCHIVO_NOMBRE, "rb");
  
  fread (r, sizeof (r), 1, f2);
	int i=0;
  while (!feof(f2)){
		
		if(string(r[i].nombre) == "Carlitos"){
			strcpy(r[i].nombre, "Roberto");
		}
		printf ("%s\n", r[i].nombre);
		
		fread (r, sizeof (r), 1, f2);		
		i++;
	}
    
  fclose (f2);
	
	delete[] r;

  return 0;
}
