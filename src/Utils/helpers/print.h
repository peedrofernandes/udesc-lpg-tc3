#ifndef _PRINT_H
#define _PRINT_H

#include <stdio.h>
#include "../constants/consts.h"

int printMainMenu() {
  int option;

  clearScreen();

  printf("\n-----------------------\n");
  printf(" MENU PRINCIPAL AGENDA\n");
  printf("-----------------------\n\n");
  printf("QUAL OPCAO DESEJA SEGUIR: \n\n");

  printf("[1] Inserir um novo registro (maximo de 100 registros!);\n");
  printf("[2] Mostrar todos os registros;\n");
  printf("[3] Remover um registro;\n");
  printf("[4] Buscar registro por nome;\n");
  printf("[5] Buscar aniversariantes do mes;\n");
  printf("[6] Buscar aniversariantes do dia;\n");
  printf("[0] Encerrar programa.\n");

  printf("Sua opcao: ");
  scanf("%d", &option);

  clearScreen();

  return option;
}

int printReducedMenu() {
  int option;

  printf("\n-----------------------\n");
  printf(" MENU PRINCIPAL AGENDA\n");
  printf("-----------------------\n\n");
  printf("QUAL OPCAO DESEJA SEGUIR: \n\n");

  printf("[1] Inserir um novo registro;\n");
  printf("[0] Encerrar programa.\n");

  printf("Sua opcao: ");
  scanf("%d", &option);

  clearScreen();

  return option;
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

void printList(int size, Person *people) {
	for (int i = 0; i < size; i++) {
		printf("Nome: %s %s\n", people[i].firstName, people[i].lastName);
		printf("Email: %s\n", people[i].email);
		printf("Telefone: (%d) %d\n", people[i].phone.ddd, people[i].phone.number);
		printf("Aniversario: %d/%d/%d\n", people[i].birthday.day, people[i].birthday.month, people[i].birthday.year);
		printf("\n");
	}
}

#endif