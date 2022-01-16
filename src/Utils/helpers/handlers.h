#ifndef _HANDLERS_H
#define _HANDLERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../constants/consts.h"
#include "mainFunctions.h"
#include "support.h"

void createPersonHandler(Person *list, int *listSize) {
  printf("\n");
  Person person;
  person = createPerson();
  insertPerson(person, list, listSize);
  systemPause();
}

void listPeopleHandler(Person *list, int listSize) {
  int i;

  if (listSize == 0) {
    printf("Valor invalido, tente novamente!\n");
    systemPause();
  } else {  
    printf("\n------------------------\n");
    printf("   TODOS OS REGISTROS\n");
    printf("------------------------\n\n");

    for (i = 0; i < listSize; i++) {
      printf("--------\n");
      printf("INDEX %d\n", i);
      printf("--------\n\n");
      printPerson(list[i]);
    }

    printf("\nFim do registro.\n\n");
    systemPause();
  }
}

void removePersonHandler(Person *list, int *listSize) {
  if (*listSize == 0) {
    printf("Valor invalido, tente novamente!\n");
    systemPause();
  } else {
    removePerson(list, listSize);
  }
}

void searchByNameHandler(Person *list, int listSize) {
  if (listSize == 0) {
    printf("Valor invalido, tente novamente!\n");
    systemPause();
  } else {
    printf("Insira o nome que deseja buscar nos registros: \n");
    char nameToBeSearched[50];
    scanf("%s", nameToBeSearched);
    searchPersonByName(listSize, nameToBeSearched, list);
    systemPause();
  }
}

void searchByMonthHandler(Person *list, int listSize) {
  int monthToBeSearched = 0;

  if (listSize == 0) {
    printf("Valor invalido, tente novamente!\n");
    systemPause();
  } else {
    printf("Insira o mes que deseja buscar por aniversariantes: ");
    scanf("%d", &monthToBeSearched);
    if (monthToBeSearched >= 1 && monthToBeSearched <= 12) {
      searchPersonByMonth(listSize, monthToBeSearched, list);
      systemPause();
    } else {
      printf("Mes invalido, retornando ao menu\n");
      systemPause();
    }
  }
}

void searchByDateHandler(Person *list, int listSize) {
  int monthToBeSearched = 0, dayToBeSearched = 0;

  if (listSize == 0) {
    printf("Valor invalido, tente novamente!\n");
    systemPause();
  } else {
    printf("Insira a data que deseja buscar por aniversariantes\n");
    printf("Mes: ");
    scanf("%d", &monthToBeSearched);
    printf("Dia: ");
    scanf("%d", &dayToBeSearched);

    printf("Data inserida: %d/%d\n", dayToBeSearched, monthToBeSearched);

    if (monthToBeSearched >= 1 && monthToBeSearched <= 12 && dayToBeSearched >= 1 && dayToBeSearched <= 31) {
      searchPersonByExactDay(listSize, monthToBeSearched, dayToBeSearched, list);
      systemPause();
    } else {
      printf("Data invalida, retornando ao menu\n");
      systemPause();
    }
  }
}

#endif