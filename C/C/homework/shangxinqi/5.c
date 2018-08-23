#include<stdio.h>

int main()
{
	int a,b,c,i;
	i=0;
	for(a=0;a<=100;a++)
	for(b=0;b<=50;b++)
	for(c=0;c<=20;c++)		
    if (a+b*2+c*5==100)
	{
	i++;
	}
	printf("%d\n",i);
	
return 0;	
}
