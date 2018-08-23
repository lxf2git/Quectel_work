#include "main.h"

void pl()
{
	int i,j,k,m,x,y,n,a;
	printf("please input year and months\n");
	scanf("%d%d",&x,&y);
	i=0;
	j=zts(x);
	k=my(x,y);
	n=(k+j+1)%7;
	a=ts(x,y);
	printf("sun mon tue wed thu fri sat\n");
	for(i=0;;i++)
	{
		{
			if((n+1)!=i&&i<n+1)
				{
					printf("    ");
				}
			else if((n+1)==i)
				{
					m=1;
					printf("%3d ",m);
					m++;
				}
			else if((i>(n+1))&&m<=a)
			{
				printf("%3d ",m);
				m++;
			}
			else
			{
				printf("\n");
				break;
			}
			if(i%7==0)
			{
				printf("\n");
			}
		}
	}
}
