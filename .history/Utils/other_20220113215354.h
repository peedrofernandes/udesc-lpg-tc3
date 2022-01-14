#ifndef _OTHER_H
#define _OTHER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inputString(char *string, int max) {
  fflush(stdin);

  int i = 0;

  fgets(string, max, stdin);

  do {
    if (string[i] == '\n') {
      string[i] = '\0';
      break;
    }
    i++;
  } while (i < strlen(string));
}

#endif