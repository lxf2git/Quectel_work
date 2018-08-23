#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Getmemory(char **p)//p = &str  *p  str
{
	*p = (char *)malloc(100*sizeof(char));
	//str=malloc...
	

}
int main()
{
	char *str=NULL;
	Getmemory(&str);//str=&
	strcpy(str,"hello baby");

	printf("str:%s\n",str);	
	if(str!=NULL)
	{
		free(str);
		str = NULL;
	}

	return 0;

}
