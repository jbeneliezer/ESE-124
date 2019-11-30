#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int nr_1, nr_2, x;
	
	//takes in input for first number
	printf("Enter a number: ");
	scanf("%d", &nr_1);
	
	//takes in input for second number
	printf("Enter another number: ");
	scanf("%d", &nr_2);
	
	x = nr_2;
	//counts down in integer steps from nr_1
	while (nr_1 > 0) {
		
		if (nr_1 % x == 0 && nr_2 % x == 0) {
			//if true prints x
			printf("Greatest common factor is %d\n", x);
			break;
		}
		
		x--;
	}
	
	return 0;
}
