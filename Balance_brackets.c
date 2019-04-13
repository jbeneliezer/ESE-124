#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE *f;
	char c;
	char value;

	if ((f = fopen("test.txt", "r")) == NULL) {
		printf ("Cannot open file test.txt");
		return 1;
	}

	c = fgetc (f);

	while (c != EOF) {
		switch (c) {
			case '(':
				push(c);
				break;
			case '[':
				push(c);
				break;
			case '{':
				push(c);
				break;
			case ')':
				value = pop();
				if (value == '(') {
					break;
				} else {
					printf ("Unbalanced parentheses!\n");
					return 1;
				}
			case ']':
				value = pop();
				if (value == '[') {
					break;
				} else {
					printf ("Unbalanced brackets!\n");
					return 1;
				}
			case '}':
				value = pop();
				if (value == '{') {
					break;
				} else {
					printf ("Unbalanced braces!\n");
					return 1;
				}
			default:
				break;
		}
		c = fgetc(f);
	}
	
	if (isempty()) {
		printf ("File is error free!\n");
		return 0;
	}
	
	while (!isempty()) {
		value = pop();
		if (value == '(') {
			printf ("Unclosed parentheses!\n");
		} else if (value == '[') {
			printf ("Unclosed brackets!\n");
		} else if (value == '{') {
			printf ("Unclosed braces!\n");
		}
	}
	return 1;
}
