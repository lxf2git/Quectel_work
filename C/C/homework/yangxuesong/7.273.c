#include<stdio.h>
int main()
{	int i;
	scanf("%d",&i);
	if(i<1||i>7)
		printf("输入错误");
	else if(i==1)
		printf("monday");
	else if(i==2)
		printf("tuesday");
	else if(i==3)
		printf("wednesday");
	else if(i==4)
		printf("4");
	else if(i==5)
		printf("5");
	else if(i==6)
		printf("6");
	else if(i==7)
		printf("7");
	return 0;
}

