#include<stdio.h>
void tab();
void prin(int n,int m);
int main()
{
		tab();
}
void tab()
{
		int n,m;
		for(n=1;n<=9;n++)
		{
				for(m=1;m<=n;m++)
				{
						prin(n,m);
				}
		
		}
}
void prin(int n,int m)
{
						printf("%d*%d=%2d ",m,n,n*m);
						if(n==m)
						{
						printf("\n");
						}
}
