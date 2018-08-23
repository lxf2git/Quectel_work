#include<stdio.h>
 
	int main()
{
	
	int a; 
	printf("请输入一个年\n");
	scanf("%d",&a);
	if(a%400==0)

	printf("这一年是润年\n");
	

	else if(a%4==0&&a%100!=0)

         printf("这一年是润年\n");   
	
        else 
          printf("这一年不是润年\n");
	return 0;
  } 

