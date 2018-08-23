#include<stdio.h>

int main()
{
	int i,j,m,k=0;
	char string[10];
	printf("请输入数字\n");
	scanf("%d",&j);
	if(j>0)
	{
		for(i=0;;i++)
		{
			m=j%10;
			j=j/10;
			k++;
			string[i]=m+48;
			if(j==0)
			break;
		}
		for(i=k-1;i>=0;i--)
		{	
			printf("%c",string[i]);
		}
			printf("\n");
	}
	else if(j<0)
	{
		string[0]=45;
		j=-j;
		for(i=1;;i++)
		{
			m=j%10;
			j=j/10;
			k++;
			string[i]=m+48;
			if(j==0)
			break;
		}
		printf("%c",string[0]);
		for(i=k;i>=1;i--)
		{
			printf("%c",string[i]);
		}
			printf("\n");
	}
	return 0;
}
