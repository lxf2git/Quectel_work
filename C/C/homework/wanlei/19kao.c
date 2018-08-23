#include<stdio.h>

#define N 100

int main()
{
	float av1,av2;
	int i,m,n,s,t;
	s=0;
	t=0;
	m=0;
	n=0;
	int a[N];
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==0)
		{
			break;
		}
		if(a[i]%2==0&&a[i]!=0)
		{
			s=s+a[i];
			m++;
		}
		if(a[i]%2==1)
		{
			t=t+a[i];
			n++;
		}
	}
	av1=s/m;
	av2=t/n;
	printf("%d个偶数平均数%f\n",m,av1);
	printf("%d个奇数平均数%f\n",n,av2);
    return 0;	
}
