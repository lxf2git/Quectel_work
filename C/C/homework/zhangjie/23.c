#include<stdio.h>
int main()
{
	int string[10];
	int i,j,k,m,n;
	printf("请输入10个数\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&string[i]);
	}
	for(i=0;i<9;i++)
		for(j=0;j<9-i;j++)
			if(string[j]>string[j+1])
			{
				k=string[j];
				string[j]=string[j+1];
				string[j+1]=k;
			}
	for(i=0;i<10;i++)
	printf("%d",string[i]);	
	printf("\n");
	printf("输入从第几个数开始的几个数\n");
	scanf("%d%d",&m,&n);
	j=m-2+n;
	for(i=m-1;i<=m-1+n/2;i++)
		{
			k=string[i];
			string[i]=string[j];
			string[j]=k;
			j--;
		}
	for(i=0;i<10;i++)
	printf("%d",string[i]);	
	printf("\n");
	return 0;
}
