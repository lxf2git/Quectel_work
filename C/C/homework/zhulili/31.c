#include<stdio.h>
#define N 10

int main()
{

	int i,a[N]={0},k,b,m,j,g;
	printf("请输入10位id：\n");
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);	
		b=N;
	for(i=0;i<N;i++)
	{
		if(i==2)
		{
			for(k=i;k<b-1;k++)
			{
				a[k]=a[k+1];

			}
			for(j=0;j<i;j++)
				for(g=0;g<b-1-1;g++)
				{
					m=a[g+1];
					a[g+1]=a[g];
					a[g]=m;
				}
			i=0;	
			b=b-1;
			printf("%d,%d\n",a[0],a[1]);
			if(b==2)
			{
				printf("%d",a[1]);break;	
			}
		}
	}
	return 0;
}
