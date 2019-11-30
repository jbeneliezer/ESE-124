#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"


int Intelligence (char com[]) {
	int action;
	int i = 0;

	char Action[15][6] = {
		"MVF",
		"MVB",
		"MVL",
		"MWR",
		"CWL",
		"CWR",
		"CWF",
		"CWB",
		"PUSH",
		"POP",
		"PEEK",
		"CLEAR",
		"BJPI",
		"CJPI",
		"RP"
	};

	while (i < 15) {
		if (strcmp(com, Action[i]) == 0) {
			action = i;
			printf ("action: %d\n", action);
			break;
		}
		i++;
	}

	if (i == 15) {
		printf ("Invalid command\n");
		return 99;
	}
	i = 0;

	return action;
}
