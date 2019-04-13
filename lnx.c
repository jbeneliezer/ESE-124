#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float x, sum_exp = 0.0, t;
	int number_of_steps, i;
	
	//takes in the argument
	printf("Input variable x: ");
	scanf("%f", &x);

	//takes in the number of times to compute the taylor series
	printf("Enter the number of steps: ");
	scanf("%d", &number_of_steps);
	
	t = x - 1;
	
	//computes the taylor series
	for(i = 1; i <= number_of_steps; i++) {
		sum_exp += t;
		t *= ((-1) * (x - 1) * i)/ (i + 1);
		
		
	}
	
	//prints the answer
	printf("ln of %f = %f\n", x, sum_exp);	
		
	return 0;
}
