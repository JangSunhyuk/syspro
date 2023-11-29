#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<grp.h>
#include<pwd.h>

int main ( int argc, char *argv[] )
{
	extern char **environ;
	char **ptr;

	if(strcmp(argv[1], "-e") == 0) {
		if(argv[2] == NULL ) {
			for (ptr = environ; *ptr != 0; ptr++ ) 
			{ 
				printf ("%s \n", *ptr); 
				exit(0);
			}
		}
		else printf ("%s \n", getenv(argv[2]));
	}
	else if(strcmp(argv[1], "-u") == 0) {
		printf("나의 실제 사용자 ID : %d(%s) \n", getuid(), getpwuid(getuid())->pw_name);
   		printf("나의 유효 사용자 ID : %d(%s) \n", geteuid(), getpwuid(geteuid())->pw_name);
	}
	else if(strcmp(argv[1], "-g") == 0) {
  		printf("나의 실제 그룹 ID : %d(%s) \n", getgid(), getgrgid(getgid())->gr_name);
   		printf("나의 유효 그룹 ID : %d(%s) \n", getegid(), getgrgid(getegid())->gr_name);
	}
	else if(strcmp(argv[1], "-i") == 0) {
		printf("나의 프로세스 번호 : [%d] \n", getpid());
	}
	else if(strcmp(argv[1], "-p") == 0) {
	        printf("내 부모 프로세스 번호 : [%d] \n", getppid());
	}
}
