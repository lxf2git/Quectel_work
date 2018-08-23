#include"reorder1.h"
#define N 4

void reorder1(char arr[])
{
	int i,M,g=0;
	int j;				 
	char t,m;
	char brr[2*N]={0};
	for(i=0;i<2*N;i++)
		for(j=0;j<2*N-1;j++)
		if(arr[j]>arr[j+1])
		{
			m=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=m;
		}
			printf("合并排序后的字符串：%s\n",arr);	
}
