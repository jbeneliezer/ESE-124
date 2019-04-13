#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void Sort (char arr[], char returnArray[][2]) {
	int i = 0, j = 0;
	arr[0] = returnArray[arr[0]][0];
	while (i < strlen(arr)) {
		while (j < strlen(returnArray)) {
   			if (arr[i] == returnArray[j][0]) {
				returnArray[j][1] += 1;
				break;
			} else {
				j++;
			}
		}
		if (j == strlen(returnArray) && arr[i] != returnArray[j]) {
			returnArray[j + 1][0] = arr[i];
			returnArray[j + 1][1] = 1;
		}
		i++;
	}

}

int main(int argc, char *argv[]) {
	FILE *f;
	FILE *f2;
	char letter;
	char word[32];
	char array[32][2];
	
	if ((f = fopen("test.txt", "r")) == NULL) {
		printf ("Cannot open file test.txt\n");
		return 1;
	}
	
	if ((f2 = fopen("output.txt", "w")) == NULL) {
		printf ("Cannot open file output.txt\n");
		return 1;
	}
	
	letter = fgetc(f);
	while (letter != EOF) {
		fscanf(f, "%s", word);
		Sort(word, array);
	} //while
	
	
	
	fprintf (f2, "%s", array);
	
	
	return 0;
}
