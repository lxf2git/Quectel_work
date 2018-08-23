#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * Getmemory()//p = &str  *p  str
{
	char *p;	
	p = (char *)malloc(100*sizeof(char));
	return p;
	

}
int main()
{
	char *str=NULL;

	str = Getmemory();//str=&
	strcpy(str,"hello baby");

	printf("str:%s\n",str);	
	if(str!=NULL)
	{
		free(str);
		str = NULL;
	}

	return 0;

}
