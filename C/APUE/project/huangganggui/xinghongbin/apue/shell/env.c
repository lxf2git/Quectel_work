#include<stdio.h>
 #include <string.h>
 #include <stdlib.h>

int main(int argc,char **argv)
{
		int i;
		for(i=1;i<argc;i++)
		{
				if(strchr(argv[i],'=')!=NULL)
				{
						myPutenv(argv[i]);
						return 0;
				}
		}
		puts(argv[1]);
		myGetenv(argv[1]+1);

		return 0;
}


int myGetenv(char* envName)
{
		printf("%s\n",getenv(envName));

}

int myPutenv(char *string)
{
		putenv(string);
}
