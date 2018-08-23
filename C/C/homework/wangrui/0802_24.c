#include<stdio.h>
#include<string.h>
#define N 100

int main()
{	
	int i,j;
	char str[N]={};
	printf("输入一串字符\n");
	gets(str);
	puts(str);
	for(i=0;i<N;i++)
	{
		if(str[i]=='c')
		{
			for(j=i;j<N;j++)
			{
				str[j]=str[j+1];
			}
			i--;
		}
	}
	printf("%s\n",str);
			

	return 0;
}

