#include<stdio.h>

int main()
{
	int  day;
		
	printf("请输入您的要查询的数字（1～7）：day=");
		scanf("%d",&day);
	if(day <=0 || day > 7)
	{
		printf("error!\n输入错误\n");
	}
	else{
	switch(day%7)
	{
	case 0:
		printf("你输入的是星期%d，sunday\n",day);break;
	case 6:
		printf("你输入的是星期%d，saturday\n",day);break;
	case 5:
		printf("你输入的是星期%d，friday\n",day);break;
	case 4:
		printf("你输入的是星期%d，thursday\n",day);break;
	case 3:
		printf("你输入的是星期%d，wednesday\n",day);break;
	case 2:
		printf("你输入的是星期%d，tuesday\n",day);break;
	case 1:
		printf("你输入的是星期%d，monday\n",day);break;
	}
	}
	return 0;
}
