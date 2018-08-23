#include<stdio.h>
#include<string.h>
int main()
{
	int i,j;
	int character=0;
	int word=0;
	int line=0;
	char a[50];
	printf("please input:\n");
	gets(a);
	j=strlen(a);
	printf("\n");	
	
	for(i=0;i<j;i++)
	{
		if(a[i]>='A'&&a[i]<='Z'||a[i]>='a'&&a[i]<='z')
		{
			character=character+1;
		}
		else
		{
		if(a[i]=='.')
		{
			line=line+1;
		}
		else
		{	
		if(a[i]==' ')
		{
			word=word+1;
		}
		}
		}
	}
	printf("character:%d line:%d word:%d",character,line,word+2);
	printf("\n");
	return 0;
}
