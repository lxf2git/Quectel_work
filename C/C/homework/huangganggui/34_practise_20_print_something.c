#include<stdio.h>

void output(char a,int l ,int c)
{
	int j=c;
	for(;l>0;l--)
	{
		for(c=j;c>0;c--)
			printf("%c ",a);
		printf("\n");

	}
}

int main()
{	
	char a;
	int l=5,c=8;
	a='l';

	output(a,l,c);

	return 0;
}
