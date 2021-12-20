#include <stdio.h>
// #include <string.h>

/* 
 to-do:
	make functions do what they meant to;

*/

// Address, Phone, Birthday = New types that will be used in Person type.

// New type Address that will be used inside Person type;
typedef struct {
  char street[50], comp[50], district[50], city[50], state[50], country[50];
  int number zipCode;
} Address;

// New type Phone that will be used inside Person type;
struct Phone {
	int ddd, number;
};

// structing birthday to be allocated inside Person
struct Birthday {
	int day, month, year;
};

// structing Person
typedef struct {
  char firstName[50];
  char lastName[50];
  char email[100];
	int id;
	struct Birthday birthday;
	struct Address address;
	struct Phone phone;
} Person;

// insertPerson receives as argument, the array of people to be inserted to, as first argument,
// and the peopleCounter, called 'c'. it will add one and return the counter as second argument
int insertPerson(Person people[], int c) {
	// system("cls || clear");
 
	printf("Para inserir um novo registro, passe as seguintes informacoes: \n\n");
	printf("Nome: ");
	scanf("%s", people[c].firstName);
	printf("Sobrenome: ");
	scanf("%s", people[c].lastName);
	printf("e-mail: ");
	scanf("%s", people[c].email);
	printf("\nSobre o endereco \n");
	printf("Rua: ");
	scanf("%s", people[c].address.rua);
	printf("Numero: ");
	scanf("%d", &people[c].address.numero);
	printf("Complemento: ");
	scanf("%s", people[c].address.comp);
	printf("Bairro: ");
	scanf("%s", people[c].address.bairro);
	printf("CEP: ");
	scanf("%d", &people[c].address.cep);
	printf("Cidade: ");
	scanf("%s", people[c].address.cidade);
	printf("Estado: ");
	scanf("%s", people[c].address.estado);
	printf("Pais: ");
	scanf("%s", people[c].address.pais);
	printf("\nAgora sobre o telefone \n");
	printf("DDD: ");
	scanf("%d", &people[c].phone.ddd);
	printf("Numero: ");
	scanf("%d", &people[c].phone.number);
	printf("\nFinalmente, sobre o aniversario\n");
	printf("Dia: ");
	scanf("%d", &people[c].birthday.day);
	printf("Mes: ");
	scanf("%d", &people[c].birthday.month);
	printf("Ano: ");
	scanf("%d", &people[c].birthday.year);
	printf("\nPessoa criada\n");
	
	c++; // increase one to peopleCounter

	return c; // returns counter updated
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
	int option = 1;

	while (option) {
		printf("\n-----------------------\n");
		printf(" MENU PRINCIPAL AGENDA\n");
		printf("-----------------------\n\n");
		printf("QUAL OPCAO DESEJA SEGUIR: \n\n");
		
		printf("Inserir um novo registro: (1) \n");
		printf("Remover um registro: (2) \n");
		printf("Buscar registro por nome: (3) \n");
		printf("Buscar aniversariantes do mes: (4) \n");
		printf("Buscar aniversariantes do dia: (5) \n");
		printf("Encerrar programa: (0) \n");

    printf("Sua opcao: ");
    scanf("%d", &option);

		switch (option) {
			// shut the program down
			case 0:
				printf("Encerrando, ate a proxima!");
				break;

			// call the function insertPerson to create one registry
			case 1:
				// insertPerson(Person people[], int c);
				break;

			// call the function removePerson to remove one registry passing unique id as argument
			case 2:
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
			case 3:
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

			case 4:
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

			case 5:
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

			default:
				printf("Valor invalido, tente novamente!\n");
		}
	}

  return 0;
}
