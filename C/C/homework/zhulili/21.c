#include<stdio.h>
int main()
{
	char string[6]={'\0'};
	int  ch;
	int i;
	for(i=0;i<=4;i++)
	{
		scanf("%d",&ch);
		getchar();
		if(ch>=0 && ch<=9)
		{				
			string[i]=ch+48;				
		}	
	}
	printf("string:%s\n",string);
	return 0;
}
