#include<stdio.h>
#include<stdlib.h>
int nu,i;
struct Age
{
	char *name;
	int age;
};

void cmp(struct Age *a)
{
		int j;
	for(i=0;i<nu;i++)
	{
		a[0].age=a[0].age>a[i].age?a[0].age:a[i].age;
	}
		for(i=0;i<nu;i++)
		{
			if(a[0].age==a[i].age)
				j=i;
		}
		printf("年龄最大的是%s %d岁\n",a[j].name,a[j].age);
		
}

int main()
{
	printf("您要比较几个人：");
	scanf("%d",&nu);
	printf("请输入姓名和年龄：\n");
	struct Age a[nu];
	for(i=0;i<nu;i++)
	{
		a[i].name=(char*)malloc(20*sizeof(char));
		scanf("%s%d",a[i].name,&a[i].age);
	}

	cmp(a);


	return 0;
}
