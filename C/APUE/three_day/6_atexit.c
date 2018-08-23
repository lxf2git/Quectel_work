#include"../apue.h"
char *string = NULL;
void creat_memory()
{
	string = (char *)malloc(20*sizeof(char));
	// if err
}

void fun()
{
	printf("fun:%s\n",string);
	//exit(0);

}
int fun1()
{
	printf("fun1:%s\n",string);
	_exit(0);
}

void freemem()
{
	printf("free---------\n");	
	if(string!=NULL)
	{
		free(string);
		string = NULL;
	}
}

void myclose()
{
	printf("close...\n");
}
void myflush()
{
	printf("flush...\n");
}
int main()
{
	atexit(freemem);
	atexit(myclose);	
	atexit(myflush);	
	creat_memory();
	strcpy(string,"hello");
	fun();
	fun1();
	printf("main end\n");	

	return 0;

}
