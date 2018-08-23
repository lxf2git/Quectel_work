#include<stdio.h>
int main()
{
	
	int i,j;
	char ch[500]={};
	printf("please input a string\n");
	gets (ch);
	for(i=0;i<500;i++)
	{
		if(ch[i] =='c')
		{
		 for(j=i;j<500;j++)
		{
			ch[j]=ch[j+1];
		}
		i--;
		}	
	}
	printf("%s",ch);


	return 0;
}

