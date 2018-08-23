#include<stdio.h>
int main()
{
	int i;
	printf("请输入数字:");
	scanf("%d",&i);
	if(i>7||i<=0)
		printf("输入错误！\n");
	else
	{	
		switch (i)
			{
			case 1: printf("Monday\n");
				break;
			case 2: printf("Tuesday\n");
				break;
			case 3: printf("Wednesday\n");
				break;
			case 4: printf("Thursday\n");
				break;
			case 5: printf("Firday\n");
				break;
			case 6: printf("Saturday\n");
				break;
			case 7: printf("Sunday\n");
				break;
			}
	}

return 0;

}
