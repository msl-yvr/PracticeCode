#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace System;
using namespace std;

void ordenarDesdeMenorNota(int* notas, int tam) {
	int temp;
	for (int i = 0; i < tam-1; i++)
	{
		for (int j= i+1; j < tam; j++)
		{
			if (notas[i]>notas[j])
			{
				temp = notas[i];
				notas[i] = notas[j];
				notas[j] = temp;
			}
		}
	}
}

void eliminarMenorNota(int* &notas, int &tam) {
	int* nuevoArreglo = new int[tam - 1];
	for (int i = 1; i < tam; i++)
	{
		nuevoArreglo[i-1] = notas[i];
	}

	delete[] notas;
	notas = nuevoArreglo;
	tam--;
}

void calcularPromedio(int* notas, int tam) {
	double sumaTotal = 0.0;
	for (int i = 0; i < tam; i++)
	{
		sumaTotal += notas[i];
	}
	cout << "\nEl promedio sin la menor nota es " << double(sumaTotal / tam) << endl;
}

int main()
{
	int tam = 6;
	int* notas = new int[tam];

	for (int i = 0; i < tam; i++)
	{
		cout << "Ingrese la nota " << i + 1 << " :" << endl;
		cin >> notas[i];
	}
	ordenarDesdeMenorNota(notas, tam);
	cout << " Estas son las notas ordenadas: ";
	for (int i = 0; i < tam; i++)
	{
		cout << notas[i] << " ";
	}
	eliminarMenorNota(notas, tam);
	calcularPromedio(notas, tam);

	delete[] notas;
    system("pause>0");
    return 0;
}
