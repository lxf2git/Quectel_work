#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int ch;
	int i = 1;
	FILE *fp=NULL;
	fp=fopen("student","r");
	if(NULL==fp)
	{
		printf("fopen error");
		exit(-1);
	}
	while((ch=fgetc(fp))!=EOF)
	{
		if(ch==10)
		{
			i++;
		}
		if(i==1||i==3||i==7||i==5||i==10)
		{
			printf("%c",ch);
		}
	}
	printf("\n");
	fclose(fp);
	return 0;
}
