#ifndef _SUPPORT_H
#define _SUPPORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearBuffer(void) {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void systemPause(void) {
  clearBuffer();
  printf("Pressione enter para continuar...");
  getchar();
}

void inputString(char *string, int max) {
  long unsigned int i = 0;

  fgets(string, max, stdin);

  do {
    if (string[i] == '\n') {
      string[i] = '\0';
      break;
    }
    i++;
  } while (i < strlen(string));

}

void upperString(char *string) {
	int i = 0;

	while (string[i] != '\0') {
		if (string[i] >= 'a' && string[i] <= 'z') {
			string[i] -= 32;
		}
		i++;
	}
}

  #ifdef WIN32
    
    void clearScreen(void) {
      system("cls");
    }

  #else

    void clearScreen(void) {
      system("clear");
    }

  #endif

#endif