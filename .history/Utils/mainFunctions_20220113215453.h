#ifndef _MAIN_FUNCTIONS_H
#define _MAIN_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "other.h"
#include "consts.h"




void insertPerson(Person *people, int listSize) {
	system("cls");

	printf("Para inserir um novo registro, passe as seguintes informacoes: \n\n");

	printf("Primeiro nome: ");
	inputString(people[listSize - 1].firstName, 50);

	printf("Sobrenome: ");
	inputString(people[listSize - 1].lastName, 50);

	printf("e-mail: ");
	inputString(people[listSize - 1].email, 50);


	printf("\nSobre o endereco:\n");


	printf("Rua: ");
	inputString(people[listSize - 1].address.street, 50);

	printf("Numero: ");
	scanf("%d", &people[listSize - 1].address.number);
	fflush(stdin);

	printf("Complemento: ");
	inputString(people[listSize - 1].address.comp, 50);

	printf("Bairro: ");
	inputString(people[listSize - 1].address.district, 50);

	printf("CEP: ");
	scanf("%d", &people[listSize - 1].address.zipCode);
	fflush(stdin);

	printf("Cidade: ");
	inputString(people[listSize - 1].address.city, 50);

	printf("Estado: ");
	inputString(people[listSize - 1].address.state, 50);

	printf("Pais: ");
	inputString(people[listSize - 1].address.country, 50);


	printf("\nAgora sobre o telefone:\n");


	printf("DDD: ");
	scanf("%d", &people[listSize - 1].phone.ddd);

	printf("Numero: ");
	scanf("%d", &people[listSize - 1].phone.number);


	printf("\nFinalmente, sobre o aniversario\n");


	printf("Dia: ");
	scanf("%d", &people[listSize - 1].birthday.day);

	printf("Mes: ");
	scanf("%d", &people[listSize - 1].birthday.month);

	printf("Ano: ");
	scanf("%d", &people[listSize - 1].birthday.year);

	system("cls");

	printf("\nRegistro criado com sucesso!\n");
}




void printPerson(Person person) {

	printf("[Informacao base]\n\n");

	printf("Nome: %s\n", person.firstName);
	printf("Sobrenome: %s\n", person.lastName);
	printf("Email: %s\n\n", person.email);

	printf("[Endereco]\n\n");

	printf("Rua: %s\n", person.address.street);
	printf("Numero: %d\n", person.address.number);
	printf("Complemento: %s\n", person.address.comp);
	printf("Bairro: %s\n", person.address.district);
	printf("CEP: %d\n", person.address.zipCode);
	printf("Cidade: %s\n", person.address.city);
	printf("Estado: %s\n", person.address.state);
	printf("Pais: %s\n\n", person.address.country);

	printf("Telefone: (%d) %d\n\n", person.phone.ddd, person.phone.number);

	printf("Data de nascimento: %d/%d/%d\n", person.birthday.day, person.birthday.month, person.birthday.year);
}




void removePerson(Person *list, int *listSize) {
	char op, op2;
	int i, index;

	system("cls");

	do {
		printf("Insira o indice da pessoa a ter seu registro removido: ");
		scanf("%d", &index);
		fflush(stdin);

		if ((index < 0) || (index > (*listSize - 1))) {
      system("cls");
      printf("Indice invalido! Tente novamente.\n");
    }
		
	} while ((index < 0) || (index > (*listSize - 1)));

	printf("Informacao da pessoa que deseja remover: \n");
	printPerson(list[index]);

  do {
	  printf("Tem certeza que deseja remover este registro? [s/n] ");
	  scanf("%c", &op);
    fflush(stdin);
    if ((toupper(op) != 'S') && (toupper(op) != 'N')) {
      system("cls");
      printf("Opcao invalida, tente novamente!\n");
    }
  } while ((toupper(op) != 'S') && (toupper(op) != 'N'));

  if (toupper(op) == 'S') {

		for (i = index; i < *listSize - 1; i++)
			list[i] = list[i + 1];
		printf("\nRegistro removido com sucesso.\n\n");
    *listSize = *listSize - 1;
    system("pause");

  } else if (toupper(op) == 'N') {

    do {
      system("cls");
      printf("Deseja voltar ao menu inicial? [s/n] ");
      scanf("%c", &op2);
      fflush(stdin);
      if ((toupper(op2) != 'S') && (toupper(op2) != 'N')) {
        printf("Opcao invalida, tente novamente!\n");
        system("pause");
      }
    } while ((toupper(op2) != 'S') && (toupper(op2) != 'N'));

    if (toupper(op2) == 'N') {
      removePerson(list, listSize);
    }
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

#endif