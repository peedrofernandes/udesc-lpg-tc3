#include <stdio.h>
#include <string.h>
#include "Utils/constants/consts.h"
#include "Utils/helpers/addPerson.h"
#include "Utils/helpers/filters.h"
#include "Utils/helpers/handlers.h"
#include "Utils/helpers/mainFunctions.h"
#include "Utils/helpers/print.h"
#include "Utils/helpers/upperString.h"

int main(void) {
	int option;
	int listSize = 0, i;
  Person list[100];
	int monthToBeSearched = 0, dayToBeSearched = 0;

  do {

    if (listSize == 0)
      option = printReducedMenu();
    else
      option = printMainMenu();

    switch (option) {
			case 0:
        // Encerrar programa
				printf("Encerrando, ate a proxima!");
				break;

			case 1:
        // Inserir novo registro
        printf("\n");
        Person person;
        person = createPerson();
				insertPerson(person, list, &listSize);
				systemPause();
				break;
    

			case 2:
        // Listar todos os registros

        if (listSize == 0) {
          printf("Valor invalido, tente novamente!\n");
          systemPause();
        } else {  
          printf("\n------------------------\n");
          printf("   TODOS OS REGISTROS\n");
          printf("------------------------\n\n");

          for (i = 0; i < listSize; i++) {
            printf("--------\n");
            printf("INDEX %d\n", i);
            printf("--------\n\n");
            printPerson(list[i]);
          }

          printf("\nFim do registro.\n\n");
          systemPause();
        }

				break;

			case 3:
        // Remover registro
        if (listSize <= 0) {
          printf("Valor invalido, tente novamente!\n");
				  systemPause();
        } else {
          removePerson(list, &listSize);
        }
        break;

      case 4:
			  // Lista registros com o nome correspondente
        if (listSize == 0) {
          printf("Valor invalido, tente novamente!\n");
				  systemPause();
        } else {
          printf("Insira o nome que deseja buscar nos registros: \n");
          char nameToBeSearched[50];
          scanf("%s", nameToBeSearched);
          searchPersonByName(listSize, nameToBeSearched, list);
          systemPause();
        }

				break;

			case 5:
			  // Lista registros com o mes correspondente
        if (listSize == 0) {
          printf("Valor invalido, tente novamente!\n");
				  systemPause();
        } else {
          printf("Insira o mes que deseja buscar por aniversariantes: ");
          scanf("%d", &monthToBeSearched);
          if (monthToBeSearched >= 1 && monthToBeSearched <= 12) {
            searchPersonByMonth(listSize, monthToBeSearched, list);
            systemPause();
            
          } else {
            printf("Mes invalido, retornando ao menu\n");
            break;
          }
        }
				break;

			case 6:
			  // Lista registros com o mes e dia correspondente
        if (listSize == 0) {
          printf("Valor invalido, tente novamente!\n");
				  systemPause();
        } else {
          printf("Insira a data que deseja buscar por aniversariantes\n");
          printf("Mes: ");
          scanf("%d", &monthToBeSearched);
          printf("Dia: ");
          scanf("%d", &dayToBeSearched);
          if (monthToBeSearched >= 1 && monthToBeSearched <= 12 && dayToBeSearched >= 1 && dayToBeSearched <= 31) {
            searchPersonByExactDay(listSize, monthToBeSearched, dayToBeSearched, list);
            systemPause();
          } else {
            printf("Data invalida, retornando ao menu\n");
            systemPause();
          }
        }
				break;

			default:
				// Loop para uma das opcoes serem acessadas
        printf("Valor invalido, tente novamente!\n");
				systemPause();
        break;
		}
  } while (option != 0);

  return 0;
}
