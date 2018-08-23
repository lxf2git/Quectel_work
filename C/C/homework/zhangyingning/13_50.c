#include<stdio.h>
#include<stdlib.h>


typedef struct people
{
	char name[20];
	int age;
}sPeople, *pPeople;

void _malloc(pPeople *p,int size)	//开辟空间
{
	*p = malloc(size);
	if(NULL == *p)
	{
		printf("malloc error");
	}
}
int in_put(pPeople man,int size)	//录入信息，并找出最大年龄
{
	int i,max_age = 0;
	for(i = 1;i <= size;i++)
	{
		printf("%d people\n",i);
		printf("please input name");
		scanf("%s",&man->name);
		printf("please input age");
		scanf("%d",&man->age);
		if(man->age > max_age)
		{
			max_age = man->age;
		}
		man++;
	}
	return(max_age);
}
void out_max_age(pPeople man,int size,int max_age)	//输出最大年龄人的信息
{
	int i;
	for(i = 1;i <= size;i++)
	{
		if(man->age == max_age)
		{
			printf("name %s\nage  %d\n",man->name,man->age);
			printf("\n");
		}
		man++;
	}
}
int main()
{
	pPeople man = NULL;
	int max_age, size;
	printf("please input people");
	scanf("%d",&size);
	_malloc(&man,size * sizeof(sPeople));
	max_age = in_put(man,size);
	out_max_age(man,size,max_age);
	if(NULL == man)
	{
		free(man);
		man = NULL;
	}
}
