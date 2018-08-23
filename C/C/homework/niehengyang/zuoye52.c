#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void tj(char *p);



int main()
{
	int i;
	char a[10];
	int flag;
	char *p=a;
	for(i=0;i<10;i++)
	{
	printf("please input the name(a or b or c):");
	scanf("%c",&p[i]);
	getchar();
	}
	tj(p);

}


void tj(char *p)
{
	int i;
	int s1=0,s2=0,s3=0;
	for(i=0;i<10;i++)
	{
		if(p[i]=='a')
		{
			s1+=1;	
		}
		if(p[i]=='b')
		{
			s2+=1;
		}
		if(p[i]=='c')
		{
			s3+=1;
		}
	}
	printf("a:%d b:%d c:%d",s1,s2,s3);

}
