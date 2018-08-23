#include"main.h"
#include"insert.h"
#include"creat.h"

int pInsert(pStu pHead,pStu pnew,int(*pIDFind)(pStu,pStu),
				pStu (*pInsertPosition)(pStu,pStu))
{
	pnew->stu_input=stu_input;
	stu_input(pnew);
	if(pIDFind(pHead,pnew))
	{
		return -1;
	}
	else
	{
		insert_back(pInsertPosition(pHead,pnew),pnew);
		return 0;
	}
}

int pidfind(pStu pHead,pStu pnew)
{
	pStu ptar=pHead;
	while(ptar->next!=NULL)
	{
		if(ptar->next->num==pnew->num)
		{
			printf("id相同输入错误\n");
			return 1;
		}
		ptar=ptar->next;
	}
	return 0;
}

pStu pinsertposition(pStu pHead,pStu pnew)
{
	pStu ptar=pHead;
	while(ptar->next!=NULL)
	{
		if(ptar->next->num > pnew->num)
		{
			break;
		}
		ptar=ptar->next;
	}
	return ptar;
}

int insert_back(pStu p1,pStu p2)
{
	if(p1==NULL||p2==NULL)
	{
		return -1;
	}
	p2->next=p1->next;
	p1->next=p2;
	return 0; 
}

void init_stu(pStu *p,int size)
{
	creat_memory((void **)p,size);
	(*p)->next=NULL;
}

int stu_input(pStu pnew)
{
	printf("请输入学号年龄\n");
	scanf("%d%d",&pnew->num,&pnew->age);
	return 0;
}

int file_chain_insert(pStu pHead,FILE *fd)
{
	fd=fopen("stu.txt","r");
	if(fd==NULL)
	{
		fd=fopen("stu.txt","w");
		return 0;
	}
	fseek(fd,0,SEEK_END);
	long l=ftell(fd);
	//printf("l:%d\n",l);
	if(l==0)
	{
		return -1;
	}
	else
	{
		fseek(fd,0,SEEK_SET);
		pStu p=NULL;
		creat_memory((void **)&p,sizeof(sStu));
		fread(p,sizeof(sStu),1,fd);
		p->next=NULL;
		while(!feof(fd))
		{	
			insert_back(pinsertposition(pHead,p),p);
			creat_memory((void **)&p,sizeof(sStu));
			fread(p,sizeof(sStu),1,fd);
			p->next=NULL;
		}
		fclose(fd);
		return 0;
	}
}
