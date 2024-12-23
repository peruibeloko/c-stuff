#include "funcionalidades.h"
#include <stdbool.h>
#include <stdlib.h>

int main(void) {
  Array arr1, arr2;
  bool arraysFilled = false;
  int choice;

  system("chcp 65001 > NUL");
  inicializarVetores(&arr1, &arr2);
  system("cls");

  do {
    printMenu();
    choice = askForInt("Escolha a sua opção: ");

    if (!arraysFilled) {
      switch (choice) {
      case 1:
        preencherVetores(&arr1, &arr2);
        arraysFilled = true;
        system("cls");
        break;
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
        system("cls");
        naoPreenchido();
        break;
      case 9:
        break;
      default:
        do {
          system("cls");
          naoReconhecido();
          printMenu();
          choice = askForInt("Escolha a sua opção: ");
        } while (choice < 1 || choice > 9);
      }
    } else {
      switch (choice) {
      case 1:
        preencherVetores(&arr1, &arr2);
        system("cls");
      case 2:
        imprimirVetores(&arr1, &arr2);
        system("cls");
      case 3:
        eliminarElementoCall(&arr1, &arr2);
        system("cls");
      case 4:
        pesquisarElementoCall(&arr1, &arr2);
        system("cls");
      case 5:
        ordenarVetores(&arr1, &arr2);
        system("cls");
      case 6:
        calcularOperacoes(&arr1, &arr2);
        system("cls");
      case 7:
        calcularEstatisticasCall(&arr1, &arr2);
        system("cls");
      case 8:
        contarElementosValidosCall(&arr1, &arr2);
        system("cls");
      case 9:
        break;
      default:
        system("cls");
        naoReconhecido();
      }
    }
  } while (choice != 9);

  return 0;
}