#ifndef _FILTERS_H
#define _FILTERS_H

#include <stdio.h>
#include <string.h>
#include "../constants/consts.h"
#include "upperString.h"
#include "print.h"

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
