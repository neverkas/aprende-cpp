#include <iostream>
#include <stdio.h>     /* sprintf */
#include <string.h>

using namespace std;

#define NOMBRE_ARCHIVO "goles-mundial.dat"
#define CANT_EQUIPOS 2 // 32
#define CANT_PARTIDOS 2 // 64

struct Gol{
    int id_gol;
    int cod_equipo;
    int fecha;
    char nombre_jugador[20];
    int id_partido;
};

struct Jugador{
    char nombre_jugador[20];
    int fecha;
    int goles;
    Jugador *sig;    
};

struct Equipo{
    int cod_equipo;
    Jugador *jugadores;
};


Gol crearGol(int id_gol, int cod_equipo, int fecha, string nombre_jugador, int id_partido){
    Gol g;
    g.id_gol = id_gol;
    g.cod_equipo = cod_equipo;
    g.fecha = fecha;
    strcpy(g.nombre_jugador, nombre_jugador.c_str());
    g.id_partido = id_partido;

    return g;
}

void crearArchivo(){
    Gol g1,g2,g3, g4, g5, g6, g7, g8, g9;
    FILE *f = fopen(NOMBRE_ARCHIVO, "wb");

    int partido, equipo, fecha;

    g1 = crearGol(1, 1, 20180110, "Gimenez", 1);
    g2 = crearGol(2, 1, 20180111, "Carlos", 1);
    g3 = crearGol(3, 1, 20180112, "Ramirez", 1);
    g4 = crearGol(4, 1, 20180112, "Ramirez", 2);
    g5 = crearGol(5, 2, 20180112, "PEdro", 2);
    g6 = crearGol(5, 2, 20180112, "Fernandez", 2);
    g7 = crearGol(5, 2, 20180112, "Juan", 2);
    g8 = crearGol(5, 2, 20180112, "Julio", 2);
    g9 = crearGol(5, 1, 20180112, "Ramirez", 2);

    fwrite(&g1, sizeof(Gol), 1, f);
    fwrite(&g2, sizeof(Gol), 1, f);
    fwrite(&g3, sizeof(Gol), 1, f);
    fwrite(&g4, sizeof(Gol), 1, f);
    fwrite(&g5, sizeof(Gol), 1, f);
    fwrite(&g6, sizeof(Gol), 1, f);
    fwrite(&g7, sizeof(Gol), 1, f);
    fwrite(&g8, sizeof(Gol), 1, f);
    fwrite(&g9, sizeof(Gol), 1, f);
    
    fclose(f);
}

void imprimirArchivo(){
    Gol g;
    FILE *f = fopen(NOMBRE_ARCHIVO, "rb");

    fread(&g, sizeof(Gol), 1, f);
    while(!feof(f)){        
        printf("id_gol: %i, cod_equipo: %i, fecha: %i, nombre_jugador: %s, id_partido: %i\n", g.id_gol, g.cod_equipo, g.fecha, g.nombre_jugador, g.id_partido);

        fread(&g, sizeof(Gol), 1, f);
    }

    fclose(f);
}

int main(){
    crearArchivo();
    
    return 0;
}