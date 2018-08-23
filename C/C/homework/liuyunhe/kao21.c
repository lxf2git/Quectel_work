#include<stdio.h>

int main()
{
		int str[100]={0};
		int i,n;
				int a;
				scanf("%d",&a);
		for(i=0;i<100;i++)
		{
				str[i]=a%2;
				a=a/2;
				if(a==0)
				{
						n=i;
						break;
				}
		}
		for(i=n;i>=0;i--)
				printf("%d",str[i]);
		printf("\n");
		return 0;
}
