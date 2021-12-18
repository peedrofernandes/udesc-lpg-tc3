#include <stdio.h>
#include <string.h>

/* 
 to-do:
	make functions do what they meant to;
*/

// Address, Phone, Birthday = New types that will be used in Person type.


typedef struct {
  char street[50], comp[50], district[50], city[50], state[50], country[50];
  int zipCode, number;
} Address;

typedef struct {
	int ddd, number;
} Phone;

typedef struct {
	int day, month, year;
} Birthday;

// Type Person:
typedef struct {
  char firstName[50];
  char lastName[50];
  char email[100];
	int id;
	Birthday birthday;
	Address address;
	Phone phone;
} Person;


void insertPerson(Person *people, int c) {
	system("cls");

	if (c > 1)
		people = realloc(people, c * sizeof(Person));
	// Reallocating memory because of the insertion!


	printf("Para inserir um novo registro, passe as seguintes informacoes: \n\n");


	printf("Primeiro nome: ");
	scanf("%s", &people[c - 1].firstName);

	printf("Sobrenome: ");
	fflush(stdin);
	fgets(people[c - 1].lastName, 50, stdin);

	printf("e-mail: ");
	scanf("%s", &people[c - 1].email);


	printf("\nSobre o endereco:\n");


	printf("Rua: ");
	fflush(stdin);
	fgets(people[c - 1].address.street, 50, stdin);

	printf("Numero: ");
	scanf("%d", &people[c - 1].address.number);

	printf("Complemento: ");
	fflush(stdin);
	fgets(people[c - 1].address.comp, 50, stdin);

	printf("Bairro: ");
	fflush(stdin);
	fgets(people[c - 1].address.district, 50, stdin);

	printf("CEP: ");
	scanf("%d", &people[c - 1].address.zipCode);

	printf("Cidade: ");
	fflush(stdin);
	fgets(people[c - 1].address.city, 50, stdin);

	printf("Estado: ");
	fflush(stdin);
	fgets(people[c - 1].address.state, 50, stdin);

	printf("Pais: ");
	fflush(stdin);
	fgets(people[c - 1].address.country, 50, stdin);


	printf("\nAgora sobre o telefone:\n");


	printf("DDD: ");
	scanf("%d", &people[c - 1].phone.ddd);

	printf("Numero: ");
	scanf("%d", &people[c - 1].phone.number);


	printf("\nFinalmente, sobre o aniversario\n");


	printf("Dia: ");
	scanf("%d", &people[c - 1].birthday.day);

	printf("Mes: ");
	scanf("%d", &people[c - 1].birthday.month);

	printf("Ano: ");
	scanf("%d", &people[c - 1].birthday.year);

	system("cls");

	printf("\nRegistro criado com sucesso!\n");
}

void printList(Person *list, int listSize) {
	int i;

	system("cls");

	printf("\n-----------------------\n");
	printf("TODOS OS REGISTROS\n");
	printf("-----------------------\n\n");

	for (i = 0; i < listSize; i++) {
		printf("Index %d\n\n", i);

		printf("Informacao base\n\n");
		printf("Nome: %s\n", list[i].firstName);
		printf("Sobrenome: %s\n", list[i].lastName);
		printf("Email: %s\n\n", list[i].email);

		printf("Endereco\n\n");

		printf("Rua: %s\n", list[i].address.street);
		printf("Numero: %d\n", list[i].address.number);
		printf("Complemento: %s\n", list[i].address.comp);
		printf("Bairro: %s\n", list[i].address.district);
		printf("CEP: %s\n", list[i].address.zipCode);
		printf("Cidade: %s\n", list[i].address.city);
		printf("Estado: %s\n", list[i].address.state);
		printf("Pais: %s\n\n", list[i].address.country);

		printf("Telefone\n\n");

		printf("Numero: (%d) - %d\n\n", list[i].phone.ddd, list[i].phone.number);
	}

	printf("Fim do registro.\n");
}

// removePerson receives as argument the peopleArray as first argument, 
// the id of the one who is about to be removed as second argument, 
// and the peopleCounter to be updated as removing one as third argument
int removePerson(/* peopleArray, person.id */ int c) {
	// system("cls || clear");
	int choice = 0;
	printf("Deseja mesmo remover este registro?\n1 para 'Sim'\n0 para 'Nao'\n");
	scanf("%d", &choice);

	if (choice == 1) {
		printf("removendo pessoa, aguarde!\n");
		c--; // decrease one to the peopleCounter, as it was removed one person
	}	else if (choice == 0) {
		printf("voltando ao menu...\n");
	} else {
		printf("valor invalido, retornando ao menu...\n");
	}

	return c; // returns counter updated
}


// searchPersonByName searchs the person passing the peopleArray as first argument, 
// and the name to be searched in array as second argument
void searchPersonByName(/* peopleArray, person */) {
	// system("cls || clear");
	printf("Exibindo nome, email e telefone de todas as pessoas com este nome\n");
}


// searchBdaysByMonth searchs the person passing the peopleArray as first argument, 
// and the month to search persons that makes birthday in month passed as second argument
void searchBdaysByMonth(/* month */) {
	// system("cls || clear");
	printf("Aqui esta uma lista do nome das pessoas que fazem aniversario neste mes\n");
}


// searchBdaysByDay searchs the person passing the peopleArray as first argument, 
// and the day and month to be searched, passed as second argument
void searchBdaysByDay(/* day, month */) {
	// system("cls || clear");
	printf("Aqui esta uma lista do nome das pessoas que fazem aniversario neste dia e mes\n");
}

int main(void) {
	int option;
	int listSize = 0;
  Person *list = malloc(sizeof(Person));

	system("cls");

  do {
		printf("\n-----------------------\n");
		printf("MENU PRINCIPAL AGENDA\n");
		printf("-----------------------\n\n");
		printf("QUAL OPCAO DESEJA SEGUIR: \n\n");
		
		printf("[1] Inserir um novo registro:\n");
		printf("[2] Mostrar todos os registros\n");
		printf("[3] Remover um registro\n");
		printf("[4] Buscar registro por nome\n");
		printf("[5] Buscar aniversariantes do mes\n");
		printf("[6] Buscar aniversariantes do dia\n");
		printf("[7] Encerrar programa\n");

    printf("Sua opcao: ");
    scanf("%d", &option);

		switch (option) {
			case 0:
				printf("Encerrando, ate a proxima!");
				break;

			case 1:
				listSize++;
				insertPerson(list, listSize);
				break;

			case 2:
				printList(list, listSize);
				break;

			// call the function removePerson to remove one registry passing unique id as argument
			case 3:
				// system("cls || clear");
				printf("Insira o nome da pessoa a ter seu registro removido: ");
				scanf("");
				if (/* person exists */ 1==1) {
					// removePerson(/* person.id */ int c);
				} else {
					printf("Pessoa nao encontrada, retornando ao menu\n");
					break;
				}
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
		}
	} while (option != 0);

	free(list);

  return 0;
}
