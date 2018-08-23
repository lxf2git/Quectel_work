#include<stdio.h>
#include<stdlib.h>
int main()
{
		int i,n,m;
		for(i=1;;)
		{
				i++;
				n=i;
				m=0;
				while(n%5==1)
				{
					n=(n-1)*4/5;
					m++;		
					if(m==5)
					{
					printf("%d\n",i);
					exit(0);
					}
				}
		}
}
