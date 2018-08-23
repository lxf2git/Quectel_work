#include<stdio.h>
main()
{
	int i,j;
	for(j=0;j<10;j++)
	{
	for(i=1;i<=j;i++)
	{
	printf("%d",i);
	printf("*");
	printf("%d",j);
	printf("=");
	printf("%d,",i*j);
	}
	printf("\n");
	}
	return 0;
	

}
