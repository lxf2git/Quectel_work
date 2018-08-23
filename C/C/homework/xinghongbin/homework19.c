#include<stdio.h>
#define N 10
int main()
{
		int i,j;
		int a[N];
		int b,s=11;
		for(i=0;i<N;i++)
		{
				printf("input number%d:\n",i);
				scanf("%d",a+i);

		}
		printf("search:\n");
		scanf("%d",&b);
		for(j=N-1;j>=0;j--)
		{
				if(a[j]==b)
						s=j;
				
		}

		if(s==11)
				printf("sorry,not found!\n");
		else
				printf("the number is:%d\n",s);
}
