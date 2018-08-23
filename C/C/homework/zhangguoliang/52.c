#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct People
{
	char *name1;
	char *name2;
	char *name3;
}sPe;

void show(sPe p,int a,int b,int c)
{
	printf("投票结果为:\n%s:%d\n%s:%d\n%s:%d\n",p.name1,a,p.name2,b,p.name3,c);
}

int main()
{
	sPe p;
	int i,a=0,b=0,c=0;
	char *q;
	printf("三个候选人分别是:\n");
	p.name1=(char *)malloc(20*sizeof(char));
	p.name2=(char *)malloc(20*sizeof(char));
	p.name3=(char *)malloc(20*sizeof(char));
	scanf("%s%s%s",p.name1,p.name2,p.name3);
	for(i=0;i<10;i++)	
	{
		printf("输入你投票的候选人:\n");
		q=(char *)malloc(20*sizeof(char));
		scanf("%s",q);
		if(strcmp(p.name1,q)==0)
			a++;
		else if(strcmp(p.name2,q)==0)
			b++;
		else if(strcmp(p.name3,q)==0)
			c++;
		else
			printf("姓名错误\n");
	}
	show(p,a,b,c);
	return 0;
}
