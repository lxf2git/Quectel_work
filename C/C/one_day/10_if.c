#include<stdio.h>

int main()
{
	int age;
	char gender;
	char name[20];

	printf("请输入：name gender age\n");
	scanf("%s",name);
	getchar();
	scanf("%c%d",&gender,&age);
	
	if(age>=0)
	{

		if(age>80)//关系表达式或者逻辑表达式
		{
				
			printf("寿星啊\n");
			printf("age:%d\n",age);
		}
		else if(age==22)//==    =
			printf("you are young!\n");

		printf("birthday:%d\n",2015-age);
	}

	else
	{	
		printf("你来自未来");
		printf("你出生于：%d\n",2015-age);
	}
	return 0;
}



