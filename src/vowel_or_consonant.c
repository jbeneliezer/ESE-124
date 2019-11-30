#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char c;
	
	printf("Enter a letter: ");
	scanf("%c", &c);
	
	//checks to see if char is a vowel
	if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i' || c == 'O' || c ==  'o' || c == 'U' || c == 'u') {
		printf("Character is a vowel\n");
	} else {
		printf("Character is a consonant\n");
	}
	return 0;
}
