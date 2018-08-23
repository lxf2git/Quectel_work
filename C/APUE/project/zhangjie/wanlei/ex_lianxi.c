#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
	int id;
	char name[20];
	int age;
	struct student *next;
}sStu;

enum menu
{
	INPUT=1,
	FIND,
	SAVE,
	PRINTF,
	EXIT
};


void init_node(sStu **p,int size);
void creat_memory(void **p,int size);
int menu(sStu *p);
int insert_chain(sStu *phead);
sStu *find_max(sStu *phead,sStu *pnew);
int insert_back(sStu *p1,sStu *p2);
int find_same(sStu *phead,sStu *pnew);
void show(sStu *phead);
void find_age(sStu *phead);
void find_age_1(int age,int x);
void save_stu(sStu *phead);
void read_stu();
void destory(sStu **p);
void i_free(void **p);

int main()
{
	sStu *phead=NULL;
	init_node(&phead,sizeof(sStu));
	menu(phead);
	destory(&phead);
	return 0;
}

void init_node(sStu **p,int size)
{
	creat_memory((void **)p,size);
	(*p)->next=NULL;
}

void creat_memory(void **p,int size)
{
	*p=malloc(size);
	if(*p==NULL)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

int menu(sStu *p)
{
	int n;
	do
	{
		printf("请选择功能：\n");
		printf("1：输入学生信息\n");
		printf("2：按年龄查找学生\n");
		printf("3：保存到磁盘\n");
		printf("4：打印到桌面\n");
		printf("5：退出\n");
		scanf("%d",&n);
		switch(n)
		{
			case INPUT:
				insert_chain(p);
				//show(p);
				break;
			case FIND:
				find_age(p);
				break;
			case SAVE:
				save_stu(p);
				break;
			case PRINTF:
				read_stu();
				break;
			case EXIT:
				return 0;
				break;
			default:
				break;
		}

	}while(n>=INPUT||n<=EXIT);
}

int insert_chain(sStu *phead)
{
	sStu *ptmp=NULL;
	sStu *pnew=NULL;
	printf("请输入学生id 姓名 年龄\n");
	init_node(&pnew,sizeof(sStu));
	scanf("%d",&pnew->id);
	scanf("%s",pnew->name);
	scanf("%d",&pnew->age);
	if(find_same(phead,pnew)||find_same_1(pnew))
	{
		return -1;	
	}
	else
	{
		ptmp=find_max(phead,pnew);
		insert_back(ptmp,pnew);
		return 0;
	}
	
	//printf("%p",pnew->next);
}

sStu *find_max(sStu *phead,sStu *pnew)
{
	sStu *ptar=phead;
	while(ptar->next!=NULL)
	{
		if(ptar->next->id>pnew->id)
		{
			break;
		}
		ptar=ptar->next;
	}
	return ptar;
}

int find_same(sStu *phead,sStu *pnew)
{
	sStu *ptar=phead;
	while(ptar->next!=NULL)
	{
		if(ptar->next->id==pnew->id)
		{
			printf("id相同输入错误\n");
			return 1;
		}
		ptar=ptar->next;
	}
	return 0;
}


int find_same_1(sStu *pnew)
{

	FILE *fp=NULL;
	fp = fopen("ex_stu.txt","r");
	if(fp==NULL)
	{
		printf("fopen error\n");
		exit(-1);
	}
	sStu *p=NULL;
	creat_memory((void **)&p,sizeof(sStu));
	while(!feof(fp))
	{
		fread(p,sizeof(sStu),1,fp);
		if(p->id==pnew->id)
		{
			printf("id相同输入错误\n");
			return 1;
		}
	}
	i_free((void **)&p);
	return 0;
}

int insert_back(sStu *p1,sStu *p2)
{
	if(p1==NULL||p2==NULL)
	{
		return -1;
	}
	p2->next=p1->next;
	p1->next=p2;
	return 0;
}

void show(sStu *phead)
{
	sStu *p;
	for(p=phead->next;p!=NULL;p=p->next)
	{
		printf("id:%d name:%s age:%d",p->id,p->name,p->age);
	}
}

void find_age(sStu *phead)
{
	int age,n=0;
	printf("请输入要查找的学生的年龄\n");
	scanf("%d",&age);
	sStu *ptar=phead;
	printf("当前输入的学生\n");
	while(ptar->next!=NULL)
	{
		if(ptar->next->age==age)
		{
			printf("id:%d name:%s age:%d\n",ptar->next->id,
											ptar->next->name,
											ptar->next->age);
			n++;
		}
		ptar=ptar->next;
	}
	find_age_1(age,n);
}

void find_age_1(int age,int x)
{
	FILE *fp=NULL;
	fp = fopen("ex_stu.txt","r");
	if(fp==NULL)
	{
		printf("fopen error\n");
		exit(-1);
	}
	sStu *p=NULL;
	creat_memory((void **)&p,sizeof(sStu));
	fread(p,sizeof(sStu),1,fp);
	printf("已经存入磁盘的学生\n");
	while(!feof(fp))
	{
		if(p->age==age)
		{
			printf("id:%d name:%s age:%d\n",p->id,
											p->name,
											p->age);
			x++;
		}
		fread(p,sizeof(sStu),1,fp);
	}
	i_free((void **)&p);
	if(x==0)
	{
		printf("not found\n");
	}
	fclose(fp);
}

void save_stu(sStu *phead)
{
	FILE *fp=NULL;
	fp = fopen("ex_stu.txt","a+");
	if(fp==NULL)
	{
		printf("fopen error\n");
		exit(-1);
	}
	sStu *ptar=phead;
	while(ptar->next!=NULL)
	{
		fwrite(ptar->next,sizeof(sStu),1,fp);
		ptar=ptar->next;
	}
	printf("保存成功\n");
	fclose(fp);
}

void read_stu()
{
	FILE *fp;
	sStu *p=NULL;
	creat_memory((void **)&p,sizeof(sStu));
	fp = fopen("ex_stu.txt","r");
	if(fp==NULL)
	{
		printf("fopen error\n");
		exit(-1);
	}
	fread(p,sizeof(sStu),1,fp);
	while(!feof(fp))
	{
		printf("id:%d name:%s age:%d\n",p->id,p->name,p->age);
		fread(p,sizeof(sStu),1,fp);
	}
	fclose(fp);
}

void destory(sStu **p)
{
	sStu *pdel=*p;
	while((*p)->next!=NULL)
	{
		pdel=(*p)->next;
		(*p)->next=pdel->next;
		pdel->next=NULL;
		i_free((void **)&pdel);
	}
	i_free((void **)p);
}

void i_free(void **p)
{
	if(*p!=NULL)
	{
		free(*p);
		*p=NULL;
	}
}
