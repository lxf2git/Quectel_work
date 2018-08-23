#include<stdio.h>

main()
{
	int a,b,c;
	a = 20,c=0;
	while((a+b)>1)
	{
	c=a+c;
    b=a%2;
	a=(a+b)/2;
	}
printf("%d\n",c);
	
return 0;
}
