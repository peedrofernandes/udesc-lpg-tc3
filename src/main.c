#include <stdio.h>
#include <string.h>
#include "Utils/constants/consts.h"
#include "Utils/helpers/handlers.h"
#include "Utils/helpers/mainFunctions.h"
#include "Utils/helpers/output.h"

// op. 1: new Person
// op. 2: show people
// op. 3: remove people
// op. 4: search person by name
// op. 5: search by month (birthday)
// op. 6: search by date (birthday)

int main(void) {
	int option;
	int listSize = 0;
  Person list[100];

  do {

    clearScreen();

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
        createPersonHandler(list, &listSize);
        break;

			case 2:
        // Listar todos os registros
        listPeopleHandler(list, listSize);
        break;

			case 3:
        // Remover registro
        removePersonHandler(list, &listSize);
        break;

      case 4:
			  // Lista registros com o nome correspondente
        searchByNameHandler(list, listSize);
        break;

			case 5:
			  // Lista registros com o mes correspondente
        searchByMonthHandler(list, listSize);
        break;

			case 6:
			  // Lista registros com o mes e dia correspondente
        searchByDateHandler(list, listSize);
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
