#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char Upper(char c) {
	return (c >= 'a' && c <= 'z') ? (c - 32): c;
}

int main(int argc, char *argv[]) {
	FILE *f;
	FILE *f2;
	char c;
	char str[32];
	int i = 0;
	
	if ((f = fopen("test.txt", "r")) == NULL) {
		printf("file %s cannot be opened\n", "test.txt");
		return 1;
	}
	if ((f2 = fopen("output.txt", "w")) == NULL) {
		printf("file %s cannot be opened\n", "output.txt");
		return 1;
	}
	
	c = fgetc(f);
	
	if ((c >= 'a' && c <= 'z') || (c >= 'C' && c <= 'Z')) {
		while (c != EOF) {
			while (c != '\0') {
				str[i] = c;
				c = fgetc (f);
				i++;
			}
			Upper(str[0]);
			fprintf(f2, "%s", str);
			c = fgetc (f);
			i = 0;
		}
	}

	return 0;
}
