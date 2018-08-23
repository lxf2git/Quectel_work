#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
	int id;
	int age;
	float math;
	char name[20];
}sStudent, *pStudent;


void found_malloc(pStudent *p,int size)
{
	*p = (pStudent)malloc(size);
	if(NULL == *p)
	{
		printf("malloc error");
	}

}
void in_put(pStudent people,int numbr)
{
	int i;
	for(i = 0;i < numbr;i++)
	{
		printf("student %d\n",i + 1);
		printf("please input ID\n");
		scanf("%d",&people->id);
		printf("please input name");
		scanf("%s",&people->name);
		printf("please input math");
		scanf("%f",&people->math);
		printf("please input age");
		scanf("%d",&people->age);
		printf("\n");
		people++;
	}
}
void out_put(pStudent people,int numbr)
{
	int i;
	for(i = 0;i < numbr;i++)
	{
		printf("%s \n",people->name);
		printf("ID: %d  ",people->id);
		printf("age: %d  ",people->age);
		printf("peport:");
		if(people->math >= 60)
		{
			printf("good\n");
		}
		else
		{
			printf("come on\n");
		}
		people++;
	}
}
void free_people(pStudent *p)
{
	if(NULL != *p)
	{
		free(*p);
		*p = NULL;
	}
}
int main()
{
	pStudent people = NULL;
	int numbr;
	printf("please input number\n");
	scanf("%d",&numbr);
	found_malloc(&people,numbr * sizeof(sStudent));
	in_put(people,numbr);
	out_put(people,numbr);
	free_people(&people);
}
