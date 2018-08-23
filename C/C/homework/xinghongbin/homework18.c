#include<stdio.h>
#define N 10
int main()
{
		int i,j,s=0,n,num;
		int a[N];
		int temp,temp1;
		for(i=0;i<N;i++)
		{
				scanf("%d",&a[i]);
				//b[i]=a[i];
		}
		temp=a[0];
		num=deal_max(a);
		a[0]=a[num];
		a[num]=temp;


		temp1=a[N-1];
		n=deal_min(a);

		a[N-1]=a[n];
		a[n]=temp1;


		for(j=1;j<N-1;j++)
		{
			s=s+a[j];
		}
			printf("average:%d\n",s/8);
		


		return 0;
}
int deal_max(int *p)
{
	int max=*p;
	int num=0;
	int i;
	for(i=0;i<N;i++)
	{
			if(max<*(p+i))
			{
					max=*(p+i);
					num=i;

			}
					
	}
	return num;

}

int deal_min(int *p)
{
	int min=*(p+N-1);
	int i,n=N-1;
	for(i=0;i<N;i++)
	{

			if(min>*(p+i))
			{
					min=*(p+i);
					n=i;
					
			}
	}
	return n;

}
