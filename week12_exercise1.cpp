#include "pch.h"
#include <iostream>
#include <ctime>
#include <conio.h>
#include<cstdlib>

using namespace System;
using namespace std;

struct Encuestado
{
    int nivelAprovacion;
    int edad;
    char nivelSocioeconomico;
};

int ingresarNumeroEncuestados() {
    int tam;
    do
    {
        cout << "Ingrese el número de personas encuestadas: ";
        cin >> tam;
    } while (tam<0||tam>100);
    cout << endl;
    return tam;
}
void generarData(Encuestado* encuestados, int tam) {
    cout << "Nivel de aprobacion / edad / nivel Socioeconomico" << endl;
    for (int i = 0; i < tam; i++)
    {
        encuestados[i].nivelAprovacion = rand() % (5 - 1 + 1) + 1;
        encuestados[i].edad = rand() % (60 - 18 + 1) + 18;
        encuestados[i].nivelSocioeconomico = rand() % (68 - 65 + 1) + 65;
        cout << encuestados[i].nivelAprovacion << " | " << encuestados[i].edad << " | " << encuestados[i].nivelSocioeconomico << endl;
    }
}
void calcularNivelAprovacionConMayorVotacion(Encuestado* encuestados, int tam) {

    int max = encuestados[0].nivelAprovacion;
    for (int i = 1; i < tam; i++)
    {
        if (encuestados[i].nivelAprovacion>max)
        {
            max = encuestados[i].nivelAprovacion;
        }
    }
    cout << "El nivel de aprobacion que obtuvo la mayor votacion es: " << max << endl;
}

void calcularParticipantesDeNivelA(Encuestado* encuestados, int tam) {
    int ccNivelA = 0;
    for (int i = 0; i < tam; i++)
    {
        if (encuestados[i].nivelSocioeconomico=='A')
        {
            ccNivelA++;
        }
    }
    cout << "En el nivel socioeconomico A participaron " << ccNivelA << " personas" << endl;
}

void calcularEdadMasJoven(Encuestado* encuestados, int tam) {
    int min = encuestados[0].edad;
    for (int i = 1; i < tam; i++)
    {
        if (encuestados[i].edad<min)
        {
            min = encuestados[i].edad;
        }
    }
    cout << "La edad de la persona mas joven que fue encuestada es: " << min << endl;
}

int main() {
    srand(time(nullptr));

    int n = ingresarNumeroEncuestados();
    Encuestado* encuestados = new Encuestado[n];

    generarData(encuestados, n);
    calcularNivelAprovacionConMayorVotacion(encuestados, n);
    calcularParticipantesDeNivelA(encuestados, n);
    calcularEdadMasJoven(encuestados, n);
    delete[] encuestados;

    system("pause>0");
    return 0;
}
