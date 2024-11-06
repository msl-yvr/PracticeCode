#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace System;
using namespace std;

struct Persona
{
    char sexo;
    int edad;
    float monto;
};
int solicitarNumeroPersonas() {
    int numPersonas;
    cout << "Ingrese el numero de personas: ";
    cin >> numPersonas;
    return numPersonas;
}

void generarData(Persona* personas, int tam) {
    int numeroGen;
    for (int i = 0; i < tam; i++)
    {
        numeroGen = rand() % 2;
        if (numeroGen==0)
        {
            personas[i].sexo = 'M';
        }
        else personas[i].sexo = 'F';
        personas[i].edad = rand() % (50 - 15 + 1) + 15;
        personas[i].monto = rand() % (500 - 25 + 1) + 25;
    }
}

void listarNmontos(Persona* personas, int tam) {
    cout << "1) El listado de los N montos generados al azar: " << endl;
    for (int i = 0; i < tam; i++)
    {
        cout << "Persona " << i + 1 << ": Monto de " << personas[i].monto << endl;
    }
}

void ordenarAscendenteGeneroMontos (Persona* personas, int tam) {
    cout << "2) El listado ordenado ascendentemente segun el genero y los montos: " << endl;
    Persona temp;
    for (int i = 0; i < tam-1; i++)
    {
        for (int j = i+1; j < tam; j++)
        {
            if (personas[i].sexo > personas[j].sexo)
            {
                temp = personas[i];
                personas[i] = personas[j];
                personas[j] = temp;
            }
            else if (personas[i].sexo == personas[j].sexo && personas[i].monto > personas[j].monto)
            {
                temp = personas[i];
                personas[i] = personas[j];
                personas[j] = temp;
            }
        }
    }
}
void promedioSegunGenero(Persona* personas, int tam) {
    cout << "3) EL promedio de gasto segun cada genero: " << endl;
    int ccM = 0, ccF = 0;
    float sumaM = 0.0, sumaF = 0.0;
    for (int i = 0; i < tam; i++)
    {
        if (personas[i].sexo=='M')
        {
            ccM++;
            sumaM = sumaM + personas[i].sexo;
        }
        else if (personas[i].sexo == 'F')
        {
            ccF++;
            sumaF += personas[i].sexo;
        }
    }
    float promedio1 = ccM > 0 ? sumaM/tam : 0.0;
    float promedio2 = ccF > 0 ? sumaF/tam : 0.0;
    cout << "El gasto promedio en hombres es " << promedio1 << endl;
    cout<< "El gasto promedio en mujeres es " << promedio2 << endl;
}

void promedioEdad(Persona* personas, int tam) {
    cout << "4) El promedio de gasto segun la edad: " << endl;
    float sumaTotal = 0.0;
    for (int i = 0; i < tam; i++)
    {
        sumaTotal += personas[i].edad;
    }

    cout << "El promedio de edad es de " << float(sumaTotal / tam) << endl;
}
int main()
{
    srand(time(NULL));
    int tam = solicitarNumeroPersonas();
    Persona* personas = new Persona[tam];
    generarData(personas, tam);
    listarNmontos(personas, tam);
    ordenarAscendenteGeneroMontos(personas, tam);
    for (int i = 0; i < tam; i++)
    {
        cout << "Persona " << i + 1 << " - sexo " << personas[i].sexo << " - monto " << personas[i].monto << endl;
    }
    promedioSegunGenero(personas, tam);
    promedioEdad(personas, tam);

    delete[] personas;
    return 0;
}
