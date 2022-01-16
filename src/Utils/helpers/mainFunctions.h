#ifndef _MAIN_FUNCTIONS_H
#define _MAIN_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "handlers.h"
#include "output.h"
#include "support.h"
#include "../constants/consts.h"



Person createPerson() {
	Person person;

  clearScreen();
  clearBuffer();

  printf("Para inserir um novo registro, passe as seguintes informacoes: \n\n");

	printf("Primeiro nome: ");
	inputString(person.firstName, 50);
	printf("Sobrenome: ");
	inputString(person.lastName, 50);
	printf("e-mail: ");
	inputString(person.email, 50);

	printf("\nSobre o endereco:\n");

	printf("Rua: ");
	inputString(person.address.street, 50);
	printf("Numero: ");
	scanf("%d", &person.address.number);
	clearBuffer();
	printf("Complemento: ");
	inputString(person.address.comp, 50);
	printf("Bairro: ");
	inputString(person.address.district, 50);
	printf("CEP: ");
	scanf("%d", &person.address.zipCode);
	clearBuffer();
	printf("Cidade: ");
	inputString(person.address.city, 50);
	printf("Estado: ");
	inputString(person.address.state, 50);
	printf("Pais: ");
	inputString(person.address.country, 50);

	printf("\nAgora sobre o telefone:\n");

	printf("DDD: ");
	scanf("%d", &person.phone.ddd);
	printf("Numero: ");
	scanf("%d", &person.phone.number);

	printf("\nFinalmente, sobre o aniversario\n");

	printf("Dia: ");
	scanf("%d", &person.birthday.day);
	printf("Mes: ");
	scanf("%d", &person.birthday.month);
	printf("Ano: ");
	scanf("%d", &person.birthday.year);

	clearScreen();
	
	return person;
}



void insertPerson(Person person, Person *list, int *size) {
	list[*size] = person;
	*size += 1;
	printf("\nRegistro criado com sucesso!\n");
}



void removePerson(Person *list, int *listSize) {
	char op, op2;
	int i, index;

	clearScreen();

	do {
		printf("Insira o indice da pessoa a ter seu registro removido: ");
		scanf("%d", &index);
		clearBuffer();

		if ((index < 0) || (index > (*listSize - 1))) {
      clearScreen();
      printf("Indice invalido! Tente novamente.\n");
    }
		
	} while ((index < 0) || (index > (*listSize - 1)));

	printf("Informacao da pessoa que deseja remover: \n");
	printPerson(list[index]);

  do {
	  printf("Tem certeza que deseja remover este registro? [s/n] ");
	  scanf("%c", &op);
    clearBuffer();
    if ((toupper(op) != 'S') && (toupper(op) != 'N')) {
      clearScreen();
      printf("Opcao invalida, tente novamente!\n");
    }
  } while ((toupper(op) != 'S') && (toupper(op) != 'N'));

  if (toupper(op) == 'S') {

		for (i = index; i < *listSize - 1; i++)
			list[i] = list[i + 1];
		printf("\nRegistro removido com sucesso.\n\n");
    *listSize -= 1;
    systemPause();

  } else if (toupper(op) == 'N') {

    do {
      clearScreen();
      printf("Deseja voltar ao menu inicial? [s/n] ");
      scanf("%c", &op2);
      clearBuffer();
      if ((toupper(op2) != 'S') && (toupper(op2) != 'N')) {
        printf("Opcao invalida, tente novamente!\n");
        systemPause();
      }
    } while ((toupper(op2) != 'S') && (toupper(op2) != 'N'));

    if (toupper(op2) == 'N') {
      removePerson(list, listSize);
    }
  }
}



Person searchPersonByName(int numOfPeople, char *name, Person *people) {
	// aux will store the name in uppercase that will be searched in the list
	char aux[50];

	strcpy(aux, name);
	upperString(aux);

	char temp[50];
	int i = 0, counter = 0;
	Person filteredPeople[100];

	for (i = 0; i < numOfPeople; i++) {
		// at each itteration, temp will store the name in uppercase
		strcpy(temp, people[i].firstName);
		upperString(temp);

    // and compare both names in uppercase
		if (!(strcmp(aux, temp))) {
			filteredPeople[counter] = people[i];
			counter++;
		}
	}

	if (counter) {
		printf("Exibindo usuarios com este nome:\n\n");
		printList(counter, filteredPeople);		
	} else {
		printf("Nenhum usuario encontrado com este nome!\n");
	}

	return *filteredPeople;
}



Person searchPersonByMonth(int numOfPeople, int month, Person *people) {
	Person filteredPeople[100];
	int counter = 0;
	for (int i = 0; i < numOfPeople; i++) {
		if (month == people[i].birthday.month) {
			filteredPeople[counter] = people[i];
			counter++;
		}
	}

	if (counter) {
		printf("Aniversariantes do mes:\n\n");
		printList(counter, filteredPeople);
	} else {
		printf("Nenhum usuario faz aniversario neste mes!\n");
	}

	return *filteredPeople;
}



Person searchPersonByExactDay(int numOfPeople, int month, int day, Person *people) {
	Person filteredPeople[100];
	int counter = 0;
	for (int i = 0; i < numOfPeople; i++) {
		if (month == people[i].birthday.month && day == people[i].birthday.day) {
			filteredPeople[counter] = people[i];
			counter++;
		}
	}

	if (counter) {
		printf("Aniversariantes do dia:\n\n");
		printList(counter, filteredPeople);
	} else {
		printf("Nenhum usuario faz aniversario neste dia!\n");
	}

	return *filteredPeople;
}

#endif