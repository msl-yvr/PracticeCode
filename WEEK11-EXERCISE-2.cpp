#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace System;

int validarTam() {
    int n;
    cout << "Ingrese el numero de alumnos: ";
    cin >> n;
    return n;
}
void generarNotas(int* notas, int tam) {
    for (int i = 0; i < tam; i++)
    {
        notas[i] = rand() % 20 + 1;
    }
}
void listarNotas(int* notas, int tam) {
    cout << "Las notas son: ";
    for (int i = 0; i < tam; i++)
    {
        cout << notas[i] << " ";
    }
    cout << endl;
}
void mostrarMayorNota(int* notas, int tam) {
    int maximo = notas[0];
    for (int i = 1; i < tam; i++)
    {
        if (notas[i]> maximo)
        {
            maximo = notas[i];
        }
    }
    cout << "La mayor nota es " << maximo << endl;
}
void mostrarMenorNota(int* notas, int tam) {
    int minimo = notas[0];
    for (int i = 1; i < tam; i++)
    {
        if (notas[i]<minimo)
        {
            minimo = notas[i];
        }
    }
    cout << "La mayor nota es " << minimo << endl;
}

void mostrarNotaPromedio(int* notas, int tam) {
    double suma = 0;
    for (int i = 0; i < tam; i++)
    {
        suma += notas[i];
    }
    cout << "La nota promedio es " << double(suma / tam) << endl;
}
void mostrarPorcentajeAprobados(int* notas, int tam) {
    int numeroAprobados = 0;
    int numeroDesa = 0;

    for (int i = 0; i < tam; i++)
    {
        if (notas[i]>=13)
        {
            numeroAprobados++;
        }
        if (notas[i]<13)
        {
            numeroDesa++;
        }
    }
 
    cout << "El porcentaje de aprobados es " << double(numeroAprobados*100.0/tam) << "% " << endl;
    cout << "El porcentaje de desaprobados es " << double(numeroDesa * 100.0 / tam) << "% " << endl;
}

void ordenarDescendente(int* notas, int tam) {
    int auxNotas;
    for (int i = 0; i < tam-1; i++)
    {
        for (int j = i+1; j < tam; j++)
        {
            if (notas[j]>notas[i])
            {
                auxNotas = notas[i];
                notas[i] = notas[j];
                notas[j] = auxNotas;
            }
        }
    }
}

int main() {
    srand(time(0));

    int tam = validarTam();
    int* notas = new int[tam];
    generarNotas(notas, tam);

    int option;
    do
    {
        cout << "-----MENU------"<<endl;
        cout << "1) Listar en pantalla las notas" << endl;
        cout << "2) Mostrar la mayor nota " << endl;
        cout << "3) Mostrar la menor nota " << endl;
        cout << "4) Mostrar la nota promedio " << endl;
        cout << "5) Mostrar el porcentaje de aprobados y desaprobados " << endl;
        cout << "6) Ordenar el arreglo en forma descendente " << endl;
        cout << "7) Salir " << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            listarNotas(notas, tam);
            break;   
        case 2:
            mostrarMayorNota(notas, tam);
                break;
        case 3:
            mostrarMenorNota(notas, tam);
            break;
        case 4:
            mostrarNotaPromedio(notas, tam);
            break;
        case 5:
            mostrarPorcentajeAprobados(notas, tam);
            break;
        case 6:
            ordenarDescendente(notas, tam);
            listarNotas(notas, tam);
            break;
        case 7:
            delete[] notas;
            cout << "Saliendo del programa.....";
            break;
        default:
            cout << "Opcion invalida, intentar de nuevo: ";
            break;
        }

    } while (option!=7);

    system("pause>0");
    return 0;
}
