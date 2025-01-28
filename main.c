#include "funcionalidades.h"
#include <stdbool.h>
#include <stdlib.h>

int main(void) {
  Array arr1 = {
      .arr = NULL,
      .size = 0,
  };
  Array arr2 = {
      .arr = NULL,
      .size = 0,
  };
  bool arraysFilled = false;
  int choice;

  inicializarVetores(&arr1, &arr2);
  system("clear");

  do {
    printMenu();
    choice = askForInt("Escolha a sua opção: ");

    if (!arraysFilled) {
      switch (choice) {
      case 1:
        preencherVetores(&arr1, &arr2);
        arraysFilled = true;
        system("clear");
        break;
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
        system("clear");
        naoPreenchido();
        break;
      case 9:
        break;
      default:
        do {
          system("clear");
          naoReconhecido();
          printMenu();
          choice = askForInt("Escolha a sua opção: ");
        } while (choice < 1 || choice > 9);
      }
    } else {
      switch (choice) {
      case 1:
        preencherVetores(&arr1, &arr2);
        break;
      case 2:
        imprimirVetores(&arr1, &arr2);
        break;
      case 3:
        eliminarElementoCall(&arr1, &arr2);
        break;
      case 4:
        pesquisarElementoCall(&arr1, &arr2);
        break;
      case 5:
        ordenarVetores(&arr1, &arr2);
        break;
      case 6:
        calcularOperacoes(&arr1, &arr2);
        break;
      case 7:
        calcularEstatisticasCall(&arr1, &arr2);
        break;
      case 8:
        contarElementosValidosCall(&arr1, &arr2);
        break;
      case 9:
        break;
      default:
        system("clear");
        naoReconhecido();
        break;
      }
    }
  } while (choice != 9);

  return 0;
}