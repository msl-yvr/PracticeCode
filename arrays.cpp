#include "pch.h"
#include <iostream>
#include <string>
#include <conio.h> // Para _getch()

using namespace std;
using namespace System;


int main() {
    int* arreglo;
    int t;
    Random r;
    while (1) {
        Console::Clear();
        cout << "Ingrese tamano de arreglo: "; cin >> t;
        arreglo= new int[t];
        for (int i = 0; i < t; i++)
        {
            arreglo[i] = r.Next(0, 100);
            cout << "arreglo[" << i << "] = " << arreglo[i] << endl;
        }
        cout << "\nPresione una tecla para continuar... "; _getch();
        delete[]arreglo;
        arreglo = nullptr;
    }

    return 0;
}
