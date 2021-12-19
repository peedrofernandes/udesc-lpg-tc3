#ifndef _MAIN_FUNCTIONS_H
#define _MAIN_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "consts.h"

/* 
 to-do:
	make functions do what they meant to;
*/

void insertPerson(Person *people, int c) {
	system("cls");

	if (c > 1)
		people = realloc(people, c * sizeof(Person));
	// If it is not the first insertion, memory has to be reallocated!


	printf("Para inserir um novo registro, passe as seguintes informacoes: \n\n");


	printf("Primeiro nome: ");
	scanf("%s", &people[c - 1].firstName);

	printf("Sobrenome: ");
	fflush(stdin);
	inputString(people[c - 1].lastName, 50);

	printf("e-mail: ");
	scanf("%s", &people[c - 1].email);


	printf("\nSobre o endereco:\n");


	printf("Rua: ");
	fflush(stdin);
	inputString(people[c - 1].address.street, 50);

	printf("Numero: ");
	scanf("%d", &people[c - 1].address.number);

	printf("Complemento: ");
	fflush(stdin);
	inputString(people[c - 1].address.comp, 50);

	printf("Bairro: ");
	fflush(stdin);
	inputString(people[c - 1].address.district, 50);

	printf("CEP: ");
	scanf("%d", &people[c - 1].address.zipCode);

	printf("Cidade: ");
	fflush(stdin);
	inputString(people[c - 1].address.city, 50);

	printf("Estado: ");
	fflush(stdin);
	inputString(people[c - 1].address.state, 50);

	printf("Pais: ");
	fflush(stdin);
	inputString(people[c - 1].address.country, 50);


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
		printf("--------\n");
		printf("INDEX %d\n", i);
		printf("--------\n\n");

		printf("Informacao base\n\n");
		printf("Nome: %s\n", list[i].firstName);
		printf("Sobrenome: %s\n", list[i].lastName);
		printf("Email: %s\n\n", list[i].email);

		printf("Endereco\n\n");

		printf("Rua: %s\n", list[i].address.street);
		printf("Numero: %d\n", list[i].address.number);
		printf("Complemento: %s\n", list[i].address.comp);
		printf("Bairro: %s\n", list[i].address.district);
		printf("CEP: %d\n", list[i].address.zipCode);
		printf("Cidade: %s\n", list[i].address.city);
		printf("Estado: %s\n", list[i].address.state);
		printf("Pais: %s\n\n", list[i].address.country);

		printf("Telefone\n\n");

		printf("Numero: (%d) %d\n\n", list[i].phone.ddd, list[i].phone.number);
	}

	printf("\nFim do registro.\n\n");
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

#endif