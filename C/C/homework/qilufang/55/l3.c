#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	int i=0;
	fp=fopen("file","r");
	char *p;
	p=malloc(sizeof(char)*100);
	fp=fopen("file","r");
	while(!feof)
	{
		i++;
		*(p+i)=fgetc(fp);
	}
	printf("%s\n",p);
	return 0;

}
