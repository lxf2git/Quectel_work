#include<stdio.h>
int main()
{	
	int num;
	int i=1;
	int j=1;
	printf("请输入数字:\n");
	scanf("%d",&num);
	while(num/i>=10)
	{
		j++;
		i=i*10;

	}
	printf("%d有%d位数\n",num,j);
return 0;

}
