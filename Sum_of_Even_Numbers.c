#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int nr, sum_odd = 0, sum_even = 0;
	char stop = '+';
	
	while(stop != '#') {
		
		printf("Enter number: ");
		scanf("%d", &nr);
		getchar();
		
		//checks if input is even or odd
		if (nr % 2 == 0){
			sum_even += nr;
		} else {
			sum_odd += nr;
		}
		
		//will stop the program
		printf("\'#\' will terminate the program, press enter to continue ");
		stop = getchar();
		
	}
	//prints the result of even and odd numbers separately
	printf("Sum of even numbers is %d\n", sum_even);
	printf("Sum of odd numbers is %d\n", + sum_odd);
	return 0;
}
