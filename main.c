#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MAX_SIZE 1000
#define MAX_ENERGY 10000

int x, y;

char **P;
int start_x, start_y, exit_x, exit_y;

int main(int argc, char **argv) {
	FILE *f;
	char c, identifier[4][100];
	int nr_columns = 0, nr_rows = 0;
	int energy = MAX_ENERGY;

	FILE *f2;

	if ((f2 = fopen("output.txt", "w")) == NULL) {
		printf ("Cannot open file output.txt");
		return 1;
	}

	int index = 0, command = 0;
	int i, j;

	if ((f = fopen("input.txt", "r")) == NULL) {
		printf ("Cannot open file input.txt\n");
		return;
	}

	c = fgetc(f);

	while (c != EOF) {
		while (c != '-') {
			while ((isalpha(c) == 0) && (c != '_')) {
				c = fgetc(f);
			}

			while ((isalpha(c) != 0) || (c == '_')) {
				identifier[command][index++] = c;
			  	c = fgetc(f);
			}
			identifier[command][index] = '\0';
		    index = 0;
		    printf ("command = %d\n", command+1);
		    printf ("identifier: %s\n", identifier[command]);

		    if (strcmp(identifier[command], "start") == 0) {
		    	while (isdigit(c) == 0) {
					c = fgetc(f);
				}
		    	while (isdigit(c) != 0) {
			    	start_x = start_x * 10 + c - '0';
			    	printf ("c = %c\n", c);
			    	c = fgetc (f);
			  	}
				while (isdigit(c) == 0) {
					c = fgetc(f);
				}
			    while (isdigit(c) != 0) {
			    	start_y = start_y * 10 + c - '0';
			    	c = fgetc (f);
			  	}
			  	printf ("start: %d, %d\n", start_x, start_y);
			  	fprintf (f2, "start: %d, %d\n", start_x, start_y);
			} else if (strcmp(identifier[command], "exit") == 0) {
		    	while (isdigit(c) == 0) {
					c = fgetc(f);
				}
		    	while (isdigit(c) != 0) {
			    	exit_x = exit_x * 10 + c - '0';
			    	c = fgetc (f);
			  	}
			  	while (isdigit(c) == 0) {
					c = fgetc(f);
				}
		    	while (isdigit(c) != 0) {
			    	exit_y = exit_y * 10 + c - '0';
			    	c = fgetc (f);
			  	}
		    	printf ("exit: %d, %d\n", exit_x, exit_y);
		    	fprintf (f2, "exit: %d, %d\n", exit_x, exit_y);
		    } else if (strcmp(identifier[command], "NR_COLUMNS") == 0) {
		    	while (isdigit(c) == 0) {
					c = fgetc(f);
				}
		    	while (isdigit(c) != 0) {
			    	nr_columns = nr_columns * 10 + c - '0';
			    	c = fgetc (f);
			  	}
			  	printf ("nr_columns: %d\n", nr_columns);
			  	fprintf (f2, "nr_columns: %d\n", nr_columns);
		    } else if (strcmp(identifier[command], "NR_ROWS") == 0) {
		    	while (isdigit(c) == 0) {
					c = fgetc(f);
				}
		    	while (isdigit(c) != 0) {
			    	nr_rows = nr_rows * 10 + c - '0';
			    	c = fgetc (f);
			  	}
			  	printf ("nr_rows: %d\n", nr_rows);
			  	fprintf (f2, "nr_rows: %d\n", nr_rows);
			  	break;
		    } else {
				printf ("Incorrect input format\n"
				"Command must be in the following format:\n"
				"keyword: args");
			}

			command++;
			c = fgetc(f);

		}
		
		while (c != '-') {
			c = fgetc(f);
		}

		P = (char **) malloc(nr_rows * sizeof(char*));
		for (i = 0; i < nr_rows; i++) {
			P[i] = (char *) malloc(nr_columns * sizeof(char));
		}

		
		for (i = 0; i < nr_rows; i++) {
			for (j = 0; j < nr_columns; j++) {
				P[i][j] = c;
				c = fgetc(f);
			}
			c = fgetc(f);
		}
		c = fgetc(f);
		
		for (i = 0; i < nr_rows; i++) {
	 		for (j = 0; j < nr_columns; j++) {
	 			printf("%c", P[i][j]);
	 			fprintf(f2, "%c", P[i][j]);
			}
			printf ("\n");
			fprintf (f2, "\n");
		}
		
		printf ("\n");
		fprintf (f2, "\n");

		break;

	}
	
	fclose(f);
	
	if ((f = fopen("intelligence.txt", "r")) == NULL) {
		printf ("Cannot open file intelligence.txt");
		return 1;
	}
	
	x = start_x;
	y = start_y;

	int temp = 0, itch = 0, spaces = 0;
	int nr = 1, times = 1;
	char direction;
	
	int action[1000];
	j = 0;
	int k = 0, a = 0;
	char com[6];
	
	
	do {
		fscanf(f, "%s", com);
		printf("command: %s\n", com);

		if (strcmp(com, "RP") == 0) {
			fscanf(f, "%d", &nr);
			fscanf(f, "%d", &times);
			printf ("nr, times = %d, %d\n", nr, times);
			fprintf (f2, "RP %d %d\n", nr, times);
		}

		while (k < nr) {
			fscanf(f, "%s", com);
			printf("command: %s\n", com);
			fprintf (f2, "%s\n", com);

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
				"CJPI"
			};

			while (j < 14) {
				if (strcmp(com, Action[j]) == 0) {
					action[a] = j;
					printf ("action: %d\n", action[a]);
					a++;
					break;
				}
				j++;
			}

			if (j == 14) {
				printf ("Invalid command\n");
				return 1;
			}
			j = 0;
			k++;
		}
		k = 0;
		c = fgetc(f);
	} while (c != EOF);
	
	j = 0;
	k = 0;
	printf ("\n");
	do {
	
		do {

			switch (action[j]) {
				case 0: //MVF
					printf ("MVF\n");
					energy -= 3;
					x += 1;
					break;
				case 1: //MVB
					printf ("MVB\n");
					energy -= 3;
					x -= 1;
					break;
				case 2: //MVL
					printf ("MVL\n");
					energy -= 3;
					y -= 1;
					break;
				case 3: //MWR
					printf ("MWR\n");
					energy -= 3;
					y += 1;
					break;
				case 4: //CWL
					printf ("CWL\n");
					energy -= 1;
					temp = y - 1;
					printf ("c = <%c>\n", P[x][temp]);
					if ((P[x][temp] == '|') || (P[x][temp] == '-')) {
						break;
					}
					while ((P[x][temp] != '|') && (P[x][temp] != '-')) {
						spaces++;
						if (temp == 0) {
							break;
						}
						temp--;
					}
					itch = 1;
					direction = 'l';
					break;
				case 5: //CWR
					printf ("CWR\n");
					energy -= 1;
					temp = y + 1;
					printf ("x, y = %d, %d\n", x, temp);
					printf ("c = <%c>\n", P[x][temp]);
					if ((P[x][temp] == '|') || (P[x][temp] == '-')) {
						break;
					}
					while ((P[x][temp] != '|') && (P[x][temp] != '-')) {
						spaces++;
						if (temp == (nr_columns - 1)) {
							break;
						}
						temp++;
					}
					itch = 1;
					direction = 'r';
					break;
				case 6: //CWF
					printf ("CWF\n");
					energy -= 1;
					temp = x + 1;
					printf ("x, y = %d, %d\n", temp, y);
					printf ("c = <%c>\n", P[temp][y]);
					if ((P[temp][y] == '|') || (P[temp][y] == '-')) {
						break;
					}
					while ((P[temp][y] != '|') && (P[temp][y] != '-')) {
						spaces++;
						if (temp == (nr_rows - 1)) {
							break;
						}
						temp++;
					}
					itch = 1;
					direction = 'f';
					break;
				case 7: //CWB
					printf ("CWB\n");
					energy -= 1;
					temp = x - 1;
					printf ("x, y = %d, %d\n", temp, y);
					printf ("c = <%c>\n", P[temp][y]);
					if ((P[temp][y] == '|') || (P[temp][y] == '-')) {
						break;
					}
					while ((P[temp][y] != '|') && (P[temp][y] != '-')) {
						spaces++;
						if (temp == 0) {
							break;
						}
						temp--;
					}
					itch = 1;
					direction = 'b';
					break;
				case 8: //PUSH
					printf ("PUSH\n");
					energy -= 4;
					push(x, y);
					break;
				case 9: //POP
					printf ("POP\n");
					energy -= 4;
					pop(x, y);
					break;
				case 10: //PEEK
					printf ("PEEK\n");
					energy -= 4;
					peek(x, y);
					break;
				case 11: //CLEAR
					printf ("CLEAR\n");
					energy -= 4;
					clear();
					break;
				case 12: //BJPI
					printf ("BJPI\n");
					energy -= 5;
					if (itch == 1) {
						if (direction == 'l') {
							y -= spaces;
						} else if (direction == 'r') {
							y += spaces;
						} else if (direction == 'f') {
							x += spaces;
						} else if (direction == 'b') {
							x -= spaces;
						}
					}
					itch = 0;
					spaces = 0;
					break;
				case 13: //CJPI
					printf ("CJPI\n");
					energy -= 3;
					if (itch == 1) {
						if (direction == 'l') {
							y -= 1;
						} else if (direction == 'r') {
							y += 1;
						} else if (direction == 'f') {
							x += 1;
						} else if (direction == 'b') {
							x -= 1;
						}
					}
					itch = 0;
					spaces = 0;
					break;
				default:
					printf ("Invalid command\n");
					return 1;
			}

			printf ("x, y: %d, %d\n", x, y);
			printf ("exit_x, exit_y: %d, %d\n", exit_x, exit_y);

			if (x == exit_x && y == exit_y) {
				printf ("Successfully exited maze!\n");
				fprintf (f2, "Successfully exited maze!\n");
				printf ("\nEnergy spent: %d\n", MAX_ENERGY - energy);
				fprintf (f2, "\nEnergy spent: %d\n", MAX_ENERGY - energy);
				return 0;
			}
			if (energy < 1) {
				printf ("out of energy!\n");
				fprintf (f2, "out of energy!\n");
				return 1;
			}
			j++;
			printf ("\n");
		} while (j < a);
		j = 0;
		k++;
	} while (k < times);
	
	printf ("Cannot escape maze\n");
	fprintf (f2, "Cannot escape maze\n");
	printf ("Position: %d, %d", x, y);
	fprintf (f2, "Position: %d, %d", x, y);
	printf ("\nEnergy spent: %d\n", MAX_ENERGY - energy);
	fprintf (f2, "\nEnergy spent: %d\n", MAX_ENERGY - energy);

	return 0;
	
}
