#include<stdio.h> 
#include<stdlib.h> 

typedef struct name_age
{
	char name[10];
	int age;
}N_a;
void find_max(N_a *point,int nu)
{
	N_a *max_p=point;
	int num=0;
	for(;num<nu;num++)
	{
		if((max_p->age)<((point+num)->age))
			max_p=point+num;
	}
		printf("年龄最大的人是%s %d岁。\n",max_p->name,max_p->age);
}
int main()
{
	int nu,num=0;
	printf("您想创建多少个人的信息？\n");
	scanf("%d",&nu);
	N_a *pn_a=(N_a*)malloc(nu*sizeof(N_a));
	for(;num<nu;num++)
	{
		printf("这是第%d个，请依次输入姓名和年龄。\n",num+1);
		scanf("%s%d",&(pn_a+num)->name,&(pn_a+num)->age);
//		printf("%s %d",(pn_a+num)->name,(pn_a+num)->age);
	}
	find_max(pn_a,nu);
}
