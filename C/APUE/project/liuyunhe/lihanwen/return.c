#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void creat_memory()
{
	extern char *string;
	string = malloc(20*sizeof(char));
}

void fun()
{
	extern char *string;
	printf("%s\n",string);
}

void freemem()
{
	extern char *string;
	printf("free----\n");
	if(NULL!=string)
	{
		free(string);
		string==NULL;
	}
}
char *string;

int main()
{
	atexit(freemem);
	creat_memory();
	strcpy(string,"hello");
	fun();
	printf("main end\n");

	return 0;
}
