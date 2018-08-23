#include<stdio.h>
#define N 6
int main()
{
	char a[6];char m;
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%c",&a[i]);
		getchar();
	}
	for(i=0;i<N;i++)		//由大到小排列，插入的数值在第一位
	{
		if(a[i]<a[i+1])
		{
			m=a[i];
			a[i]=a[i+1];
			a[i+1]=m;
		}
	}
	for(i=0;i<N;i++)
	printf("%c ",a[i]);
	return 0;
}
