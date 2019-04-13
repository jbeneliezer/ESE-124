#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int nr, i = 2, factor = 1;
	
	//takes an integer input from the keyboard
	printf("Enter a number: ");
	scanf("%d", &nr);

	
	while (i < nr) {
		while (nr % i == 0) {
			printf("%d\n", i);
			factor += 1;
			nr /= i;
		}
		i++;
	
	}
	
	printf("%d\n", nr);
	printf("\n");
		
	if (factor == 1) {
		printf("%d is prime\n", nr);
	} else {
		printf("Number has %d prime factors\n", factor);
	}
	
	
	return 0;
}
