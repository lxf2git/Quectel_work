#include<stdio.h>
#include<time.h>
int main()
{
	int a[10];
	//scanf("%d",&a[10]);
	srand(time(NULL));
	int max,min,i,b,c,m,n;
	for(i=0;i<10;i++)
	{
		a[i]=rand()%100;
		if(i==0)
		{
		max=a[0];
		min=a[0];
		}
		printf("%d\t",a[i]);
		if(max<a[i])
		{
			max=a[i];
			b=i;
		}
		if(min>a[i])
		{
			min=a[i];
			c=i;
		}
		if(i==9)
		printf("\n");
	}
			printf("最大%d\n",max);
			printf("最小%d\n",min);
	printf("\n");
	m=a[9];
	n=a[0];
	a[9]=max;
	a[0]=min;
	a[b]=m;
	a[c]=n;
	for(i=0;i<=9;i++)
	printf("%d\t",a[i]);
	printf("\n");
	return 0;
}
