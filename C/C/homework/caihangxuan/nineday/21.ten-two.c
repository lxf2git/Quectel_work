#include<stdio.h> 
int main()
{
	int ten,two[500],bit;
	printf("请输入一个十进制数");
	scanf("%d",&ten);
	if(ten<0)
	  printf("请输入正数。");
	for(bit=0;ten>0;bit++)
	{
		two[bit]=ten%2;
		ten=ten/2;
	}
	//bit--;
	for(;bit>=0;bit--)
	{
		printf("%d",two[bit]);
	}
		printf("\n");
}
