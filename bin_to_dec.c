#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int bin, dec = 0, x = 1, i;
	
	//takes in an integer input
	printf("Enter a number in binary: ");
	scanf("%d", &bin);
	
	//iterates over every decimal place in bin
	for (i = 1; i <= bin; i = i) {
		
		//introduces variable last_digit to evaluate the right-most decimal place
		int last_digit = bin % 10;
		
		//shifts the measurement to the next place to the left
		bin /= 10;
		
		//multiplies the value of the operation by the placement in base-2
		dec += last_digit * x;
		x = x * 2;

	}
	
	printf("Decimal number = %d", dec);
	
	return 0;
}
