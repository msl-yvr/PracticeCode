#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>


using namespace std;
using namespace System;

void ingresarJugadores(char* jugadores, int* puntajes, int tam){
    for (int i = 0; i < tam; i++)
    {
        cout << "\nIngrese el nombre del jugador "<<i+1<<": ";
        cin >> jugadores[i];
        cout << "Ingrese su puntaje: ";
        cin >> puntajes[i];
    }
    cout << endl;
}

void ordenarJugadoresPuntaje(char* jugadores, int* puntajes, int tam){
    char auxJugadores;
    int auxPuntajes;
    for (int i = 0; i < tam-1; i++)
    {
        for (int j = i+1; j < tam; j++)
        {
            if (puntajes[i]<puntajes[j])
            {
                auxPuntajes = puntajes[i];
                puntajes[i] = puntajes[j];
                puntajes[j] = auxPuntajes;

                auxJugadores = jugadores[i];
                jugadores[i] = jugadores[j];
                jugadores[j] = auxJugadores;
            }
        }
    }

}

int buscarJugadorPorNombre(char* jugadores, int* puntajes, int tam, char nombre) {

    for (int i = 0; i < tam; i++)
    {
        if (nombre == jugadores[i])
        {
            return i; //posicion del jugaddor buscado
        }
        else return -1;//jugador no encontrado
    }
}

double calcularPromedio(int* puntajes, int tam) {
    double suma = 0;
    for (int i = 0; i < tam; i++)
    {
        suma += puntajes[i];
    }
    return (double)suma / tam;
}

void mostrarRankingFinal(char* jugadores, int* puntajes, int tam) {
    cout << "Ranking de jugadores............." << endl;
    for (int i = 0; i < tam; i++)
    {
        cout << i + 1 << ") Jugador " << jugadores[i] << "- " << puntajes[i] << " puntos" << endl;
    }
}
int main() {

    //ingreso de cantidad de jugadores
    int n;
    cout << "Ingrese la cantidad de jugadores: "; 
    cin >> n;

    char* jugadores = new char[n];
    int* puntajes = new int[n];

    ingresarJugadores(jugadores, puntajes, n);
    ordenarJugadoresPuntaje(jugadores, puntajes, n);
    mostrarRankingFinal(jugadores, puntajes, n);

    //buscar dentro del ranking
    char nombreBuscar;
    int posicionEncontrada;
    cout << "\nIngrese el nombre(char) a buscar: ";
    cin >> nombreBuscar;
    posicionEncontrada = buscarJugadorPorNombre(jugadores, puntajes, n, nombreBuscar);
    if (posicionEncontrada != -1)
    {
        cout << "El jugador " << jugadores[posicionEncontrada] << " fue encontrado y tiene un puntaje de " << puntajes[posicionEncontrada] << endl;
    }
    else 
    {
        cout << "El jugador no fue encontrado" << endl;
    }

    //calcular promedio de todos los puntajes
    double promedio = calcularPromedio(puntajes, n);
    cout << "El promedio de puntajes es " << promedio << endl;

    //eliminamos los arreglos dinamicos del heap
    delete[] puntajes;
    delete[] jugadores;

    system("pause>0");
    return 0;
}
