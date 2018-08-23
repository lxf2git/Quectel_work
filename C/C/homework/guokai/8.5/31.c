#include<stdio.h>
#define N k
int main()
{
	int a[N]={};
	int i=0,j=0,n,k;
	scanf("%d",&n);
	for(k=0;k<n;k++)
			a[k]=k+1;
	do
	{
		if(a[i]!=-1)
		{
			j++;
			if(j%3==0)
					a[i]=-1;
		}
		i++;
		if(i==10)
				i=0;
	}
	while(j!=(10*3-1));
	printf("%d",a[i-1]);
	return 0;
}
