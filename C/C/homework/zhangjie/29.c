#include<stdio.h>

void count()
{
	int a[100]={0};
	int i,character=0,line=0,word=0;
	for(i=0;;i++)
	{
		scanf("%c",&a[i]);
		if(a[i]==32||a[i]==46)
		{
			word++;
			if(a[i]==46)
			{
				line++;
			}
		}
		else if(a[i]!=32&&a[i]!=46&&a[i]!=10)
		{
			character++;
		}
		else if(a[i]==10)
		{
			break;
		}
	}
	printf("character:%d word:%d line:%d\n",character,word,line);
}

int main()
{
	count();
	return 0;
}
