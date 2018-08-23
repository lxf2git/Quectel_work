#include<stdio.h>
#include<string.h>

int main()
{
	int i,a,j,k;
	char ch[50]={};
	printf("please input a string\n");
	gets(ch);
	a=strlen(ch);
	//printf("%d\n",a);
	for(i=a;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(ch[j]=='c')
				{
				for(k=j;k<i;k++)
				ch[k]=ch[k+1];
				}
		}
	}			
	puts(ch);
	return 0;
}
