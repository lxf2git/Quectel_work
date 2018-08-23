#include<stdio.h>
int main()
{
	int i;	
	int *p=NULL;
	int a[5]={1,2,3,4,5};
	p=a;//p=&a[0]	
	for(i=0;i<5;i++)
	{
		printf("%d ",*(p+i));//p[i]  a[i] *(a+i)
	}
	return 0;

}
