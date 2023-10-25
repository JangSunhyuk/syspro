#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]){

	FILE *fp;
	int text;
	char buf;

	if ( argc < 3 ){
	
		fprintf(stderr, "How to use: %s num File1\n", argv[0]);
		
		exit(1);
	
	}

	if ( strcmp ( argv[1], "0" ) == 0){

		fp = fopen( argv[2], "wb");

		while(1){

			fscanf(fp , "%s", &buf);
			fwrite(&buf, 1, sizeof(buf), fp);

			if (buf == NULL) break;
			else {
				
				buf = NULL;
				continue;

			}
		
		}

		//while(scanf ("%s", fp) != NULL )
		//	printf ("%s", fp);

		fclose(fp);
		exit (2);

	}

	else {

		fp = fopen(argv[2], "r");

		text = getc(fp);

		while ( text != EOF ) {

			putc ( text,  stdout );
			text = getc( fp );

		}
	}

	fclose ( fp );
	exit (0);
}
