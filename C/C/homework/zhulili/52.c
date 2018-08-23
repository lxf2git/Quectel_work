#include<stdio.h>
#include<stdlib.h>

typedef struct Candidate
{
	char *name;
	int poll;
}sCa;

typedef struct Voter
{
	char *voter;

}sVo;

void vote(sVo *q,sCa *po,int x,int y)
{
	int i,j;
	printf("请投票：\n");
	for(i=0;i<x;i++)
	{
		(q+i)->voter = (char *)malloc(20);
		scanf("%s",(q+i)->voter);
	}
	for(i=0;i<x;i++)
		for(j=0;j<y;j++)
	{
		if(*(q+i)->voter==*(po+j)->name)
				(po+j)->poll=(po+j)->poll+1;
	}
	printf("每个人的得票结果：\n");
	for(i=0;i<y;i++)
	printf("得票人：%s   票数：%d \n",(po+i)->name,(po+i)->poll);
	for(i=0;i<x;i++)
	{
		free((q+i)->voter);
		(q+i)->voter = NULL;
	}
}

int main()
{
	sVo *p;
	sCa *po;
	int i;
	int candidate_count,voter_count;
	printf("请输入候选人的人数：");
	scanf("%d",&candidate_count);
	printf("请输入投票人数：");
	scanf("%d",&voter_count);
	p = (sVo *)malloc(voter_count*sizeof(sVo));
	po = (sCa *)malloc(candidate_count*sizeof(sCa));
	printf("请输入候选人的名字和起始票数：\n");
	for(i=0;i<candidate_count;i++)
	{
		(po+i)->name = (char *)malloc(20);
		scanf("%s%d",(po+i)->name,&(po+i)->poll);
	}
	vote(p,po,voter_count,candidate_count);
	for(i=0;i<candidate_count;i++)
	{
		free((po+i)->name);
		(po+i)->name = NULL;
	}
	if(p!=NULL)
	{
		free(p);
		p = NULL;
	}
	if(po!=NULL)
	{
		free(po);
		po = NULL;

	}
	return 0;

}
