#include<stdio.h>
#include<stdlib.h>
#define N 100
typedef struct People
{
	char name[20];
	int age;
}sP;

int input(sP *pman,int n)
{
//	printf("n in ip:%d\n",n);
	printf("please input name:");
	scanf("%s",pman->name);
	printf("please input age:");
	scanf("%d",&pman->age);
//	printf("age:%d\n",pman->age);
//	printf("n out ip:%d\n",n);
	return n;
}

void compare(sP *pm, int n)
{
	int i,max=0,a;
	for(i=0;i<n;i++)
	{
		if(pm[i].age > max)
		{
			max = pm[i].age;
//			printf("compare-->>pman.%d:%d",i,pman[i].age);
			a=i;
		}
	}
	printf("最大的年龄是%d，名字是%s\n",pm[a].age,pm[a].name);
}

int main()
{
	int n,i;
	printf("please input number of people:");
	scanf("%d",&n);
//	printf("n1:%d\n",n);
	sP peop[N];
	sP * pm;
	pm = &peop[0];
//	printf("n2:%d\n",n);
	pm = (sP *)malloc((n+1)*(sizeof(sP)));	
//	printf("n3:%d\n",n);
	for(i=0;i<n;i++)
	{
		pm = &peop[i];
//	printf("n4:%d\n",n);
		n=input(pm,n);
//	printf("n5:%d\n",n);
		printf("i:%d\n",i);
		if(i == n-1)
		{
			break;
		}
	}

		compare(&peop,n);
	
	return 0;

}
