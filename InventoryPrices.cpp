#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>


using namespace std;
using namespace System;

void ingresarProductos(char* productos, int* precios, int tam) {
	for (int i = 0; i < tam; i++)
	{
		cout << "Ingrese el codigo del producto " <<i+1<<": ";
		cin >> productos[i];
		cout << "Ingrese su precio: ";
		cin >> precios[i];
	}
}

void ordenarProductosPorPrecio(char* productos, int* precios, int tam) {
	char auxProductos;
	int auxPrecios;
	for (int i = 0; i < tam-1; i++)
	{
		for (int j = i+1; j < tam; j++)
		{
			if (precios[i]<precios[j])
			{
				auxPrecios = precios[i];
				precios[i] = precios[j];
				precios[j] = auxPrecios;

				auxProductos = productos[i];
				productos[i] = productos[j];
				productos[j] = auxProductos;
			}
		}
	}
}

int buscarProducto(char* productos, int* precios, int tam, char nombreProducto) {
	for (int i = 0; i < tam; i++)
	{
		if (nombreProducto == productos[i])
		{
			return i;//posicion encontrada
		}

		else {
			return -1;
		}
	}
}

double calcularPromedio(int* precios, int tam) {
	double suma=0;
	for (int i = 0; i < tam; i++)
	{
		suma += precios[i];
	}
	return suma/(double)tam;
}

void mostrarListaOrdenada(char* productos, int* precios, int tam) {
	cout << endl;
	for (int i = 0; i < tam; i++)
	{
		cout << i + 1 << ") Producto " << productos[i] << " - Precio: " << precios[i] << endl;
	}
}

void actualizarPrecio(char* productos, int* precios, int tam, int precioNuevo,
	char nombreProducto) {

	for (int i = 0; i < tam; i++)
	{
		if (nombreProducto ==productos[i])
		{
			precios[i] = precioNuevo;
		}
	}
}

int main() {

	//ingreso de cantidad de jugadores
	int n;
	cout << "Ingrese la cantidad de productos: ";
	cin >> n;

	char* productos = new char[n];
	int* precios = new int[n];

	ingresarProductos(productos, precios, n);
	ordenarProductosPorPrecio(productos, precios, n);
	mostrarListaOrdenada(productos, precios, n);

	//buscar dentro del ranking
	char nombreBuscar1;
	int posicionEncontrada;
	cout << "\nIngrese el nombre (char) a buscar: ";
	cin >> nombreBuscar1;
	posicionEncontrada = buscarProducto(productos, precios, n, nombreBuscar1);
	if (posicionEncontrada == -1)
	{
		cout << "Producto no encontrado" << endl;
		
	}
	else
	{
		cout << "El producto " << productos[posicionEncontrada] << " fue encontrado y su precios es de " << precios[posicionEncontrada] << endl;
	}

	//calcular promedio de todos los puntajes
	double promedio = calcularPromedio(precios, n);
	cout << "El promedio de precios es " << promedio << endl;

	//actualizar precio de un producto inventario xd
	char nombreProducto;
	int precioNuevo;
	cout << "\nIngrese el producto a actualizar precio: ";
	cin >> nombreProducto;
	cout << "Ingrese el nuevo precio: ";
	cin >> precioNuevo;
	actualizarPrecio(productos, precios, n, precioNuevo, nombreProducto);

	//mostramos el arreglo actualizado y ordenado
	cout << endl;
	ordenarProductosPorPrecio(productos, precios, n);
	mostrarListaOrdenada(productos, precios, n);

	//eliminamos los arreglos dinamicos del heap
	delete[] productos;
	delete[] precios;

    system("pause>0");
    return 0;
}
