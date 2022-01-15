#ifndef _UPPERSTRING_H_
#define _UPPERSTRING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void upperString(char *string) {
	int i = 0;

	while (string[i] != '\0') {
		if (string[i] >= 'a' && string[i] <= 'z') {
			string[i] -= 32;
		}
		i++;
	}
}

#endif