#include<stdio.h>
int main()
{
	int i,j,k;
	k=0;
	do
	{
		printf("你有多少钱？\n");
		scanf("%d",&i);
	}while(i<1&&printf("穷鬼还想喝饮料？\n我回去拿钱\n"));
	 for(j=1;j<=i;j++)
		{
			k++;
			if(k%2==0)
			k++;
		}
	printf("你一共可以买%d瓶饮料\n",k);
	return 0;
}
