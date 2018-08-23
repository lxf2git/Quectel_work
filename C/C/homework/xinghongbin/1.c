#include<stdio.h>
int deal(int *a,int *b,int i);
int main()
{
		int a[10];
		int i,j,c;
		printf("input 10num of int type: \n");
		for(i=0;i<10;i++)
				scanf("%d",a+i);
		for(j=1;j<10;j++)
			c=deal(&a[0],&a[j],j);
		printf("max:%d   num:%d\n",a[0],c);
//		for(i=0;i<10;i++)
//				if(a[0]==a[i])
//						printf("标号%d\n",i);
		return 0;

}
int deal(int *a,int *b,int j)
{
		int c,d;
		if(*a<*b)
		{
				c=*a;
				*a=*b;
				*b=c;
				d=j;
			//	printf("d:%d\n",d);
			//	return d;
		}
		
		return d;
}
