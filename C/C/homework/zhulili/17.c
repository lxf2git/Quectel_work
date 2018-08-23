#include<stdio.h>

int main()
{
	int i;
	int a[3],max,min,m,n,j,k,q,w;
	for(i=0;i<3;i++)
		scanf("%d",&a[i]);
	max=a[0];
	min=a[0];
	for(i=1;i<3;i++)
	{
		if(max<a[i])
		{
			max=a[i];
			q=i;
		}
		if(min>a[i])
		{
			min=a[i];
			w=i;
		}
	}
	j=a[2];
	k=a[0];
	m=max;
	n=min;
	a[2]=m;
	a[0]=n;	
	a[w]=k;
	a[q]=j;
	printf("最大值：%d\n",max);
	printf("最小值：%d\n",min);
	for(i=0;i<3;i++)
	printf("%d\t",a[i]);
	return 0;
}
