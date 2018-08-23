#include<stdio.h>
int main()
{
	int day;
	printf("请输入1～7其中一个数:");
	scanf("%d",&day);
	switch(day)
	{
	case 1 : printf("mon");break;
	case 2 : printf("tue");break;
	case 3 : printf("wed");break;
	case 4 : printf("thu");break;
	case 5 : printf("fir");break;
	case 6 : printf("sat");break;
	case 7 : printf("sun");break;
	default : printf("输入有误");break;
	}
	return 0;


}
