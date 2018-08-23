#include"init.h"
#include"insert.h"

void init_node(pStu *pp, int size)
{
	create_memory((void **)pp,size);
	(*pp)->next = NULL;
}

void create_memory(void **pp,int size)
{
	*pp = malloc(size);
	if(NULL == *pp)
	{
		printf("pnode malloc error!\n");
		exit(-1);
	}
}

void openfile(FILE **popen)
{
	*popen = fopen("/home/struct/22_s/work_22/2_sday/a.txt","w+");
	if(NULL == *popen)
	{
		printf("file open error!\n");
	}
}
void readfile(FILE **popen)
{
	*popen = fopen("/home/struct/22_s/work_22/2_sday/a.txt","r+");
	if(NULL == *popen)
	{
		printf("file open error!\n");
	}
}

void load(pStu phead, FILE *fp)
{
	readfile(&fp);
	load_read(phead, fp);
	fclose(fp);
}

void load_read(pStu phead, FILE *fp)
{
	pStu pnew=NULL;
	while(!feof(fp))
	{
//		printf("feof:%d\n",feof(fp));
//		printf("load_read--->!\n");
		init_node(&pnew,sizeof(sStu));
		fread(pnew, sizeof(sStu), 1,fp);
		if(pnew->num != 0)
		{
			insert(phead,pnew,find_id,posite_in);
		}
	}
}

void destory_node(pStu *p)
{
	if(*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}

void exit_my(pStu *phead)
{
	pStu pdel=NULL;
	while((*phead)->next != NULL)
	{
		pdel = (*phead)->next;
		(*phead)->next = pdel->next;
		pdel->next = NULL;
		destory_node(&pdel);
	}
	destory_node(phead);
	printf("exit\n");
}
