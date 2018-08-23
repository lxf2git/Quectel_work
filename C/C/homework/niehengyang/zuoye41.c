#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *link(char *p1,char *p2,int flag);
int main()
{
	int i,j,flag;
	char *p1=NULL;
	char *p2=NULL;
	p1=(char *)malloc(10*sizeof(char));
	printf("please input a:");
	gets(p1);
	p2=(char *)malloc(10*sizeof(char));
	printf("please input b:");
	gets(p2);
	printf("please input flag");
	scanf("%d",&flag);
	p1=link(p1,p2,flag);
	printf("%s\n",p1);

}

char *link(char *p1,char *p2,int flag)
{
	
	switch(flag)
	{
		case 0:
		strcat(p1,p2);
		return p1;
		break;
		case 1:
		strcat(p2,p1);
		return p2;
		break;
		default: 
		return p1=NULL;
	}


}
