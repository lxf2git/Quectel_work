#include<stdio.h>
int main()
{
		int a,i,n,m=0;
		scanf("%d",&a);
		for(i=2;i<=a/2;i++)
		{
				if(a%i==0)
				{ 
						m=m+i;
						n++;
		printf("%d\n",i);}

		}
printf("%d",m);

}
