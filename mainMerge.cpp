#include "ListaMerge.h"
#include <chrono>
#include <iostream>
#include <time.h>

using namespace std;

int main() {

  srand(time(NULL));
  // int lista_definida[] = {70, 1,  12, 8,  99, 72, 5,  15, 20, 91,
  //                         14, 61, 66, 41, 81, 88, 16, 21, 34, 90};

  int lista_definida[] = {3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};

  int size = 15;
  int vetorAux[size];

  // Testes MergeSort
  // Teste 2.1 - Ler lista

  StaticList loe(lista_definida, size);
  cout << "Lista Original: " << endl;
  loe.print();
  cout << "Ordenando: " << endl;
  loe.mergeSort(0, size, vetorAux);
  cout << "Lista Ordenada: " << endl;
  loe.print();
  cout << endl << "--------------------" << endl;

  // Teste 2.2 - Lista aleatória
  /*ListaEstatica loe2;
  loe2.listaAleatoria();*/

  return 0;
}