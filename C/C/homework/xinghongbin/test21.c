#include<stdio.h>
int main()
{
		int i,b[20],c[20],k,j,a;
		scanf("%d",&a);
		for(i=0;a/2!=0;i++)
		{
				b[i]=a%2;
				a=a/2;
		}
		b[i]=1;
		for(j=i,k=0;j>=0;j--,k++)
		{
				c[k]=b[j];
				printf("%d",c[k]);
		}
		printf("\n");
		return 0;
}
