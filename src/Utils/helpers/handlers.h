#ifndef _HANDLERS_H
#define _HANDLERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearBuffer(void) {
  char c = getchar();
  while ((c != '\n') && (c != EOF))
    c = getchar();
}

void inputString(char *string, int max) {
  clearBuffer();

  long long unsigned int i = 0;

  fgets(string, max, stdin);

  do {
    if (string[i] == '\n') {
      string[i] = '\0';
      break;
    }
    i++;
  } while (i < strlen(string));
}

  #ifdef WIN32
    
    void clearScreen(void) {
      system("cls");
    }

    void systemPause(void) {
      system("pause");
    }

  #else

    void clearScreen(void) {
      system("clear");
    }

    void systemPause(void) {
      system("read -p \"Pressione qualquer tecla para continuar...\"");
    }

  #endif

#endif