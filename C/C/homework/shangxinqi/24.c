#include<stdio.h>
int main()
{
	int i;
	char str[100];
	printf("please input:");
	gets(str);
	for(i=0;i<100;i++)
	{
		if(str[i]==99)
		{
			str[i]='\0';
		}
	}
	puts(str);
	return 0;
}
