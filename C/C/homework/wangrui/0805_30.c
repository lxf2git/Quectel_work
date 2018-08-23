#include<stdio.h>
#include<string.h>
#define N 100

void input(char str1[N],char str2[N]);
void _sort(char str[N]);
void _deal(char str[N]);
int main()
{
	char str_1[N]={};
	char str_2[N]={};
	input(str_1,str_2);
	_deal(str_1);
	return 0;
}

void input(char str1[N],char str2[N])
{
	printf("string1:\n");
	scanf("%s",str1);
	printf("string2:\n");
	scanf("%s",str2);
	_sort(str1);
	_sort(str2);
	_sort(strcat(str1,str2));
}

void _sort(char str[N])
{
	int i,n,j;
	for(j=0;j<strlen(str)-1;j++)
	{
		for(i=0;i<strlen(str)-1;i++)
		{	
			if(str[i]>=str[i+1])
			{
				n=str[i];
				str[i]=str[i+1];
				str[i+1]=n;
			}
		}
	}
	printf("%s\n",str);
}

void _deal(char s[N])
{
	int i,j,k,m;
	m=N;
	for(i=0;i<m;i++)
	{
		m=strlen(s);
		if(s[i]==s[i+1])
		{
			for(j=i;j<m;j++)
			{
				s[j+1]=s[j+2];
			}
			i--;
		}
		
	}
	printf("%s\n",s);
}
