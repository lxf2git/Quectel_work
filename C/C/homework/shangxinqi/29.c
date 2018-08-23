#include<stdio.h>
//#include<string.h>
void character(char a[]);
void word(char a[]);
void line(char a[]);
int main()
{
	int i;
	char a[50]="0";
	printf("输入正文:\n");
	for(i=0;i<50;i++)
	{
	scanf("%c",&a[i]);
	if(a[i]==10&&a[i-1]==10)
	{
	break;
	}
	}
	character(a);
	word(a);
	line(a);
	return 0;
}
void character(char a[])
{
	int j,character=0;
	for (j=0;j<50;j++)
	{
		if((a[j]<=90&&a[j]>=65)||(a[j]<=122&&a[j]>=97))
		{
		character++;
		}
	}	
printf("character:%d\n",character);
}
void word(char a[])
{
	int i,word=0;
    for(i=0;i<50;i++)
	{
		if(a[i]==32||a[i]==46)
		{
			word++;
		}
	}
printf("word:%d\n",word);
}
void line(char a[])
{
int i,line=0;
	for(i=0;i<50;i++)
	{
		if(a[i]==10)
		line++;
	}
printf("line:%d\n",line-1);
}

