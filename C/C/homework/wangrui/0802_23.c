#include<stdio.h>
#include<string.h>
#define N 10

int main()
{
	int fr,ed,i,n,m;
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	int brr[10]={};
	scanf("%d",&fr);
	scanf("%d",&ed);
	fr=fr-1;
	ed=ed-1;
	n=fr;
	m=ed;
	for(i=0;m>=fr;m--)
	{
		brr[i]=arr[m];
		i++;
	}
	
//	for(i=0;i<=N;i++)
//	{
//		printf("%d ",brr[i]);
//	}
	for(i=0;n<=ed;n++)
	{
		arr[n]=brr[i];
		i++;
		
	}
	for(i=0;i<N;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

	return 0;
}
