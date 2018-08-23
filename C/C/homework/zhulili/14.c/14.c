#include<stdio.h>

char number(char a);

int main()
{
	char a;
	a=number(a);
	//printf("%d",x);
	return 0;
}
char number(char a)
{
	int count;
	count = 0;
	for(;;)
	{
		scanf("%c",&a);
		if(a!='\n')
		{
			if(a>=48 && a<=57)
			{
				count+=1;
		
			}
		}
		if(a=='\n')
		{
				break;
		}			
	}
				
		printf("%d\n",count);
	return count;
}
