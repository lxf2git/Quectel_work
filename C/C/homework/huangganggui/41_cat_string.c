#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void judge_string(char *);
void input(char *);
char *mycat(char*,char*,int);

int main()
{
	char *str1,*str2,*string;
	int flog;

	str1=(char *)malloc(100*sizeof(char));
	str2=(char *)malloc(100*sizeof(char));
	string=(char *)malloc(200*sizeof(char));
	judge_string(str1);
	judge_string(str2);
	judge_string(string);
	
	input(str1);
	input(str2);
	printf("input a number 1 or 2:\n");
	scanf("%d",&flog);

	string=mycat(str1,str2,flog);

	if(NULL == string)
	{
		printf("the flog is err!\n");
	}else
	{
		puts(string);
	}
	
	
	return 0;
}
void judge_string(char *string)
{
	if (NULL == string)
	{
		printf("ERR!");
		exit(-1);
	}
}

void input(char *string)
{
	printf("input a string please:\n");
	scanf("%s",string);

}

char *mycat(char *str1,char *str2,int flog)
{
	if(0 == flog)
	{
		 return strcat(str1,str2);
	}
	else if(1 == flog)
	{
		 strcat(str2,str1);
		 return str2;
	}else
	{
		return NULL;
	}
}
