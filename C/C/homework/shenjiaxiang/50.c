#include<stdio.h>
#include<stdlib.h>

typedef struct people
{
	char *name;
	int age;
}*pPeo,Speo;

int main()
{
	int n,i,t,age_max;
	age_max=0;
	pPeo p;
	printf("请输入人数：\n");
	scanf("%d",&n);	
	p = (pPeo)malloc(n*sizeof(Speo));
	printf("请输入人物信息name  age:\n");
	for(i=0;i<n;i++)
	{
		(p+i)->name = (char *)malloc(10*sizeof(char));
		scanf("%s%d",(p+i)->name,&(p+i)->age);
		printf("*****************************\n");
	}
	for(i=0;i<n;i++)
	{
			if((p+i)->age>age_max)
			{
					age_max=(p+i)->age;
					t=i;
			}
	}
	printf("%s  %d\n",(p+t)->name,(p+t)->age);
	

	return 0;
}
