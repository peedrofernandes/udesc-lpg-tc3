#ifndef _ADD_PERSON_H
#define _ADD_PERSON_H

#include <stdio.h>
#include <stdlib.h>
#include "../constants/consts.h"
#include "handlers.h"

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

#endif