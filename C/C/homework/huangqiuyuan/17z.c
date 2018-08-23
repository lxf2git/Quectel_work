#include<stdio.h>
int main()
{
	int a[5],i,j,q=0,p=0;
	printf("请输入5个数：\n");
	for(i=0;i<5;i++)
	{	
		scanf("%d",&a[i]);
	}
	int max=a[0],lit=a[0];
	for(i=0;i<5;i++)
{
	if(a[i]>max)
	{ max=a[i];
	  q=i;}	
}
	
	for(j=0;j<5;j++)
{
	if(a[j]<lit)
	{lit=a[j];
	   p=j;}
}

	a[q]=a[4];
	a[p]=a[0];
	a[4]=max;
	a[0]=lit;
//	printf("%d %d",i,j);
	printf("%d %d %d %d %d",a[0],a[1],a[2],a[3],a[4]);
//	for (i=0;i<5;i++)
//	printf("%d",a[i]);
	return 0;
}
