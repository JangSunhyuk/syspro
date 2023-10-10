#include <stdio.h>
#include <string.h>
#include "copy.h"

char line[MAXLINE];
char str[5][MAXLINE];
char ch[MAXLINE];
void copy(char form[], char to[]);


int main() {

	for(int i = 0; i < 5; i++){

		fgets(line, MAXLINE, stdin);
		copy(str[i], line);
	
	}

	for(int i = 0; i <  5; i++){
		for(int j = i+1; j < 5; j++){
			if(strlen(str[i]) < strlen(str[j])) {

				copy(ch,  str[i]);
				copy(str[i], str[j]);
				copy(str[j], ch);
			
			}
		}
	}

	for(int i = 0; i < 5; i++){

		printf("%s", str[i]);
	
	}

	return  0;
}
