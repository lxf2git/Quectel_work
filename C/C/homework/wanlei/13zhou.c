#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 10
#define M 20

typedef struct Student
{
	char name[M];
	char sex;
	int id;
	int age;
}sStu;

void creat_memory(void **p,int size);
void input(sStu *p);
void store(sStu *p,FILE *fp);
void output(FILE *fp);
void i_free(void **p);

int main()
{
	sStu stu[N];
	FILE *fp=NULL;
	char *pch=NULL;
	creat_memory((void **)&pch,M*sizeof(char));
	printf("请输入存入学生信息的文件名\n");
	scanf("%s",pch);
	fp=fopen(pch,"w+");
	input(stu);
	store(stu,fp);
	i_free((void**)&pch);
	fclose(fp);
	return 0;
}

void creat_memory(void **p,int size)
{
	*p=malloc(size);
	if(NULL==*p)
	{
		printf("malloc error\n");
		exit(-1);
	}
}

void input(sStu *p)
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("请输入学生姓名 年龄id 性别\n");
		getchar();
		scanf("%s",p[i].name);
		getchar();
		scanf("%d",&p[i].age);
		scanf("%d",&p[i].id);
		getchar();
		scanf("%c",&p[i].sex);
	}
}

void store(sStu *p,FILE *fp)
{
	int i;
	for(i=0;i<N;i++)
	{
		fwrite(&p[i],sizeof(sStu),1,fp);
	}
	output(fp);
}

void output(FILE *fp)
{
	int i;
	sStu *p1=NULL;
	creat_memory((void **)&p1,N*sizeof(sStu));
	fseek(fp,0,SEEK_SET);
	for(i=0;i<N;i++)
	{
		if(i==0||i==2||i==4||i==6||i==9)
		{
			fread(&p1[i],sizeof(sStu),1,fp);
			printf("name:%s age:%d id:%d sex:%c\n",
						p1[i].name,p1[i].age,
						p1[i].id,p1[i].sex);
		}
		else
		{
			fseek(fp,sizeof(sStu),SEEK_CUR);
		}
	}
	i_free((void **)&p1);
}

void i_free(void **p)
{
	if(*p!=NULL)
	{
		free(*p);
		*p=NULL;
	}
}
