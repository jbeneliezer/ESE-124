#include <stdio.h>
#include <stdlib.h>

#define LEN 32

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FILE *f;
	FILE *f2;
	int index = 0;
	char c, identifier [LEN];
	float value = 0.0, dec_value = 0.0;
	float i = 0.1;

	
	if ((f = fopen ("C:/Users/judahbene/Documents/ESE 124/Notes/test.txt", "r")) == NULL) {
       printf ("File %s cannot be opened\n", "program.txt");
       return 1;
	}
	
	if ((f2 = fopen("C:/Users/judahbene/Documents/ESE 124/Notes/output.txt", "w")) == NULL) {
		printf("File %s cannot be opened\n", "output.txt");
		return 1;
	}
	 
	//reads first character from the file
	c = fgetc (f);
	
	//reads characters until end of file
	while (c != EOF) {
	
	  while (c == ' ' || c == '\n')
	        c = fgetc (f);
	  
	  //checks if letter
	  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_')) {
	    
	    //all following digits belong to the same name
	    while ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || (c == '_')) {
		  identifier [index++] = c;
		  c = fgetc(f);
		} // while
	    identifier [index] = '\0';
	    index = 0;
	  
	    if (strcmp (identifier, "start") == 0 || strcmp (identifier, "START") == 0)
		  fprintf (f2, "keyword START ");
		else if (strcmp (identifier, "stop") == 0 || strcmp (identifier, "STOP") == 0)
		  fprintf (f2, "keyword STOP ");
		else if (strcmp (identifier, "speed") == 0 || strcmp (identifier, "SPEED") == 0)
		  fprintf (f2, "keyword SPEED ");
		else if (strcmp (identifier, "set") == 0 || strcmp (identifier, "SET") == 0)
		  fprintf (f2, "keyword SET");
		else if (strcmp (identifier, "alarm") == 0 || strcmp (identifier, "ALARM") == 0)
		  fprintf (f2, "keyword ALARM");
		else if (strcmp (identifier, "move") == 0 || strcmp (identifier, "MOVE") == 0)
		  fprintf (f2, "keyword MOVE");
		else if (strcmp (identifier, "left") == 0 || strcmp (identifier, "LEFT") == 0)
		  fprintf (f2, "keyword LEFT");
		else if (strcmp (identifier, "right") == 0 || strcmp (identifier, "RIGHT") == 0)
		  fprintf (f2, "keyword RIGHT");
		else if (strcmp (identifier, "forward") == 0 || strcmp (identifier, "FORWARD") == 0)
		  fprintf (f2, "keyword FORWARD");
		else if (strcmp (identifier, "backward") == 0 || strcmp (identifier, "BACKWARD") == 0)
		  fprintf (f2, "keyword BACKWARD");
		else if (strcmp (identifier, "red") == 0 || strcmp (identifier, "RED") == 0)
		  fprintf (f2, "keyword RED");
		else if (strcmp (identifier, "green") == 0 || strcmp (identifier, "GREEN") == 0)
		  fprintf (f2, "keyword GREEN");
		else if (strcmp (identifier, "blue") == 0 || strcmp (identifier, "BLUE") == 0)
		  fprintf (f2, "keyword BLUE");
		else
		  fprintf (f2, " identifier: %s ", identifier);
	       
	  //checks char to see if a number
	  } else if (c >= '0' && c <= '9' ) {
        
	      while (c >= '0' && c <= '9') {
		    value = value * 10 + c - '0';
		    c = fgetc (f);
		  }
	      if (c == '.') {
		      c = fgetc (f);
		      while (c >= '0' && c <= '9') {
		        dec_value = dec_value + i * (c - '0');
		    	i *= 0.1;
		    	c = fgetc (f);
			  }
			}
		  value += dec_value;
	      fprintf (f2, "Value = %f ", value);
	      value = 0;
	      i = 0.1;
        }
        //chec
        else if (c == '=') {
          fprintf (f2, " EQUAL ");
          c = fgetc (f);
        } else if (c == ';') {
          fprintf (f2, " SEMICOLON \n");
          c = fgetc (f);
        } else if (c == '+') {
          fprintf (f2, "%c", c);
          c = fgetc (f);
          if (c >= '0' && c <= '9' ) {
	        while (c >= '0' && c <= '9') {
		      value = value * 10 + c - '0';
		      c = fgetc (f);
		      if (c == '.') {
		    	c = fgetc (f);
		    	while (c >= '0' && c <= '9') {
		    	  dec_value += i * (c - '0');
		    	  c = fgetc (f);
		          i *= 0.1;
				}
			  }
		    }
		    value += dec_value;
		    fprintf (f2, "%f", value);
			value = 0.0;
			i = 0.1;
          } else {
          	fprintf (f2, "%c", c);
          	c = fgetc (f);
		  }
        } else if ( c == '-') {
          if (c >= '0' && c <= '9') {
        	while (c >= '0' && c <= '9') {
		      value = value * 10 + c - '0';
		      c = fgetc (f);
		      if (c == '.') {
		    	c = fgetc (f);
		    	while (c >= '0' && c <= '9') {
		    	  dec_value += i * (c - '0');
		    	  c = fgetc (f);
		          i *= 0.1;
				}
			  }
		    }
		    value = -(value + dec_value);
		    fprintf (f2, "%f", value);
			value = 0.0;
			i = 0.1;
		  } else {
			fprintf (f2, "%c", c);
			c = fgetc (f);
		  }
		} else if (c == '/' || c == '*') {
		  fprintf (f2, "%c", c);
		  c = fgetc (f);
		} else if (c == '<' || c == '>' || c == ',' || c == '.' || c == '?') {
		  fprintf (f2, " %c ", c);
		  c = fgetc (f);
		  if (c == '=') {
		  	fprintf (f2, " %c ", c);
		  	c = fgetc (f);
		  }
	    }
		
    }
	return 0;
}
