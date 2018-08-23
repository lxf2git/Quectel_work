#include<stdio.h>

int power(int *m,int *n);

int main()
{
		int m,n,x;
		int *p1,*p2;
		printf("please input a integer:\n");
		scanf("%d",&m);
		printf("please input power:\n");
		scanf("%d",&n);

		p1=&m;
		p2=&n;

		x=power(p1,p2);
		
		printf("%d\n",x%1000);

		return 0;
}

int power(int *m,int *n)
{
		int x=1;
		if(*n>0)
		{
				(*n)--;
				x=*m * power(m,n);
		}
		return x;
}
