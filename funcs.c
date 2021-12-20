#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Address {
	char rua[50], comp[50], bairro[50], cidade[50], estado[50], pais[50];
	int numero, cep;
};

struct Phone {
	int ddd, number;
};

struct Birthday {
	int day, month, year;
};

typedef struct {
	char firstName[50], lastName[50];
	char email[100];
	struct Birthday birthday;
	struct Address address;
	struct Phone phone;
} Person;

void showData(int size, Person *people) {
	for (int i = 0; i < size; i++) {
		printf("%s %s\n", people[i].firstName, people[i].lastName);
		printf("%s\n", people[i].email);
		printf("(%d) %d\n", people[i].phone.ddd, people[i].phone.number);
		printf("%d/%d/%d\n", people[i].birthday.day, people[i].birthday.month, people[i].birthday.year);
		printf("\n");
	}
}

Person filterPersonByName(int *size, char *name, Person *people) {
	// char aux[50];
	// memset(aux, '\0', sizeof(aux));
	// strcpy(aux, name);
	// char temp[50];
	int i = 0;
	Person filteredPeople[*size];
	int counter = 0;

	// for (i = 0; aux[i] != '\0'; i++) {
  //   if(aux[i] >= 'a' && aux[i] <= 'z') {
  //     aux[i] = aux[i] - 32;
  //   }
	// }

	for (int i = 0; i < *size; i++) {
		// memset(temp, '\0', sizeof(temp));
		// strcpy(temp, people[i].firstName);
	
		// for (i = 0; temp[i]!='\0'; i++) {
		// 	if(temp[i] >= 'a' && temp[i] <= 'z') {
    //     temp[i] = temp[i] - 32;
    //   }		
		// }

		// if (!(strcmp(aux, temp))) {
		if (!strcmp(name, people[i].firstName)) {
			filteredPeople[counter] = people[i];
			counter++;
		}
		// printf("%s\n%s", temp, aux);
	}

	if (counter) {
		printf("Exibindo usuarios com este nome:\n\n");
		showData(counter, filteredPeople);		
	} else {
		printf("Nenhum usuario encontrado com este nome!\n");
	}

	return *filteredPeople;
}

Person filterPersonByMonth(int *size, int month, Person *people) {
	Person filteredPeople[*size];
	int counter = 0;
	int i;
	for (int i = 0; i < *size; i++) {
		if (month == people[i].birthday.month) {
			filteredPeople[counter] = people[i];
			counter++;
		}
	}

	if (counter) {
		printf("Aniversariantes do mes:\n\n");
		showData(counter, filteredPeople);
	} else {
		printf("Nenhum usuario faz aniversario neste mes!\n");
	}

	return *filteredPeople;
}

Person filterPersonByExactDay(int *size, int month, int day, Person *people) {
	Person filteredPeople[*size];
	int counter = 0;
	int i;
	for (int i = 0; i < *size; i++) {
		if (month == people[i].birthday.month && day == people[i].birthday.day) {
			filteredPeople[counter] = people[i];
			counter++;
		}
	}

	if (counter) {
		printf("Aniversariantes do dia:\n\n");
		showData(counter, filteredPeople);
	} else {
		printf("Nenhum usuario faz aniversario neste dia!\n");
	}

	return *filteredPeople;
}

int main(void) {
	int *size;
	*size = 3;

	Person people[*size];
	char *nameToBeFiltered[50];
	int monthToBeFiltered;
	int dayToBeFiltered;

	for (int i = 0; i < *size; i++) {
		// printf("primeiro nome da pessoa %d: ", i + 1);
		scanf("%s", people[i].firstName);
		// printf("sobrenome da pessoa %d: ", i + 1);
		scanf("%s", people[i].lastName);
		// printf("email da pessoa %d: ", i + 1);
		scanf("%s", people[i].email);
		// printf("dia: ");
		scanf("%d", &people[i].birthday.day);
		// printf("mes: ");
		scanf("%d", &people[i].birthday.month);
		// printf("ano: ");
		scanf("%d", &people[i].birthday.year);
		// printf("ddd telefone: ");
		scanf("%d", &people[i].phone.ddd);
		// printf("numero telefone: ");
		scanf("%d", &people[i].phone.number);
		// printf("-----------------------\n");
	}

	printf("Digite o nome que deseja buscar no banco: ");
	scanf("%s", *nameToBeFiltered);
	filterPersonByName(size, *nameToBeFiltered, people);

	// printf("Insira o mes para buscar usuarios deste: ");
	// scanf("%d", &monthToBeFiltered);
  // filterPersonByMonth(size, monthToBeFiltered, people);

	// printf("Buscar aniversariantes de um dia e mes\n");
	// printf("Mes: ");
	// scanf("%d", &monthToBeFiltered);
	// printf("Dia: ");
	// scanf("%d", &dayToBeFiltered);
  // filterPersonByExactDay(size, monthToBeFiltered, dayToBeFiltered, people);

	return 0;
}
