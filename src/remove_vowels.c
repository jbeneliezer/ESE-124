#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char *Remove_vowels(char str[]) {
	int i = 0, j = 0;
	char vowelArray[6] = "aeiou";
	while (i < strlen(str)) {
		while (j < 6) {
			while (str[i] != vowelArray[j]) {
				j++;
			}
			if (j != 6) {
				str[i++] = str[i];
			}
		}
		j = 0;
	}
} //Remove_vowels

int main(int argc, char *argv[]) {
	FILE *f;
	FILE *f2;
	char array[32];
	char array2[100];
	char c;
	
	if ((f = fopen("test.txt", "r")) == NULL) {
		printf ("Cannot open file test.txt");
		return 1;
	}
	
	if ((f = fopen("output.txt", "w")) == NULL) {
		printf ("Cannot open file output.txt");
		return 1;
	}
	
	c = fgetc(f);
	while (c != EOF) {
		fscanf(f, "%s", array);
		while (i < strlen(array)) {
			array2[i++] = Remove_vowels(array);
		}
			
		
	}
	
	fprintf (f2, "%s\n", array2);
	
	return 0;
}
