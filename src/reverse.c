#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char *Reverse(char word[], char arr[]) {
	arr = strrev(word);
	return arr;
}

int main(int argc, char *argv[]) {
	FILE *f;
	FILE *f2;
	char c;
	char *str;
	char *array;
	int i = 0;
	
	if ((f = fopen("test.txt", "r")) == NULL) {
		printf ("Cannot open file test.txt");
		return 1;
	}
	
	if ((f2 = fopen ("output.txt", "w")) == NULL) {
		printf ("Cannot open file output.txt");
		return 1;
	}
	
	c = fgetc(f);
	
	while (c != EOF) {
		str[i++] = c;
		c = fgetc(f);
	}
	
	array = Reverse(str, array);
	
	fprintf (f2, "%s\n", array);
	
	return 0;
}
