#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int nr, ones_result = 0, zeros_result = 0, i, shift;
	
	//takes integer input from the keyboard
	printf("Enter an integer: ");
	scanf("%d", &nr);
	
	//checks each bit to see if 1 or 0
	for (i = 0; i < 32; i++) {
		shift = 1 << i;
		if ((nr & shift) == shift) {
			ones_result += 1;
		} else {
			zeros_result += 1;
		}
		
	}	
		
	
	
	printf("In binary your number has %d ones\n", ones_result);
	printf("In binary your number has %d zeros\n", zeros_result);
	
	return 0;
	
}
