#include<stdio.h>
void bts3(int *p,int*q,int *a);
void bts(int *p,int*q);
main()
{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		bts3(&a,&b,&c);
		printf("%d %d %d\n",a,b,c);	
		printf("%d-%d=%d\n",a,c,a-c);
}
void bts3(int *p,int *q,int *a)
{
		bts(p,q);
		bts(p,a);
		bts(q,a);
}
void bts(int *p,int *q)
{
		int a;
		if(*p<*q)
		{
			a=*p;
			*p=*q;
			*q=a;	
		}
}
