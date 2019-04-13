#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int nr, nr_zeros = 0, i, shift;
	
	//takes integer input from the keyboard
	printf("Enter an integer: ");
	scanf("%d", &nr);

	//checks each bit from left to right to see if 1 or 0
	for (i = 31; i >= 0; i--) {
	    shift = 1 << i;
		if ((nr & shift) != shift) {
			nr_zeros += 1;
		}
		
	}
	
	printf("This number has %d leading zeros\n", nr_zeros);
	
	return 0;
	
}
