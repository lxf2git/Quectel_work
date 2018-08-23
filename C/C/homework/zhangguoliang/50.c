#include<stdio.h>
#include<stdlib.h>

struct Human
{
	char *name;
	int age;
};

void comp(struct Human **q,int n)
{
	int i,j,max=0;
	for(i=0;i<n;i++)
	{
		if(max<q[i]->age)
		{
			max=q[i]->age;
				j=i;
		}
	}
	printf("年龄最大者为%s 年龄是%d岁\n",q[j]->name,q[j]->age);
}

int main()
{
	int num,i;
	printf("请输入人数:\n");
	scanf("%d",&num);
	struct Human *p[num];
	for(i=0;i<num;i++)
	{
		p[i]=(struct Human *)malloc(sizeof(struct Human));
		p[i]->name=(char *)malloc(20*sizeof(char));
		printf("please input name age\n");
		scanf("%s%d",p[i]->name,&p[i]->age);
	}
	comp(p,num);
}
