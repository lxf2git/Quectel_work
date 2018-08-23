#include<stdio.h>
#include<string.h>

int judge_str(char str[]);
int main()
{
		int i;
		char string[20];
		gets(string);
		i = judge_str(string);
		printf("%d\n",i);
		return 0;
}
int judge_str(char str[])
{
		int i,j,k=0;
		i=strlen(str);
		printf("i:%d\n",i);
		puts(str);
		for(j=0;j<i/2;j++)
		{
				if(str[j]==str[i-j-1])
						k++;
		}
		printf("j:%d\n",j);
		printf("k:%d\n",k);
		if(k==j)
				return 0;
		else
				return (-1);
}

