#include<stdio.h>
#define N 100
int main()
{
	int nu,i,re,in=0,j,k,d;
	int str_a[100]={0};
	int str_b[100]={0};
	printf("please input in number : \n");
	scanf("%d",&nu);
	for(i=0;in!=1;i++)
	{
 		re=nu%2;
	 	in=nu/2;
		nu=nu/2;
		str_a[i]=re;
	}
	str_a[i]=in;
	for(k=0,j=i;j>=0;j--,k++)
	{
		str_b[j]=str_a[k];
	}
    for(j=0;j<i+1;j++)
	{
		printf("%d",str_b[j]);
	}
	printf("\n");
 	return 0;
}
