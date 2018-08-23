#include<stdio.h>
#define N 41

int l;
int s;

void first(int a[])
{
	int i;
	for(i=0;i<N;i++)
	{
		a[i]=1;
		if((i+1)%3==0)
		{
			l=i;
			s++;
			a[i]=0;
		}
	}
}

void twice(int a[])
{
	int i,n=0;
	i=l+1;
	while(i<N+1)
	{
		if(i==N)
		{
			i=0;
			continue;
		}
		if(a[i]==0)
		{
			i++;
			continue;
		}
		n++;
		if(n%3==0)
		{
			a[i]=0;
			s++;
		}
		if(s==N-1)
		break;
		i++;
	}
	for(i=0;i<N;i++)
	{
		printf("%d:%d\n",i+1,a[i]);
	}
	for(i=0;i<N;i++)
	{
		if(a[i]==1)
		printf("活下来的是%d号\n",i+1);
	}
}

int main()
{
	int a[N]={0};
	first(a);
	twice(a);
	return 0;
}
