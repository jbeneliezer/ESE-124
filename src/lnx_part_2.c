#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	float x, ln_x = 0.0, epsilon, t;
	int i = 1;
	
	//input value of x
	printf ("x = ");
	scanf ("%f", &x);
	
	//input epsilon
	printf ("epsilon = ");
	scanf ("%f", &epsilon);
	
	t = x - 1;
	
	//checks if value of t is greater than epsilon
	while (t >= epsilon || t <= -epsilon) {
		ln_x += t;
		t *= ((-1) * (x - 1) * i)/ (i + 1);
		i++;
		
	}
	
	//prints the result
	printf ("ln of %f = %f \n", x, ln_x);
	
	return 0;
}
