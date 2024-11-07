#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace System;
using namespace std;

void generarData(int* arreglo, int tam) {
	cout << "Generando los datos del arreglo de forma aleatoria: " << endl;
	for (int i = 0; i < tam; i++)
	{
		arreglo[i] = rand() % (100 - 1 + 1) + 1;
		cout << arreglo[i] << " ";
	}
	cout << endl;
}
void buscarMayorElemento(int* arreglo, int tam) {
	cout << "Buscando el mayor y mostrando su ubicacion : " << endl;
	int mayor = arreglo[0];
	int posMayor = 0;
	for (int i = 1; i < tam; i++)
	{
		if (arreglo[i]>mayor)
		{
			mayor = arreglo[i];
		}
	}
	for (int i = 0; i < tam; i++)
	{
		if (arreglo[i]==mayor)
		{
			posMayor = i;
		}
	}
	cout << "El mayor es " << mayor << " y se encuentra en la posicion " << posMayor << endl;
}

void buscarMenorElemento(int* arreglo, int tam) {
	cout << "Buscando el menor y mostrando su ubicacion: " << endl;
	int menor = arreglo[0];
	int posMenor = 0;
	for (int i = 1; i < tam; i++)
	{
		if (arreglo[i]<menor)
		{
			menor = arreglo[i];
		}
	}
	for (int i = 0; i < tam; i++)
	{
		if (arreglo[i] == menor)
		{
			posMenor = i;
		}
	}
	cout << "El menor es " << menor << " y se encuentra en la posicion " << posMenor << endl;
}

void ordenarDescendente(int* arreglo, int tam) {
	cout << "Arreglo en forma descendente: " << endl;
	int temp;
	for (int i = 0; i < tam-1; i++)
	{
		for (int j = i+1; j < tam; j++)
		{
			if (arreglo[i]<arreglo[j])
			{
				temp = arreglo[i];
				arreglo[i] = arreglo[j];
				arreglo[j] = temp;
			}
		}
	}
	for (int i = 0; i < tam; i++)
	{
		cout << arreglo[i] << " ";
	}
	cout << endl;
}
int main()
{
	int tam;
	do
	{
		cout << "Ingrese el tamano del arreglo: ";
		cin >> tam;
		if (tam < 0 || tam>100)
		{
			cout << "Intente de nuevo" << endl;
		}

	} while (tam<0||tam>100);
	int* arreglo = new int[tam];
	int opcion;
	do
	{
		cout << "Menu" << endl;
		cout << "1) Listar en pantalla los elementos del arreglo" << endl;
		cout << "2) Buscar el mayor y mostrar su ubicacin" << endl;
		cout << "3) Buscar el menor y mostrar su ubicacion" << endl;
		cout << "4) Ordenar el arreglo en forma descendente y mostrarlo en pantalla" << endl;
		cout << "5) Salir" << endl;
		cout << "Ingrese una opcion...";
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			generarData(arreglo, tam);
			break;
		case 2:
			buscarMayorElemento(arreglo, tam);
			break;
		case 3:
			buscarMenorElemento(arreglo, tam);
			break;
		case 4:
			ordenarDescendente(arreglo, tam);
			break;
		case 5:
			delete[]arreglo;
			cout << "Saliendo del programa..." << endl;
			break;
		default:
			cout << "Opcion invalida ";
			break;
		}

	} while (opcion!=5);

    system("pause>0");
    return 0;
}
