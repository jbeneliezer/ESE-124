#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define SMALL -3.4e38

float Largest(float x, float y, float z) {
	return (x > y) ? ((x > z) ? x: z) : ((y > z) ? y: z);
}

int main(int argc, char *argv[]) {
	FILE *f;
		
	float x, y = SMALL, z = SMALL, largest;
	char c;
	
	if ((f = fopen("test.txt", "r")) == NULL) {
		printf ("Cannot open file %s\n", "test.txt");
		return 1;
	}
	
	fscanf(f, "%f", &x);
	c = fgetc(f);
	
	while (c != EOF) {
		largest = Largest(x, y, z);
		
		z = y;
		y = largest;
		
		fscanf (f, "%f", &x);
		c = fgetc(f);
	}
	
	printf("%f\n", largest);
	
	return 0;
}
