#include<stdio.h>
main()
{
		int i,j,k,d=0;
		for(i=0;i<=100;i++)
				for(j=0;j<=50;j++)
						for(k=0;k<=20;k++)
								if(i+2*j+5*k==100)
										d++;
		printf("%d\n",d);
		return 0;
}
