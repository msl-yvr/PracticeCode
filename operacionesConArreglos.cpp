#include "pch.h"
#include <iostream>
#include <conio.h> 

using namespace std;
using namespace System;

//ver elementos de arreglo
void listarElementos(int* arreglo, int tam) {
    cout << "Lista de elementos: " << endl;
    for (int i = 0; i < tam; i++)
    {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

//this function modifies the size of the array 
void agregarNuevoElementoAlFinal(int*& arreglo, int& tam, 
    int nuevoElemento) {
    //Step 1: create a new array with modified size
    int* nuevoArreglo = new int[tam + 1];

    //Step 2: copy all elements of the original array to
    //the new array
    for (int i = 0; i < tam; i++)
    {
        nuevoArreglo[i] = arreglo[i];//Process: copy
    }

    //Step 3: add the new element in the last position
    nuevoArreglo[tam] = nuevoElemento;

    //Step 4: delete memory of the original array
    delete[] arreglo;//arreglo=nullptr

    //Step 5: update array ptr to point to the new array
    arreglo = nuevoArreglo;//al arreglo original le paso la referencia del nuevo arreglo

    //Step 6: increase the 'size'
    tam++;
}

//eliminar en un posicion especifica
void elminarElementoPosicion(int*& arreglo,int& tam, int position) {//esta funcion modifica la estructura

    //Paso 1: verificar si la posicion es validad
    if (position < 0 || position >= tam) {
        cout << "La posicion es un valor incorrecto, intente de nuevo...";
        return;
    }

    //Paso 2: crear nuevo arreglo con un tamano reducido
    int* nuevoArreglo = new int[tam - 1];

    //Paso 3: copiar en el nuevo arreglo los elementos del arreglo original, 
    //excluyendo el elemento de la posicion indicada
    int j = 0;//nuevo indice para el nuevoPuntero
    for (int i = 0; i < tam; i++)
    {
        if (i!=position)
        {
           nuevoArreglo[j] = arreglo[i];
           j++;
        }
    }

    //Paso 4: liberar memoria del arreglo original
    delete[] arreglo;

    //Paso 5: actualizar el puntero del arreglo originbal para que apunte a nuevo arreglo
    arreglo = nuevoArreglo;

    //paso 6: reducir el tamano en 1
    tam--;
}

//agregar elementos al incio
void agregarNuevoElementoAlInicio(int*& arreglo, int& tam,
    int nuevoElemento) {
    //paso 1: crear un nuevo arreglo con tamano aumentado en 1
    int* nuevoArreglo = new int[tam + 1];

    //paso 2: colocar el nuevo elmento en la primmera posicion del nuevo arreglo
    nuevoArreglo[0] = nuevoElemento;//en la poscion inicial, 'for en medio o al final'

    //paso 3: copiar elementos del arreglo ariginal al nuevo arreglo,
    //desplazando los elementos a la derecha
    for (int i = 0; i < tam; i++)
    {
        nuevoArreglo[i + 1] = arreglo[i];//copiamos a parttie del sguiente elemento

    }
    //paso 4: eliminar la memoriua del arreglo ariginal
    delete[] arreglo;

    //paso 5: actualizamos el puntero, para que apunte al nuevo arreglo
    arreglo = nuevoArreglo;

    //paso 6: aumentar el tam del arreglo
    tam++;

}

//modificar elemeto de una poscion especifica
void modificarElementoPosicion(int* arreglo, int tam, int position,
    int nuevoElemento) {
    if (position<0||position>=tam)
    {
        cout << "Posicion ingresada invalida..." << endl;
        return;
    }

    arreglo[position] = nuevoElemento;

}

//agregar en una posicion, NO INICIAL, NO FINAL
void agregarNuevoElementoEnUnaPosicion(int*& arreglo, int& tam, int position, int nuevoElemento) {
    if (position < 0 || position >= tam)
    {
        cout << "Posicion ingresada invalida..." << endl;
        return;
    }

    int* nuevoArreglo = new int[tam + 1];
    //copiado en dos mementos:
    //uno, desde el inicio hasta la posicion que me piden ingresar
    //dos, desde la posicion siguienta hasta el tamano
    for (int i = 0; i < position; i++)
    {
        nuevoArreglo[i] = arreglo[i];//copiamos
    }
    nuevoArreglo[position] = nuevoElemento;//insertamos el nuev elemento en la posicion indicada

    for (int i = position; i < tam; i++)
    {
        nuevoArreglo[i + 1] = arreglo[i];//desde la siguiente posicion 
    }

    delete[] arreglo;
    arreglo = nuevoArreglo;
    tam++;
}

//ordenar elementos de mayor a menor
void ordenarDescendente(int* arreglo, int tam) {

    int auxlArreglo;
    for (int i = 0; i < tam-1; i++)
    {
        for (int j = i+1; j < tam; j++)
        {
            if (arreglo[j]>arreglo[i])
            {
                auxlArreglo = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = auxlArreglo;
            }
        }
    }
}

int main() {
 
    int tam = 0;
    int* arreglo = nullptr;//initial value for ptr
    int nuevoElemento;
    int position;
    int nuevoValorElemento;
    do
    {
        cout << "MENU" << endl;
        cout << "1) LISTAR ELEMENTO " << endl;
        cout << "2) AGREGAR AL FINAL " << endl;
        cout << "3) ELIMINAR EN POSICION " << endl;
        cout << "4) AGREGAR AL INICIO" << endl;
        cout << "5) MODIFICAR EN POSICION " << endl;
        cout << "6) INSERTAR EN POSICION " << endl;
        cout << "7) ORDENAR DE MAYOR A MENOR" << endl;
        cout << "8) SALIR" << endl;
        cout<<"Eligir una opcion : " << endl;

        int option;
        cin >> option;
        switch (option)
        {
        case 1:
            listarElementos(arreglo, tam);
            break;
        case 2:
            cout << "Ingrese un nuevo elemento" << endl;
            cin >> nuevoElemento;
            agregarNuevoElementoAlFinal(arreglo, tam, nuevoElemento);
            break;
        case 3:
            cout << "La posicion del elemento a eleminar" << endl;
            cin >> position;
            elminarElementoPosicion(arreglo, tam, position);
            break;
        case 4:
            cout << "Ingrese un nuevo elemento" << endl;
            cin >> nuevoElemento;
            agregarNuevoElementoAlInicio(arreglo, tam, nuevoElemento);
            break;
        case 5:
            cout << "Ingrese la posicion dle elemento a modificar" << endl;
            cin >> position;
            cout << "Ingrese el nuevo valor del elemento a modificar" << endl;
            cin >> nuevoValorElemento;
            modificarElementoPosicion(arreglo, tam, position, nuevoValorElemento);
            break;
        case 6:
            cout << "Invgrese la posicion a insertar: ";
            cin >> position;
            cout << "Ingrese el elemento a insertar" << endl;
            cin >> nuevoElemento;
            agregarNuevoElementoEnUnaPosicion(arreglo, tam, position, nuevoElemento);
            break;
        case 7:
            ordenarDescendente(arreglo, tam);
            break;
        case 8:
            cout << "Saliendo del programa";
            delete[]arreglo;
            break;
        default:
            cout << "Opcion incorrecta. Intente de nuevo..." << endl;
            break;
        }
    } while (true);
   

    system("pause>0");
    return 0;
}
