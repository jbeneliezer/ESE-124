#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	unsigned long int nr, int_nr, bin_nr = 0;
	
	printf ("Enter number: ");
	scanf ("%d", &int_nr);
	
	nr = int_nr;
	
	push(2);
	
	while (int_nr > 0) {
		push(int_nr % 2);
		int_nr /= 2;
	}
	
	while (peek() != 2) {
		bin_nr = bin_nr * 10 + pop();
	}
	
	printf ("%d in binary is %d\n", nr, bin_nr);
	
	return 0;
}
