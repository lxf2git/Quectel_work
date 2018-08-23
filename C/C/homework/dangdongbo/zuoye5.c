#include<stdio.h>
int  main()
{
	int a,b,c,n,i=1;
	
		for(c=0;c<21;c++)
			{
			for(b=0;b*2+c*5<=100;b++)
				{
					a=100-b*2-c*5;
					i++;
			printf("%d %d %d\n",a,b,c);
	}}
printf("%d\n",i);
}
