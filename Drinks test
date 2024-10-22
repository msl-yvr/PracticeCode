#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h> // Para _getch(), solo disponible en Windows

using namespace std;
using namespace System;

// Función para registrar un voto y actualizar el total de votos
void registrarVotoBebida(int* contadorAgua, int* contadorJugo, int* contadorRefresco, int bebidaSeleccionada, int* totalVotos) {
    switch (bebidaSeleccionada) {
    case 1:
        (*contadorAgua)++;
        break;
    case 2:
        (*contadorJugo)++;

        break;
    case 3:
        (*contadorRefresco)++;
        break;
    default:
        cout << "Opción inválida." << endl;
        return;
    }
    (*totalVotos)++;
}

// Función para determinar y mostrar la bebida más popular
void determinarBebidaMasPopular(int* contadorAgua, int* contadorJugo, int* contadorRefresco) {
    cout << "\nLa bebida más popular es: ";
    if (*contadorAgua > *contadorJugo && *contadorAgua > *contadorRefresco) {
        cout << "Agua" << endl;
    }
    else if (*contadorJugo > *contadorAgua && *contadorJugo > *contadorRefresco) {
        cout << "Jugo" << endl;
    }
    else if (*contadorRefresco > *contadorAgua && *contadorRefresco > *contadorJugo) {
        cout << "Refresco" << endl;
    }
    else {
        cout << "Empate entre varias bebidas." << endl;
    }
}

// Función para calcular y mostrar los porcentajes y el total de votos
void mostrarPorcentajes(int* contadorAgua, int* contadorJugo, int* contadorRefresco, int totalVotos) {
    if (totalVotos == 0) {
        cout << "No hay votos registrados aún." << endl;
        return;
    }

    double porcentajeAgua = (*contadorAgua * 100.0) / totalVotos;
    double porcentajeJugo = (*contadorJugo * 100.0) / totalVotos;
    double porcentajeRefresco = (*contadorRefresco * 100.0) / totalVotos;

    cout << "\nResultados de la encuesta:" << endl;
    cout << "Agua: " << porcentajeAgua << "%" << endl;
    cout << "Jugo: " << porcentajeJugo << "%" << endl;
    cout << "Refresco: " << porcentajeRefresco << "%" << endl;
    cout << "Total de votos: " << totalVotos << endl;
}

int main() {
    int* contadorAgua = new int(0);
    int* contadorJugo = new int(0);
    int* contadorRefresco = new int(0);
    int totalVotos = 0;
    int opcion;
    int bebidaSeleccionada;

    do {
        cout << "\nSeleccione una opción:" << endl;
        cout << "1. Registrar voto" << endl;
        cout << "2. Ver porcentajes de popularidad" << endl;
        cout << "3. Ver bebida más popular" << endl;
        cout << "4. Salir" << endl;
        cout << "> ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "\nSeleccione su bebida favorita:" << endl;
            cout << "1. Agua" << endl;
            cout << "2. Jugo" << endl;
            cout << "3. Refresco" << endl;
            cout << "> ";
            cin >> bebidaSeleccionada;
            registrarVotoBebida(contadorAgua, contadorJugo, contadorRefresco, bebidaSeleccionada, &totalVotos);
            break;
        case 2:
            mostrarPorcentajes(contadorAgua, contadorJugo, contadorRefresco, totalVotos);
            break;
        case 3:
            determinarBebidaMasPopular(contadorAgua, contadorJugo, contadorRefresco);
            break;
        case 4:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
        }

    } while (opcion != 4);

    // Liberar memoria asignada dinámicamente
    delete contadorAgua;
    delete contadorJugo;
    delete contadorRefresco;

    return 0;
}
