#ifndef _MAIN_FUNCTIONS_H
#define _MAIN_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#include "consts.h"

/* 
 to-do:
	make functions do what they meant to;
*/

void insertPerson(Person *people, int c) {
	system("cls");

	if (c > 1)
		people = (Person*) realloc(people, (c * sizeof(Person)));
	// If it is not the first insertion, memory has to be reallocated!


	printf("Para inserir um novo registro, passe as seguintes informacoes: \n\n");

	printf("Primeiro nome: ");
	inputString(people[c - 1].firstName, 50);

	printf("Sobrenome: ");
	inputString(people[c - 1].lastName, 50);

	printf("e-mail: ");
	inputString(people[c - 1].email, 50);


	printf("\nSobre o endereco:\n");


	printf("Rua: ");
	inputString(people[c - 1].address.street, 50);

	printf("Numero: ");
	scanf("%d", &people[c - 1].address.number);
	fflush(stdin);

	printf("Complemento: ");
	inputString(people[c - 1].address.comp, 50);

	printf("Bairro: ");
	inputString(people[c - 1].address.district, 50);

	printf("CEP: ");
	scanf("%d", &people[c - 1].address.zipCode);
	fflush(stdin);

	printf("Cidade: ");
	inputString(people[c - 1].address.city, 50);

	printf("Estado: ");
	inputString(people[c - 1].address.state, 50);

	printf("Pais: ");
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




// removePerson receives as argument the peopleArray as first argument, 
// the id of the one who is about to be removed as second argument, 
// and the peopleCounter to be updated as removing one as third argument
// int removePerson(/* peopleArray, person.id */ int c) {
// 	// system("cls || clear");
// 	int choice = 0;
// 	printf("Deseja mesmo remover este registro?\n1 para 'Sim'\n0 para 'Nao'\n");
// 	scanf("%d", &choice);

// 	if (choice == 1) {
// 		printf("removendo pessoa, aguarde!\n");
// 		c--; // decrease one to the peopleCounter, as it was removed one person
// 	}	else if (choice == 0) {
// 		printf("voltando ao menu...\n");
// 	} else {
// 		printf("valor invalido, retornando ao menu...\n");
// 	}

// 	return c; // returns counter updated
// }



void removePerson(Person *list, int listSize) {
	char op;
	int i, index;

	system("cls");

	do {
		printf("Insira o indice da pessoa a ter seu registro removido: ");
		scanf("%d", &index);
		fflush(stdin);

		if ((index < 0) || (index > (listSize - 1)))
			printf("Index invalido! Tente novamente.\n");
		
	} while ((index < 0) || (index > (listSize - 1)));

	printf("Informacao da pessoa que deseja remover: \n");
	printPerson(list[index]);
	printf("Tem certeza que deseja remover este registro? [s/n] ");
	scanf("%c", &op);

	if (toupper(op) == 'S') {
		for (i = index; i < listSize - 2; i++) {
			list[i] = list[i + 1];
		}
		list = realloc(list, (listSize - 1) * sizeof(Person));
		printf("\nRegistro removido com sucesso.\n\n");
	}

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