#include<stdio.h>	

typedef struct Student
{
	char *name;
	int age;
	int id;
	struct Student *next;
}sStu,*pStu;

void creat_memory(pStu *p,int size)
{
	p = (pStu)malloc(size);
	if(*p==NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void init_memory(pStu *p,int size)
{
	creat_memory(&p,size);
	(*p)->next = NULL;
}

pStu find_max(pStu pHead,pStu pnew)
{
	pStu ptmp=pHead;
	while(ptmp->next!=NULL)
	{
		if(ptmp->next->id >= pnew->id)
		{
			return ptmp;
		}
		ptmp = ptmp->next;
	}
	return ptmp;
}

int insert_back(pStu pPos,pStu pIn)
{
	if(pPos==NULL||pIn==NULL)
	{
		return -1;
	}
	pIn->next = pPos->next;
	pPos->next = pIn;

	return 0;
}




void insert_chain(pStu pHead)
{
	pStu pnew=NULL;
	init_memory(&pnew,sizeof(sStu));
	printf("请输入学生姓名 年龄 序号\n");
	pnew->name=malloc(20*sizeof(char));
	scanf("%s %d %d",pnew->name,&pnew->age,&pnew->id);
	pStu pmax = fine_max(pHead,pnew);
	insert_back(pmax,pnew);
}





int main()
{
	pStu pHead=NULL;
	init_memory(&pHead,sizeof(sStu));	
	insert_chain(pHead);
	
	


	
	
