#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace System;



//generar datos forma aleatoria
void generarDatosArreglo(int* arreglo, int tam) {
    for (int i = 0; i < tam; i++)
    {
        arreglo[i] = rand() % 100;
    }
}
//listar elementos del arreglo
void listarArreglo(int* arreglo, int tam) {
    cout << "Elementos del arreglo: ";
    for (int i = 0; i < tam; i++)
    {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}
//Buscar el mayor y mostrar su ubicación
void buscarMayorElemento(int* arreglo, int tam) {
    int posicion = 0;
    int maximo = arreglo[0];
    for (int i = 1; i < tam; i++)
    {
        if (arreglo[i]>maximo)
        {
            maximo = arreglo[i];
            posicion = i;
        }
    }
    cout << "El mayor es " << maximo << " y su posicion es " << posicion << endl;
}
//Buscar el menor y mostrar su ubicación
void buscarMenorElemento(int* arreglo, int tam) {
    int posicion = 0;
    int minimo = arreglo[0];
    for (int i = 1; i < tam; i++)
    {
        if (arreglo[i] < minimo)
        {
            minimo = arreglo[i];
            posicion = i;
        }
    }
    cout << "El menor es " << minimo << " y su posicion es " << posicion << endl;
}

//Ordenar el arreglo en forma descendente y mostrarlo en pantalla
void ordenarDescendente(int* arreglo, int tam) {
    int auxArreglo;
    for (int i = 0; i < tam-1; i++)
    {
        for (int j = i+1; j < tam; j++)
        {
            if (arreglo[j]>arreglo[i])
            {
                auxArreglo = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = auxArreglo;
            }
        }
    }

}

//validar tamano de arreglo
int validarTam() {
    int n;
    do
    {
        cout << "Ingrese el tamano del arreglo: "; cin >> n;
        if (n < 1 || n>100)
        {
            cout << "Tamano invalido vuelve a intentarlo: "; cin >> n;
        }
    } while (n < 1 || n>100);
    return n;
}

int main() {
    srand(time(0));

    int* arreglo = nullptr;
    int tam = validarTam();
    arreglo = new int[tam];
    generarDatosArreglo(arreglo, tam);

    int option;
      do
      {
          cout << ">>>>>MENU" << endl;
          cout << "1) Listar en pantalla los elementos del arreglo    " << endl;
          cout << "2) Buscar el mayor y mostrar su ubicación          " << endl;
          cout << "3) Buscar el menor y mostrar su ubicación          " << endl;
          cout << "4) Ordenar el arreglo en forma descendente y mostrarlo en pantalla" << endl;
          cout << "5) Salir " << endl;
          cin >> option;
          switch (option)
          {
          case 1:
              listarArreglo(arreglo, tam);
              break;
          case 2:
              buscarMayorElemento(arreglo, tam);
              break;
          case 3:
              buscarMenorElemento(arreglo, tam);
              break;
          case 4:
              ordenarDescendente(arreglo, tam);
              listarArreglo(arreglo, tam);
              break;
          case 5:
              delete[] arreglo;
              cout << "Programa finalizado..." << endl;
              exit(0);
              break;
          default:
              cout << "Opción no válida. Intente nuevamente." << endl;
              break;
          }
      } while (option!=6);

    system("pause>0");
    return 0;
}
