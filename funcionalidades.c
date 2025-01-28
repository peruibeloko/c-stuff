#include "array.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//? Internals

int askForInt(char* prompt) {
  int dest = 0;
  printf("%s", prompt);
  int result = scanf("%d", &dest);
  while (result <= 0) {
    printf("Por favor forneça um número\n");
    result = scanf("%d", &dest);
  }
  return dest;
}

void fillArrayManual(Array* arr) {
  for (int i = 0; i < arr->size; i++) {
    printf("Valor para a posição %d do vetor: ", i);
    int valor = 0;

    do {
      valor = askForInt("");
    } while (valor < 1 || valor > 3000);

    arr->arr[i] = valor;
  }
}

void fillArrayAuto(Array* arr) {
  for (int i = 0; i < arr->size; i++) {
    arr->arr[i] = rand() % 3000;
  }
}

void printArray(Array* arr) {
  printf("[ ");
  for (int i = 0; i < (arr->size) - 1; i++) {
    printf("%d - ", arr->arr[i]);
  }
  printf("%d ]\n", arr->arr[(arr->size) - 1]);
}

bool findElement(Array* arr, int el) {
  for (int i = 0; i < arr->size; i++) {
    if (arr->arr[i] == el) {
      return true;
    }
  }
  return false;
}

void clearElementAtPos(Array* arr, int pos) { arr->arr[pos] = 0; }

ArraySlice* mergeSort(ArraySlice* arr, int startIndex, int endIndex) {
  int size = arr->size;

  if (size == 1) {
    return take(arr, 0, 1);
  }

  ArraySlice* l = mergeSort(arr, startIndex, startIndex + size / 2);
  ArraySlice* r = mergeSort(arr, startIndex + size / 2 + 1, endIndex);

  for (int i = 0; i < l->size && i < r->size; i++) {
    if (sliceGet(l, i) > sliceGet(r, i)) {
      swap(l, i, r, i);
    }
  }

  return join(l, r);
}

void mergeSortCall(Array* arr) { mergeSort(toSlice(arr), 0, arr->size - 1); }

int* calcStatistics(Array* arr) {}

int countValidElements(Array* arr) {
  int count = arr->size;
  for (int i = 0; i < arr->size; i++) {
    if (arr->arr[i] == 0) {
      count--;
    }
  }

  return count;
}

//? Public

void naoPreenchido() { printf("Os vetores ainda não foram preenchidos!\n\n"); }

void naoReconhecido() { printf("Opção não reconhecida, tente novamente.\n\n"); }

void printMenu() {
  printf("========== MENU DE OPÇÕES ==========\n");
  printf("1 - Preencher vetores\n");
  printf("2 - Imprimir vetores\n");
  printf("3 - Eliminar elemento do vetor\n");
  printf("4 - Pesquisar elemento nos vetores\n");
  printf("5 - Ordenar os vetores\n");
  printf("6 - Calcular operações matemáticas\n");
  printf("7 - Calcular métodos estatísticos\n");
  printf("8 - Total de elementos válidos\n");
  printf("9 - Sair\n");
  printf("====================================\n");
}

void inicializarVetores(Array* arr1, Array* arr2) {
  system("clear");
  printf("========== INICIALIZAR VETORES ==========\n");
  int tamanho1 = askForInt("Qual o tamanho do vetor 1? ");
  int tamanho2 = askForInt("Qual o tamanho do vetor 2? ");
  printf("========================================\n\n");

  arr1 = initArray(tamanho1);
  arr2 = initArray(tamanho2);
}

void preencherVetores(Array* arr1, Array* arr2) {
  system("clear");
  printf("========== PREENCHENDO VETORES ==========\n");
  printf("[1] Automático\n");
  printf("[2] Manual\n");
  int estrategia;

  do {
    estrategia = askForInt("Escolha o método para preencher o vetor 1: ");
    switch (estrategia) {
    case 1:
      fillArrayAuto(arr1);
      break;
    case 2:
      fillArrayManual(arr1);
      break;
    default:
      naoReconhecido();
      break;
    }
  } while (estrategia < 1 || estrategia > 2);

  estrategia = 0;

  do {
    estrategia = askForInt("Escolha o método para preencher o vetor 2: ");
    switch (estrategia) {
    case 1:
      fillArrayAuto(arr2);
      break;
    case 2:
      fillArrayManual(arr2);
      break;
    default:
      naoReconhecido();
      break;
    }
  } while (estrategia != 1 && estrategia != 2);
}

void imprimirVetores(Array* arr1, Array* arr2) {}

void eliminarElementoCall(Array* arr1, Array* arr2) {}

void pesquisarElementoCall(Array* arr1, Array* arr2) {}

void ordenarVetores(Array* arr1, Array* arr2) {
  mergeSortCall(arr1);
  mergeSortCall(arr2);
}

void calcularOperacoes(Array* arr1, Array* arr2) {}

void calcularEstatisticasCall(Array* arr1, Array* arr2) {}

void contarElementosValidosCall(Array* arr1, Array* arr2) {}