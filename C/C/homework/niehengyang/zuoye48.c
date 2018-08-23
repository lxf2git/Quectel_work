#include<stdio.h>
#include<stdlib.h>
int double_t(int ,int );
int main()
{
	int n,i;
	int a[3];
	int (*p)(int ,int );
	/*for(i=0;i<3;i++)
	{
	}*/
	//a=(int *)malloc(3*sizeof(int));
	printf("please input nu:\n");
	//scanf("%d",n);
	p=double_t;
	for(i=0;i<3;i++)
	{
	scanf("%d",&a[i]);
	a[i]=((*p),a[i],i);
	}
	for(i=0;i<3;i++)
	{
	printf("%d ",a[i]);
	}
	/*for(i=0;i<3;i++)
	{
	printf("%d\n",b[i]);
	}*/
}


int double_t(int a,int i)
{
	//int i;
	for(i=0;i<3;i++)
	{
	a[i]=a[i]*2;
	}
	return a[i];

}
