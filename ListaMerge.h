#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <chrono>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#define TAM_MAX 1000

using namespace std;
using namespace std::chrono;

class StaticList {
public:
  int size;
  int list[TAM_MAX];

  // initialize list constructor
  StaticList() { size = 0; }

  // copy constructor
  StaticList(int originalList[], int tam) {
    for (int i = 0; i < tam; i++) {
      list[i] = originalList[i];
    }
    size = tam;
  }

  // Merge function
  void Merge(int left, int mid, int right, int vetorAux[]) {
    
    int ex = left;
    int mx = mid;

    for (int i = left; i < right; i++) {
      //checks if there are still elements in the left part of the vector and if there are still elements in the right part or if the left element is <= the right part element
      
      if (ex < mid && (mx >= right || list[ex] <= list[mx])) {
        vetorAux[i] = list[ex];
        ex++;
      } else {
        vetorAux[i] = list[mx];
        mx++;
      }
    }

    for (int i = left; i < right; i++) {
      list[i] = vetorAux[i];
    }

    cout << "Passo de ordenacao: ";
    for (int x = left; x < right; x++) {
        cout << list[x] << " ";
    }
    cout << endl;
    
  }

  // ordenation function 
  void mergeSort(int left, int right, int vetorAux[]) {
    if (right - left > 1) {
      int mid = (left + right) / 2;
      mergeSort(left, mid, vetorAux);
      mergeSort(mid, right, vetorAux);
      Merge(left, mid, right, vetorAux);
    }
  }

  void generatePermutation(int n) {
    for (int j = 0; j < n; j++) {
      list[j] = rand() % 1000;
    }
  }

  void aleatoryList() {
    for (int i = 1; i <= TAM_MAX; i++) {

      generatePermutation(i);
      size = i;
      int vetorAux[size];
      auto start = steady_clock::now();
      mergeSort(0, i, vetorAux);
      auto end = steady_clock::now();
      auto diff = end - start; // obtendo tempo transcorrido do algoritmo
      // cout << "Numero de element os: " << i << " -- ";
      // cout << endl;
      // cout << "Tempo: ";
      // cout << duration<double, std::milli>(diff).count() << " ms" << endl;
      cout << duration<double, std::milli>(diff).count()
           << endl; // impressão do tempo em 'ms'
    }
  }

  // print list
  void print() {
    for (int i = 0; i < size; i++) {
      cout << list[i] << " ";
    }
    cout << endl;
  }
};

#endif