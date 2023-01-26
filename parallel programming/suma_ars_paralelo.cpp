// suma_ars_paralelo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <omp.h>

#define N 1000
#define chunk 100
#define show 100
void printArr(int *d);
using namespace std;

int main()
{
    cout << "Suma Arreglos en paralelo!\n";
    // Inicialización de arreglos de 1000 elementos
    int a[N], b[N], c[N];
    int i;
    srand(time(NULL));
    // Generamos aleatoriamente numeros de 0 - 999 para llenar los arreglos
    for (i = 0; i < N; i++)
    {
        a[i] = (rand() % N);
        b[i] = (rand() % N);
    }
    int batch = chunk;

    // Ciclo para procesamiento en paralelo
    #pragma omp parallel for shared(a, b, c, batch) private(i) schedule(static, batch)
    
    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i];
    // Impresión de arreglos: Arreglo 1 linea 1, Arreglo 2 linea 2, Suma de arreglos linea 3
    cout << "Imprimiendo los primeros " << show << " valores del arreglo a: " << endl;
    printArr(a);
    cout << "Imprimiendo los primeros " << show << "valores del arreglo b: " << endl;
    printArr(b);
    cout << "Imprimiendo los primeros " << show << "valores de la suma de arreglos: " << endl;
    printArr(c);
}

void printArr(int *d) {
    // Función para imprmir un segmento de la sumatoria de los arreglos
    for (int x = 0; x < show; x++)
        cout << d[x] << " - ";
    cout << endl;
}
