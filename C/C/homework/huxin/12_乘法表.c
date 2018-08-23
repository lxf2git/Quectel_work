#include<stdio.h>
void xunhuan();
void xianshi(int x,int y);
 
int main()
{
    printf("乘法表\n");
    xunhuan();	
    return 0;
}	
void xunhuan()
{		
	int i,j,n=0;
 	for(i=0;i<10;i++)
			for(j=1;j<10;j++)
			{
					if(j<=i)
					xianshi(j,i);
			}
}	
void xianshi(int x,int y)
{		
	printf("%2d",x);
	printf("*");
    printf("%d",y);
    printf("=");
	printf("%2d",x*y);
    printf(" ");
	if(x==y)
	printf("\n");
}				
	
