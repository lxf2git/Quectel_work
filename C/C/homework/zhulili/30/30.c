#include<stdio.h>
#include<string.h>
#define N 4

void reorder(char arr[])
{
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%c",&arr[i]);
		getchar();
	}
	int j;				 
	char t,m,k=0;
	char brr[N]={0};
	for(i=0;i<N;i++)
	{
		for(j=0;j<N-1;j++)
		if(arr[j]>arr[j+1])
		{
			m=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=m;
		}
	}
	for(i=0;i<N;i++)
	printf("%c ",arr[i]);	
}


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


void delete(char arr[])
{
	int i,j,g,x;
	for(j=0;j<2*N;j++)
	for(i=0;i<2*N;i++)
		if(arr[i]==arr[i+1])
			for(g=i;g<2*N;g++)
				arr[g]=arr[g+1];
	printf("删除相同字符后的字符串：%s\n",arr);
}


int main()
{
	int i,t,ma;
	char a[500]={0};
	char string1[500]={0},string2[200]={0};
	printf("请输入两个4个以内的字符串string1[i]和string2[i]：\n");
	reorder(&string1[0]);
	getchar();
	reorder(&string2[0]);
	getchar();
	strcat(string1,string2);
	printf("合并后的字符串为：%s\n",string1);
	reorder1(string1);
	delete(string1);
	return 0;
}
