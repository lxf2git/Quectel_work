#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

typedef struct people
{
	char *ob1;
	char *ob2;
	char *ob3;
}*pPeo,Speo;

int main()                             //vote 票
{
	int a,b,c,n,i;
	char p[N];
	a=0;b=0;c=0;
	Speo name;
	printf("请输入投票人数：");
	scanf("%d",&n);
//	name = (pPeo)malloc(sizeof(Speo));
	name.ob1 = (char *)malloc(sizeof(char));
	name.ob2 = (char *)malloc(sizeof(char));
	name.ob3 = (char *)malloc(sizeof(char));
/*	for(i=0;i<N;i++)
	{
		p[i] = (char *)malloc(N*sizeof(char));
	}*/
	printf("请输入候选人的名字：1、   2、   3、   \n");
//	scanf("%s%s%s",name->ob1,name->ob2,name->ob3);
	scanf("%s",name.ob1);
	getchar();
	scanf("%s",name.ob2);
	getchar();
	scanf("%s",name.ob3);
	getchar();
	for(i=0;i<N;i++)
	{
		printf("请输入你选择的候选人的名字%d：\n",i);
		scanf("%s",&p);
		if(strcmp(p,name.ob1)==0)
				a++;
		if(strcmp(p,name.ob2)==0)
				b++;
		if(strcmp(p,name.ob3)==0)
				c++;
		if(i==n-1)
				break;
	}
	printf("%s=%d\n",name.ob1,a);
	printf("%s=%d\n",name.ob2,b);
	printf("%s=%d\n",name.ob3,c);

}
