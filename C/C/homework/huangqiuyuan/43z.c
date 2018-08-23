#include<stdio.h>

int main()
{
	int i,j,m;
	char a[100]={};
	printf("输入一个字符串");
	for(i=0;;i++)
	{
		scanf("%c",&a[i]);
		if(a[i]=='\n')
		{
		//	i--;
			break;
		}
	}
		j=i;
	for(i=0;;i++)
	{
	printf("%c",a[i]);
		
		if(i==j-1)
		{break;}
			for(m=0;m<(2*i+1);m++)
				{
						printf("#");
				}
	}	


	return 0;
}
