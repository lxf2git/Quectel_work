#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct student 
{
	int id;
	int age;
	char *name;
	struct student *next;

}sNode,*pNode;

enum choose_name
{
	Input=1,
	Find,
	Save,
	Print,
	Exit
};


void create_memory(pNode *p, int size)
{
	*p=(pNode)malloc(size);
	if(NULL==*p)
	{
		printf("create error!\n");
		exit(-1);
	}
	(*p)->next=NULL;

}

void show_chain(pNode);

pNode find_max(pNode pHead,pNode pnew)
{
	pNode pTrav=pHead;
	while(pTrav->next!=NULL)
	{
		if(pTrav->next->id>pnew->id)
		{
			return pTrav;
		}
		pTrav=pTrav->next;
	}
	return pTrav;
}
void Insert_back(pNode pPos,pNode pIn)
{
	while(pPos==NULL||pIn==NULL)
	{
		printf("Insert error!\n");
	}
		pIn->next=pPos->next;
		pPos->next=pIn;
}

void Insert_chain(pNode pHead)
{
	pNode pnew=NULL;
		create_memory(&pnew,sizeof(sNode));
		//pnew->next=NULL;
		pnew->name=(char *)malloc(20*sizeof(char));
		printf("please input name,id,age:\n");
		scanf("%s",pnew->name);
		getchar();
		scanf("%d%d",&pnew->id,&pnew->age);
		pNode pTrav=find_max(pHead,pnew);
		Insert_back(pTrav,pnew);
	show_chain(pHead);	
}
void Find_node(pNode pHead,int find_age)
{
	pNode ptmp=NULL;
	for(ptmp=pHead->next;ptmp!=NULL;ptmp=ptmp->next)
	{
		if(ptmp->age==find_age)
		{
			printf("id:%d age:%d name:%s",ptmp->id,ptmp->age,ptmp->name);
		}
	}
	printf("\n");
}
void show_chain(pNode pHead)
{
	pNode ptmp=pHead->next;
	for(;ptmp!=NULL;ptmp=ptmp->next)
	{
		printf("id:%d age:%d name:%s",ptmp->id,ptmp->age,ptmp->name);
	}
	printf("\n");
}

void save_node(pNode pHead)
{
	pNode ptmp=NULL;
	FILE *fp=NULL;
	fp=fopen("save.txt","w+");
	for(ptmp=pHead->next;ptmp!=NULL;ptmp=ptmp->next)
	{
	fwrite(ptmp,sizeof(ptmp),1,fp);
	}
	fclose(fp);

}
//int choose_s(int);

int main()
{
	pNode pHead=NULL;
	create_memory(&pHead,sizeof(sNode));
	while(1)
	{
	int choose;
	printf("*********************\n");
	printf("******1.Input********\n");
	printf("******2.Find*********\n");
	printf("******3.Save*********\n");
	printf("******4.Print********\n");
	printf("******5.exit*********\n");
	printf("*********************\n");
	printf("please input choose:\n");
	scanf("%d",&choose);
	

	switch(choose)
	{
		case Input:
			Insert_chain(pHead);
			//printf("%d",pHead->next->age);
			break;
		case Find:
			printf("please input find age:\n");
			int find_age;
			scanf("%d",&find_age);
			Find_node(pHead ,find_age);
			break;
		case Save:
			save_node(pHead);
			break;
		case Print:
			//printf("%d",pHead->next->age);
			show_chain(pHead);
			break;
		case Exit:
			exit(-1);
		default:
		printf("input error!please input restart.\n");
	}
	}
}
