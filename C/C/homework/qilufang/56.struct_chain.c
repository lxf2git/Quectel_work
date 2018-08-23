#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 10
enum comand
{
	INPUT=1,
	CATCH,
	SAVE,
	PRINTF,
	EXIT,
};

/************结构体声明**************/
typedef struct Student 
{
	char name[10];
	int age;
	int id;
	struct Student *next;
}sStu,*pStu;
pStu pHead=NULL;

/*************开空间函数****************/
void getmemory(void **p,int size)
{
	*p=malloc(size);
	if(NULL==*p)
	{
		printf("getmemory_error!\n");
		exit(-1);
	}
}

/************链表开空间函数*************/
void init_Stu(pStu *p,int size)
{
	getmemory((void **)p,size);
	(*p)->next=NULL;
}

/*************寻找最大值**************/
pStu find_max(pStu pnew)
{
	pStu stmp=pHead;
	while(stmp->next != NULL)
	{
			if(stmp->next->id >= pnew->id)
			{
				return stmp;
			}
			stmp=stmp->next;
	}
	return stmp;
}

/*************输出函数*******************/
void output(pStu pHead)
{
	pStu stmp;
	stmp=pHead;
	while(stmp->next != NULL)
	{
		printf("Name:%s Age:%d Id:%d\n",stmp->next->name,stmp->next->age,
						stmp->next->id);
		stmp=stmp->next;
	}
}

/**************插入函数************/
int inser_back(pStu pIn,pStu pPos)
{
	if(pPos==NULL||pIn==NULL)
	{
		return -1;
	}
	pIn->next=pPos->next;
	pPos->next=pIn;
	return 0;
}

/**********创建链表函数***************/
void make_chain()
{
	pStu pnew=NULL;
	init_Stu(&pnew,sizeof(sStu));
	printf("输入学生的Name Age Id:\n");
	scanf("%s%d%d",pnew->name,&pnew->age,&pnew->id);
	pStu pmax = find_max(pnew);
	inser_back(pnew,pmax);
}

/************查询函数1***************/
int catch_1()
{
	char str[20];
	printf("请输入你查询的学生的Name\n");
	getchar();
	gets(str);
	pStu stmp;
	stmp=pHead;
	while(stmp->next != NULL)
	{
		if(strcmp(stmp->next->name,str)==0)
		{
			printf("Name:%s Age:%d Id:%d\n",stmp->next->name,
						stmp->next->age,stmp->next->id);
			return 1;
		}
		stmp=stmp->next;
	}
	return 0;
}

/**************查询函数2*************/
void catch()
{
	int ret;
	ret=catch_1();
	if(ret==0)
	{
		printf("你输入的名字不存在\n");
	}
}

/************保存函数*************/
void save()
{
	pStu stmp;
	FILE *fp;
	if((fp=fopen("file","a"))==NULL)
	{
		printf("file_open_error!\n");
		exit(-1);
	}
	for(stmp=pHead;stmp->next != NULL;stmp=stmp->next)
	{
		fwrite(stmp->next->name,20*sizeof(char),1,fp);
		fwrite(&stmp->next->age,sizeof(int),1,fp);
		fwrite(&stmp->next->id,sizeof(int),1,fp);
	}
	fclose(fp);
}

/***********主函数******************/
int main()
{
	int i,in=0;
	init_Stu(&pHead,sizeof(sStu));
	for(i=0;;i++)
	{
		printf("<1>*************输入学生信息\n");
		printf("<2>*************查找学生信息\n");
		printf("<3>*************保存所有学生信息\n");
		printf("<4>*************打印所有学生信息\n");
		printf("<5>*************退出\n");
		printf("输入你选择的服务：\n");
		scanf("%d",&in);
		switch(in)
		{
			case INPUT : make_chain(); break;
			case CATCH : catch(); break;
			case SAVE : save(); break;
			case PRINTF : output(pHead); break;
			case EXIT : exit(0);
			default : printf("请重新输入：\n"); break;
		}
	}
	return 0;

}
