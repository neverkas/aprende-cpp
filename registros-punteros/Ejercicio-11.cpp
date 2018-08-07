#include <iostream>

using namespace std;

const int CANT_MUTANTES_MAX = 10;
const int CANT_PLANETAS_MAX = 10;

struct Mutante{
    string nombre;
    int fuerza;
};

struct Planeta{
    string nombre;
    struct Mutante mutantes[CANT_MUTANTES_MAX];
    int cantidadMutantes;
};

int main()
{
    int cantidadPlanetas;
    int cantidadMutantes;

    cout << "Cantidad de planetas: ";
    cin >> cantidadPlanetas;
    
    Planeta planetas[CANT_PLANETAS_MAX];
    
    for(int x=0; x < cantidadPlanetas; x++){
        Planeta planeta;
        cout << "# Planeta " << (x+1) << endl;
        cout << "Planeta: ";
        cin >> planeta.nombre;

        cout << "Cantidad de mutantes: ";
        cin >> planeta.cantidadMutantes;

        for(int i=0; i < planeta.cantidadMutantes; i++){
            Mutante mutante;

            cout << "# Mutante " << (i+1) << endl;
            cout << "\tNombre: ";
            cin >> mutante.nombre;
            cout << "\tFuerza: ";
            cin >> mutante.fuerza;
            cout << "-----------------------" << endl;
            
            // Agrego cada mutante cargado al vector 'mutantes'
            planeta.mutantes[i] = mutante;
        } // end for
        
        // Agrego cada Planeta al vector Planetas
        planetas[x] = planeta;

        cout << "----------------------------------" << endl;
    } // end for

    cout << endl;
    
    cout << "INFORMACION GUARDADA: " << endl;
    for(int x=0; x < cantidadPlanetas; x++){
        Planeta planeta = planetas[x];
        
        cout << "# Planeta " << (x+1) << endl;
        cout << "Nombre: " << planeta.nombre << endl;
        cout << "Mutantes:"<< endl;
        
        for(int i=0; i < planeta.cantidadMutantes; i++){
            Mutante mutante = planeta.mutantes[i];
            
            cout << "# Mutante " << (i+1) << endl;
            cout << "\tNombre: " << mutante.nombre << endl;
            cout << "\tFuerza: " << mutante.fuerza << endl;
            cout << "---------------------------" << endl;
        } // end for 
        
    } // end for

    return 0;
}
