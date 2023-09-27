#include <stdio.h>
#include <string.h>
#include "copy.h"

char line[MAXLINE];
char longest[MAXLINE];
void copy(char form[], char to[]);

int main(){
	int len;
	int max;
	max = 0;

	while(fgets(line,MAXLINE,stdin) != NULL){
		len = strlen(line);

		if(len > max) {
			max = len;
			copy(line, longest);
		}
	}
	if(max > 0)
		printf("%s \n", longest);

	return  0;
}
