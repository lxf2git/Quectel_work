#include<stdio.h>
int main()
{
	int a,b,c,i;
	i=0;
	for(a=0;a<101;a++)
			for(b=0;b<51;b++)
					for(c=0;c<21;c++)
							if(a+2*b+5*c==100)
							{
								i+=1;
								printf("100=%d+%d+%d\n",a,b,c);
								
							}
	printf("%d\n",i);

	return 0;
}
