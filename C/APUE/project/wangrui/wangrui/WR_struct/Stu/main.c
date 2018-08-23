#include"student.h"

int main()
{
	char choose;
	pNode phead;
	Init_node(&phead);
	load_file(phead);
	do
	{
		choose = Menu();
//		printf("%d\n",choose);
		switch(choose)
		{
			case INPUT:creat_input_chain(phead);break; 		   
			case FIND:find_age(phead);break; 		   
			case SAVE:save_file(phead);break; 		   
			case PRINT:show_chain(phead);break; 		   
			case EXIT:Destory_list(&phead);break;
		   	default:printf("Choose again!\n");break;			  

		}
	}while(choose!=5);
	return 0;
}
void load_file(pNode phead)
{
	FILE * fp = NULL;
	pNode ptmp=NULL;
	pNode ptail=phead;
	fp = fopen("student.txt","r");
	if(fp == NULL)
	{
		printf("fopen error\n");
		exit(-1);
	}
	while(feof(fp)==0)
	{
		Init_node(&ptmp);
		fread(ptmp,sizeof(sNode),1,fp);
		if(NULL != ptmp)
		{
		printf("%d %s %d\n",ptmp->id,ptmp->name,ptmp->age);
		ptail->next = ptmp;
		ptail = ptmp;
		}
	}
	printf("load over\n");
	fclose(fp);
}
#if 1
void save_file(pNode phead)
{
	pNode ptmp = NULL;
	FILE *fp = NULL;
	fp = fopen("student.txt","w+");
	if(fp == NULL)
	{
		printf("fopen error\n");
		exit(-1);
	}
	for(ptmp = phead->next ;ptmp != NULL ;ptmp = ptmp->next)
	{
		fwrite(ptmp,sizeof(sNode),1,fp);
	}
	printf("write over\n");
	fclose(fp);

	fp = fopen("student.txt","r");
	if(fp == NULL)
	{
		printf("fopen error\n");
		exit(-1);
	}
	for(ptmp = phead->next ;ptmp != NULL ;ptmp = ptmp->next)
	{
		fread(ptmp,sizeof(sNode),1,fp);
		printf("%d %s %d\n",ptmp->id,ptmp->name,ptmp->age);
	}
	printf("read over\n");
	fclose(fp);
}
#endif
void find_age(pNode phead)
{
	pNode ptmp = NULL;
	int years;
	int n=0;
	printf("find Age:\n");
	scanf("%d",&years);
	for(ptmp = phead->next ;ptmp != NULL ;ptmp = ptmp->next)
	{
		if(ptmp->age == years)
		{
			printf("No.%d Name: %s Age: %d\n"
						,ptmp->id,ptmp->name,ptmp->age);
			n++;
		}
	}
	if(n==0)
	{
		printf("no this age student !\n");
	}
}
void Destory_list(pNode *phead)
{
	pNode pdel = NULL;
	while((*phead)->next != NULL)
	{
		pdel = (*phead)->next;
		(*phead)->next = pdel->next;
		pdel->next = NULL;
		Destory_node(&pdel);
	}
	Destory_node(phead);
}
void Destory_node(pNode *p)
{
	if(*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}
void show_chain(pNode phead)
{
	pNode ptmp = phead;
	for(ptmp = phead->next ;ptmp != NULL ;ptmp = ptmp->next)
	{
		if(ptmp->id==0)
		{
			continue;
		}
		printf("No.%d Name: %s Age: %d\n"
						,ptmp->id,ptmp->name,ptmp->age);
	}
}
void creat_input_chain(pNode phead)
{
	pNode pnew = NULL;
	Init_node(&pnew);
	Input_chain(phead,pnew);
	Insert_chain(phead,pnew);
}
void Input_chain(pNode phead,pNode pnew)
{
	do
	{
		printf("Please input student ID:\n");
		scanf("%d",&pnew->id);
	}while(judge(phead,pnew->id)==-1 && pnew->id==0 && printf("ID repeat!"));
	
	printf("student name:\n");
	scanf("%s",pnew->name);
	printf("student age:\n");
	scanf("%d",&pnew->age);
}
int judge(pNode phead,int nid)
{
	pNode ptmp = phead;
	while(ptmp->next != NULL)
	{
		if(ptmp->next->id == nid)
		{
			return -1;
		}
		ptmp = ptmp->next;
	}
	return 0;
}
void Insert_chain(pNode phead,pNode pnew)
{
	pNode pPos = Find_pos(phead,pnew);
	if(pPos==NULL||pnew==NULL)
	{
		printf("insert error");
		exit(-1);
	}
	pnew->next=pPos->next;
	pPos->next=pnew;
}
pNode Find_pos(pNode phead,pNode pnew)
{
	pNode ptmp = phead;
	while(ptmp->next != NULL)
	{
		if(ptmp->next->id >= pnew->id)
		{
			return ptmp;
		}
		ptmp = ptmp->next;
	}
	return ptmp;
}
char Menu()
{
	char choose[4];
	printf("Input(ID) -----> 1\n");
	printf("Find(AGE) -----> 2\n");
	printf("Save ----------> 3\n");
	printf("Print ---------> 4\n");
	printf("Exit ----------> 5\n");
	scanf("%s",choose);
	if(choose[0]<'1'||choose[0]>'5');
	{
		printf("Choose again\n");
		Menu();
	}
	return choose[0];
}
void Init_node(pNode *p)
{
	creat_memory(p,sizeof(sNode));
	(*p)->next = NULL;
}

void creat_memory(pNode *p,int size)
{
	*p = (pNode)malloc(size);
	if(*p==NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
}
