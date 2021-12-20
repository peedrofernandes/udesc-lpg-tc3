#include <stdio.h>
#include <string.h>
#include "Utils/input.h"
#include "Utils/mainFunctions.h"
#include ""

int main(void) {
	int option, index;
	int listSize = 0, i;
  Person *list;

  list = malloc(sizeof(Person));

  do {
    system("cls");

		printf("\n-----------------------\n");
		printf(" MENU PRINCIPAL AGENDA\n");
		printf("-----------------------\n\n");
		printf("QUAL OPCAO DESEJA SEGUIR: \n\n");
		
		printf("[1] Inserir um novo registro:\n");
		printf("[2] Mostrar todos os registros\n");
		printf("[3] Remover um registro\n");
		printf("[4] Buscar registro por nome\n");
		printf("[5] Buscar aniversariantes do mes\n");
		printf("[6] Buscar aniversariantes do dia\n");
		printf("[0] Encerrar programa\n");

    printf("Sua opcao: ");
    scanf("%d", &option);

		system("cls");

		switch (option) {
			case 0: // Encerrar programa
				printf("Encerrando, ate a proxima!");
				break;

			case 1: // Inserir novo registro
				listSize++;
				insertPerson(list, listSize);
				system("pause");
				break;

			case 2: // Listar todos os registros

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
				system("pause");
				break;

			case 3: // Remover registro
				removePerson(list, listSize);
				listSize--;
				system("pause");
				break;

			// call the function searchPersonByName to list all persons
			// with the name passed as argument
			case 4:
				// system("cls || clear");
				printf("Insira o nome da pessoa que deseja buscar mais informacoes: ");
				scanf("");
				if (/* person exists */ 1==1) {
					searchPersonByName(/* person */);
				} else {
					printf("Pessoa nao encontrada, retornando ao menu\n");
					break;
				}
				break;

			case 5:
				// system("cls || clear");
				printf("Insira o mes que deseja buscar por aniversariantes: ");
				scanf("");
				if (/* month exists */ 1==1) {
					if (/* bdays in this month */ 1==1) {
					searchBdaysByMonth(/* month */);
					} else {
						printf("Nao ha pessoas no registro que fazem aniversario neste mes, retornando ao menu\n");
						break;
					}
				} else {
					printf("Mes invalido, retornando ao menu\n");
					break;
				}
				break;

			case 6:
				// system("cls || clear");
				printf("Insira a data que deseja buscar por aniversariantes\n");
				printf("Dia: ");
				scanf("");
				printf("Mes: ");
				scanf("");
				if (/* month exists */ 1==1) {
					if (/* bdays in this day */ 1==1) {
					searchBdaysByDay(/* day, month */);
					} else {
						printf("Nao ha pessoas no registro que fazem aniversario nesta data, retornando ao menu\n");
						break;
					}
				} else {
					printf("Mes invalido, retornando ao menu\n");
					break;
				}
				break;
			case 7:

			default:
				printf("Valor invalido, tente novamente!\n");
				system("pause");
				break;
		}
  } while (option != 0);

  return 0;
}
