#include<stdio.h>

int main()
{
	char  num[3]={0},num1[3]={0},c[5]={0};

	scanf("%s%s",num,num1);
	
	c[1] = num[0];
	c[3] = num[1];
	
	c[0] = num1[0];
	c[2] = num1[1];

	printf("%s",c);		
		
	return 0;				
}
