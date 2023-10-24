#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
   FILE *fp;
   int c; 
   int count = 0;



   if ( strcmp ( argv[1], "-n" ) == 0 ){

	   for ( int i = 2; i < argc; i++){

		   fp = fopen ( argv[i], "r");
/*
		   if ( fp == NULL ) {

			   perror( argv[i] );
			   continue;
		   
		   }
*/
		   c = getc ( fp );

		   count++;

		   printf ("%3d   ", count );

		   while ( c != EOF ) {

			   putc ( c, stdout );
			   c = getc (fp);
		   }
	   }
   }

   else {
	   		for(int i = 1; i < argc; i++){

   				fp = fopen(argv[i], "r");

   				c = getc( fp );

   				while (c != EOF) {

	  				putc(c, stdout);
      				c = getc(fp); 

	   		}
   		}
   }

   fclose(fp); 
   return 0;

}
