#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int Vowels(char word[]) {
	int num = 0, i = 0, j = 0;
	char vowelList[6] = "aeiou";
	while (i < strlen(word)) {
		while (j < 6) {
			if (word[i] == vowelList[j]) {
				num += 1;
			}
			j++;
		} //while
		j = 0;
		i++;
	} //while
	return num;
} //Vowels


int main(int argc, char *argv[]) {
	FILE *f;
	FILE *f2;
	char c;
	char str[100];
	char str1[100];
	char str2[100];
	char large_str[100];
	char small_str[100];
	int largest, smallest, i = 0;
	
	if ((f = fopen("test.txt", "r")) == NULL) {
		printf ("Cannot open file test.txt");
		return 1;
	}
	
	if ((f2 = fopen("output.txt", "w")) == NULL) {
		printf ("Cannot open file output.txt");
		return 1;
	}
	
	c = fgetc(f);
	fscanf(f, "%s", str1);
	fscanf(f, "%s", str2);
	
	if (Vowels(str1) > Vowels(str2)) {
		while (i < strlen(str1)) {
			large_str[i++] = str1[i];
		}
		i = 0;
		while (i < strlen(str2)) {
			small_str[i++] = str2[i];
		}
		i = 0;
	} else if (Vowels(str1) < Vowels(str2)) {
		while (i < strlen(str1)) {
			small_str[i++] = str1[i];
		}
		i = 0;
		while (i < strlen(str2)) {
			large_str[i++] = str2[i];
		}
		i = 0;
	}
	i = 0;
	
	largest = Vowels(large_str);
	smallest = Vowels(small_str);
	while (c != EOF) {
		fscanf(f, "%s", str);
		if (Vowels(str) > largest) {
			while (i < strlen(str)) {
				large_str[i++] = str[i];
			}
			largest = Vowels(str);
			i = 0;
		} else if (Vowels(str) < smallest) {
			while (i < strlen(str)) {
				small_str[i++] = str[i];
			}
			smallest = Vowels(str);
			i = 0;
		}
		c = fgetc(f);
	} //while
	
	fprintf (f2, "Most vowels: %s, %d\n", large_str, largest);
	fprintf (f2, "Least vowels: %s, %d\n", small_str, smallest);
	
	return 0;
}
